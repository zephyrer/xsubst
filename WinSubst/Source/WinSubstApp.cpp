// WinSubst application.
// Copyright (c) 2004 by Elijah Zarezky,
// All rights reserved.

// WinSubstApp.cpp - implementation of the CWinSubstApp class
// initially generated by AfxScratch 1.0.2297 on 25.07.2004 at 13:26:11

#include "stdafx.h"
#include "WinSubstApp.h"
#include "SubstsList.h"
#include "MainDialog.h"

#if defined(_DEBUG)
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif	// _DEBUG

// object model
IMPLEMENT_DYNAMIC(CWinSubstApp, CWinApp)

// message map
BEGIN_MESSAGE_MAP(CWinSubstApp, CWinApp)
END_MESSAGE_MAP()

CWinSubstApp::CWinSubstApp(void)
{
}

CWinSubstApp::~CWinSubstApp(void)
{
}

HICON CWinSubstApp::LoadSmIcon(LPCTSTR pszResName)
{
	HINSTANCE hInstRes = AfxGetResourceHandle();
	int cxSmIcon = ::GetSystemMetrics(SM_CXSMICON);
	int cySmIcon = ::GetSystemMetrics(SM_CYSMICON);
	HANDLE hSmIcon = ::LoadImage(hInstRes, pszResName, IMAGE_ICON, cxSmIcon, cySmIcon, 0);
	return (static_cast<HICON>(hSmIcon));
}

BOOL CWinSubstApp::InitInstance(void)
{
	CMainDialog dlgMain;
	m_pMainWnd = &dlgMain;
	dlgMain.DoModal();
	return (FALSE);
}

#if defined(_DEBUG)

void CWinSubstApp::AssertValid(void) const
{
	// first perform inherited validity check...
	CWinApp::AssertValid();
	// ...and then verify our own state as well
}

void CWinSubstApp::Dump(CDumpContext& dumpCtx) const
{
	try {
		// first invoke inherited dumper...
		CWinApp::Dump(dumpCtx);
		// ...and then dump own unique members
	}
	catch (CFileException* pXcpt) {
		pXcpt->ReportError();
		pXcpt->Delete();
	}
}

#endif	// _DEBUG

// the one and only application object
static CWinSubstApp g_appWinSubst;

// end of file
