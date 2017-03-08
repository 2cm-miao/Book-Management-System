#if !defined(AFX_UM_H__C6B1A195_FE42_4068_BC34_10403CCDC4E0__INCLUDED_)
#define AFX_UM_H__C6B1A195_FE42_4068_BC34_10403CCDC4E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Um.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Um dialog

class Um : public CDialog
{
// Construction
public:
	Um(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Um)
	enum { IDD = IDD_MANAGER1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Um)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Um)
	afx_msg void OnA();
	afx_msg void OnB();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UM_H__C6B1A195_FE42_4068_BC34_10403CCDC4E0__INCLUDED_)
