
// MFC_FileDlg.h : ͷ�ļ�
//

#pragma once


// CMFC_FileDlg �Ի���
class CMFC_FileDlg : public CDialogEx
{
// ����
public:
	CMFC_FileDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_FILE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBchoosefile();
	afx_msg void OnBnClickedBchoosefolder();
};
