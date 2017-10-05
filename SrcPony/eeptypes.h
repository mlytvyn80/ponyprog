//=========================================================================//
//                                                                         //
//  PonyProg - Serial Device Programmer                                    //
//                                                                         //
//  Copyright (C) 1997-2017   Claudio Lanconelli                           //
//                                                                         //
//  http://ponyprog.sourceforge.net                                        //
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

#ifndef _EEPTYPES_H
#define _EEPTYPES_H

#include "globals.h"

#include <QVector>
#include <QString>
// #include <QStringList>

#define EID_INVALID     0

#define E24XX           0x01
// Sub types
#define E2400           0x010000
#define E2402           0x010001
#define E2404           0x010002
#define E2408           0x010004
#define E2416           0x010008

#define E24XX2          0x02
// Sub types
#define E24000          0x020000
#define E24E16          0x020008
#define E2432           0x020010
#define E2464           0x020020
#define E24128          0x020040
#define E24256          0x020080
#define E24512          0x020100

#define AVRAT90         0x03
#define AVRTiny         0x14
#define AVRMega         0x15
// Sub types
#define AT90S0000       0x030000
#define AT90S1200       0x030002
#define AT90S2313       0x030003
#define AT90S4414       0x030004
#define AT90S8515       0x030005

#define ATmega603       0x150008
#define ATmega103       0x150009

#define AT90S2323       0x03000A
#define AT90S2343       0x03000B
#define AT90S2333       0x03000C
#define AT90S4433       0x03000D
#define AT90S4434       0x03000E
#define AT90S8534       0x03000F
#define AT90S8535       0x030010

#define ATtiny22        0x140011
#define ATtiny12        0x140012
#define ATtiny13        0x140013
#define ATtiny15        0x140014

#define ATmega8515      0x150015
#define ATmega8535      0x150016

#define ATmega8         0x15001A
#define ATmega161       0x150020
#define ATmega163       0x150021
#define ATmega16        0x150022
#define ATmega323       0x150023
#define ATmega32        0x150024
#define ATmega162       0x150025
#define ATmega169       0x150026
#define ATmega164       0x150027
#define ATmega324       0x150028
#define ATmega644       0x150029

#define ATmega64        0x15002A
#define ATmega128       0x150030

#define ATmega48        0x150031
#define ATmega88        0x150032
#define ATmega168       0x150033
#define ATmega640       0x150034
#define ATmega1280      0x150035
#define ATmega1281      0x150036
#define ATmega2560      0x150037
#define ATmega2561      0x150038
#define ATmega328       0x150039 // new (RG 22.06.2012)
#define ATmega1284	0x15003A // new (RG 10.06.2017)

#define ATtiny11        0x140080
#define ATtiny10        0x140081
#define ATtiny28        0x140082
#define ATtiny26        0x140083
#define ATtiny2313      0x140084
#define ATtiny25        0x140085
#define ATtiny45        0x140086
#define ATtiny85        0x140087
#define ATtiny261       0x140088
#define ATtiny461       0x140089
#define ATtiny861       0x14008A
#define ATtiny24	0x14008B
#define ATtiny44	0x14008C
#define ATtiny84	0x14008D
#define ATtiny4313	0x14008E // new 16.09.2015 @RG

#define AT90CAN32       0x030100
#define AT90CAN64       0x030101
#define AT90CAN128      0x030102

#define E93X6           0x04
// Sub types
#define E9300           0x040000
#define E9306           0x040001
#define E9346           0x040004
#define E9356           0x040008
#define E9357           0x040009
#define E9366           0x040010
#define E9376           0x040020
#define E9386           0x040040

#define PIC16XX         0x05
// Sub types
#define PIC1600         0x050000
#define PIC1684         0x050001
#define PIC1683         0x050002

#define E250XX          0x06
// Sub types
#define E25000          0x060000
#define E25010          0x060001
#define E25020          0x060002
#define E25040          0x060004

#define E2506XX         0x07
// Sub types
#define E250600         0x070000
#define E2506           0x070001

#define E24XX5          0x08
// Sub types
#define E24325          0x080010
#define E24645          0x080020

#define E25XXX          0x09
// Sub types
#define E25XX0          0x090000
#define E25080          0x090004
#define E25160          0x090008
#define E25320          0x090010
#define E25640          0x090020
#define E25128          0x090040
#define E25256          0x090080

