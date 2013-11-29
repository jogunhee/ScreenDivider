// SettingDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "SettingDlg.h"
#include "afxdialogex.h"
#include "SettingGeneralDlg.h"
#include "SettingStyleDlg.h"


// CSettingDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSettingDlg, CFlatDialogEx)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CFlatDialogEx(CSettingDlg::IDD, pParent)
{
}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CFlatDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SETTINGS, m_List);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CFlatDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_SETTINGS, &CSettingDlg::OnLvnItemchangedListSettings)
	ON_BN_CLICKED(IDCLOSE, &CSettingDlg::OnBnClickedClose)
	ON_BN_CLICKED(IDC_DEFAULT, &CSettingDlg::OnBnClickedDefault)
	ON_BN_CLICKED(IDC_SAVE, &CSettingDlg::OnBnClickedSave)
END_MESSAGE_MAP()


// CSettingDlg �޽��� ó�����Դϴ�.
BOOL CSettingDlg::OnInitDialog()
{
	CFlatDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_List.InsertItem(0, L"General");
	m_List.InsertItem(1, L"Style");

	m_pDlgGeneral = new CSettingGeneralDlg();
	m_pDlgGeneral->Create(IDD_SETTING_GENERAL_DIALOG, (CWnd *)this);
	m_pDlgGeneral->MoveWindow(135, 29, 279, 195);
	m_pDlgGeneral->ShowWindow(SW_SHOW);

	m_pDlgStyle = new CSettingStyleDlg();
	m_pDlgStyle->Create(IDD_SETTING_STYLE_DIALOG, (CWnd *)this);
	m_pDlgStyle->MoveWindow(135, 29, 279, 195);
	m_pDlgStyle->ShowWindow(SW_HIDE);

	CFile file(_T("Setting.dat"), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	Serialize(ar);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CSettingDlg::OnLvnItemchangedListSettings(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notifiation handler code here
	UpdateData(TRUE);

	switch (m_List.GetHotItem())
	{
	case 0:
		m_pDlgGeneral->ShowWindow(SW_SHOW);
		m_pDlgStyle->ShowWindow(SW_HIDE);
		break;
	case 1:
		m_pDlgGeneral->ShowWindow(SW_HIDE);
		m_pDlgStyle->ShowWindow(SW_SHOW);
		break;
	}

	UpdateData(FALSE);
	*pResult = 0;
}




void CSettingDlg::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		UpdateData(true);
		m_pDlgGeneral->Serialize(ar);
		m_pDlgStyle->Serialize(ar);
		UpdateData(false);
	}
	else
	{	// loading code
		m_pDlgGeneral->Serialize(ar);
		m_pDlgStyle->Serialize(ar);
	}
}

void CSettingDlg::OnBnClickedClose()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EndDialog(IDCANCEL);
}


void CSettingDlg::OnBnClickedDefault()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
	m_pDlgGeneral->OnInitDialog();
	m_pDlgStyle->OnInitDialog();
	UpdateData(false);
}


void CSettingDlg::OnBnClickedSave()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CFile file(_T("Setting.dat"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	Serialize(ar);
}
