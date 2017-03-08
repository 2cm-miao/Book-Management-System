// Uok1.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "Uok1.h"
#include "users.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Uok1 dialog


Uok1::Uok1(CWnd* pParent /*=NULL*/)
	: CDialog(Uok1::IDD, pParent)
{
	//{{AFX_DATA_INIT(Uok1)
	m_num1 = _T("");
	//}}AFX_DATA_INIT
}


void Uok1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Uok1)
	DDX_Text(pDX, IDC_NUM1, m_num1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Uok1, CDialog)
	//{{AFX_MSG_MAP(Uok1)
	ON_BN_CLICKED(IDC_OK1, OnOk1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Uok1 message handlers

void Uok1::OnOk1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Cusers me;
	if(!me.IsOpen())  me.Open();

	me.MoveFirst();
	while(!me.IsEOF())
	{
		CString s(me.m_snum);

		int f=s.Find(m_num1,0);

		if(f>=0)
		{
			me.Edit();
			me.m_sbook="";
			me.Update();
			me.Requery();
			break;
		}
		me.MoveNext();
	}
	
	me.Close();
		
		
	Uok1::OnCancel();
}
