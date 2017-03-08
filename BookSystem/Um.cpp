// Um.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "Um.h"
#include "Umbook.h"
#include "Umusers.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Um dialog


Um::Um(CWnd* pParent /*=NULL*/)
	: CDialog(Um::IDD, pParent)
{
	//{{AFX_DATA_INIT(Um)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Um::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Um)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Um, CDialog)
	//{{AFX_MSG_MAP(Um)
	ON_BN_CLICKED(IDC_A, OnA)
	ON_BN_CLICKED(IDC_B, OnB)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Um message handlers

void Um::OnA() 
{
	// TODO: Add your control notification handler code here
	Um::OnOK();
	Umbook um;
	um.DoModal();
}

void Um::OnB() 
{
	// TODO: Add your control notification handler code here
	Um::OnOK();
	Umusers um;
	um.DoModal();
}
