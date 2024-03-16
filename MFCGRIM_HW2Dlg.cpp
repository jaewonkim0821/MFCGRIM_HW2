
// MFCGRIM_HW2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCGRIM_HW2.h"
#include "MFCGRIM_HW2Dlg.h"
#include "afxdialogex.h"
using namespace std;
#include <iostream>
#include <Windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{

	
public:
	CAboutDlg();
	
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCGRIMHW2Dlg 대화 상자



CMFCGRIMHW2Dlg::CMFCGRIMHW2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCGRIM_HW2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCGRIMHW2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCGRIMHW2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Image, &CMFCGRIMHW2Dlg::OnBnClickedImage)
	ON_BN_CLICKED(Action, &CMFCGRIMHW2Dlg::OnBnClickedAction)
	ON_BN_CLICKED(SaveImage, &CMFCGRIMHW2Dlg::OnBnClickedSaveimage)
	ON_BN_CLICKED(LoadImage, &CMFCGRIMHW2Dlg::OnBnClickedLoadimage)

	//ON_EN_CHANGE(IDC_EDIT_X, &CMFCGRIMHW2Dlg::OnEnChangeEditX)
	//ON_EN_CHANGE(IDC_EDIT_Y, &CMFCGRIMHW2Dlg::OnEnChangeEditY)
END_MESSAGE_MAP()


// CMFCGRIMHW2Dlg 메시지 처리기

BOOL CMFCGRIMHW2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	

  return TRUE;
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_editX.SubclassDlgItem(IDC_EDIT_X, this);
	m_editY.SubclassDlgItem(IDC_EDIT_Y, this);

	// CEdit 컨트롤에 대한 EN_CHANGE 이벤트 처리기 설정
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCGRIMHW2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCGRIMHW2Dlg::OnPaint()
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
HCURSOR CMFCGRIMHW2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCGRIMHW2Dlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}

void CMFCGRIMHW2Dlg::OnBnClickedImage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nWidth = 1200;
	int nHeight = 800;
	int nBpp = 8;
	static RGBQUAD rgb[256];
	m_image.Create(nWidth, -nHeight, nBpp);
	BOOL validImgPos(int x, int y);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	memset(fm, 0xff, nWidth * nHeight);

	
	/*for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {

			fm[j * nPitch + i * 3] = 255;
			fm[j * nPitch + i * 3 + 1] = 255;
			fm[j * nPitch + i * 3 + 2] = 255;
		}
	}
	*/
	UpdateDisplay();
}

bool CMFCGRIMHW2Dlg::vaildImgPos(int x, int y)
{
	int nWidth = m_image.GetWidth(); // 가로폭 픽셀
	int nHeight = m_image.GetHeight(); // 세로폭 픽셀

	CRect rect(0, 0, nWidth, nHeight);
	// 주어진 x, y 에 대해서 영역 안에 들어가면 그 값을 리턴해 준다.
	CPoint point(x, y);
	return rect.PtInRect(point); // Cpoint값으로 바꿔 준다.
}
static int nSttX, nSttY;

void CMFCGRIMHW2Dlg::moveCircle()
{

	std::cout << "x 값을 입력하세요: ";
	std::cin >> nSttX;
	std::cout << "y 값을 입력하세요: ";
	std::cin >> nSttY;
	int nGray = 40;
	int interval = 5;
	int nWidth = m_image.GetWidth(); // 가로폭 픽셀
	int nHeight = m_image.GetHeight(); // 세로폭 픽셀
	unsigned char* fm = (unsigned char*)m_image.GetBits(); // 내가 만든 이미지의 첫번째 포인터의 값을 가져오겠다.
	int nPitch = m_image.GetPitch();

	// 전체 이미지를 흰색으로 초기화한다.
	memset(fm, 0xff, nWidth * nHeight); // 메모리를 어떠한 값으로 연결할 것인지

	// 원의 반지름을 설정한다.
	int r = 100;

	for (int j = nSttY - r; j < nSttY + r; j++) {
		for (int i = nSttX - r; i < nSttX + r; i++) {
			int dx = i - nSttX;
			int dy = j - nSttY;
			if (vaildImgPos(i, j) && (dx * dx + dy * dy <= r * r)) {
				// 픽셀이 이미지 내에 있고, 원의 내부에 있는 경우에만 그레이로 채웁니다.
				fm[j * nPitch + i] = nGray;
			}
		}
	}

	UpdateDisplay();
	
}


void CMFCGRIMHW2Dlg::OnBnClickedAction()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = 0;i < 3; i++) {
		moveCircle();
		Sleep(1);
	}

}


CString g_strFileImage = _T("Image.bmp");
void CMFCGRIMHW2Dlg::OnBnClickedSaveimage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	m_image.Save(g_strFileImage);
	cout << "Image.bmp파일로 저장되었습니다."<< endl;
}


void CMFCGRIMHW2Dlg::OnBnClickedLoadimage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// 이미지가 없으면 제거
	if (m_image != NULL) {
		m_image.Destroy();
	}
	// 이미지 로드하기
	m_image.Load(g_strFileImage);

	UpdateDisplay();
	cout << "원의 중앙 좌표값은 다음과 같습니다." << nSttX << "\t" << nSttY << endl;
}

 /* void CMFCGRIMHW2Dlg::OnEnChangeEditX()
{
	CString strX;
	m_editX.GetWindowTextW(strX);
	nSttX = _ttoi(strX);
	moveCircle();
	UpdateDisplay();
}


void CMFCGRIMHW2Dlg::OnEnChangeEditY()
{
	CString strY;
	m_editX.GetWindowTextW(strY);
	nSttX = _ttoi(strY);
	moveCircle();
	UpdateDisplay();
}
*/
