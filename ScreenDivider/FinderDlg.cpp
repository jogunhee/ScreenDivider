// FinderDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "FinderDlg.h"
#include "afxdialogex.h"


// CFinderDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFinderDlg, CDialogEx)

CFinderDlg::CFinderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFinderDlg::IDD, pParent)
{

}

CFinderDlg::~CFinderDlg()
{
}

void CFinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFinderDlg, CDialogEx)
END_MESSAGE_MAP()


// CFinderDlg �޽��� ó�����Դϴ�.


BOOL CFinderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	// Fill background with white
	SetBackgroundColor(RGB(255, 255, 255));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
