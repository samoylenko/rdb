// ShitSenderDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CShitSenderDlg dialog
class CShitSenderDlg : public CDialog
{
// Construction
public:
	CShitSenderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SHITSENDER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	UINT m_nThreads;
	afx_msg void OnBnClickedBtnstart();
	CString Log;
	void GetShit(void);
	afx_msg void OnBnClickedBtnstop();
};
