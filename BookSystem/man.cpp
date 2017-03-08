// man.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "man.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cman

IMPLEMENT_DYNAMIC(Cman, CRecordset)

Cman::Cman(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(Cman)
	m_mid = _T("");
	m_mname = _T("");
	m_nsex = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString Cman::GetDefaultConnect()
{
	return _T("ODBC;DSN=booksystem");
}

CString Cman::GetDefaultSQL()
{
	return _T("[dbo].[man]");
}

void Cman::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(Cman)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[mid]"), m_mid);
	RFX_Text(pFX, _T("[mname]"), m_mname);
	RFX_Text(pFX, _T("[nsex]"), m_nsex);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// Cman diagnostics

#ifdef _DEBUG
void Cman::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cman::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
