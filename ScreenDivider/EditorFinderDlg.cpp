// FinderDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorFinderDlg.h"
#include "afxdialogex.h"


// CFinderDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CEditorFinderDlg, CFlatDialogEx)

CEditorFinderDlg::CEditorFinderDlg(CWnd* pParent /*=NULL*/)
	: CFlatDialogEx(CEditorFinderDlg::IDD, pParent)
{
	m_Y = 0;
	m_X = 0;
	m_WIDTH = 0;
	m_HEIGHT = 0;
}

CEditorFinderDlg::~CEditorFinderDlg()
{
}

void CEditorFinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CFlatDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_FINDER, m_btnFinder);
	DDX_Text(pDX, IDC_STATIC_Y, m_Y);
	DDX_Text(pDX, IDC_STATIC_X, m_X);
	DDX_Text(pDX, IDC_STATIC_WIDTH, m_WIDTH);
	DDX_Text(pDX, IDC_STATIC_HEIGHT, m_HEIGHT);
}


BEGIN_MESSAGE_MAP(CEditorFinderDlg, CFlatDialogEx)
END_MESSAGE_MAP()


// CFinderDlg �޽��� ó�����Դϴ�.
BOOL CEditorFinderDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CBitmapButtonEx *pButton;
	pButton = (CBitmapButtonEx *)GetDlgItem(IDC_BUTTON_FINDER);
	pButton->LoadBitmaps
		(
			IDB_BITMAP_FINDER_ICON,
			IDB_BITMAP_FINDER_ICON_HOVER,
			IDB_BITMAP_FINDER_ICON_SEL,
			IDB_BITMAP_FINDER_ICON,
			IDB_BITMAP_FINDER_ICON_DISABLED
		);
		
	CRect rectButton;
	pButton->GetWindowRect(rectButton);

	if (rectButton.PtInRect(pMsg->pt))
	{
		switch (pMsg->message)
		{
		case WM_LBUTTONDOWN:
			SetCursor(LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR_FINDER)));
			SetCapture();
			break;
		case WM_MOUSEMOVE:
			break;
		case WM_LBUTTONUP:
			break;
		}
	}

	return CFlatDialogEx::PreTranslateMessage(pMsg);
}

BOOL CEditorFinderDlg::OnInitDialog()
{
	CFlatDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_btnFinder.LoadBitmaps(IDB_BITMAP_FINDER, IDB_BITMAP_FINDER, IDB_BITMAP_FINDER, IDB_BITMAP_FINDER);
	m_btnFinder.SizeToContent();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
