//=========================================================================//
//                                                                         //
//  PonyProg - Serial Device Programmer                                    //
//                                                                         //
//  Copyright (C) 1997-2007   Claudio Lanconelli                           //
//                                                                         //
//  http://ponyprog.sourceforge.net                                        //
//                                                                         //
//-------------------------------------------------------------------------//
// $Id: e2dlg.h,v 1.6 2008/01/30 17:06:35 lancos Exp $
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

#ifndef e2DIALOG_H
#define e2DIALOG_H

#include <QDialog>
#include <QWidget>
#include <QObject>


#include "e2cmdw.h"
#include "globals.h"

#include "ui_e2dlg.h"

#include "string_table.h"

using namespace Translator;

class e2CmdWindow;

class e2Dialog : public QDialog, public Ui::E2Dialog
{
	Q_OBJECT

public:               //---------------------------------------- public
	e2Dialog(QWidget* bw, const QString title = STR_MSGINTSETUP);
	virtual ~e2Dialog();            // Destructor

protected:    //--------------------------------------- protected

private slots:
	void onOk();
	void onTest();
	void onChangePort(bool);
	void onSelectNum(int i);
	void onSelectCOM(int i);
	void onSelectLPT(int i);

private:              //--------------------------------------- private
	int Test(int p = 0, int open_only = 0) const;
	void setWidgetsText();
	void getSettings();
	void setSettings();

	QStringList lptList;
	QStringList comList;
	QStringList usbList;

//	e2CmdWindow* cmdWin;
	int port_no;                    // Numero della porta utilizzata
	int lpt_no, com_no;
	HInterfaceType interf_type;
};

#endif
