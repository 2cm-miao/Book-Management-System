#if !defined(AFX_UMUSERS_H__F93E7E6A_97A5_4792_9A63_C4863E2DE421__INCLUDED_)
#define AFX_UMUSERS_H__F93E7E6A_97A5_4792_9A63_C4863E2DE421__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Umusers.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Umusers dialog

class Umusers : public CDialog
{
// Construction
public:
	Umusers(CWnd* pParent = NULL);   // standard constructor
	void list_all(CString);

// Dialog Data
	//{{AFX_DATA(Umusers)
	enum { IDD = IDD_MANAGER3 };
	CListCtrl	m_list3;
	CString	m_snum;
	CString	m_sname;
	CString	m_sclass;
	CString	m_sbook;
	CString	m_sage;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Umusers)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Umusers)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd2();
	afx_msg void OnDel2();
	afx_msg void OnChange2();
	afx_msg void OnQue2();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UMUSERS_H__F93E7E6A_97A5_4792_9A63_C4863E2DE421__INCLUDED_)
