#if !defined(AFX_MAN_H__EC8D8024_A8B7_43D1_872C_7AF61C1CAD4C__INCLUDED_)
#define AFX_MAN_H__EC8D8024_A8B7_43D1_872C_7AF61C1CAD4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// man.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cman recordset

class Cman : public CRecordset
{
public:
	Cman(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Cman)

// Field/Param Data
	//{{AFX_FIELD(Cman, CRecordset)
	CString	m_mid;
	CString	m_mname;
	CString	m_nsex;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cman)
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

#endif // !defined(AFX_MAN_H__EC8D8024_A8B7_43D1_872C_7AF61C1CAD4C__INCLUDED_)
