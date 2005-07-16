// SubstSvc NT service.
// Copyright (c) 2004-2005 by Elijah Zarezky,
// All rights reserved.

// stdafx.h - include file for standard system include files

// initially generated by AfxScratch v1.0.2290 on 18.07.2004 at 11:12:43
// visit http://zarezky.spb.ru/projects/afx_scratch.html for more info

#if !defined(__stdafx_h)
#define __stdafx_h

#if defined(_MSC_VER) && (_MSC_VER > 1000)
#pragma once
#endif	// _MSC_VER

// unreferenced inline/local function has been removed
#pragma warning(disable: 4514)
// function not inlined
#pragma warning(disable: 4710)
// identifier was truncated in the debug information
#pragma warning(disable: 4786)

// MFC headers
#include <afxwin.h>			// MFC core and standard components
#include <afxmt.h>			// MFC multithreaded extensions
#include <afxconv.h>			// global Unicode/ANSI translation helpers
#include <afxtempl.h>		// MFC collection template classes

// ATL headers
#include <atlbase.h>

// PSDK headers
#include <shlwapi.h>			// light-weight utility APIs

#pragma hdrstop

// shared globals
extern TCHAR g_szServiceName[];
extern SERVICE_STATUS_HANDLE g_hServiceStatus;
extern DWORD g_dwServiceState;

// core service routines
void WINAPI ServiceHandler(DWORD fdwControl);
void WINAPI ServiceMain(DWORD dwArgc, LPTSTR apszArgv[]);

// force ISO/IEC 14882 conformance in for loop scope
#if (_MSC_VER < 1300)
#define for if (false); else for
#else
#pragma conform(forScope, on)
#endif	// _MSC_VER

#endif	// __stdafx_h

// end of file
