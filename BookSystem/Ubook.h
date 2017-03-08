#if !defined(AFX_UBOOK_H__7FA6C948_5E86_474C_871C_E2640940D100__INCLUDED_)
#define AFX_UBOOK_H__7FA6C948_5E86_474C_871C_E2640940D100__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Ubook.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ubook dialog

class Ubook : public CDialog
{
// Construction
public:
	Ubook(CWnd* pParent = NULL);   // standard constructor
	void list_all(CString);

// Dialog Data
	//{{AFX_DATA(Ubook)
	enum { IDD = IDD_USERS };
	CListCtrl	m_list1;
	CButton	m_que;
	CString	m_bname;
	CString	m_bid;
	CString	m_bbor;
	CString	m_baut;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ubook)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ubook)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCel1();
	afx_msg void OnBack();
	afx_msg void OnBorrow();
	afx_msg void OnQue();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UBOOK_H__7FA6C948_5E86_474C_871C_E2640940D100__INCLUDED_)
