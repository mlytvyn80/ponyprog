//=========================================================================//
//-------------------------------------------------------------------------//
// easyi2c.h -- Header for for EasyI2CInterface class                      //
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

#ifndef	_EASYI2CINTERFACE_H
#define	_EASYI2CINTERFACE_H

#include "portint.h"
#include "businter.h"

class EasyI2CInterface : public BusInterface, public PortInterface
{
 public:		//------------------------------- public
	EasyI2CInterface();

	virtual int Open(int com_no);
	virtual void Close();

	virtual void SetDataOut(int sda = 1);
	virtual void SetClock(int scl = 1);
	virtual int GetDataIn() ;
	virtual int GetClock() ;
	virtual void SetClockData();
	virtual int IsClockDataUP() ;
	virtual int IsClockDataDOWN() ;
	virtual int TestPort(int port);

 protected:		//------------------------------- protected

 private:		//------------------------------- private

};

#endif