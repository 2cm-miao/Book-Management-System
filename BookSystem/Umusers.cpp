// Umusers.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "Umusers.h"
#include "users.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Umusers dialog


Umusers::Umusers(CWnd* pParent /*=NULL*/)
	: CDialog(Umusers::IDD, pParent)
{
	//{{AFX_DATA_INIT(Umusers)
	m_snum = _T("");
	m_sname = _T("");
	m_sclass = _T("");
	m_sbook = _T("");
	m_sage = _T("");
	//}}AFX_DATA_INIT
}


void Umusers::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Umusers)
	DDX_Control(pDX, IDC_LIST3, m_list3);
	DDX_Text(pDX, IDC_SNUM, m_snum);
	DDX_Text(pDX, IDC_SNAME, m_sname);
	DDX_Text(pDX, IDC_SCLASS, m_sclass);
	DDX_Text(pDX, IDC_SBOOK, m_sbook);
	DDX_Text(pDX, IDC_SAGE, m_sage);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Umusers, CDialog)
	//{{AFX_MSG_MAP(Umusers)
	ON_NOTIFY(NM_CLICK, IDC_LIST3, OnClickList3)
	ON_BN_CLICKED(IDC_ADD2, OnAdd2)
	ON_BN_CLICKED(IDC_DEL2, OnDel2)
	ON_BN_CLICKED(IDC_CHANGE2, OnChange2)
	ON_BN_CLICKED(IDC_QUE2, OnQue2)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Umusers message handlers

BOOL Umusers::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	CRect rect;
	 // 获取编程语言列表视图控件的位置和大小   
    m_list3.GetClientRect(&rect);   
  
    // 为列表视图控件添加全行选中和栅格风格   
    m_list3.SetExtendedStyle(m_list3.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);   
  
    // 为列表视图控件添加三列   
    m_list3.InsertColumn(0, _T("学号"), LVCFMT_CENTER, rect.Width()/5, 0);   
    m_list3.InsertColumn(1, _T("姓名"), LVCFMT_CENTER, rect.Width()/5, 1);   
    m_list3.InsertColumn(2, _T("年龄"), LVCFMT_CENTER, rect.Width()/5, 2);
	m_list3.InsertColumn(3, _T("班级"), LVCFMT_CENTER, rect.Width()/5, 3);
	m_list3.InsertColumn(4, _T("借阅书本"), LVCFMT_CENTER, rect.Width()/5, 4);

	CString strsql;
	strsql.Format("select * from dbo.users order by snum");
	list_all(strsql);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Umusers::list_all(CString str)
{
	m_list3.DeleteAllItems();
	Cusers me;
	if(!me.Open())  me.Open();
	int nindex=0;
	me.MoveFirst();
	while(!me.IsEOF())
	{
		LV_ITEM litem;
		litem.mask=LVIF_TEXT;
		litem.iItem=nindex;
		litem.iSubItem=0;
		litem.pszText="";

		m_list3.InsertItem(&litem);

		m_list3.SetItemText(nindex,0,me.m_snum);
		m_list3.SetItemText(nindex,1,me.m_sname);
		m_list3.SetItemText(nindex,2,me.m_sage);
		m_list3.SetItemText(nindex,3,me.m_sclass);
		m_list3.SetItemText(nindex,4,me.m_sbook);

		me.MoveNext();
	}
	me.Close();

}

void Umusers::OnClickList3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR); 

	*pResult = 0;

	CString strLangName;    // 选择语言的名称字符串   

    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;   
  
    if (-1 != pNMListView->iItem)        // 如果iItem不是-1，就说明有列表项被选择   
    {   
        // 获取被选择列表项第一个子项的文本   
         strLangName= m_list3.GetItemText(pNMListView->iItem, 0);   
        // 将选择的语言显示与编辑框中   
        SetDlgItemText(IDC_SNUM, strLangName);   

		strLangName = m_list3.GetItemText(pNMListView->iItem, 1);
		SetDlgItemText(IDC_SNAME, strLangName);  

		strLangName = m_list3.GetItemText(pNMListView->iItem, 2);
		SetDlgItemText(IDC_SAGE, strLangName);  

		strLangName = m_list3.GetItemText(pNMListView->iItem, 3);
		SetDlgItemText(IDC_SCLASS, strLangName);

		strLangName = m_list3.GetItemText(pNMListView->iItem, 4);
		SetDlgItemText(IDC_SBOOK, strLangName);
    }  

}

