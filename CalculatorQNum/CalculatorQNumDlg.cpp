
// CalculatorQNumDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CalculatorQNum.h"
#include "CalculatorQNumDlg.h"
#include "afxdialogex.h"

#pragma warning(disable : 4996)

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CCalculatorQNumDlg dialog



CCalculatorQNumDlg::CCalculatorQNumDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATORQNUM_DIALOG, pParent)
	, edtOperand1(_T(""))
	, edtOperand2(_T(""))
	, edtResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CCalculatorQNumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_OPERAND_1, edtOperand1);
	DDX_Text(pDX, IDC_EDT_OPERAND_2, edtOperand2);
	DDX_Text(pDX, IDC_EDT_RESULT, edtResult);
	DDX_Control(pDX, IDC_RD_QINT, rdQInt);
	DDX_Control(pDX, IDC_RD_QFLOAT, rdQFloat);
	DDX_Control(pDX, IDC_RD_DEC, rdDec);
	DDX_Control(pDX, IDC_RD_BIN, rdBin);
	DDX_Control(pDX, IDC_RD_HEX, rdHex);
	DDX_Control(pDX, IDC_CB_OPERATOR, cbOperator);
	DDX_Control(pDX, IDC_CB_CONVERT, cbConvert);
	DDX_Control(pDX, IDC_BTN_A, btnA);
	DDX_Control(pDX, IDC_BTN_B, btnB);
	DDX_Control(pDX, IDC_BTN_C, btnC);
	DDX_Control(pDX, IDC_BTN_D, btnD);
	DDX_Control(pDX, IDC_BTN_E, btnE);
	DDX_Control(pDX, IDC_BTN_F, btnF);
	DDX_Control(pDX, IDC_BTN_9, btn9);
	DDX_Control(pDX, IDC_BTN_8, btn8);
	DDX_Control(pDX, IDC_BTN_7, btn7);
	DDX_Control(pDX, IDC_BTN_6, btn6);
	DDX_Control(pDX, IDC_BTN_5, btn5);
	DDX_Control(pDX, IDC_BTN_4, btn4);
	DDX_Control(pDX, IDC_BTN_3, btn3);
	DDX_Control(pDX, IDC_BTN_2, btn2);
	DDX_Control(pDX, IDC_BTN_1, btn1);
	DDX_Control(pDX, IDC_BTN_0, btn0);
	DDX_Control(pDX, IDC_BTN_SIGN, btnSign);
	DDX_Control(pDX, IDC_BTN_DOT, btnDot);
	DDX_Control(pDX, IDC_BTN_RESULT, btnResult);
	DDX_Control(pDX, IDC_BTN_CE, btnCE);
	DDX_Control(pDX, IDC_BTN_BACK, btnBack);
	DDX_Control(pDX, IDC_CB_BITWISE, cbBitwise);
	DDX_Control(pDX, IDC_RD_ON, rdOn);
	DDX_Control(pDX, IDC_RD_OFF, rdOff);
}

BEGIN_MESSAGE_MAP(CCalculatorQNumDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RD_QINT, &CCalculatorQNumDlg::OnBnClickedRdQint)
	ON_BN_CLICKED(IDC_RD_QFLOAT, &CCalculatorQNumDlg::OnBnClickedRdQfloat)
	ON_BN_CLICKED(IDC_RD_DEC, &CCalculatorQNumDlg::OnBnClickedRdDec)
	ON_BN_CLICKED(IDC_RD_BIN, &CCalculatorQNumDlg::OnBnClickedRdBin)
	ON_BN_CLICKED(IDC_RD_HEX, &CCalculatorQNumDlg::OnBnClickedRdHex)
	ON_EN_CHANGE(IDC_EDT_OPERAND_1, &CCalculatorQNumDlg::OnEnChangeEdtOperand1)
	ON_CBN_SELCHANGE(IDC_CB_OPERATOR, &CCalculatorQNumDlg::OnCbnSelchangeCbOperator)
	ON_CBN_SELCHANGE(IDC_CB_CONVERT, &CCalculatorQNumDlg::OnCbnSelchangeCbConvert)
	ON_EN_CHANGE(IDC_EDT_OPERAND_2, &CCalculatorQNumDlg::OnEnChangeEdtOperand2)
	ON_EN_CHANGE(IDC_EDT_RESULT, &CCalculatorQNumDlg::OnEnChangeEdtResult)
	ON_BN_CLICKED(IDC_BTN_A, &CCalculatorQNumDlg::OnBnClickedBtnA)
	ON_BN_CLICKED(IDC_BTN_B, &CCalculatorQNumDlg::OnBnClickedBtnB)
	ON_BN_CLICKED(IDC_BTN_C, &CCalculatorQNumDlg::OnBnClickedBtnC)
	ON_BN_CLICKED(IDC_BTN_D, &CCalculatorQNumDlg::OnBnClickedBtnD)
	ON_BN_CLICKED(IDC_BTN_E, &CCalculatorQNumDlg::OnBnClickedBtnE)
	ON_BN_CLICKED(IDC_BTN_F, &CCalculatorQNumDlg::OnBnClickedBtnF)
	ON_BN_CLICKED(IDC_BTN_9, &CCalculatorQNumDlg::OnBnClickedBtn9)
	ON_BN_CLICKED(IDC_BTN_8, &CCalculatorQNumDlg::OnBnClickedBtn8)
	ON_BN_CLICKED(IDC_BTN_7, &CCalculatorQNumDlg::OnBnClickedBtn7)
	ON_BN_CLICKED(IDC_BTN_6, &CCalculatorQNumDlg::OnBnClickedBtn6)
	ON_BN_CLICKED(IDC_BTN_5, &CCalculatorQNumDlg::OnBnClickedBtn5)
	ON_BN_CLICKED(IDC_BTN_4, &CCalculatorQNumDlg::OnBnClickedBtn4)
	ON_BN_CLICKED(IDC_BTN_3, &CCalculatorQNumDlg::OnBnClickedBtn3)
	ON_BN_CLICKED(IDC_BTN_2, &CCalculatorQNumDlg::OnBnClickedBtn2)
	ON_BN_CLICKED(IDC_BTN_1, &CCalculatorQNumDlg::OnBnClickedBtn1)
	ON_BN_CLICKED(IDC_BTN_0, &CCalculatorQNumDlg::OnBnClickedBtn0)
	ON_BN_CLICKED(IDC_BTN_DOT, &CCalculatorQNumDlg::OnBnClickedBtnDot)
	ON_BN_CLICKED(IDC_BTN_SIGN, &CCalculatorQNumDlg::OnBnClickedBtnSign)
	ON_BN_CLICKED(IDC_BTN_RESULT, &CCalculatorQNumDlg::OnBnClickedBtnResult)
	ON_BN_CLICKED(IDC_BTN_CE, &CCalculatorQNumDlg::OnBnClickedBtnCe)
	ON_BN_CLICKED(IDC_BTN_BACK, &CCalculatorQNumDlg::OnBnClickedBtnBack)
	ON_EN_SETFOCUS(IDC_EDT_OPERAND_1, &CCalculatorQNumDlg::OnSetfocusEdtOperand1)
	ON_EN_SETFOCUS(IDC_EDT_OPERAND_2, &CCalculatorQNumDlg::OnSetfocusEdtOperand2)
	ON_CBN_SELCHANGE(IDC_CB_BITWISE, &CCalculatorQNumDlg::OnCbnSelchangeCbBitwise)
	ON_BN_CLICKED(IDC_BTN_FILE_IN, &CCalculatorQNumDlg::OnBnClickedBtnFileIn)
	ON_BN_CLICKED(IDC_BTN_FILE_OUT, &CCalculatorQNumDlg::OnBnClickedBtnFileOut)
	ON_BN_CLICKED(IDC_RD_ON, &CCalculatorQNumDlg::OnBnClickedRdOn)
	ON_BN_CLICKED(IDC_RD_OFF, &CCalculatorQNumDlg::OnBnClickedRdOff)
