#pragma once


// CAddNoiseTab_2 dialog

class CAddNoiseTab_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CAddNoiseTab_2)

public:
	CAddNoiseTab_2(CWnd* pParent = nullptr); // standard constructor
	virtual ~CAddNoiseTab_2();
	CEdit Edit_SN_Prob;
	CEdit Edit_PN_Prob;

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDNOISE_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