void Umusers::OnAdd2() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	Cusers me;
	if(!me.IsOpen())  me.Open();
	me.AddNew();
	me.m_strFilter.Format("select * from dbo.users where snum='%s'",m_snum);
	if(!me.IsBOF())
	{
		me.AddNew();
		me.m_snum=m_snum;
		me.m_sname=m_sname;
		me.m_sage=m_sage;
		me.m_sclass=m_sclass;
		me.m_sbook=m_sbook;
		me.Update();
		AfxMessageBox("添加成功！");
		CWnd* a;
		a=CWnd::GetDlgItem(IDC_SNUM);
		a->SetWindowText("");
		a=CWnd::GetDlgItem(IDC_SNAME);
		a->SetWindowText("");
		a=CWnd::GetDlgItem(IDC_SAGE);
		a->SetWindowText("");
		a=CWnd::GetDlgItem(IDC_SCLASS);
		a->SetWindowText("");
		a=CWnd::GetDlgItem(IDC_SBOOK);
		a->SetWindowText("");

	}
	CString strsql;
	strsql.Format("select * from dbo.users order by snum");
	list_all(strsql);

}

void Umusers::OnDel2() 
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);
	Cusers u;
	u.Open();
	u.MoveFirst();
	while(!u.IsEOF()){
		if(u.m_snum==m_snum){
			u.Delete();
			break;
		}
		u.MoveNext();
	}
	u.Close();
	
	AfxMessageBox("删除成功！");  

	CString strsql;
	strsql.Format("select * from dbo.users order by snum");
	list_all(strsql);


	CWnd* a;
	a=CWnd::GetDlgItem(IDC_SNUM);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_SNAME);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_SAGE);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_SCLASS);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_SBOOK);
	a->SetWindowText("");

}

void Umusers::OnChange2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Cusers me;
	if(!me.IsOpen())  me.Open();

	me.MoveFirst();
	while(!me.IsEOF())
	{
		CString s(me.m_snum);

		int f=s.Find(m_snum,0);

		if(f>=0)
		{
			me.Edit();
			me.m_snum=m_snum;
			me.m_sname=m_sname;
			me.m_sage=m_sage;
			me.m_sclass=m_sclass;
			me.m_sbook=m_sbook;
			me.Update();
			me.Requery();
			break;
		}
		me.MoveNext();
	}
	
	me.Close();

	AfxMessageBox("修改成功！");
		
		
	CWnd* a;
	a=CWnd::GetDlgItem(IDC_SNUM);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_SNAME);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_SAGE);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_SCLASS);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_SBOOK);
	a->SetWindowText("");

	CString strsql;
	strsql.Format("select * from dbo.users order by snum");
	list_all(strsql); 


}

void Umusers::OnQue2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int nindex=0;
	Cusers me;
	me.Open();
	m_list3.DeleteAllItems();
	if(!m_snum.IsEmpty())
	{
		me.MoveFirst();
		while(!me.IsEOF())
		{
			CString s(me.m_snum);

			int f=s.Find(m_snum,0);

			if(f>=0)
			{
				LV_ITEM litem;
				litem.mask=LVIF_TEXT;

				litem.iItem=nindex;
				litem.iSubItem=0;
				litem.pszText="";

				m_list3.InsertItem(&litem);

				m_list3.SetItemText(nindex,0,me.m_snum);
				m_list3.SetItemText(nindex,1,me.m_sname);
				m_list3.SetItemText(nindex,2,me.m_sage);
				m_list3.SetItemText(nindex,3,me.m_sclass);
				m_list3.SetItemText(nindex,4,me.m_sbook);	
			}
			me.MoveNext();
		}
		me.Close();
	}
	else
	{
		me.MoveFirst();
		while(!me.IsEOF())
		{
			CString s(me.m_sname);

			int f=s.Find(m_sname,0);

			if(f>=0)
			{
				LV_ITEM litem;
				litem.mask=LVIF_TEXT;

				litem.iItem=nindex;
				litem.iSubItem=0;
				litem.pszText="";

				m_list3.InsertItem(&litem);

				m_list3.SetItemText(nindex,0,me.m_snum);
				m_list3.SetItemText(nindex,1,me.m_sname);
				m_list3.SetItemText(nindex,2,me.m_sage);
				m_list3.SetItemText(nindex,3,me.m_sclass);
				m_list3.SetItemText(nindex,4,me.m_sbook);	
			}
			me.MoveNext();
		}
		me.Close();
	}
	AfxMessageBox("查找完毕！");  
}

void Umusers::OnButton4() 
{
	// TODO: Add your control notification handler code here
	Umusers::OnCancel();
}