END_MESSAGE_MAP()


// CCalculatorQNumDlg message handlers

BOOL CCalculatorQNumDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	// Khởi tạo các chế độ mặc định của ứng dụng là QInt và Dec
	rdQInt.SetCheck(TRUE);
	rdDec.SetCheck(TRUE);
	rdOff.SetCheck(TRUE);
	radioLastChose = IDC_RD_DEC;
	dialogLastFocused = IDC_EDT_OPERAND_1;

	// Thiết lập giá trị mặc định
	// Combo box operator
	cbOperator.AddString(L"Operator");
	cbOperator.AddString(L"+");
	cbOperator.AddString(L"-");
	cbOperator.AddString(L"*");
	cbOperator.AddString(L"/");
	cbOperator.AddString(L">");
	cbOperator.AddString(L"<");
	cbOperator.AddString(L">=");
	cbOperator.AddString(L"<=");
	cbOperator.AddString(L"==");
	cbOperator.AddString(L"!=");
	cbOperator.SetCurSel(0);
	
	// Combo box converter exclude convert to Dec
	cbConvert.AddString(L"Convert to");
	cbConvert.AddString(L"Convert to Bin");
	cbConvert.AddString(L"Convert to Hex");
	cbConvert.SetCurSel(0);

	// Combo box bitwise
	cbBitwise.AddString(L"Bitwise");
	cbBitwise.AddString(L"AND");
	cbBitwise.AddString(L"OR");
	cbBitwise.AddString(L"XOR");
	cbBitwise.AddString(L"NOT");
	cbBitwise.AddString(L"SHL");
	cbBitwise.AddString(L"SHR");
	cbBitwise.AddString(L"ROL");
	cbBitwise.AddString(L"ROR");
	cbBitwise.SetCurSel(0);

	// Vì đang ở Dec nên tắt những view không liên quan
	enableHexKey(FALSE);
	btnDot.EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_FILE_IN)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BTN_FILE_OUT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TV_CHOOSE_FILE)->ShowWindow(SW_HIDE);

	// Thiết lập font chữ
	CFont m_font;
	m_font.CreateFont(20, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, 0, L"Microsoft Sans Serif");
	btn0.SetFont(&m_font);
	btn1.SetFont(&m_font);
	btn2.SetFont(&m_font);
	btn3.SetFont(&m_font);
	btn4.SetFont(&m_font);
	btn5.SetFont(&m_font);
	btn6.SetFont(&m_font);
	btn7.SetFont(&m_font);
	btn8.SetFont(&m_font);
	btn9.SetFont(&m_font);
	btnSign.SetFont(&m_font);
	btnDot.SetFont(&m_font);
	btnA.SetFont(&m_font);
	btnB.SetFont(&m_font);
	btnC.SetFont(&m_font);
	btnD.SetFont(&m_font);
	btnE.SetFont(&m_font);
	btnF.SetFont(&m_font);

	(GetDlgItem(IDC_EDT_OPERAND_1))->SetFont(&m_font);
	(GetDlgItem(IDC_EDT_OPERAND_2))->SetFont(&m_font);
	(GetDlgItem(IDC_EDT_RESULT))->SetFont(&m_font);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorQNumDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorQNumDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorQNumDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// @Overide hàm OnOK từ base class (ngăn ấn Enter thoát chương trình)
void CCalculatorQNumDlg::OnOK()
{
	UpdateData();
	OnBnClickedBtnResult();
}

//Hàm bắt sự kiện click button in file
void CCalculatorQNumDlg::OnBnClickedBtnFileIn()
{
	CString filename;
	char fileFilter[] = { "Text Files (*.txt)|*.txt|" };
	CFileDialog dlg(TRUE, CString(".txt"), NULL, 0, CString(fileFilter));		// Mở dialog file để chọn file .txt

	GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"");

	if (dlg.DoModal() == IDOK)													// Lấy đường dẫn file in và xuất ra operand 1
	{
		filename = dlg.GetPathName();
		inFile = CW2A(filename);
	}

	edtOperand1.SetString(filename);
	GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
}

//Hàm bắt sự kiện click button out file
void CCalculatorQNumDlg::OnBnClickedBtnFileOut()
{
	CString filename;
	char fileFilter[] = { "Text Files (*.txt)|*.txt|" };
	CFileDialog dlg(FALSE, CString(".txt"), NULL, 0, CString(fileFilter));		// Mở dialog file để lưu file .txt
	GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"");

	if (dlg.DoModal() == IDOK)													// Lấy đường dẫn file in và xuất ra operand 2
	{
		filename = dlg.GetPathName();		
		outFile = CW2A(filename);
	}

	GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"executing....");
	edtOperand2.SetString(filename);
	GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);

	OnBnClickedBtnResult();
}

//Hàm bắt sự kiện click radio button On - Bật chế độ chọn file
void CCalculatorQNumDlg::OnBnClickedRdOn()
{
	OnBnClickedBtnCe();

	GetDlgItem(IDC_BTN_FILE_IN)->ShowWindow(SW_SHOW);			// Hiển thị các mục cần thiết để chọn file
	GetDlgItem(IDC_BTN_FILE_OUT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TV_CHOOSE_FILE)->ShowWindow(SW_SHOW);

	if (rdQFloat.GetCheck() == TRUE)							// Bật operand 2 bị ẩn ở QFloat
	{
		GetDlgItem(IDC_EDT_OPERAND_2)->EnableWindow();
	}
}

//Hàm bắt sự kiện click radio button On - Tắt chế độ chọn file
void CCalculatorQNumDlg::OnBnClickedRdOff()
{
	GetDlgItem(IDC_BTN_FILE_IN)->ShowWindow(SW_HIDE);			// Ẩn các mục cần thiết để chọn file
	GetDlgItem(IDC_BTN_FILE_OUT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TV_CHOOSE_FILE)->ShowWindow(SW_HIDE);

	if (rdQFloat.GetCheck() == TRUE)							// Tăt operand 2 ở QFloat
	{
		GetDlgItem(IDC_EDT_OPERAND_2)->EnableWindow(FALSE);
	}

	OnBnClickedBtnCe();
}


// Bắt sự kiện click rdQInt -> Chuyển chế độ số nguyên
void CCalculatorQNumDlg::OnBnClickedRdQint()
{
	OnBnClickedBtnCe();									// Xóa hết dữ liệu

	cbOperator.EnableWindow();							// Bật/tắt các view liên quan
	cbBitwise.EnableWindow();

	OnBnClickedRdBin();
	rdHex.EnableWindow();

	enableHexKey(FALSE);
	btnDot.EnableWindow(FALSE);

	GetDlgItem(IDC_EDT_OPERAND_2)->EnableWindow();
}

