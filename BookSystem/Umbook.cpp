// Umbook.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "Umbook.h"
#include "book.h"
#include "Um.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Umbook dialog


Umbook::Umbook(CWnd* pParent /*=NULL*/)
	: CDialog(Umbook::IDD, pParent)
{
	//{{AFX_DATA_INIT(Umbook)
	m_baut1 = _T("");
	m_bbor1 = _T("");
	m_bid1 = _T("");
	m_bname1 = _T("");
	//}}AFX_DATA_INIT
}


void Umbook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Umbook)
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Text(pDX, IDC_BAUT1, m_baut1);
	DDX_Text(pDX, IDC_BBOR1, m_bbor1);
	DDX_Text(pDX, IDC_BID1, m_bid1);
	DDX_Text(pDX, IDC_BNAME1, m_bname1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Umbook, CDialog)
	//{{AFX_MSG_MAP(Umbook)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, OnClickList2)
	ON_BN_CLICKED(IDC_ADD1, OnAdd1)
	ON_BN_CLICKED(IDC_DEL1, OnDel1)
	ON_BN_CLICKED(IDC_CHANGE1, OnChange1)
	ON_BN_CLICKED(IDC_QUE1, OnQue1)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Umbook message handlers

void Umbook::OnClickList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR); 

	*pResult = 0;

	CString strLangName;    // 选择语言的名称字符串   

    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;   
  
    if (-1 != pNMListView->iItem)        // 如果iItem不是-1，就说明有列表项被选择   
    {   
        // 获取被选择列表项第一个子项的文本   
         strLangName= m_list2.GetItemText(pNMListView->iItem, 0);   
        // 将选择的语言显示与编辑框中   
        SetDlgItemText(IDC_BID1, strLangName);   

		strLangName = m_list2.GetItemText(pNMListView->iItem, 1);
		SetDlgItemText(IDC_BNAME1, strLangName);  

		strLangName = m_list2.GetItemText(pNMListView->iItem, 2);
		SetDlgItemText(IDC_BAUT1, strLangName);  

		strLangName = m_list2.GetItemText(pNMListView->iItem, 3);
		SetDlgItemText(IDC_BBOR1, strLangName);  
    }  

}

BOOL Umbook::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	CRect rect;
	 // 获取编程语言列表视图控件的位置和大小   
    m_list2.GetClientRect(&rect);   
  
    // 为列表视图控件添加全行选中和栅格风格   
    m_list2.SetExtendedStyle(m_list2.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);   
  
    // 为列表视图控件添加三列   
    m_list2.InsertColumn(0, _T("书本编号"), LVCFMT_CENTER, rect.Width()/4, 0);   
    m_list2.InsertColumn(1, _T("书名"), LVCFMT_CENTER, rect.Width()/4, 1);   
    m_list2.InsertColumn(2, _T("作者"), LVCFMT_CENTER, rect.Width()/4, 2);
	m_list2.InsertColumn(3, _T("是否借出"), LVCFMT_CENTER, rect.Width()/4, 2);

	CString strsql;
	strsql.Format("select * from dbo.book order by bid");
	list_all(strsql);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Umbook::list_all(CString str)
{
	m_list2.DeleteAllItems();
	Cbook me;
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

		m_list2.InsertItem(&litem);

		m_list2.SetItemText(nindex,0,me.m_bid);
		m_list2.SetItemText(nindex,1,me.m_bname);
		m_list2.SetItemText(nindex,2,me.m_baut);
		m_list2.SetItemText(nindex,3,me.m_bbor);

		me.MoveNext();
	}
	me.Close();


}

