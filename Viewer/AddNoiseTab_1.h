#pragma once


// CAddNoiseTab_1 dialog

class CAddNoiseTab_1 : public CDialogEx
{
	DECLARE_DYNAMIC(CAddNoiseTab_1)

public:
	CAddNoiseTab_1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CAddNoiseTab_1();
	CEdit Edit_GN_Mean;
	CEdit Edit_GN_Stdev;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDNOISE_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