// Bắt sự kiện click rdQFloat -> Chuyển chế độ số thực
void CCalculatorQNumDlg::OnBnClickedRdQfloat()
{
	OnBnClickedBtnCe();									// Xóa hết dữ liệu

	cbOperator.EnableWindow(FALSE);						// Bật/tắt các view liên quan
	cbBitwise.EnableWindow(FALSE);

	if (rdHex.GetCheck() == TRUE)						// Vì ở số thực không có Hex nên tắt đi
	{													// Nếu nó được chọn ở số nguyên thì sẽ được chuyển sang bật rdDec ở số thực
		rdHex.SetCheck(FALSE);
		rdDec.SetCheck(TRUE);
		rdHex.EnableWindow(FALSE);
	}
	else
	{
		rdHex.EnableWindow(FALSE);
	}
	
	enableHexKey(FALSE);
	btnDot.EnableWindow(TRUE);
	btnSign.EnableWindow(TRUE);

	cbConvert.ResetContent();							// Convert chỉ có hoặc là to bin hoặc là to dec
	
	if (rdDec.GetCheck() == TRUE)
	{
		cbConvert.AddString(L"Convert to Bin");
	}
	else
	{
		cbConvert.AddString(L"Convert to Dec");
	}

	cbConvert.SetCurSel(0);

	if (rdOn.GetCheck() == TRUE)							// Bật operand 2 bị ẩn ở QFloat
	{
		GetDlgItem(IDC_EDT_OPERAND_2)->EnableWindow();
	}
	else
	{
		GetDlgItem(IDC_EDT_OPERAND_2)->EnableWindow(FALSE);
	}
}

// Bắt sự kiện click rdDec -> Chuyển cơ số 10
void CCalculatorQNumDlg::OnBnClickedRdDec()
{
	cbConvert.ResetContent();						// Thiết lập lại cbConvert cho phù hợp vì Dec convert to Dec là thừa

	if (rdQInt.GetCheck() == TRUE)					// Nếu ở số nguyên thì có 2 lựa chọn là Bin hoặc Hex
	{
		cbConvert.AddString(L"Convert to");
		cbConvert.AddString(L"Convert to Bin");
		cbConvert.AddString(L"Convert to Hex");
	}
	else											// Còn ở số thực thì convert Dec to Bin
	{
		cbConvert.AddString(L"Convert to Bin");
		btnDot.EnableWindow();
	}

	cbConvert.SetCurSel(0);

	convertBaseOperand(10);
	
	if (rdQInt.GetCheck() == TRUE)					// Giữ nguyên phép toán đã chọn
	{
		if (cbConvertLastChose != 0)
		{
			cbConvert.SetCurSel(cbConvertLastChose);
			OnCbnSelchangeCbConvert();
		}
		else if (cbOperatorLastChoose != 0)
		{
			cbOperator.SetCurSel(cbOperatorLastChoose);
			OnCbnSelchangeCbOperator();
		}
		else if (cbBitwiseLastChoose != 0)
		{
			cbBitwise.SetCurSel(cbBitwiseLastChoose);
			OnCbnSelchangeCbBitwise();
		}

	}
	else											// Nếu ở số thực thì chỉ chuyển đổi qua lại Bin và Dec
	{
		OnCbnSelchangeCbConvert();
	}

	enableHexKey(FALSE);
	enableDecKey();

	radioLastChose = IDC_RD_DEC;
}

// Bắt sự kiện click rdBin -> Chuyển cơ số 2
void CCalculatorQNumDlg::OnBnClickedRdBin()
{
	cbConvert.ResetContent();							// Thiết lập lại cbConvert cho phù hợp 

	if (rdQInt.GetCheck() == TRUE)						// Nếu ở số nguyên thì có 2 lựa chọn là Dec hoặc Hex
	{
		cbConvert.AddString(L"Convert to");
		cbConvert.AddString(L"Convert to Dec");
		cbConvert.AddString(L"Convert to Hex");
	}
	else												// Còn ở số thực thì convert Bin to Dec
	{
		cbConvert.AddString(L"Convert to Dec");
	}

	cbConvert.SetCurSel(0);

	convertBaseOperand(2);

	if (rdQInt.GetCheck() == TRUE)						// Giữ nguyên phép toán đã chọn
	{
		if (cbConvertLastChose != 0)
		{
			if (radioLastChose == IDC_RD_HEX)
			{
				cbConvertLastChose = (cbConvertLastChose == 1) ? 2 : 1;			// Vì ở convert ở rdHex là [Bin, Dec] sang rdBin là [Dec, Hex] -> thay đổi index để phù hợp chuyển đổi
			}																	// Tức là chọn Bin ở rdHex thì qua rdBin sẽ chuyển ngược về Hex

			cbConvert.SetCurSel(cbConvertLastChose);
			OnCbnSelchangeCbConvert();
		}
		else if (cbOperatorLastChoose != 0)
		{
			cbOperator.SetCurSel(cbOperatorLastChoose);
			OnCbnSelchangeCbOperator();
		}
		else if (cbBitwiseLastChoose != 0)
		{
			cbBitwise.SetCurSel(cbBitwiseLastChoose);
			OnCbnSelchangeCbBitwise();
		}
	}
	else												// Nếu ở số thực thì chỉ chuyển đổi qua lại Bin và Dec
	{
		OnCbnSelchangeCbConvert();
	}

	enableHexKey(FALSE);
	enableDecKey(FALSE);

	if (rdQFloat.GetCheck() == TRUE)
	{
		btnDot.EnableWindow(FALSE);
	}

	radioLastChose = IDC_RD_BIN;
}

// Bắt sự kiện click rdHex -> Chuyển cơ số 16
void CCalculatorQNumDlg::OnBnClickedRdHex()
{
	cbConvert.ResetContent();						// Thiết lập lại cbConvert cho phù hợp vì số thực không có Hex nên ta chỉ xét số nguyên
	cbConvert.AddString(L"Convert to");
	cbConvert.AddString(L"Convert to Bin");
	cbConvert.AddString(L"Convert to Dec");

	cbConvert.SetCurSel(0);

	convertBaseOperand(16);

	if (cbConvertLastChose != 0)											// Giữ nguyên phép toán đã chọn
	{
		if (radioLastChose == IDC_RD_BIN)
		{
			cbConvertLastChose = (cbConvertLastChose == 1) ? 2 : 1;			// Vì ở convert ở rdBin là [Dec, Hex] sang rdHex là [Bin, Dec] -> thay đổi index để phù hợp chuyển đổi
		}																	// Tức là chọn Dec ở rdBin thì qua rdHex sẽ vẫn chọn Dec

		cbConvert.SetCurSel(cbConvertLastChose);
		OnCbnSelchangeCbConvert();
	}
	else if (cbOperatorLastChoose != 0)
	{
		cbOperator.SetCurSel(cbOperatorLastChoose);
		OnCbnSelchangeCbOperator();
	}
	else if (cbBitwiseLastChoose != 0)
	{
		cbBitwise.SetCurSel(cbBitwiseLastChoose);
		OnCbnSelchangeCbBitwise();
	}
	
	enableHexKey();
	enableDecKey();

	radioLastChose = IDC_RD_HEX;
	cbConvertLastChose = cbConvert.GetCurSel();
}

// Hàm bắt sự kiện khi combo box Operator thay đổi
void CCalculatorQNumDlg::OnCbnSelchangeCbOperator()
{
	if (cbOperator.GetCurSel() != 0)							// Nếu đang chọn combo box này thì tắt các combo box còn lại
	{
		cbConvert.SetCurSel(0);
		cbBitwise.SetCurSel(0);

		edtResult = L"";
		GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(edtResult);
		GetDlgItem(IDC_EDT_OPERAND_2)->EnableWindow();			// Bật toán hạng 2 vì nếu ở Convert thì không cần nên sẽ bị tắt
	}
	
	cbOperatorLastChoose = cbOperator.GetCurSel();				// Lưu lại các giá trị đã chọn và update kết quả
	cbBitwiseLastChoose = 0;
	cbConvertLastChose = 0;
	OnBnClickedBtnResult();
}

