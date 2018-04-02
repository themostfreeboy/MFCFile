
// MFC_FileDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_File.h"
#include "MFC_FileDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_FileDlg 对话框




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


// CMFC_FileDlg 消息处理程序

BOOL CMFC_FileDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_FileDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_FileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_FileDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	exit(0);
}


void CMFC_FileDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	exit(0);
}


void CMFC_FileDlg::OnBnClickedBchoosefile()//选择文件
{
	// TODO: 在此添加控件通知处理程序代码
	CString szPath = _T("");
	CString strPath = _T("");

	//CFileDialog::CFileDialog( BOOL bOpenFileDialog, LPCTSTR lpszDefExt = NULL, LPCTSTR lpszFileName = NULL, DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, LPCTSTR lpszFilter = NULL, CWnd* pParentWnd = NULL);
    //参数意义如下：
    //bOpenFileDialog：为TRUE则显示打开对话框，为FALSE则显示保存对话文件对话框。 
    //lpszDefExt：指定默认的文件扩展名。 
    //lpszFileName：指定默认的文件名。 
    //dwFlags：指明一些特定风格。 
    //lpszFilter：是最重要的一个参数，它指明可供选择的文件类型和相应的扩展名。

    CFileDialog dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.cfg)|*.cfg|All Files (*.*)|*.*||"), NULL);

    if (dlgFile.DoModal())
    {
        szPath = dlgFile.GetPathName();
    }
	if(!szPath.IsEmpty())
	{
		strPath.Format(_T("文件路径：%s"),szPath);
	    SetDlgItemText(IDC_SFILE,strPath);
	    AfxMessageBox(strPath,MB_OK,NULL);
	}
	else
	{
		SetDlgItemText(IDC_SFILE,_T("文件路径无效"));
        AfxMessageBox(_T("无效的文件，请重新选择"),MB_OK,NULL);
	}
}


void CMFC_FileDlg::OnBnClickedBchoosefolder()//选择文件夹
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFolderPath[MAX_PATH] = {0};//存放选择的目录路径
    CString strFolderPath = _T("");

    ZeroMemory(szFolderPath, sizeof(szFolderPath));

    BROWSEINFO bi;
    bi.hwndOwner = m_hWnd;//父窗口句柄
    bi.pidlRoot = NULL;//要显示的文件目录对话框的根(Root)
    bi.pszDisplayName = szFolderPath;//保存被选取的文件夹路径的缓冲区
    bi.lpszTitle = _T("请选择文件夹");//显示位于对话框左上部的标题
    bi.ulFlags = 0;//指定对话框的外观和功能的标志
    bi.lpfn = NULL;//处理事件的回调函数
    bi.lParam = 0;//应用程序传给回调函数的参数
    bi.iImage = 0;//文件夹对话框的图片索引

    LPITEMIDLIST lpidlBrowse = SHBrowseForFolder(&bi);//弹出选择目录对话框

    if(lpidlBrowse && SHGetPathFromIDList(lpidlBrowse, szFolderPath))
    {
        strFolderPath.Format(_T("文件夹路径：%s"), szFolderPath);
		SetDlgItemText(IDC_SFOLDER,strFolderPath);
        AfxMessageBox(strFolderPath,MB_OK,NULL);
    }
    else
	{
		SetDlgItemText(IDC_SFOLDER,_T("文件夹路径无效"));
        AfxMessageBox(_T("无效的文件夹，请重新选择"),MB_OK,NULL);
	}
}
