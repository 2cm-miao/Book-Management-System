// BookSystem.h : main header file for the BOOKSYSTEM application
//

#if !defined(AFX_BOOKSYSTEM_H__03FD7A6C_A8AC_4F93_AC60_EA3CB16848BC__INCLUDED_)
#define AFX_BOOKSYSTEM_H__03FD7A6C_A8AC_4F93_AC60_EA3CB16848BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBookSystemApp:
// See BookSystem.cpp for the implementation of this class
//

class CBookSystemApp : public CWinApp
{
public:
	CBookSystemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookSystemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBookSystemApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKSYSTEM_H__03FD7A6C_A8AC_4F93_AC60_EA3CB16848BC__INCLUDED_)