// Hàm bắt sự kiện khi combo box Convert thay đổi
void CCalculatorQNumDlg::OnCbnSelchangeCbConvert()
{
	if (cbConvert.GetCurSel() != 0)								// Nếu đang chọn combo box này thì tắt các combo box còn lại
	{
		cbOperator.SetCurSel(0);
		cbBitwise.SetCurSel(0);

		edtOperand2 = L"";
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
		GetDlgItem(IDC_EDT_OPERAND_2)->EnableWindow(FALSE);		// Tắt toán hạng 2 vì không cần
	}
	else if (rdQInt.GetCheck() == TRUE)
	{
		GetDlgItem(IDC_EDT_OPERAND_2)->EnableWindow();
	}
	
	cbConvertLastChose = cbConvert.GetCurSel();					// Lưu lại các giá trị đã chọn và update kết quả
	cbOperatorLastChoose = 0;
	cbBitwiseLastChoose = 0;
	OnBnClickedBtnResult();
}

// Hàm bắt sự kiện khi combo box Bitwise thay đổi
void CCalculatorQNumDlg::OnCbnSelchangeCbBitwise()
{
	if (cbBitwise.GetCurSel() != 0)								// Nếu đang chọn combo box này thì tắt các combo box còn lại
	{
		cbConvert.SetCurSel(0);
		cbOperator.SetCurSel(0);

		edtResult = L"";
		GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(edtResult);
		
		if (cbBitwise.GetCurSel() == 4)							// Tắt toán hạng 2 khi bitwise là NOT (toán tử 1 ngôi)
		{
			GetDlgItem(IDC_EDT_OPERAND_2)->EnableWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_EDT_OPERAND_2)->EnableWindow();
		}
	}

	cbBitwiseLastChoose = cbBitwise.GetCurSel();				// Lưu lại các giá trị đã chọn và update kết quả
	cbConvertLastChose = 0;
	cbOperatorLastChoose = 0;
	OnBnClickedBtnResult();
}

// Hàm bắt sự kiện khi edit box operand 1 thay đổi
void CCalculatorQNumDlg::OnEnChangeEdtOperand1()
{
	UpdateData();

	// Kiểm tra tính hợp lệ của Operand 1 và 2
	if (!isValidOp1())
	{
		if (!isValidOp2())
		{
			GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"Input of operand 1 and 2 is invalid!");
			return;
		}
		else
		{
			GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"Input of operand 1 is invalid!");
			return;
		}
	}

	GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"");
}

// Hàm bắt sự kiện khi edit box operand 2 thay đổi
void CCalculatorQNumDlg::OnEnChangeEdtOperand2()
{
	UpdateData();

	// Kiểm tra tính hợp lệ của Operand 1 và 2
	if (!isValidOp2())
	{
		if (!isValidOp1())
		{
			GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"Input of operand 1 and 2 is invalid!");
			return;
		}
		else
		{
			GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"Input of operand 2 is invalid!");
			return;
		}
	}

	GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"");
}

// Hàm bắt sự kiện khi edtOperand1 được focus - Lưu lại view đã focus
void CCalculatorQNumDlg::OnSetfocusEdtOperand1()
{
	dialogLastFocused = IDC_EDT_OPERAND_1;
}

// Hàm bắt sự kiện khi edtOperand2 được focus - Lưu lại view đã focus
void CCalculatorQNumDlg::OnSetfocusEdtOperand2()
{
	dialogLastFocused = IDC_EDT_OPERAND_2;
}

// Hàm bắt sự kiện khi edit box result thay đổi
void CCalculatorQNumDlg::OnEnChangeEdtResult()
{
	UpdateData();
}

//**** Các hàm bắt sự kiện khi click các số, chữ thích hợp ở các hệ cơ số để đưa vào edit box  - CHÈN KÍ TỰ THÍCH HỢP VÀO EDIT BOX ĐƯỢC FOCUS ****/

void CCalculatorQNumDlg::OnBnClickedBtnA()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('A');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('A');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtnB()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('B');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('B');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtnC()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('C');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('C');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtnD()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('D');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('D');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtnE()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('E');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('E');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtnF()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('F');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('F');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtn9()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('9');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('9');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtn8()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('8');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('8');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtn7()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('7');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('7');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtn6()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('6');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('6');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtn5()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('5');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('5');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtn4()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('4');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('4');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtn3()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('3');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('3');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtn2()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('2');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('2');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtn1()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('1');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('1');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtn0()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('0');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('0');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}


void CCalculatorQNumDlg::OnBnClickedBtnDot()
{
	// Append value in edit text
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.AppendChar('.');
		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.AppendChar('.');
		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}
/******************************************************************************************************************/

// Hàm bắt sự kiện khi click button sign +/-
void CCalculatorQNumDlg::OnBnClickedBtnSign()
{
	if (rdDec.GetCheck() == TRUE)							// Nếu là số ở thập phân thì thêm hoặc bỏ '-' vào trước chuỗi
	{
		if (dialogLastFocused == IDC_EDT_OPERAND_1)
		{
			if (edtOperand1.GetAt(0) != '-')
			{
				edtOperand1.Insert(0, '-');
			}
			else
			{
				edtOperand1.Delete(0);
			}

			GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);

		}

		if (dialogLastFocused == IDC_EDT_OPERAND_2)
		{
			if (edtOperand2.GetAt(0) != '-')
			{
				edtOperand2.Insert(0, '-');
			}
			else
			{
				edtOperand2.Delete(0);
			}

			GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
		}
	}
	else if (rdBin.GetCheck() == TRUE)						// Nếu là số nhị phân
	{
		if (rdQInt.GetCheck() == TRUE)						// Số nguyên QInt thì chuyển về bù 2
		{
			if (dialogLastFocused == IDC_EDT_OPERAND_1)
			{
				string operand1 = CW2A(edtOperand1.GetString());
				QInt temp = QInt::convertToTwoComplement(QInt(operand1, 2));

				edtOperand1.SetString((CString)(QInt::convertQIntToBin(temp).c_str()));

				GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);

			}

			if (dialogLastFocused == IDC_EDT_OPERAND_2)
			{
				string operand2 = CW2A(edtOperand2.GetString());
				QInt temp = QInt::convertToTwoComplement(QInt(operand2, 2));

				edtOperand2.SetString((CString)(QInt::convertQIntToBin(temp).c_str()));

				GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
			}
		}
		else												// Nếu là số thực thì đổi bit dấu 
		{
			if (dialogLastFocused == IDC_EDT_OPERAND_1)
			{
				string operand1 = CW2A(edtOperand1.GetString());
				string temp = QFloat::convertQFloatToBin(QFloat(operand1, 2));
				
				if (temp[0] == '1')
				{
					temp[0] = '0';
				}
				else
				{
					temp[0] = '1';
				}

				edtOperand1.SetString((CString)(temp.c_str()));

				GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);

			}

			if (dialogLastFocused == IDC_EDT_OPERAND_2)
			{
				string operand2 = CW2A(edtOperand2.GetString());
				string temp = QFloat::convertQFloatToBin(QFloat(operand2, 2));

				if (temp[0] == '1')
				{
					temp[0] = 0;
				}
				else
				{
					temp[0] = 1;
				}

				edtOperand1.SetString((CString)(temp.c_str()));

				GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
			}
		}
	}
	else if (rdHex.GetCheck() == TRUE)						// Nếu là số thập lục phân thì chuyển về Bin -> Bù 2 -> Hex
	{
		if (rdQInt.GetCheck() == TRUE)
		{
			if (dialogLastFocused == IDC_EDT_OPERAND_1)
			{
				string operand1 = CW2A(edtOperand1.GetString());
				QInt temp = QInt::convertToTwoComplement(QInt(operand1, 16));

				edtOperand1.SetString((CString)(QInt::convertQIntToHex(temp).c_str()));

				GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);

			}

			if (dialogLastFocused == IDC_EDT_OPERAND_2)
			{
				string operand2 = CW2A(edtOperand2.GetString());
				QInt temp = QInt::convertToTwoComplement(QInt(operand2, 16));

				edtOperand2.SetString((CString)(QInt::convertQIntToHex(temp).c_str()));

				GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
			}
		}
	}
}

