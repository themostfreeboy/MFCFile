
// MFC_File.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_FileApp:
// �йش����ʵ�֣������ MFC_File.cpp
//

class CMFC_FileApp : public CWinApp
{
public:
	CMFC_FileApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_FileApp theApp;