void Umbook::OnAdd1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	Cbook me;
	if(!me.IsOpen())  me.Open();
	me.AddNew();
	me.m_strFilter.Format("select * from dbo.book where snum='%s'",m_bid1);
	if(!me.IsBOF())
	{
		me.AddNew();
		me.m_bid=m_bid1;
		me.m_bname=m_bname1;
		me.m_baut=m_baut1;
		me.m_bbor=m_bbor1;
		me.Update();

		AfxMessageBox("添加成功！");

		CWnd* a;
		a=CWnd::GetDlgItem(IDC_BID1);
		a->SetWindowText("");
		a=CWnd::GetDlgItem(IDC_BNAME1);
		a->SetWindowText("");
		a=CWnd::GetDlgItem(IDC_BAUT1);
		a->SetWindowText("");
		a=CWnd::GetDlgItem(IDC_BBOR1);
		a->SetWindowText("");

	}

	CString strsql;
	strsql.Format("select * from dbo.book order by bid");
	list_all(strsql);
}

void Umbook::OnDel1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Cbook u;
	u.Open();
	u.MoveFirst();
	while(!u.IsEOF()){
		if(u.m_bid==m_bid1){
			u.Delete();
			break;
		}
		u.MoveNext();
	}
	u.Close();
	
	AfxMessageBox("删除成功！");  

	CString strsql;
	strsql.Format("select * from dbo.book order by bid");
	list_all(strsql);


	CWnd* a;
	a=CWnd::GetDlgItem(IDC_BID1);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_BNAME1);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_BAUT1);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_BBOR1);
	a->SetWindowText("");
}

void Umbook::OnChange1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Cbook me;
	if(!me.IsOpen())  me.Open();

	me.MoveFirst();
	while(!me.IsEOF())
	{
		CString s(me.m_bid);

		int f=s.Find(m_bid1,0);

		if(f>=0)
		{
			me.Edit();
			me.m_bid=m_bid1;
			me.m_bname=m_bname1;
			me.m_baut=m_baut1;
			me.m_bbor=m_bbor1;
			me.Update();
			me.Requery();
			break;
		}
		me.MoveNext();
	}
	
	me.Close();

	AfxMessageBox("修改成功！");
		
		
	CWnd* a;
	a=CWnd::GetDlgItem(IDC_BID1);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_BNAME1);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_BAUT1);
	a->SetWindowText("");
	a=CWnd::GetDlgItem(IDC_BBOR1);
	a->SetWindowText("");

	CString strsql;
	strsql.Format("select * from dbo.book order by bid");
	list_all(strsql); 
}

void Umbook::OnQue1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int nindex=0;
	Cbook me;
	me.Open();
	m_list2.DeleteAllItems();
	if(!m_bid1.IsEmpty())
	{
		me.MoveFirst();
		while(!me.IsEOF())
		{
			CString s(me.m_bid);

			int f=s.Find(m_bid1,0);

			if(f>=0)
			{
				LV_ITEM litem;
				litem.mask=LVIF_TEXT;

				litem.iItem=nindex;
				litem.iSubItem=0;
				litem.pszText="";

				m_list2.InsertItem(&litem);

				m_list2.SetItemText(nindex,0,me.m_bid);
				m_list2.SetItemText(nindex,1,me.m_bname);
				m_list2.SetItemText(nindex,2,me.m_baut);
				m_list2.SetItemText(nindex,3,me.m_bbor);	
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
			CString s(me.m_bname);

			int f=s.Find(m_bname1,0);

			if(f>=0)
			{
				LV_ITEM litem;
				litem.mask=LVIF_TEXT;

				litem.iItem=nindex;
				litem.iSubItem=0;
				litem.pszText="";

				m_list2.InsertItem(&litem);

				m_list2.SetItemText(nindex,0,me.m_bid);
				m_list2.SetItemText(nindex,1,me.m_bname);
				m_list2.SetItemText(nindex,2,me.m_baut);
				m_list2.SetItemText(nindex,3,me.m_bbor);	
			}
			me.MoveNext();
		}
		me.Close();
	}
	AfxMessageBox("查找完毕！");  
}

void Umbook::OnButton7() 
{
	// TODO: Add your control notification handler code here
	Umbook::OnCancel();
	Um um;
	um.DoModal();

	
}