// Hàm bắt sự kiện click btnResult(dấu =) - Tính kết quả hoặc convert tương ứng
void CCalculatorQNumDlg::OnBnClickedBtnResult()
{
	// Nếu chế độ file được bật thì thực thi 
	if (rdOn.GetCheck() == TRUE)
	{
		inFile = CW2A (edtOperand1.GetString());
		outFile = CW2A (edtOperand2.GetString());

		GetDlgItem(IDC_EDT_RESULT)->BeginWaitCursor();

		if (executeFile() == TRUE)
		{
			GetDlgItem(IDC_EDT_RESULT)->EndWaitCursor();
			GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"DONE!");
		}
		else
		{
			GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"FAILED!");
		}
	}
	else
	{
		// Kiểm tra tính hợp lệ của Operand 1 và 2
		if (!isValidOp1())
		{
			if (!isValidOp2())
			{
				GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"Input of operand 1 and 2 is invalid!");
				return;
			}
			else
			{
				GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"Input of operand 1 is invalid!");
				return;
			}
		}

		if (!isValidOp2())
		{
			GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"Input of operand 2 is invalid!");
			return;
		}

		// Nếu chưa chọn operator hoặc convert hoặc bitwise thì sẽ thông báo
		if (cbOperator.GetCurSel() == 0 && cbConvert.GetCurSel() == 0 && cbBitwise.GetCurSel() == 0 && rdQInt.GetCheck())
		{
			GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(L"You must choose --operator-- or --converter-- or --bitwise-- to calculate!");
			return;
		}

		try
		{
			// Tính toán hoặc chuyển cơ số tương ứng
			if (!edtOperand1.IsEmpty() && !edtOperand2.IsEmpty() && cbOperator.GetCurSel() != 0)
			{
				calculateResult();
			}
			else if (!edtOperand1.IsEmpty() && ((cbConvert.GetCurSel() != 0 && rdQInt.GetCheck() == TRUE) || rdQFloat.GetCheck() == TRUE))
			{
				convertBaseResult();
			}
			else if (!edtOperand1.IsEmpty() && (!edtOperand2.IsEmpty() || cbBitwise.GetCurSel() == 4) && cbBitwise.GetCurSel() != 0)
			{
				doBitwise();
			}
		}
		catch (const char* msg)
		{
			GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(CString(msg));
		}
	}
}

// Hàm bắt sự kiện click Clear all - Xóa hết dữ liệu ở edit box
void CCalculatorQNumDlg::OnBnClickedBtnCe()
{
	edtOperand1.SetString(L"");
	GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
	edtOperand2.SetString(L"");
	GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	edtResult.SetString(L"");
	GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(edtResult);
}

// Hàm bắt sự kiện khi click Backsapce - Xóa 1 kí tự ở cuối chuỗi ở operand tương ứng
void CCalculatorQNumDlg::OnBnClickedBtnBack()
{
	if (dialogLastFocused == IDC_EDT_OPERAND_1)
	{
		edtOperand1.Delete(edtOperand1.GetLength() - 1);

		GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);

	}

	if (dialogLastFocused == IDC_EDT_OPERAND_2)
	{
		edtOperand2.Delete(edtOperand2.GetLength() - 1);

		GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
	}
}

/**
 *	Hàm enableHexKey - Hàm bật các phím của hệ cơ số 16
 *	@param	 BOOL		TRUE - bật, FALSE - tắt
 *	@return	 none
 */
void CCalculatorQNumDlg::enableHexKey(BOOL isEnable)
{
	btnA.EnableWindow(isEnable);
	btnB.EnableWindow(isEnable);
	btnC.EnableWindow(isEnable);
	btnD.EnableWindow(isEnable);
	btnE.EnableWindow(isEnable);
	btnF.EnableWindow(isEnable);
}

/**
 *	Hàm enableDecKey - Hàm bật các phím của hệ cơ số 10
 *	@param	 BOOL		TRUE - bật, FALSE - tắt
 *	@return	 none
 */
void CCalculatorQNumDlg::enableDecKey(BOOL isEnable)
{
	btn2.EnableWindow(isEnable);
	btn3.EnableWindow(isEnable);
	btn4.EnableWindow(isEnable);
	btn5.EnableWindow(isEnable);
	btn6.EnableWindow(isEnable);
	btn7.EnableWindow(isEnable);
	btn8.EnableWindow(isEnable);
	btn9.EnableWindow(isEnable);
}

/**
 *	Hàm getBase - Hàm lấy hệ cơ số đang chọn
 *	@param	 none
 *	@return	 int		Hệ cơ số đang chọn
 */
int CCalculatorQNumDlg::getBase()
{
	if (rdDec.GetCheck() == TRUE)
	{
		return 10;
	}
	else if (rdBin.GetCheck() == TRUE)
	{
		return 2;
	}
	else if (rdHex.GetCheck() == TRUE)
	{
		return 16;
	}
}

/**
 *	Hàm isValidDecStr - Kiểm tra tính hợp lệ của chuỗi thập phân
 *	@param	 string		Chuỗi thập phân cần kiểm tra
 *	@return	 BOOL		TRUE - hợp lệ, FALSE - không hợp lệ
 */
BOOL CCalculatorQNumDlg::isValidDecStr(string src)
{
	int countDot = 0;
	int countSign = 0;

	for (int i = 0; i < src.size(); i++)
	{
		if (src[i] == '.')								// Nếu chuỗi có dấu '.'
		{
			countDot++;

			if (!rdQFloat.GetCheck() || countDot > 1)	// Và không ở chế độ số thực hoặc số lượng dấu '.' > 1 thì không hợp lệ
			{
				return FALSE;
			}
		}
		else if (src[i] == '-')							// Nếu chuỗi có dấu '-' và > 1 thì không hợp lệ
		{
			countSign++;

			if (countSign > 1)
			{
				return FALSE;
			}
		}
		else if (!('0' <= src[i] && src[i] <= '9'))		// Nếu chuỗi không phải là số thập phân thì không hợp lệ
		{
			return FALSE;
		}
	}

	return TRUE;
}

/**
 *	Hàm isValidBinStr - Kiểm tra tính hợp lệ của chuỗi nhị phân
 *	@param	 string		Chuỗi nhị phân cần kiểm tra
 *	@return	 BOOL		TRUE - hợp lệ, FALSE - không hợp lệ
 */
BOOL CCalculatorQNumDlg::isValidBinStr(string src)
{
	for (int i = 0; i < src.size(); i++)
	{
		if (src[i] != '0' && src[i] != '1')			// Nếu chuỗi có kí tự không phải '0' hoặc '1' thì không hợp lệ
		{
			return FALSE;
		}
	}

	return TRUE;
}

/**
 *	Hàm isValidHexStr - Kiểm tra tính hợp lệ của chuỗi thập lục phân
 *	@param	 string		Chuỗi thập lục phân cần kiểm tra
 *	@return	 BOOL		TRUE - hợp lệ, FALSE - không hợp lệ
 */
