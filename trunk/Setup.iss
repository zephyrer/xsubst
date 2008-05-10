;; xsubst utility.
;; Copyright (c) 2004-2005 by Elijah Zarezky,
;; All rights reserved.

;; Licensed under the Apache License, Version 2.0 (the "License");
;; you may not use this file except in compliance with the License.
;; You may obtain a copy of the License at
;;
;; http://www.apache.org/licenses/LICENSE-2.0
;;
;; Unless required by applicable law or agreed to in writing, software
;; distributed under the License is distributed on an "AS IS" BASIS,
;; WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;; See the License for the specific language governing permissions and
;; limitations under the License.

;; Setup.iss - setup script for Inno Setup compiler

[Setup]
AppName=xsubst
AppVerName=xsubst 1.0.3839
AppID={{5F7BE167-B54A-408C-9AE0-66F20E2BEFFC}
AppPublisher=Elijah Zarezky
AppPublisherURL=http://zarezky.spb.ru/
AppSupportURL=http://zarezky.spb.ru/projects/xsubst.html
AppUpdatesURL=http://zarezky.spb.ru/projects/xsubst.html
AppVersion=1.0.3839
DefaultDirName={pf}\PowerGadgets\xsubst
DefaultGroupName=PowerGadgets\xsubst
AllowNoIcons=true
Compression=lzma
SolidCompression=true
OutputDir=.\Setup
OutputBaseFilename=xsubst-1.0.3839-setup
VersionInfoVersion=1.0.3839
MinVersion=0,5.0.2195
PrivilegesRequired=admin
WizardImageFile=compiler:WizModernImage-IS.bmp
WizardSmallImageFile=compiler:WizModernSmallImage-IS.bmp
LicenseFile=ApacheLicense.rtf

[LangOptions]
DialogFontName=Tahoma
DialogFontSize=8

[Code]
procedure CleanupHKCU();
begin
   RegDeleteKeyIncludingSubkeys(HKCU, 'Software\Elijah Zarezky\xsubst');
   RegDeleteKeyIfEmpty(HKCU, 'Software\Elijah Zarezky');
end;

function StopService(): boolean;
var
	ResCode: integer;
begin
	Exec(GetSystemDir() + '\net.exe', 'stop "Substituted Drives Manager"', GetSystemDir(), SW_HIDE, ewWaitUntilTerminated, ResCode);
	Result := true;
end;

[Files]
Source: ".\WinSubst\Output.2003\x86\Release\Unicode\WinSubst.exe"; DestDir: "{app}"
Source: ".\SubstSvc\Output.2003\x86\Release\Unicode\SubstSvc.exe"; DestDir: "{app}"; Check: StopService
Source: ".\ApacheLicense.rtf"; DestDir: "{app}"; Flags: ignoreversion
Source: ".\Redist\mfc71u.dll"; DestDir: "{app}"
Source: "..\Redist\mfc71enu.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: ".\Redist\msvcr71.dll"; DestDir: "{app}"

[Icons]
Name: "{group}\WinSubst"; Filename: "{app}\WinSubst.exe"
Name: "{group}\xsubst on the Web"; Filename: "{app}\xsubst.url"
Name: "{group}\xsubst License"; Filename: "{app}\ApacheLicense.rtf"
Name: "{group}\Uninstall xsubst"; Filename: "{uninstallexe}"
Name: "{userdesktop}\WinSubst"; Filename: "{app}\WinSubst.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\WinSubst"; Filename: "{app}\WinSubst.exe"; Tasks: quicklaunchicon

[INI]
Filename: "{app}\xsubst.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://zarezky.spb.ru/projects/xsubst.html"

[Registry]
Root: HKU; Subkey: ".DEFAULT\Software\Elijah Zarezky"; Flags: uninsdeletekeyifempty
Root: HKU; Subkey: ".DEFAULT\Software\Elijah Zarezky\xsubst"; Flags: uninsdeletekey
Root: HKU; Subkey: ".DEFAULT\Software\Elijah Zarezky\xsubst\SubstSvc"; Flags: uninsdeletekey
Root: HKU; Subkey: ".DEFAULT\Software\Elijah Zarezky\xsubst\SubstSvc\Drives"; Flags: uninsdeletekey
Root: HKU; Subkey: ".DEFAULT\Software\Elijah Zarezky\xsubst\SubstSvc\Logging"; Flags: uninsdeletekey
Root: HKU; Subkey: ".DEFAULT\Software\Elijah Zarezky\xsubst\SubstSvc\Logging"; ValueType: dword; ValueName: "Continuous"; ValueData: "1"; Flags: createvalueifdoesntexist

[Tasks]
Name: desktopicon; Description: "Create a &desktop icon"; GroupDescription: "Additional icons:"; Flags: unchecked
Name: quicklaunchicon; Description: "Create a &Quick Launch icon"; GroupDescription: "Additional icons:"; Flags: unchecked

[Run]
Filename: "{app}\SubstSvc.exe"; Parameters: "/Register"; StatusMsg: "Registering Substituted Drives Manager service..."; Flags: runhidden; AfterInstall: CleanupHKCU
Filename: "{sys}\net.exe"; Parameters: "start ""Substituted Drives Manager"""; StatusMsg: "Starting Substituted Drives Manager service..."; Flags: runhidden
Filename: "{app}\WinSubst.exe"; Description: "Launch WinSubst"; Flags: nowait postinstall skipifsilent

[UninstallRun]
Filename: "{sys}\net.exe"; Parameters: "stop ""Substituted Drives Manager"""; StatusMsg: "Stopping Substituted Drives Manager service..."; Flags: runhidden
Filename: "{app}\SubstSvc.exe"; Parameters: "/UnRegister"; StatusMsg: "Unregistering Substituted Drives Manager service..."; Flags: runhidden; AfterInstall: CleanupHKCU

[UninstallDelete]
Type: files; Name: "{app}\SubstSvc.log"
Type: files; Name: "{app}\xsubst.url"

;; end of file