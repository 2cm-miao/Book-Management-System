#if !defined(AFX_UOK1_H__10D08AD8_80AB_4A57_A81F_737A3E84B3BF__INCLUDED_)
#define AFX_UOK1_H__10D08AD8_80AB_4A57_A81F_737A3E84B3BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Uok1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Uok1 dialog

class Uok1 : public CDialog
{
// Construction
public:
	Uok1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Uok1)
	enum { IDD = IDD_DIALOG2 };
	CString	m_num1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Uok1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Uok1)
	afx_msg void OnOk1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UOK1_H__10D08AD8_80AB_4A57_A81F_737A3E84B3BF__INCLUDED_)
