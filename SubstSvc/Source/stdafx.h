// SubstSvc NT service.
// Copyright (c) 2004-2011 by Elijah Zarezky,
// All rights reserved.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// stdafx.h - include file for standard system include files

// initially generated by AfxScratch v1.0.2290 on 18.07.2004 at 11:12:43
// visit http://zarezky.spb.ru/projects/afx_scratch.html for more info

#if !defined(__stdafx_h)
#define __stdafx_h

#if defined(_MSC_VER) && (_MSC_VER > 1000)
#pragma once
#endif   // _MSC_VER

//////////////////////////////////////////////////////////////////////////////////////////////
// unwanted warnings

// unreferenced inline/local function has been removed
#pragma warning(disable: 4514)
// function not inlined
#pragma warning(disable: 4710)
// identifier was truncated in the debug information
#pragma warning(disable: 4786)

// C4996: function or variable may be unsafe
#define _CRT_SECURE_NO_WARNINGS

//////////////////////////////////////////////////////////////////////////////////////////////
// use WinXP/IE6 features

#define WINVER 0x0501
#define _WIN32_WINDOWS 0x0500
#define _WIN32_IE 0x0600
#define _WIN32_WINNT 0x0501

//////////////////////////////////////////////////////////////////////////////////////////////
// prevent automatic CRT/STL/MFC/ATL manifest dependencies generation

// see http://www.codeproject.com/KB/cpp/PrivateAssemblyProjects.aspx and
// http://blog.m-ri.de/index.php/2008/05/06/hotfix-fuer-usemsprivateassembliesh-und-vc-2008/
// by by Martin Richter for more information

#define _CRT_NOFORCE_MANIFEST
#define _STL_NOFORCE_MANIFEST
#define _AFX_NOFORCE_MANIFEST
#define _ATL_NOFORCE_MANIFEST

#ifdef __cplusplus
extern "C"
{
#endif

__declspec(selectany) int _forceCRTManifest;
__declspec(selectany) int _forceMFCManifest;
__declspec(selectany) int _forceAtlDllManifest;

// the next symbols are used by the several versions of VC++ 2008 (9.0)
__declspec(selectany) int _forceCRTManifestRTM;
__declspec(selectany) int _forceMFCManifestRTM;
__declspec(selectany) int _forceMFCManifestCUR;

#ifdef __cplusplus
}   // extern "C"
#endif

//////////////////////////////////////////////////////////////////////////////////////////////
// MFC headers

#if (_MSC_VER >= 1300)
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#define _ATL_DISABLE_DEPRECATED
#endif   // _MSC_VER

#include <afxwin.h>        // MFC core and standard components
#include <afxmt.h>         // MFC multithreaded extensions
#include <afxconv.h>       // global Unicode/ANSI translation helpers
#include <afxtempl.h>      // MFC collection template classes

//////////////////////////////////////////////////////////////////////////////////////////////
// ATL headers

#include <atlbase.h>

//////////////////////////////////////////////////////////////////////////////////////////////
// PSDK headers

#include <shlwapi.h>       // light-weight utility APIs

#pragma hdrstop

//////////////////////////////////////////////////////////////////////////////////////////////
// shared globals

extern TCHAR g_szServiceName[];
extern SERVICE_STATUS_HANDLE g_hServiceStatus;
extern DWORD g_dwServiceState;

//////////////////////////////////////////////////////////////////////////////////////////////
// core service routines

void WINAPI ServiceHandler(DWORD fdwControl);
void WINAPI ServiceMain(DWORD dwArgc, LPTSTR apszArgv[]);

//////////////////////////////////////////////////////////////////////////////////////////////
// some tricks

// force ISO/IEC 14882 conformance in for loop scope
#if (_MSC_VER < 1300)
#define for if (false); else for
#else
#pragma conform(forScope, on)
#endif   // _MSC_VER

#endif   // __stdafx_h

// end of file