BOOL CCalculatorQNumDlg::isValidHexStr(string src)
{
	for (int i = 0; i < src.size(); i++)
	{
		if (toupper(src[i]) == 'A' ||
			toupper(src[i]) == 'B' ||
			toupper(src[i]) == 'C' ||
			toupper(src[i]) == 'D' ||
			toupper(src[i]) == 'E' ||
			toupper(src[i]) == 'F')					// Nếu là các kí tự của hệ 16 thì bỏ qua
		{
			continue;
		}

		if (!('0' <= src[i] && src[i] <= '9'))		// Nếu không phải là số 0-9 thì không hợp lệ
		{
			return FALSE;
		}
	}

	return TRUE;
}

/**
 *	Hàm isValidOp1 - Kiểm tra tính hợp lệ của toán hạng 1 (Operand1)
 *	@param	 none
 *	@return	 BOOL		TRUE - hợp lệ, FALSE - không hợp lệ
 */
BOOL CCalculatorQNumDlg::isValidOp1()
{
	string operand1 = CW2A(edtOperand1.GetString());

	if (rdBin.GetCheck() == TRUE)				// Kiểm tra tính hợp lệ ở từng loại cơ số
	{
		return isValidBinStr(operand1);
	}
	else if (rdDec.GetCheck() == TRUE)
	{
		return isValidDecStr(operand1);
	}
	else if (rdHex.GetCheck() == TRUE)
	{
		return isValidHexStr(operand1);
	}

	return FALSE;
}

/**
 *	Hàm isValidOp2 - Kiểm tra tính hợp lệ của toán hạng 2 (Operand2)
 *	@param	 none
 *	@return	 BOOL		TRUE - hợp lệ, FALSE - không hợp lệ
 */
BOOL CCalculatorQNumDlg::isValidOp2()
{
	string operand2 = CW2A(edtOperand2.GetString());

	if (rdBin.GetCheck() == TRUE)				// Kiểm tra tính hợp lệ ở từng loại cơ số
	{
		return isValidBinStr(operand2);
	}
	else if (rdDec.GetCheck() == TRUE)
	{
		return isValidDecStr(operand2);
	}
	else if (rdHex.GetCheck() == TRUE)
	{
		return isValidHexStr(operand2);
	}

	return FALSE;
}

/**
 *	Hàm calculateResult - Tính toán kết quả + - * / của 2 toán hạng (Operand1 và Operand2) và xuất ra edit box Result
 *	@param	 none
 *	@return	 none		
 */
void CCalculatorQNumDlg::calculateResult()
{
	string operand1 = CW2A (edtOperand1.GetString());
	string operand2 = CW2A (edtOperand2.GetString());
	string result = "";

	if (rdQInt.GetCheck() == TRUE)
	{
		QInt _operand_1;
		QInt _operand_2;
		QInt _result;


		_operand_1.scanQInt(operand1, getBase());		// Chuyển toán hạng về QInt theo hệ cơ số tương ứng
		_operand_2.scanQInt(operand2, getBase());


		switch (cbOperator.GetCurSel())					// Thực hiện tính toán + - * / theo combo box Operator đã chọn
		{
		case 1: // Operator +
			_result = _operand_1 + _operand_2;
			break;
		case 2: // Operator -
			_result = _operand_1 - _operand_2;
			break;
		case 3: // Operator *
			_result = _operand_1 * _operand_2;
			break;
		case 4: // Operator /
			_result = _operand_1 / _operand_2;
			break;
		case 5: // Operator >
			result = (_operand_1 > _operand_2) ? "true" : "false";
			break;
		case 6: // Operator <
			result = (_operand_1 < _operand_2) ? "true" : "false";
			break;
		case 7: // Operator >=
			result = (_operand_1 >= _operand_2) ? "true" : "false";
			break;
		case 8: // Operator <=
			result = (_operand_1 <= _operand_2) ? "true" : "false";
			break;
		case 9: // Operator ==
			result = (_operand_1 == _operand_2) ? "true" : "false";
			break;
		case 10: // Operator !=
			result = (_operand_1 != _operand_2) ? "true" : "false";
			break;
		}

		if (result == "")
		{
			switch (getBase())								// Trả kết quả về hệ cơ số đã chọn
			{
			case 10:
				result = QInt::convertQIntToDec(_result);
				break;
			case 2:
				result = QInt::convertQIntToBin(_result);
				break;
			case 16:
				result = QInt::convertQIntToHex(_result);
				break;
			}
		}

	}

	edtResult = CString(result.c_str());
	GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(edtResult);
}

/**
 *	Hàm convertBaseOperand - Chuyển đổi toán hạng TỪ HỆ CƠ SỐ ĐÃ CHỌN TRƯỚC ĐÓ về hệ cơ số thích hợp và update chúng lên edit box tương ứng
 *	@param	 const int		Hệ cơ số cần chuyển về
 *	@return	 none
 */
void CCalculatorQNumDlg::convertBaseOperand(const int base)
{
	string operand1 = "";
	string operand2 = "";

	if (!edtOperand1.IsEmpty())							// Lấy dữ liệu và chuyển về string
	{
		operand1 = CW2A(edtOperand1.GetString());
	}

	if (!edtOperand2.IsEmpty())
	{
		operand2 = CW2A(edtOperand2.GetString());
	}

	if (rdQInt.GetCheck() == TRUE)						// Nếu Mode đang chọn là số nguyên QInt
	{
		if (radioLastChose == IDC_RD_BIN)				//	Nếu hệ cơ số đã chọn trước đó là Bin thì convertBinTo hệ cơ số còn lại là Dec và Hex
		{
			if (base == 10)
			{
				if (operand1 != "")
				{
					edtOperand1 = CString((QInt::convertQIntToDec(QInt(operand1, 2))).c_str());
					GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
				}

				if (operand2 != "")
				{
					edtOperand2 = CString((QInt::convertQIntToDec(QInt(operand2, 2))).c_str());
					GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
				}
			}
			else if (base == 16)					
			{
				if (operand1 != "")
				{
					edtOperand1 = CString((QInt::convertQIntToHex(QInt(operand1, 2))).c_str());
					GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
				}

				if (operand2 != "")
				{
					edtOperand2 = CString((QInt::convertQIntToHex(QInt(operand2, 2))).c_str());
					GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
				}
			}
		}
		else if (radioLastChose == IDC_RD_DEC)				//	Nếu hệ cơ số đã chọn trước đó là Dec thì convertDecTo hệ cơ số còn lại là Bin và Hex
		{
			if (base == 2)
			{
				if (operand1 != "")
				{
					edtOperand1 = CString((QInt::convertQIntToBin(QInt(operand1, 10))).c_str());
					GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
				}

				if (operand2 != "")
				{
					edtOperand2 = CString((QInt::convertQIntToBin(QInt(operand2, 10))).c_str());
					GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
				}
			}
			else if (base == 16)
			{
				if (operand1 != "")
				{
					edtOperand1 = CString((QInt::convertQIntToHex(QInt(operand1, 10))).c_str());
					GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
				}

				if (operand2 != "")
				{
					edtOperand2 = CString((QInt::convertQIntToHex(QInt(operand2, 10))).c_str());
					GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
				}
			}
		}
		else if (radioLastChose == IDC_RD_HEX)				//	Nếu hệ cơ số đã chọn trước đó là Hex thì convertHexTo hệ cơ số còn lại là Dec và Bin
		{
			if (base == 10)
			{
				if (operand1 != "")
				{
					edtOperand1 = CString((QInt::convertQIntToDec(QInt(operand1, 16))).c_str());
					GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
				}

				if (operand2 != "")
				{
					edtOperand2 = CString((QInt::convertQIntToDec(QInt(operand2, 16))).c_str());
					GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
				}
			}
			else if (base == 2)
			{
				if (operand1 != "")
				{
					edtOperand1 = CString((QInt::convertQIntToBin(QInt(operand1, 16))).c_str());
					GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
				}

				if (operand2 != "")
				{
					edtOperand2 = CString((QInt::convertQIntToBin(QInt(operand2, 16))).c_str());
					GetDlgItem(IDC_EDT_OPERAND_2)->SetWindowTextW(edtOperand2);
				}
			}
		}
	}
	else		// Nếu Mode đang chọn là số thựcQFloat thì chuyển về Dec hoặc Bin vì chỉ có 2 hệ cơ số nên không cần biết hệ cơ số đã chọn trước đó
	{
		if (base == 10)
		{
			if (operand1 != "")
			{
				edtOperand1 = CString((QFloat::convertQFloatToDec(QFloat(operand1, 2))).c_str());
				GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
			}
		}
		else if (base == 2)
		{

			if (operand1 != "")
			{
				edtOperand1 = CString((QFloat::convertQFloatToBin(QFloat(operand1, 10))).c_str());
				GetDlgItem(IDC_EDT_OPERAND_1)->SetWindowTextW(edtOperand1);
			}
		}
	}
}

