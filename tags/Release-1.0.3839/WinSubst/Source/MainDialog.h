// WinSubst application.
// Copyright (c) 2004-2007 by Elijah Zarezky,
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

// MainDialog.h - interface of the CMainDialog class

// initially generated by AfxScratch v1.0.2297 on 25.07.2004 at 13:26:11
// visit http://zarezky.spb.ru/projects/afx_scratch.html for more info

#if !defined(__MainDialog_h)
#define __MainDialog_h

#if defined(_MSC_VER) && (_MSC_VER > 1000)
#pragma once
#endif	// _MSC_VER

class CMainDialog: public CDialog
{
	DECLARE_DYNAMIC(CMainDialog)
	DECLARE_MESSAGE_MAP()

// construction/destruction
public:
	CMainDialog(CWnd* pParentWnd = NULL);
	virtual ~CMainDialog(void);

// overridables
public:
	virtual BOOL OnInitDialog(void);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual void OnOK(void);
	virtual void OnCancel(void);

// message map functions
protected:
	afx_msg void OnClose(void);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT uCtlColor);
	afx_msg void OnSysCommand(UINT uID, LPARAM lParam);
	afx_msg void OnSubstsListItemChanged(NMHDR* pHdr, LRESULT* pnResult);
	afx_msg void OnButtonNewSubst(void);
	afx_msg void OnButtonChangeSubst(void);
	afx_msg void OnButtonDeleteSubst(void);
	afx_msg void OnButtonExit(void);

// attributes
public:
	HICON m_hIcon;
	HICON m_hSmIcon;
	CImageList m_imageList;
	int m_iDefIcon;
	CSubstsList m_listSubsts;
	DWORD m_dwSvcState;

// implementation helpers
private:
	void GetSvcStateText(CString& strDest);
	void ControlService(DWORD dwCode);

// diagnostic services
#if defined(_DEBUG)
public:
	virtual void AssertValid(void) const;
	virtual void Dump(CDumpContext& dumpCtx) const;
#endif
};

#endif	// __MainDialog_h

// end of file