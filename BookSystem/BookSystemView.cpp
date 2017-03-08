// BookSystemView.cpp : implementation of the CBookSystemView class
//

#include "stdafx.h"
#include "BookSystem.h"

#include "BookSystemSet.h"
#include "BookSystemDoc.h"
#include "BookSystemView.h"

#include"afxdb.h"
#include"users.h"
#include"Ubook.h"
#include"man.h"
#include"Um.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookSystemView

IMPLEMENT_DYNCREATE(CBookSystemView, CRecordView)

BEGIN_MESSAGE_MAP(CBookSystemView, CRecordView)
	//{{AFX_MSG_MAP(CBookSystemView)
	ON_BN_CLICKED(IDC_CEL, OnCel)
	ON_BN_CLICKED(IDC_LOG1, OnOK)
	ON_BN_CLICKED(IDC_LOG2, OnOK1)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookSystemView construction/destruction

CBookSystemView::CBookSystemView()
	: CRecordView(CBookSystemView::IDD)
{
	//{{AFX_DATA_INIT(CBookSystemView)
	m_pSet = NULL;
	m_snum = _T("");
	m_sname = _T("");
	m_mname = _T("");
	m_mid = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CBookSystemView::~CBookSystemView()
{
}

void CBookSystemView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBookSystemView)
	DDX_Text(pDX, IDC_SNUM, m_snum);
	DDX_Text(pDX, IDC_SNAME, m_sname);
	DDX_Text(pDX, IDC_MNAME, m_mname);
	DDX_Text(pDX, IDC_MID, m_mid);
	//}}AFX_DATA_MAP
}

BOOL CBookSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CBookSystemView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_bookSystemSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CBookSystemView printing

BOOL CBookSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBookSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBookSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBookSystemView diagnostics

#ifdef _DEBUG
void CBookSystemView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CBookSystemView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CBookSystemDoc* CBookSystemView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBookSystemDoc)));
	return (CBookSystemDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBookSystemView database support
CRecordset* CBookSystemView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CBookSystemView message handlers

void CBookSystemView::OnOK() 
{
	// TODO: Add your control notification handler code here
	CDatabase m_database;
	Cusers *m_re=new Cusers(&m_database);
	CString str;
	UpdateData(TRUE);
	str.Format("select * from users where snum='%s' and sname='%s'",m_snum,m_sname);
		m_re->Open(AFX_DB_USE_DEFAULT_TYPE,str);
	if(m_re->GetRecordCount()==0)
	{
		AfxMessageBox("用户名或密码错误！");
	}
	else{
		AfxMessageBox("登陆成功！");
		Ubook ub;
		ub.DoModal();

	}
	CWnd* a;
	a=CWnd::GetDlgItem(IDC_SNUM);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_SNAME);
	a->SetWindowText("");

}

void CBookSystemView::OnCel() 
{
	// TODO: Add your control notification handler code here
//	CBookSystemView::OnCel();
}

void CBookSystemView::OnOK1() 
{
	// TODO: Add your control notification handler code here
	CDatabase m_database;
	Cman *m_re=new Cman(&m_database);
	CString str;
	UpdateData(TRUE);
	str.Format("select * from man where mid='%s' and mname='%s'",m_mid,m_mname);
		m_re->Open(AFX_DB_USE_DEFAULT_TYPE,str);
	if(m_re->GetRecordCount()==0)
	{
		AfxMessageBox("用户名或密码错误！");
	}
	else{
		AfxMessageBox("登陆成功！");
		Um ub;
		ub.DoModal();

	}
	CWnd* a;
	a=CWnd::GetDlgItem(IDC_MID);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_MNAME);
	a->SetWindowText("");
}