/**
 *	Hàm convertBaseResult - Chuyển đổi kết quả về hệ cơ số theo Combo Box Convert đã chọn và update lên edit box Result
 *	@param	 none
 *	@return	 none
 */
void CCalculatorQNumDlg::convertBaseResult()
{
	if (rdQInt.GetCheck() == TRUE)												// Nếu mode đang chọn là số nguyên QInt
	{
		if (cbConvert.GetCurSel() != 0)											// Combo box Convert đã được chọn
		{
			if (rdDec.GetCheck() == TRUE)			// Nếu hệ cơ số đang chọn là Dec
			{
				string operand1 = CW2A(edtOperand1.GetString());
				string result;

				if (cbConvert.GetCurSel() == 1)		// Convert Dec to Bin
				{
					result = QInt::convertQIntToBin(QInt(operand1, 10));
				}
				else if (cbConvert.GetCurSel() == 2) // Convêrt Dec to Hex
				{
					result = QInt::convertQIntToHex(QInt(operand1, 10));
				}

				edtResult = CString(result.c_str());
				GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(edtResult);
			}
			else if (rdBin.GetCheck() == TRUE)		// Nếu hệ cơ số đang chọn là Bin
			{
				string operand1 = CW2A(edtOperand1.GetString());
				string result;

				if (cbConvert.GetCurSel() == 1)		// Convert Bin to Dec
				{
					result = QInt::convertQIntToDec(QInt(operand1, 2));
				}
				else if (cbConvert.GetCurSel() == 2) // Convert Bin to Hex
				{
					result = QInt::convertQIntToHex(QInt(operand1, 2));
				}

				edtResult = CString(result.c_str());
				GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(edtResult);
			}
			else if(rdHex.GetCheck() == TRUE)		// Nếu hệ cơ số đang chọn là Hex
			{
				string operand1 = CW2A(edtOperand1.GetString());
				string result;

				if (cbConvert.GetCurSel() == 1)		// Convert Hex to Bin
				{
					result = QInt::convertQIntToBin(QInt(operand1, 16));
				}
				else if (cbConvert.GetCurSel() == 2) // Convert Hex to Dec
				{
					result = QInt::convertQIntToDec(QInt(operand1, 16));
				}

				edtResult = CString(result.c_str());
				GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(edtResult);
			}
		}
	}
	else									// Nếu hệ cơ số đang chọn là số thực QFloat
	{
		if (rdDec.GetCheck() == TRUE)		// Convert Dec to Bin nếu Dec đang chọn
		{
			string operand1 = CW2A(edtOperand1.GetString());
			string result;

			result = QFloat::convertQFloatToBin(QFloat(operand1, 10));

			edtResult = CString(result.c_str());
			GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(edtResult);
		}
		else if (rdBin.GetCheck() == TRUE)	// Convert Bin to Dec nếu Bin đang chọn
		{
			string operand1 = CW2A(edtOperand1.GetString());
			string result;

			result = QFloat::convertQFloatToDec(QFloat(operand1, 2));

			edtResult = CString(result.c_str());
			GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(edtResult);
		}
	}
}

/**
 *	Hàm doBitwise - Thực hiện tính toán các thao tác trên bit từ các toán hạng và update kết quả lên edit box Result
 *	@param	 none
 *	@return	 none
 */
void CCalculatorQNumDlg::doBitwise()
{
	string operand1 = CW2A(edtOperand1.GetString());
	string operand2 = CW2A(edtOperand2.GetString());
	string result;

	if (rdQInt.GetCheck() == TRUE)
	{
		QInt _operand_1;
		QInt _operand_2;
		QInt _result;

		_operand_1.scanQInt(operand1, getBase());			// Chuyển toán hạng về QInt theo hệ cơ số tương ứng
		_operand_2.scanQInt(operand2, getBase());

		switch (cbBitwise.GetCurSel())						// Thực hiện các thao tác AND, OR, XOR, NOT, SHL, SHR, ROL, ROR theo combox box Bitwise đã chọn
		{
		case 1: // AND
			_result = _operand_1 & _operand_2;
			break;
		case 2: // OR
			_result = _operand_1 | _operand_2;
			break;
		case 3: // XOR
			_result = _operand_1 ^ _operand_2;
			break;
		case 4: // NOT
			_result = ~ _operand_2;
			break;
		case 5: // SHL
			_result = _operand_1 << stoi(QInt::convertQIntToDec(_operand_2));
			break;
		case 6: // SHR
			_result = _operand_1 >> stoi(QInt::convertQIntToDec(_operand_2));
			break;
		case 7: // ROL
			_result = _operand_1.rol(stoi(QInt::convertQIntToDec(_operand_2)));
			break;
		case 8: // ROR
			_result = _operand_1.ror(stoi(QInt::convertQIntToDec(_operand_2)));
			break;
		}

		switch (getBase())								// Trả kết quả về hệ cơ số tương ứng
		{
		case 10:
			result = QInt::convertQIntToDec(_result);
			break;
		case 2:
			result = QInt::convertQIntToBin(_result);
			break;
		case 16:
			result = QInt::convertQIntToHex(_result);
			break;
		}
	}

	edtResult = CString(result.c_str());
	GetDlgItem(IDC_EDT_RESULT)->SetWindowTextW(edtResult);
}

/**
 *	Hàm executeQInt - Hàm xử lý số QInt
 *	@param	  string 		Chuỗi cần xử lý
 *	@return	  none
 */
