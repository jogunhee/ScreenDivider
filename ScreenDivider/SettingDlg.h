#pragma once
#include "SettingGeneralDlg.h"
#include "SettingStyleDlg.h"

// CSettingDlg 대화 상자입니다.

class CSettingDlg : public CFlatDialogEx
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSettingDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SETTING_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

private:
	CSettingStyleDlg *m_pDlgStyle;
	CSettingGeneralDlg *m_pDlgGeneral;
	CListCtrl m_List;
public:
	afx_msg void OnLvnItemchangedListSettings(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void Serialize(CArchive& ar);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedClose();
	afx_msg void OnBnClickedDefault();
	afx_msg void OnBnClickedSave();
};
