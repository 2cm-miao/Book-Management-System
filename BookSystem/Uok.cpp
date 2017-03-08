// Uok.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "Uok.h"
#include "users.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Uok dialog


Uok::Uok(CWnd* pParent /*=NULL*/)
	: CDialog(Uok::IDD, pParent)
{
	//{{AFX_DATA_INIT(Uok)
	m_name = _T("");
	m_num = _T("");
	//}}AFX_DATA_INIT
}


void Uok::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Uok)
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_NUM, m_num);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Uok, CDialog)
	//{{AFX_MSG_MAP(Uok)
	ON_EN_CHANGE(IDC_NUM, OnChangeNum)
	ON_BN_CLICKED(IDC_OK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Uok message handlers

void Uok::OnChangeNum() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void Uok::OnOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Cusers me;
	if(!me.IsOpen())  me.Open();

	me.MoveFirst();
	while(!me.IsEOF())
	{
		CString s(me.m_snum);

		int f=s.Find(m_num,0);

		if(f>=0)
		{
			me.Edit();
			me.m_sbook=m_name;
			me.Update();
			me.Requery();
			break;
		}
		me.MoveNext();
	}
	
	me.Close();
		
		
	Uok::OnCancel();

}
