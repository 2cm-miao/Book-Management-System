#if !defined(AFX_USERS_H__3470DC78_8479_48EE_81BE_960FC7F16D0E__INCLUDED_)
#define AFX_USERS_H__3470DC78_8479_48EE_81BE_960FC7F16D0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// users.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cusers recordset

class Cusers : public CRecordset
{
public:
	Cusers(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Cusers)

// Field/Param Data
	//{{AFX_FIELD(Cusers, CRecordset)
	CString	m_snum;
	CString	m_sname;
	CString	m_sage;
	CString	m_sclass;
	CString	m_sbook;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cusers)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERS_H__3470DC78_8479_48EE_81BE_960FC7F16D0E__INCLUDED_)
