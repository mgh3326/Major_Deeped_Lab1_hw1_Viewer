
// ViewerDlg.h : header file
//
#include <opencv2\opencv.hpp>
#include "RawInfoDlg.h"
#include "ImgScalingDlg.h"
#include "RotationDlg.h"
#include "FilterDlg.h"
using namespace cv;
#pragma once


// CViewerDlg dialog
class CViewerDlg : public CDialogEx
{
	// Construction
public:
	CViewerDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIEWER_DIALOG };
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
	enum ImageFormat
	{
		FORMAT_RGB,
		FORMAT_YUV444,
		FORMAT_YUV420,
		FORMAT_GRAY
	};
private:
	unsigned char **ch_in_1, **ch_in_2, **ch_in_3;
	unsigned char **ch_in_gray, **ch_in_gray2;
	int* Hist;

	int nHeight_in, nWidth_in;
	int nFormat;
	bool isImageOpened;
	//, isLeftImg = true;	//왼쪽 오른쪽 사진 구분하기 위해

public:
	CStatic m_PicOri;
	CStatic m_PicProc;
	CRawInfoDlg RawInfoDlg;
	CImgScalingDlg ImgScalingDlg;
	CRotationDlg RotationDlg;
	enum InterpolationType {
		BILINEAR,
		BICUBIC
	};
	Mat Ori_Img, Proc_Img;
	CRect rect;
	CDC* m_pDC;
	/*unsigned char ** GrayImg;*/
	enum FilterType {
		FILTER_AVERAGE,
		FILTER_SMOOTH,
		FILTER_SHARPEN,
		FILTER_GAUSSIAN
	};


	void DisplayImage(Mat DispMat, bool blnOut);
	void DisplayBitmap(CDC* pDC, CRect rect, IplImage* DispIplImage);
	void ResizeImage(IplImage* src, IplImage** dst, CRect* rect);
	afx_msg void OnFileOpenBtnClick();
	afx_msg void OnCloseMenuClick();
	afx_msg void OnConvertgayBtnClick();

	afx_msg void OnEditScalingClick();
	afx_msg void OnEditRotationClick();
	afx_msg void OnHistogramGetClick();
	afx_msg void OnHistogramEqualizationClicked();
	afx_msg void OnHistogramMatchingClicked();
	afx_msg void OnEditFilterClicked();


	unsigned char** Padding(unsigned char** In, int nHeight, int nWidth, int nFilterSize);
	void AverageFilter(unsigned char** In_Pad, unsigned char** Out, int nHeight, int nWidth, int nFilterSize);
	void SmoothFilter(unsigned char** In_Pad, unsigned char** Out, int nHeight, int nWidth);
	void SharpenFilter(unsigned char** In_Pad, unsigned char** Out, int nHeight, int nWidth);
	void GaussianFilter(unsigned char** In_Pad, unsigned char** Out, int nHeight, int nWidth);


};

unsigned char** MemAlloc2D(int nHeight, int nWidth, unsigned char nInitVal);
//double ** MemAllocDouble2D(int nHeight, int nWidth, unsigned char nInitVal);
void MemFree2D(unsigned char** Mem, int nHeight);
bool isInsideBoundary(int nHeight, int nWidth, double h, double w);
unsigned char BilinearInterpolation(unsigned char** In, int nHeight_Ori, int nWidth_Ori, double h_Cvt, double W_Cvt);
unsigned char BicubicInterpolation(unsigned char** In, int nHeight_Ori, int nWidth_Ori, double h_Cvt, double W_Cvt);
void DisplayHistogram(int *Hist);
unsigned char** MemAlloc2D(int nHeight, int nWidth, unsigned char nInitVal);
