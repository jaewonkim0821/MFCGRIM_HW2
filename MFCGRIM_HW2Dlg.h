
// MFCGRIM_HW2Dlg.h: 헤더 파일
//

#pragma once


// CMFCGRIMHW2Dlg 대화 상자
class CMFCGRIMHW2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCGRIMHW2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CImage m_image;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCGRIM_HW2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	
	DECLARE_MESSAGE_MAP()
private:
	int m_nSttX; // X 값 멤버 변수 추가
	int m_nSttY; // Y 값 멤버 변수 추가
	CEdit m_editX; // X 값을 입력받는 CEdit 컨트롤
	CEdit m_editY; // Y 값을 입력받는 CEdit 컨트롤
public:
	
	afx_msg void OnBnClickedImage();
	afx_msg void OnBnClickedAction();
	afx_msg void OnBnClickedSaveimage();
	afx_msg void OnBnClickedLoadimage();
	afx_msg void UpdateDisplay();
	afx_msg void moveCircle();
	afx_msg bool vaildImgPos(int x, int y);
	
	
	//afx_msg void OnEnChangeEditX();
	//afx_msg void OnEnChangeEditY();
};
