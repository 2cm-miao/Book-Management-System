#if !defined(AFX_BOOK_H__51037871_B98D_4DC9_B5CC_D9ACCF257DFF__INCLUDED_)
#define AFX_BOOK_H__51037871_B98D_4DC9_B5CC_D9ACCF257DFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// book.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cbook recordset

class Cbook : public CRecordset
{
public:
	Cbook(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Cbook)

// Field/Param Data
	//{{AFX_FIELD(Cbook, CRecordset)
	CString	m_bid;
	CString	m_bname;
	CString	m_baut;
	CString	m_bbor;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cbook)
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

#endif // !defined(AFX_BOOK_H__51037871_B98D_4DC9_B5CC_D9ACCF257DFF__INCLUDED_)
