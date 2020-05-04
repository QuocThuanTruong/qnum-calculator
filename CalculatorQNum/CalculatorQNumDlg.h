
// CalculatorQNumDlg.h : header file
//
#include "QInt.h"
#include "QFloat.h"
#include <string>
#include <vector>
#include <thread>
using namespace std;

#pragma once


// CCalculatorQNumDlg dialog
class CCalculatorQNumDlg : public CDialogEx
{
// Construction
public:
	CCalculatorQNumDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATORQNUM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnOK();
public:
	afx_msg void OnBnClickedRdQint();
	afx_msg void OnBnClickedRdQfloat();
	afx_msg void OnBnClickedRdDec();
	afx_msg void OnBnClickedRdBin();
	afx_msg void OnBnClickedRdHex();
	afx_msg void OnEnChangeEdtOperand1();
	afx_msg void OnCbnSelchangeCbOperator();
	afx_msg void OnCbnSelchangeCbConvert();
	afx_msg void OnCbnSelchangeCbBitwise();
	afx_msg void OnEnChangeEdtOperand2();
	afx_msg void OnEnChangeEdtResult();
	afx_msg void OnBnClickedBtnA();
	afx_msg void OnBnClickedBtnB();
	afx_msg void OnBnClickedBtnC();
	afx_msg void OnBnClickedBtnD();
	afx_msg void OnBnClickedBtnE();
	afx_msg void OnBnClickedBtnF();
	afx_msg void OnBnClickedBtn9();
	afx_msg void OnBnClickedBtn8();
	afx_msg void OnBnClickedBtn7();
	afx_msg void OnBnClickedBtn6();
	afx_msg void OnBnClickedBtn5();
	afx_msg void OnBnClickedBtn4();
	afx_msg void OnBnClickedBtn3();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn0();
	afx_msg void OnBnClickedBtnDot();
	afx_msg void OnBnClickedBtnSign();
	afx_msg void OnBnClickedBtnResult();
	afx_msg void OnBnClickedBtnCe();
	afx_msg void OnBnClickedBtnBack();
	afx_msg void OnSetfocusEdtOperand1();
	afx_msg void OnSetfocusEdtOperand2();
private:
	CButton rdQInt;
	CButton rdQFloat;
	CButton rdDec;
	CButton rdBin;
	CButton rdHex;
private:
	CString edtOperand1;
	CString edtOperand2;
	CString edtResult;
	CComboBox cbOperator;
	CComboBox cbConvert;
	CComboBox cbBitwise;
private:
	CButton btnA;
	CButton btnB;
	CButton btnC;
	CButton btnD;
	CButton btnE;
	CButton btnF;
	CButton btn9;
	CButton btn8;
	CButton btn7;
	CButton btn6;
	CButton btn5;
	CButton btn4;
	CButton btn3;
	CButton btn2;
	CButton btn1;
	CButton btn0;
	CButton btnSign;
	CButton btnDot;
	CButton btnResult;
	CButton btnCE;
	CButton btnBack;
private:
	int dialogLastFocused;
	int radioLastChose;
	int cbConvertLastChose;
	int cbOperatorLastChoose;
	int cbBitwiseLastChoose;
private:
	void enableHexKey(BOOL isEnable = TRUE);
	void enableDecKey(BOOL isEnable = TRUE);
	int getBase();
	BOOL isValidDecStr(string src);
	BOOL isValidBinStr(string src);
	BOOL isValidHexStr(string src);
private:
	BOOL isValidOp1();
	BOOL isValidOp2();
	void calculateResult();	
	void convertBaseOperand(const int base);
	void convertBaseResult();
	void doBitwise();
};
