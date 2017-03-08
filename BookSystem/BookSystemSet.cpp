// BookSystemSet.cpp : implementation of the CBookSystemSet class
//

#include "stdafx.h"
#include "BookSystem.h"
#include "BookSystemSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookSystemSet implementation

IMPLEMENT_DYNAMIC(CBookSystemSet, CRecordset)

CBookSystemSet::CBookSystemSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBookSystemSet)
	m_bid = _T("");
	m_bname = _T("");
	m_baut = _T("");
	m_bbor = _T("");
	m_mid = _T("");
	m_mname = _T("");
	m_nsex = _T("");
	m_snum = _T("");
	m_sname = _T("");
	m_sage = _T("");
	m_sclass = _T("");
	m_sbook = _T("");
	m_nFields = 12;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CBookSystemSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=booksystem");
}

CString CBookSystemSet::GetDefaultSQL()
{
	return _T("[dbo].[book],[dbo].[man],[dbo].[users]");
}

void CBookSystemSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBookSystemSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[bid]"), m_bid);
	RFX_Text(pFX, _T("[bname]"), m_bname);
	RFX_Text(pFX, _T("[baut]"), m_baut);
	RFX_Text(pFX, _T("[bbor]"), m_bbor);
	RFX_Text(pFX, _T("[mid]"), m_mid);
	RFX_Text(pFX, _T("[mname]"), m_mname);
	RFX_Text(pFX, _T("[nsex]"), m_nsex);
	RFX_Text(pFX, _T("[snum]"), m_snum);
	RFX_Text(pFX, _T("[sname]"), m_sname);
	RFX_Text(pFX, _T("[sage]"), m_sage);
	RFX_Text(pFX, _T("[sclass]"), m_sclass);
	RFX_Text(pFX, _T("[sbook]"), m_sbook);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBookSystemSet diagnostics

#ifdef _DEBUG
void CBookSystemSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBookSystemSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
