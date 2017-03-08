#if !defined(AFX_UOK_H__EC921C1B_0E65_4CA9_B660_A5EF11F893C1__INCLUDED_)
#define AFX_UOK_H__EC921C1B_0E65_4CA9_B660_A5EF11F893C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Uok.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Uok dialog

class Uok : public CDialog
{
// Construction
public:
	Uok(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Uok)
	enum { IDD = IDD_DIALOG1 };
	CString	m_name;
	CString	m_num;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Uok)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Uok)
	afx_msg void OnChangeNum();
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UOK_H__EC921C1B_0E65_4CA9_B660_A5EF11F893C1__INCLUDED_)