#define AT89SXX         0x0A
// Sub types
#define AT89S0000       0x0A0000
#define AT89S8252       0x0A0002
#define AT89S8253       0x0A0003
#define AT89S53         0x0A0004
#define AT89S52         0x0A0005
#define AT89S51         0x0A0006

#define PIC168XX        0x0B
// Sub types
#define PIC16800        0x0B0000
#define PIC1684A        0x0B0001
#define PIC16870        0x0B0002
#define PIC16871        0x0B0003
#define PIC16872        0x0B0004
#define PIC16873        0x0B0005
#define PIC16874        0x0B0006
#define PIC16876        0x0B0008
#define PIC16877        0x0B0009
#define PIC16873A       0x0B000A
#define PIC16874A       0x0B000B
#define PIC16876A       0x0B000C
#define PIC16877A       0x0B000D

#define PIC16627        0x0B0020
#define PIC16628        0x0B0021

#define ENVMXXX         0x0C
// Sub types
#define ENVM3000        0x0C0000
#define EMDA2061        0x0C0002
#define EMDA2062        0x0C0003
#define ENVM3060        0x0C0004

#define E93XX_8         0x0D
// Sub types
#define E9300_8         0x0d0000
#define E9306_8         0x0d0001
#define E9346_8         0x0d0004
#define E9356_8         0x0d0008
#define E9357_8         0x0d0009
#define E9366_8         0x0d0010
#define E9376_8         0x0d0020
#define E9386_8         0x0d0040

#define PIC125XX        0x0E
// Sub types
#define PIC12500        0x0E0000
#define PIC12508        0x0E0004
#define PIC12509        0x0E0005
#define PIC12508A       0x0E0008
#define PIC12509A       0x0E0009
#define PIC12E518       0x0E0010
#define PIC12E519       0x0E0011

#define PIC12608        0x0E0024
#define PIC12609        0x0E0025
#define PIC12608A       0x0E0026
#define PIC12609A       0x0E0027
#define PIC12671        0x0E0030
#define PIC12672        0x0E0031
#define PIC12673        0x0E0032
#define PIC12674        0x0E0033

//#define PIC162XX      0x0F
// Sub types
//#define       PIC16200        0x0F0000
//#define       PIC1627         0x0F0004
//#define       PIC1628         0x0F0005

#define X24C44XX        0x10
// Sub types
#define S24H30          0x100001
#define X24C44          0x100002
#define X24C45          0x100003

#define E24XX1_A        0x11
// Sub types
#define E2401_A         0x110001

#define AT17XXX         0x12
// Sub types
#define AT1765          0x120002
#define AT17128         0x120003
#define AT17256         0x120004
#define AT17512         0x120005
#define AT17010         0x120006

#define E24XX1_B        0x13
// Sub types
#define E2401_B         0x130001

#define NO_OF_EEPTYPE   0x15

#define MAXEEPSUBTYPE   64


#define KB(x)   ((x) * 1024)


// EK 2017
// common structure for chips
struct chipInfo
{
	QString name;
	long id;    // pretype | subtype
	int  sz;    //dimensione in numero di banchi
	int  splt;  // split
	int  wpgsz; // page size
	int  adrsz; //dimensione dello spazio di indirizzamento in numero di banchi
};


// extern long BuildE2PType(int pritype, int subtype = 0);
extern long BuildE2PType(unsigned long type);
extern int GetE2PSubType(unsigned long type);
extern int GetE2PPriType(unsigned long type);

chipInfo GetChipInfo(QVector<chipInfo> &c, long subtype);

// extern QString GetEEPTypeString(int pritype, int subtype);
extern QString GetEEPTypeString(unsigned long type);

extern int GetEEPTypeIndex(int type);
// extern QStringList GetEEPSubTypeList(int type);
extern QVector<chipInfo> GetEEPSubTypeVector(int type);
extern int GetEEPSubTypeIndex(unsigned long type);
// extern int GetEEPTypeSize(int pritype, int subtype);
extern int GetEEPTypeSize(unsigned long type);
// extern int GetEEPAddrSize(int pritype, int subtype);
extern int GetEEPAddrSize(unsigned long type);
// extern int GetEEPTypeSplit(int pritype, int subtype);
extern int GetEEPTypeSplit(unsigned long type);

// extern long GetEEPTypeFromSize(int pritype, int size);
extern long GetEEPTypeFromSize(unsigned long type, int size);
extern long GetEEPTypeFromString(const QString &name);

// extern int GetEEPTypeWPageSize(int pritype, int subtype);
extern int GetEEPTypeWPageSize(unsigned long type);


#endif
