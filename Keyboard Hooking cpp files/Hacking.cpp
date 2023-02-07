﻿
// Hacking.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "Hacking.h"
#include "HackingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHackingApp

BEGIN_MESSAGE_MAP(CHackingApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CHackingApp 생성

CHackingApp::CHackingApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CHackingApp 개체입니다.

CHackingApp theApp;


// CHackingApp 초기화

BOOL CHackingApp::InitInstance()
{
	CWinApp::InitInstance();


	
	CHackingDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

