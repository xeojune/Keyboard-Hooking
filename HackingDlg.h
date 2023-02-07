static CListBox* g_input_key_value;

// HackingDlg.h: 헤더 파일
//

#pragma once


// CHackingDlg 대화 상자
class CHackingDlg : public CDialogEx
{
// 생성입니다.
public:
	CListBox m_input_key_value;
	BOOL SetHook();
	BOOL UnHook();

	inline void AddEventString(const wchar_t* ap_string)
	{
		int index = m_input_key_value.InsertString(-1, ap_string);
		m_input_key_value.SetCurSel(index);
	}

	CListBox* GetMyListBoxAddr() { return &m_input_key_value; }

public:
	CHackingDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HACKING_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	
};
