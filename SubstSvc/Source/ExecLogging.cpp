// SubstSvc NT service.
// Copyright (c) 2004 by Elijah Zarezky,
// All rights reserved.

// ExecLogging.cpp - implementation of the executive logging
// initially generated by AfxScratch 1.0.2290 on 18.07.2004 at 11:12:43

#include "stdafx.h"
#include "ExecLogging.h"

#if defined(_DEBUG)
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif	// _DEBUG

// private globals
static CString g_strLogName;
static CCriticalSection g_csLogging;
static LOG_LEVEL g_eLogLevel;

// creates log file
void CreateLogFile(LPCTSTR pszFileName)
{
	CStdioFile fileLog;
	CFileException xcpt;

	CWinApp* pApp = AfxGetApp();
	g_strLogName = pszFileName;
	UINT fuOpen = CFile::modeCreate | CFile::modeWrite | CFile::typeText;
	if (pApp->GetProfileInt(_T("Logging"), _T("Continuous"), FALSE)) {
		fuOpen |= CFile::modeNoTruncate;
	}
	if (fileLog.Open(g_strLogName, fuOpen, &xcpt)) {
		try {
			fileLog.SeekToEnd();
			fileLog.WriteString(_T(">>> begin of log\n"));
			fileLog.Close();
		}
		catch (CFileException* pXcpt) {
			// simple clean-up
			pXcpt->Delete();
		}
	}
	else {
		// unable to create log file
	}
	g_eLogLevel = static_cast<LOG_LEVEL>(pApp->GetProfileInt(_T("Logging"), _T("Level"), LL_NORMAL));
}

// writes log file entry
void WriteLogFileEntry(LOG_LEVEL eLevel, LPCTSTR pszFormat, ...)
{
	va_list argList;
	CString strTemp;
	CString strEntry;
	CStdioFile fileLog;
	CFileException xcpt;

	if (eLevel <= g_eLogLevel) {
		// this entry should be written
		va_start(argList, pszFormat);
		CString strTime = CTime::GetCurrentTime().Format(_T("%d.%m.%Y %H:%M:%S"));
		strTemp.FormatV(pszFormat, argList);
		strTemp.Replace(_T("\r\n"), _T("\n"));
		strTemp.TrimRight(_T('\n'));
		strEntry.Format(_T("%s\t%s\n"), static_cast<LPCTSTR>(strTime), static_cast<LPCTSTR>(strTemp));
		CSingleLock singleLock(&g_csLogging);
		singleLock.Lock();
		if (singleLock.IsLocked()) {
			// log file has been locked
			enum { fuOpen = CFile::modeWrite | CFile::typeText };
			if (fileLog.Open(g_strLogName, fuOpen, &xcpt)) {
				try {
					fileLog.SeekToEnd();
					fileLog.WriteString(strEntry);
					fileLog.Close();
				}
				catch (CFileException* pXcpt) {
					// simple clean-up
					pXcpt->Delete();
				}
			}
			else {
				// unable to open log file - nothing we can do
			}
			singleLock.Unlock();
		}
		va_end(argList);
	}
}

int WriteLogFileDbgRpt(int /*fnType*/, char* pszMessage, int* /*pnRetVal*/)
{
	USES_CONVERSION;

	CStdioFile fileLog;
	CFileException xcpt;

	if (g_eLogLevel > LL_NONE) {
		// some logging is enbaled
		CSingleLock singleLock(&g_csLogging);
		singleLock.Lock();
		if (singleLock.IsLocked()) {
			// log file has been locked
			enum { fuOpen = CFile::modeWrite | CFile::typeText };
			if (fileLog.Open(g_strLogName, fuOpen, &xcpt)) {
				try {
					fileLog.SeekToEnd();
					CString strTemp(A2T(pszMessage));
					strTemp.Replace(_T("\r\n"), _T("\n"));
					fileLog.WriteString(strTemp);
					fileLog.Close();
				}
				catch (CFileException* pXcpt) {
					// simple clean-up
					pXcpt->Delete();
				}
			}
			else {
				// unable to open log file - nothing we can do
			}
			singleLock.Unlock();
		}
		// completely handled
		return (TRUE);
	}
	else {
		return (FALSE);
	}
}

// end of file
