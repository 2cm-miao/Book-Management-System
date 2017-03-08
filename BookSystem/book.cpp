// book.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "book.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cbook

IMPLEMENT_DYNAMIC(Cbook, CRecordset)

Cbook::Cbook(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(Cbook)
	m_bid = _T("");
	m_bname = _T("");
	m_baut = _T("");
	m_bbor = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString Cbook::GetDefaultConnect()
{
	return _T("ODBC;DSN=booksystem");
}

CString Cbook::GetDefaultSQL()
{
	return _T("[dbo].[book]");
}

void Cbook::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(Cbook)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[bid]"), m_bid);
	RFX_Text(pFX, _T("[bname]"), m_bname);
	RFX_Text(pFX, _T("[baut]"), m_baut);
	RFX_Text(pFX, _T("[bbor]"), m_bbor);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// Cbook diagnostics

#ifdef _DEBUG
void Cbook::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cbook::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
