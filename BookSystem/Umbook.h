#if !defined(AFX_UMBOOK_H__110E068F_8BCC_42B3_AC63_C71C709C0954__INCLUDED_)
#define AFX_UMBOOK_H__110E068F_8BCC_42B3_AC63_C71C709C0954__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Umbook.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Umbook dialog

class Umbook : public CDialog
{
// Construction
public:
	Umbook(CWnd* pParent = NULL);   // standard constructor
	void list_all(CString str);

// Dialog Data
	//{{AFX_DATA(Umbook)
	enum { IDD = IDD_MANAGER2 };
	CListCtrl	m_list2;
	CString	m_baut1;
	CString	m_bbor1;
	CString	m_bid1;
	CString	m_bname1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Umbook)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Umbook)
	afx_msg void OnClickList2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd1();
	afx_msg void OnDel1();
	afx_msg void OnChange1();
	afx_msg void OnQue1();
	afx_msg void OnButton7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UMBOOK_H__110E068F_8BCC_42B3_AC63_C71C709C0954__INCLUDED_)
