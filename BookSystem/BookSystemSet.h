// BookSystemSet.h : interface of the CBookSystemSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOOKSYSTEMSET_H__2FB6F407_7BCB_4A91_A071_9195EFBA6A88__INCLUDED_)
#define AFX_BOOKSYSTEMSET_H__2FB6F407_7BCB_4A91_A071_9195EFBA6A88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBookSystemSet : public CRecordset
{
public:
	CBookSystemSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBookSystemSet)

// Field/Param Data
	//{{AFX_FIELD(CBookSystemSet, CRecordset)
	CString	m_bid;
	CString	m_bname;
	CString	m_baut;
	CString	m_bbor;
	CString	m_mid;
	CString	m_mname;
	CString	m_nsex;
	CString	m_snum;
	CString	m_sname;
	CString	m_sage;
	CString	m_sclass;
	CString	m_sbook;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookSystemSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKSYSTEMSET_H__2FB6F407_7BCB_4A91_A071_9195EFBA6A88__INCLUDED_)

