// BookSystemDoc.cpp : implementation of the CBookSystemDoc class
//

#include "stdafx.h"
#include "BookSystem.h"

#include "BookSystemSet.h"
#include "BookSystemDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookSystemDoc

IMPLEMENT_DYNCREATE(CBookSystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CBookSystemDoc, CDocument)
	//{{AFX_MSG_MAP(CBookSystemDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookSystemDoc construction/destruction

CBookSystemDoc::CBookSystemDoc()
{
	// TODO: add one-time construction code here

}

CBookSystemDoc::~CBookSystemDoc()
{
}

BOOL CBookSystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBookSystemDoc diagnostics

#ifdef _DEBUG
void CBookSystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBookSystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBookSystemDoc commands
