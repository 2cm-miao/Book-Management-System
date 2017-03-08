// Ubook.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "Ubook.h"
#include "book.h"
#include "Uok.h"
#include "Uok1.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ubook dialog


Ubook::Ubook(CWnd* pParent /*=NULL*/)
	: CDialog(Ubook::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ubook)
	m_bname = _T("");
	m_bid = _T("");
	m_bbor = _T("");
	m_baut = _T("");
	//}}AFX_DATA_INIT
}


void Ubook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ubook)
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_QUE, m_que);
	DDX_Text(pDX, IDC_BNAME, m_bname);
	DDX_Text(pDX, IDC_BID, m_bid);
	DDX_Text(pDX, IDC_BBOR, m_bbor);
	DDX_Text(pDX, IDC_BAUT, m_baut);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ubook, CDialog)
	//{{AFX_MSG_MAP(Ubook)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_CEL1, OnCel1)
	ON_BN_CLICKED(IDC_BACK, OnBack)
	ON_BN_CLICKED(IDC_BORROW, OnBorrow)
	ON_BN_CLICKED(IDC_QUE, OnQue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ubook message handlers

BOOL Ubook::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	CRect rect;
	 // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
    m_list1.GetClientRect(&rect);   
  
    // Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
    m_list1.SetExtendedStyle(m_list1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);   
  
    // Ϊ�б���ͼ�ؼ��������   
    m_list1.InsertColumn(0, _T("�鱾���"), LVCFMT_CENTER, rect.Width()/4, 0);   
    m_list1.InsertColumn(1, _T("����"), LVCFMT_CENTER, rect.Width()/4, 1);   
    m_list1.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width()/4, 2);
	m_list1.InsertColumn(3, _T("�Ƿ���"), LVCFMT_CENTER, rect.Width()/4, 2);

	CString strsql;
	strsql.Format("select * from dbo.book order by bid");
	list_all(strsql);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Ubook::list_all(CString str)
{
	m_list1.DeleteAllItems();
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

		m_list1.InsertItem(&litem);

		m_list1.SetItemText(nindex,0,me.m_bid);
		m_list1.SetItemText(nindex,1,me.m_bname);
		m_list1.SetItemText(nindex,2,me.m_baut);
		m_list1.SetItemText(nindex,3,me.m_bbor);

		me.MoveNext();
	}
	me.Close();
}

void Ubook::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here


	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR); 

	*pResult = 0;

	CString strLangName;    // ѡ�����Ե������ַ���   

    NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;   
  
    if (-1 != pNMListView->iItem)        // ���iItem����-1����˵�����б��ѡ��   
    {   
        // ��ȡ��ѡ���б����һ��������ı�   
         strLangName= m_list1.GetItemText(pNMListView->iItem, 0);   
        // ��ѡ���������ʾ��༭����   
        SetDlgItemText(IDC_BID, strLangName);   

		strLangName = m_list1.GetItemText(pNMListView->iItem, 1);
		SetDlgItemText(IDC_BNAME, strLangName);  

		strLangName = m_list1.GetItemText(pNMListView->iItem, 2);
		SetDlgItemText(IDC_BAUT, strLangName);  

		strLangName = m_list1.GetItemText(pNMListView->iItem, 3);
		SetDlgItemText(IDC_BBOR, strLangName); 
    }  
	
}

void Ubook::OnCel1() 
{
	// TODO: Add your control notification handler code here
	Ubook::OnCancel();
}

void Ubook::OnBack() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int nindex=0;
	Cbook me;
	me.Open();
	me.MoveFirst();
	while(!me.IsEOF())
	{
		CString s(me.m_bid);

		int f=s.Find(m_bid,0);

		if(f>=0)
		{
			CString str(_T(m_bbor));
			int flag=str.Find(_T("��"));
			if(flag>=0)  
			{
				AfxMessageBox("��ͼ��û�б����");
				flag=1;
			}
			else
			{
				me.Edit();
				me.m_bbor="��";
				me.Update();
				me.Requery();

				Uok1 ok;
				ok.DoModal();

				AfxMessageBox("����ɹ���");
				break;
			}
		}
		me.MoveNext();
	}
	me.Close();
	
	CString strsql;
	strsql.Format("select * from dbo.book order by bid");
	list_all(strsql);
}

void Ubook::OnBorrow() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int nindex=0;
	Cbook me;
	me.Open();
	me.MoveFirst();
	while(!me.IsEOF())
	{
		CString s(me.m_bid);

		int f=s.Find(m_bid,0);

		if(f>=0)
		{
			CString str(m_bbor);
			int flag=str.Find(_T("��"));
			if(flag==-1)  
			{
				AfxMessageBox("��ͼ���ѱ����");
				flag=1;
			}
			else
			{
				me.Edit();
				me.m_bbor="��";
				me.Update();
				me.Requery();

				Uok ok;
				ok.DoModal();

				AfxMessageBox("����ɹ���");
				break;
			}
		}
		me.MoveNext();
	}
	me.Close();
	
	CString strsql;
	strsql.Format("select * from dbo.boook order by bid");
	list_all(strsql);
}

void Ubook::OnQue() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int nindex=0;
	Cbook me;
	me.Open();
	m_list1.DeleteAllItems();
	if(!m_bid.IsEmpty())
	{
		me.MoveFirst();
		while(!me.IsEOF())
		{
			CString s(me.m_bid);

			int f=s.Find(m_bid,0);

			if(f>=0)
			{
				LV_ITEM litem;
				litem.mask=LVIF_TEXT;

				litem.iItem=nindex;
				litem.iSubItem=0;
				litem.pszText="";

				m_list1.InsertItem(&litem);

				m_list1.SetItemText(nindex,0,me.m_bid);
				m_list1.SetItemText(nindex,1,me.m_bname);
				m_list1.SetItemText(nindex,2,me.m_baut);
				m_list1.SetItemText(nindex,3,me.m_bbor);	
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

			int f=s.Find(m_bname,0);

			if(f>=0)
			{
				LV_ITEM litem;
				litem.mask=LVIF_TEXT;

				litem.iItem=nindex;
				litem.iSubItem=0;
				litem.pszText="";

				m_list1.InsertItem(&litem);

				m_list1.SetItemText(nindex,0,me.m_bid);
				m_list1.SetItemText(nindex,1,me.m_bname);
				m_list1.SetItemText(nindex,2,me.m_baut);
				m_list1.SetItemText(nindex,3,me.m_bbor);	
			}
			me.MoveNext();
		}
		me.Close();
	}
	AfxMessageBox("������ϣ�"); 
}
