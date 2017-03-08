// BookSystemView.h : interface of the CBookSystemView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOOKSYSTEMVIEW_H__4C3F86F6_FE98_4ED9_8C71_E0C534D08F61__INCLUDED_)
#define AFX_BOOKSYSTEMVIEW_H__4C3F86F6_FE98_4ED9_8C71_E0C534D08F61__INCLUDED_

#include"afxdb.h"
#include"users.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBookSystemSet;

class CBookSystemView : public CRecordView
{
protected: // create from serialization only
	CBookSystemView();
	DECLARE_DYNCREATE(CBookSystemView)

public:
	//{{AFX_DATA(CBookSystemView)
	enum { IDD = IDD_BOOKSYSTEM_FORM };
	CBookSystemSet* m_pSet;
	CString	m_snum;
	CString	m_sname;
	CString	m_mname;
	CString	m_mid;
	//}}AFX_DATA

// Attributes
public:
	CBookSystemDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookSystemView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBookSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBookSystemView)
	afx_msg void OnOK();
	afx_msg void OnCel();
	afx_msg void OnOK1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BookSystemView.cpp
inline CBookSystemDoc* CBookSystemView::GetDocument()
   { return (CBookSystemDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKSYSTEMVIEW_H__4C3F86F6_FE98_4ED9_8C71_E0C534D08F61__INCLUDED_)
