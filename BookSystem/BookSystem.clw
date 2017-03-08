; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Uok1
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BookSystem.h"
LastPage=0

ClassCount=15
Class1=CBookSystemApp
Class2=CBookSystemDoc
Class3=CBookSystemView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=9
Resource1=IDD_DIALOG1
Resource2=IDD_USERS
Class5=CBookSystemSet
Resource3=IDD_MANAGER2
Resource4=IDD_MANAGER3
Resource5=IDD_MANAGER1
Resource6=IDD_ABOUTBOX
Class7=Cusers
Class8=Ubook
Class9=Cbook
Class10=Cman
Class11=Um
Class12=Umbook
Class13=Umusers
Resource7=IDR_MAINFRAME
Class14=Uok
Resource8=IDD_BOOKSYSTEM_FORM
Class15=Uok1
Resource9=IDD_DIALOG2

[CLS:CBookSystemApp]
Type=0
HeaderFile=BookSystem.h
ImplementationFile=BookSystem.cpp
Filter=N

[CLS:CBookSystemDoc]
Type=0
HeaderFile=BookSystemDoc.h
ImplementationFile=BookSystemDoc.cpp
Filter=N

[CLS:CBookSystemView]
Type=0
HeaderFile=BookSystemView.h
ImplementationFile=BookSystemView.cpp
Filter=D
LastObject=CBookSystemView
BaseClass=CRecordView
VirtualFilter=RVWC


[CLS:CBookSystemSet]
Type=0
HeaderFile=BookSystemSet.h
ImplementationFile=BookSystemSet.cpp
Filter=N

[DB:CBookSystemSet]
DB=1
DBType=ODBC
ColumnCount=12
Column1=[bid], 1, 10
Column2=[bname], 1, 20
Column3=[baut], 1, 10
Column4=[bbor], 1, 20
Column5=[mid], 1, 10
Column6=[mname], 1, 20
Column7=[nsex], 1, 10
Column8=[snum], 1, 10
Column9=[sname], 1, 20
Column10=[sage], 1, 10
Column11=[sclass], 1, 20
Column12=[sbook], 1, 20


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=BookSystem.cpp
ImplementationFile=BookSystem.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
Command4=ID_APP_EXIT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_RECORD_FIRST
Command10=ID_RECORD_PREV
Command11=ID_RECORD_NEXT
Command12=ID_RECORD_LAST
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

[DLG:IDD_USERS]
Type=1
Class=Ubook
ControlCount=14
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BID,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BAUT,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BNAME,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_BBOR,edit,1350631552
Control10=IDC_BACK,button,1342242816
Control11=IDC_BORROW,button,1342242816
Control12=IDC_QUE,button,1342242816
Control13=IDC_CEL1,button,1342242816
Control14=IDC_STATIC,static,1342308352

[DLG:IDD_MANAGER1]
Type=1
Class=Um
ControlCount=2
Control1=IDC_A,button,1342242816
Control2=IDC_B,button,1342242816

[DLG:IDD_MANAGER2]
Type=1
Class=Umbook
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BID1,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BAUT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BNAME1,edit,1350631552
Control7=IDC_LIST2,SysListView32,1350631425
Control8=IDC_ADD1,button,1342242816
Control9=IDC_DEL1,button,1342242816
Control10=IDC_CHANGE1,button,1342242816
Control11=IDC_QUE1,button,1342242816
Control12=IDC_STATIC,static,1342308352
Control13=IDC_BBOR1,edit,1350631552
Control14=IDC_BUTTON7,button,1342242816
Control15=IDC_STATIC,static,1342308352

[DLG:IDD_MANAGER3]
Type=1
Class=Umusers
ControlCount=17
Control1=IDC_STATIC,static,1342308352
Control2=IDC_SNUM,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SNAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SCLASS,edit,1350631552
Control7=IDC_LIST3,SysListView32,1350631425
Control8=IDC_CHANGE2,button,1342242816
Control9=IDC_DEL2,button,1342242816
Control10=IDC_ADD2,button,1342242816
Control11=IDC_QUE2,button,1342242816
Control12=IDC_STATIC,static,1342308352
Control13=IDC_SAGE,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_SBOOK,edit,1350631552
Control16=IDC_BUTTON4,button,1342242816
Control17=IDC_STATIC,static,1342308352

[DLG:IDD_BOOKSYSTEM_FORM]
Type=1
Class=CBookSystemView
ControlCount=13
Control1=IDC_SNUM,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_SNAME,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LOG1,button,1342242816
Control6=IDC_STATIC,button,1342177287
Control7=IDC_MID,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_MNAME,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_LOG2,button,1342242816
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352

[CLS:Cusers]
Type=0
HeaderFile=users.h
ImplementationFile=users.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=Cusers

[DB:Cusers]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[snum], 1, 10
Column2=[sname], 1, 20
Column3=[sage], 1, 10
Column4=[sclass], 1, 20
Column5=[sbook], 1, 20

[CLS:Ubook]
Type=0
HeaderFile=Ubook.h
ImplementationFile=Ubook.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

[CLS:Cbook]
Type=0
HeaderFile=book.h
ImplementationFile=book.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:Cbook]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[bid], 1, 10
Column2=[bname], 1, 20
Column3=[baut], 1, 10
Column4=[bbor], 1, 20

[CLS:Cman]
Type=0
HeaderFile=man.h
ImplementationFile=man.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=Cman

[DB:Cman]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[mid], 1, 10
Column2=[mname], 1, 20
Column3=[nsex], 1, 10

[CLS:Um]
Type=0
HeaderFile=Um.h
ImplementationFile=Um.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

[CLS:Umbook]
Type=0
HeaderFile=Umbook.h
ImplementationFile=Umbook.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

[CLS:Umusers]
Type=0
HeaderFile=Umusers.h
ImplementationFile=Umusers.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=Umusers

[DLG:IDD_DIALOG1]
Type=1
Class=Uok
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NUM,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350631552
Control5=IDC_OK,button,1342242816

[CLS:Uok]
Type=0
HeaderFile=Uok.h
ImplementationFile=Uok.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_APP_ABOUT

[DLG:IDD_DIALOG2]
Type=1
Class=Uok1
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NUM1,edit,1350631552
Control3=IDC_OK1,button,1342242816

[CLS:Uok1]
Type=0
HeaderFile=Uok1.h
ImplementationFile=Uok1.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_APP_ABOUT