void CCalculatorQNumDlg::executeQInt(string srcQInt)
{
	string p1;
	string p2;
	string firstNum;
	string secondNum;
	string _operator = "";
	stringstream lineProcessing;

	QInt firstQNum;
	QInt secondQNum;
	int base_1;
	int base_2;

	const int uOpSize = 1;
	string uOperator[] = { "~" };																								// Toán tử 1 ngôi
	const int bOpSize = 17;
	string bOperator[] = { "+", "-", "*", "/", "<", ">", "==", "<=", ">=", "=", "&", "|", "^", "<<", ">>", "rol", "ror" };		// Toán tử 2 ngôi

	int operatorType = 0;								// Loại toán tử
	int paramCount = 1;									// Số lượng tham số

	for (int i = 0; i < srcQInt.size(); i++)			// Đếm số lượng tham số dựa vào đếm dấu space
	{
		if (srcQInt[i] == ' ')
		{
			paramCount++;
		}
	}

	for (int i = 0; i < uOpSize; i++)					// Tìm toán tử 1 ngôi có trong mảng quy định
	{
		if (srcQInt.find(uOperator[i], 0) != string::npos)
		{
			operatorType = 1;
			break;
		}
	}

	for (int i = 0; i < bOpSize; i++)					// Tìm toán tử 2 ngôi có trong mảng quy định toán tử nằm giữ 2 khoảng trắng VD: -10 + 30 -> operator +
	{
		int pos = srcQInt.find(bOperator[i], 0);

		if (pos != string::npos)
		{
			if (bOperator[i] == "-")
			{
				if (srcQInt[pos - 1] == ' ' && srcQInt[pos + 1] == ' ')
				{
					operatorType = 2;
					break;
				}
			}
			else
			{
				operatorType = 2;
				break;
			}
		}
	}													// Nếu không có toán tử thì mặc định là 0

	lineProcessing << srcQInt;							// Đọc dữ liệu vào bộ đệm

	lineProcessing >> p1;								// Lấy chỉ thị p1 

	if (paramCount - operatorType == 3)					// Lấy chỉ thị p2 nếu có
	{													// VD: 2 10 1011 -> paramCount(3) - operatorType(0) = 3 -> Có p2
		lineProcessing >> p2;							// VD: 
	}
	else												// Không thì cho p2 và p1 là như nhau tức là 2 nhập vào hệ cơ số X và xuất ra hệ cơ số X
	{
		p2 = p1;
	}

	switch (operatorType)								// Kiểm tra loại toán tử
	{
	case 0:												// Không có toán tử -> Lấy số đầu để chuyển cơ số
		lineProcessing >> firstNum;
		break;
	case 1:												// Toán tử 1 ngôi -> lấy toán tử rồi đến số cần tính
		lineProcessing >> _operator >> firstNum;
		break;
	case 2:												// Toán tử 2 ngôi -> lấy số đầu > toán tử > số sau
		lineProcessing >> firstNum >> _operator >> secondNum;
		break;
	}

	base_1 = stoi(p1);									// Chuyển đổi p1, p2 sang số nguyên
	base_2 = stoi(p2);

	try
	{
		firstQNum.scanQInt(firstNum, base_1);

		if (_operator == "")							// Chuyển đổi cơ số và xuất ra
		{
			firstQNum.printQInt(base_2);
		}
		else if (_operator == "~")						// Tính NOT bit và xuất ra
		{
			(~firstQNum).printQInt(base_2);
		}
		else if (_operator == "+")						// Tính + và xuất kết quả
		{
			secondQNum.scanQInt(secondNum, base_1);
			(firstQNum + secondQNum).printQInt(base_2);
		}
		else if (_operator == "-")						// Tính - và xuất kết quả
		{
			secondQNum.scanQInt(secondNum, base_1);
			(firstQNum - secondQNum).printQInt(base_2);
		}
		else if (_operator == "*")						// Tính * và xuất kết quả
		{
			secondQNum.scanQInt(secondNum, base_1);
			(firstQNum * secondQNum).printQInt(base_2);
		}
		else if (_operator == "/")						// Tính / và xuất kết quả
		{
			secondQNum.scanQInt(secondNum, base_1);
			(firstQNum / secondQNum).printQInt(base_2);
		}
		else if (_operator == "<")						// So sánh < và xuất kết quả
		{
			secondQNum.scanQInt(secondNum, base_1);
			cout << ((firstQNum < secondQNum) ? "true" : "false") << endl;
		}
		else if (_operator == ">")						// So sánh > và xuất kết quả
		{
			secondQNum.scanQInt(secondNum, base_1);
			cout << ((firstQNum > secondQNum) ? "true" : "false") << endl;
		}
		else if (_operator == "<=")						// So sánh <= và xuất kết quả
		{
			secondQNum.scanQInt(secondNum, base_1);
			cout << ((firstQNum <= secondQNum) ? "true" : "false") << endl;
		}
		else if (_operator == ">=")						// So sánh >= và xuất kết quả
		{
			secondQNum.scanQInt(secondNum, base_1);
			cout << ((firstQNum >= secondQNum) ? "true" : "false") << endl;
		}
		else if (_operator == "==")						// So sánh == và xuất kết quả
		{
			secondQNum.scanQInt(secondNum, base_1);
			cout << ((firstQNum == secondQNum) ? "true" : "false") << endl;
		}
		else if (_operator == "&")						// Tính AND bit và xuất ra kết quả
		{
			secondQNum.scanQInt(secondNum, base_1);
			(firstQNum & secondQNum).printQInt(base_2);
		}
		else if (_operator == "|")						// Tính OR bit và xuất ra kết quả
		{
			secondQNum.scanQInt(secondNum, base_1);
			(firstQNum | secondQNum).printQInt(base_2);
		}
		else if (_operator == "^")						// Tính XOR bit và xuất ra kết quả
		{
			secondQNum.scanQInt(secondNum, base_1);
			(firstQNum ^ secondQNum).printQInt(base_2);
		}
		else if (_operator == "<<")						// Tính SHL bit và xuất ra kết quả
		{
			int num = stoi(secondNum);
			(firstQNum << num).printQInt(base_2);
		}
		else if (_operator == ">>")						// Tính SHR bit và xuất ra kết quả
		{
			int num = stoi(secondNum);
			(firstQNum >> num).printQInt(base_2);
		}
		else if (_operator == "rol")					// Tính ROL bit và xuất ra kết quả
		{
			int num = stoi(secondNum);
			(firstQNum.rol(num)).printQInt(base_2);
		}
		else if (_operator == "ror")					// Tính ROR bit và xuất ra kết quả
		{
			int num = stoi(secondNum);
			(firstQNum.ror(num)).printQInt(base_2);
		}
	}
	catch (const char* msg)
	{
		cout << msg;
	}
}

/**
 *	Hàm executeQFloat - Hàm xử lý số QFloat
 *	@param	  string 		Chuỗi cần xử lý
 *	@return	  none
 */
void CCalculatorQNumDlg::executeQFloat(string srcQFloat)
{
	string p1;
	string p2;
	string convertedNum;
	stringstream ssIn;

	QFloat destNum;

	int base_1;
	int base_2;

	ssIn << srcQFloat;								// Lấy dữ liệu cần xử lí

	ssIn >> p1 >> p2 >> convertedNum;				// Tách 3 thành phần 

	base_1 = stoi(p1);								// Chuyển p1, p2 sang số nguyên
	base_2 = stoi(p2);

	try
	{
		destNum.scanQFloat(convertedNum, base_1);	// Chuyển cơ số và xuất ra
		destNum.printQFloat(base_2);
	}
	catch (const char* msg)
	{
		cout << msg;
	}
}

/**
 *	Hàm executeQFloat - Hàm xử lý số File theo QInt hoặc QFloat
 *	@param	  none
 *	@return	  none
 */
BOOL CCalculatorQNumDlg::executeFile()
{
	FILE* input = freopen(inFile.c_str(), "r", stdin);
	FILE* output = freopen(outFile.c_str(), "w", stdout);

	if (input && output)
	{
		cin.seekg(SEEK_SET);

		if (rdQInt.GetCheck() == TRUE)
		{
			while (!cin.eof())
			{
				string srcQInt;
				getline(cin, srcQInt);
				executeQInt(srcQInt);
			}
		}

		if (rdQFloat.GetCheck() == TRUE)
		{
			while (!cin.eof())
			{
				string strIn;
				getline(cin, strIn);
				executeQFloat(strIn);
			}
		}

		fclose(input);
		fclose(output);

		return TRUE;
	}

	return FALSE;
}
