
// MFC_FileDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_File.h"
#include "MFC_FileDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_FileDlg �Ի���




CMFC_FileDlg::CMFC_FileDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_FileDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_FileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_FileDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFC_FileDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFC_FileDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BCHOOSEFILE, &CMFC_FileDlg::OnBnClickedBchoosefile)
	ON_BN_CLICKED(IDC_BCHOOSEFOLDER, &CMFC_FileDlg::OnBnClickedBchoosefolder)
END_MESSAGE_MAP()


// CMFC_FileDlg ��Ϣ�������

BOOL CMFC_FileDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_FileDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_FileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_FileDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	exit(0);
}


void CMFC_FileDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	exit(0);
}


void CMFC_FileDlg::OnBnClickedBchoosefile()//ѡ���ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString szPath = _T("");
	CString strPath = _T("");

	//CFileDialog::CFileDialog( BOOL bOpenFileDialog, LPCTSTR lpszDefExt = NULL, LPCTSTR lpszFileName = NULL, DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, LPCTSTR lpszFilter = NULL, CWnd* pParentWnd = NULL);
    //�����������£�
    //bOpenFileDialog��ΪTRUE����ʾ�򿪶Ի���ΪFALSE����ʾ����Ի��ļ��Ի��� 
    //lpszDefExt��ָ��Ĭ�ϵ��ļ���չ���� 
    //lpszFileName��ָ��Ĭ�ϵ��ļ����� 
    //dwFlags��ָ��һЩ�ض���� 
    //lpszFilter��������Ҫ��һ����������ָ���ɹ�ѡ����ļ����ͺ���Ӧ����չ����

    CFileDialog dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.cfg)|*.cfg|All Files (*.*)|*.*||"), NULL);

    if (dlgFile.DoModal())
    {
        szPath = dlgFile.GetPathName();
    }
	if(!szPath.IsEmpty())
	{
		strPath.Format(_T("�ļ�·����%s"),szPath);
	    SetDlgItemText(IDC_SFILE,strPath);
	    AfxMessageBox(strPath,MB_OK,NULL);
	}
	else
	{
		SetDlgItemText(IDC_SFILE,_T("�ļ�·����Ч"));
        AfxMessageBox(_T("��Ч���ļ���������ѡ��"),MB_OK,NULL);
	}
}


void CMFC_FileDlg::OnBnClickedBchoosefolder()//ѡ���ļ���
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFolderPath[MAX_PATH] = {0};//���ѡ���Ŀ¼·��
    CString strFolderPath = _T("");

    ZeroMemory(szFolderPath, sizeof(szFolderPath));

    BROWSEINFO bi;
    bi.hwndOwner = m_hWnd;//�����ھ��
    bi.pidlRoot = NULL;//Ҫ��ʾ���ļ�Ŀ¼�Ի���ĸ�(Root)
    bi.pszDisplayName = szFolderPath;//���汻ѡȡ���ļ���·���Ļ�����
    bi.lpszTitle = _T("��ѡ���ļ���");//��ʾλ�ڶԻ������ϲ��ı���
    bi.ulFlags = 0;//ָ���Ի������ۺ͹��ܵı�־
    bi.lpfn = NULL;//�����¼��Ļص�����
    bi.lParam = 0;//Ӧ�ó��򴫸��ص������Ĳ���
    bi.iImage = 0;//�ļ��жԻ����ͼƬ����

    LPITEMIDLIST lpidlBrowse = SHBrowseForFolder(&bi);//����ѡ��Ŀ¼�Ի���

    if(lpidlBrowse && SHGetPathFromIDList(lpidlBrowse, szFolderPath))
    {
        strFolderPath.Format(_T("�ļ���·����%s"), szFolderPath);
		SetDlgItemText(IDC_SFOLDER,strFolderPath);
        AfxMessageBox(strFolderPath,MB_OK,NULL);
    }
    else
	{
		SetDlgItemText(IDC_SFOLDER,_T("�ļ���·����Ч"));
        AfxMessageBox(_T("��Ч���ļ��У�������ѡ��"),MB_OK,NULL);
	}
}
