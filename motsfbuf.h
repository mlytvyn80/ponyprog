//=========================================================================//
//-------------------------------------------------------------------------//
// motsfbuf.h -- Header for Motorola S-record FileBuf class                //
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

#ifndef _MOTOSFBUF_H
#define _MOTOSFBUF_H

// Include standard V files as needed

#include "types.h"
#include "filebuf.h"

class MotorolaSFileBuf : public FileBuf
{
  public:		//---------------------------------------- public

	MotorolaSFileBuf(e2AppWinInfo *wininfo = 0);
	virtual ~MotorolaSFileBuf();

	virtual int Load(int loadtype = ALL_TYPE, long relocation_offset = 0);
	virtual int Save(int savetype = ALL_TYPE, long relocation_offset = 0);

  protected:	//--------------------------------------- protected

  private:		//--------------------------------------- private

	int WriteRecord(FILE *fh, BYTE *bptr, long curaddr, long recsize, int fmt);
	int ParseRecord(char *lbufPC, BYTE *buf_startP, BYTE *buf_endP, long offset, int nocopy);

	BYTE *highestPC;
	long highestAddr;
	long lowestAddr;
};
#endif
