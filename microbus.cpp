//=========================================================================//
//-------------------------------------------------------------------------//
// microbus.cpp -- Source for Microwire bus driver class                   //
// This file is part of PonyProg.                                          //
//-------------------------------------------------------------------------//
//                                                                         //
//  PonyProg - Serial Device Programmer                                    //
//                                                                         //
//  Copyright (C) 1997, 1998  Claudio Lanconelli                           //
//                                                                         //
//  e-mail: lanconel@cs.unibo.it                                           //
//  http://www.cs.unibo.it/~lanconel                                       //
//                                                                         //
//-------------------------------------------------------------------------//
//                                                                         //
// This program is free software; you can redistribute it and/or           //
// modify it under the terms of the GNU  General Public License            //
// as published by the Free Software Foundation; either version2 of        //
// the License, or (at your option) any later version.                     //
//                                                                         //
// This program is distributed in the hope that it will be useful,         //
// but WITHOUT ANY WARRANTY; without even the implied warranty of          //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU       //
// General Public License for more details.                                //
//                                                                         //
// You should have received a copy of the GNU  General Public License      //
// along with this program (see COPYING);     if not, write to the         //
// Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. //
//                                                                         //
//-------------------------------------------------------------------------//
//=========================================================================//

#include "types.h"
#include "microbus.h"
#include "errcode.h"

#include "e2app.h"

#ifdef	_LINUX_
//#  include <asm/io.h>
#  include <unistd.h>
#else
#  ifdef	__BORLANDC__
#    define	__inline__
#  else // _MICROSOFT_ VC++
#    define	__inline__ __inline
#    define _export
#  endif
#endif

// Costruttore
MicroWireBus::MicroWireBus(BusInterface *ptr)
	: BusIO(ptr)
{
	UserDebug(Constructor, "MicroWireBus::MicroWireBus()\n");
}

// Distruttore
MicroWireBus::~MicroWireBus()
{
	UserDebug(Destructor, "MicroWireBus::~MicroWireBus()\n");

	Close();
}

void MicroWireBus::SetDelay()
{
	int val = THEAPP->GetMicroWireSpeed();
	int n;

	switch(val)
	{
	case TURBO:
		n = 0;         // as fast as your PC can
		break;
	case FAST:
		n = 1;
		break;
	case SLOW:
		n = 10;
		break;
	default:
		n = 5;         //Default (< 100KHz)
		break;
	}
	BusIO::SetDelay(n);

	UserDebug1(UserApp2, "MicroWire::SetDelay() = %d\n", n);
}


int MicroWireBus::SendDataBit(int b)
{
	clearCLK();		//si assicura che SCK low
	bitDI(b);

	WaitUsec(shot_delay);

	setCLK();		//device latch data bit now!

	WaitUsec(shot_delay);

	clearCLK();

	return OK;
}

// ritorna un numero negativo se c'e` un errore, altrimenti 0 o 1
int MicroWireBus::RecDataBit()
{
	register UBYTE b;

	clearCLK();		//si assicura che SCK low

	WaitUsec(shot_delay);

	setCLK();

	WaitUsec(shot_delay);

	b = getDO();
	clearCLK();

	return b;
}

//* OK, ora ci alziamo di un livello: operiamo sul byte
int MicroWireBus::SendDataWord(int wo, int wlen)
{
	int k;

	clearCLK();
	//Dal piu` significativo al meno significativo
	for (k = wlen-1; k >= 0; k--)
		SendDataBit(wo & (1<<k));
	clearDI();

	return OK;
}

int MicroWireBus::RecDataWord(int wlen)
{
	int k, val = 0;

	clearCLK();
	for (k = wlen-1; k >= 0; k--)
		if ( RecDataBit() )
			val |= 1 << k;

	return val;
}

int MicroWireBus::WaitReadyAfterWrite(long timeout)
{
	clearCLK();
	ClearReset();	//27/05/98

	WaitUsec(shot_delay);

	SetReset();		//27/05/98

	WaitUsec(shot_delay);

	clearCLK();

	long k;
	for (k = timeout; k > 0  &&  !getDO(); k--)
		WaitUsec(1);		//07/08/99 ** try to fix temporization (so to need only one global calibration)

	UserDebug1(UserApp1, "MicroWireBus::WaitReadyAfterWrite() = %ld\n", k);

	return k ? OK : -1;
}

int MicroWireBus::Reset(void)
{
	UserDebug(UserApp2, "MicroWireBus::Reset()\n");

	SetDelay();

	clearCLK();
	//clearDI();	//27/05/98
	setDI();

	ClearReset();	//Da un impulso sul reset
	WaitMsec(1);	//27/05/98
	SetReset();

	WaitMsec(50);

	return OK;
}


int MicroWireBus::CalcAddressSize(int mem_size, int org) const
{
	if (mem_size-- <= 0)
		return -1;

	int k;
	for (k = 15; k > 0; k--)
		if ( mem_size & (1<<k) )
			break;
	if (org)
		k++;

	return k+1;
}
