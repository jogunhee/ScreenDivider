// EditorWindowDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ScreenDivider.h"
#include "EditorWindowDlg.h"
#include "afxdialogex.h"


// CEditorWindowDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CEditorWindowDlg, CDialogEx)

CEditorWindowDlg::CEditorWindowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEditorWindowDlg::IDD, pParent)
{

}

CEditorWindowDlg::~CEditorWindowDlg()
{
}

void CEditorWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditorWindowDlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
//	ON_WM_SIZE()
END_MESSAGE_MAP()


// CEditorWindowDlg �޽��� ó�����Դϴ�.


void CEditorWindowDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialogEx::OnLButtonDown(nFlags, point);
	SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);
	//PostMessage(WM_NCLBUTTONDOWN, HTCAPTION,MAKEWPARAM(point.x,point.y));
}


//void CEditorWindowDlg::OnSize(UINT nType, int cx, int cy)
//{
//	CDialogEx::OnSize(nType, cx, cy);
//	
//	
//	if(hDlg = GetSafeHwnd())
//		{
//			hDlg.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOZORDER);
//		}
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
//}
