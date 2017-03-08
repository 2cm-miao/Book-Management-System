// users.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "users.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cusers

IMPLEMENT_DYNAMIC(Cusers, CRecordset)

Cusers::Cusers(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(Cusers)
	m_snum = _T("");
	m_sname = _T("");
	m_sage = _T("");
	m_sclass = _T("");
	m_sbook = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString Cusers::GetDefaultConnect()
{
	return _T("ODBC;DSN=booksystem");
}

CString Cusers::GetDefaultSQL()
{
	return _T("[dbo].[users]");
}

void Cusers::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(Cusers)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[snum]"), m_snum);
	RFX_Text(pFX, _T("[sname]"), m_sname);
	RFX_Text(pFX, _T("[sage]"), m_sage);
	RFX_Text(pFX, _T("[sclass]"), m_sclass);
	RFX_Text(pFX, _T("[sbook]"), m_sbook);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// Cusers diagnostics

#ifdef _DEBUG
void Cusers::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cusers::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
