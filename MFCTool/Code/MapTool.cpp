// MapTool.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "MapTool.h"
#include "afxdialogex.h"
#include "FileInfo.h"
#include "Texture_Manager.h"
#include "MainFrm.h"
#include "MFCToolView.h"
#include "Terrain.h"

USING(Client)

// CMapTool 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMapTool, CDialog)

CMapTool::CMapTool(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MAPTOOL, pParent)
{
	m_iDrawID = 0; 
}

CMapTool::~CMapTool()
{
}

void CMapTool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_PICTURE, m_Picture);
}


BEGIN_MESSAGE_MAP(CMapTool, CDialog)
	ON_WM_DROPFILES()
	ON_LBN_SELCHANGE(IDC_LIST1, &CMapTool::OnLbnSelchangePicture)
	ON_BN_CLICKED(IDC_BUTTON1, &CMapTool::OnBnClickedNaviSave)
END_MESSAGE_MAP()


// CMapTool 메시지 처리기입니다.


void CMapTool::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDialog::OnDropFiles(hDropInfo);
	UpdateData(TRUE); 
	_uint iCount = DragQueryFile(hDropInfo, 0xffffffff, nullptr, 0);// 1이 32
	TCHAR szFilePath[MAX_PATH] = L""; 
	CString strRelativePath = L""; 
	TCHAR szFileName[MAX_PATH] = L""; 
	for (_uint i = 0 ; i < iCount; ++i)
	{
		DragQueryFile(hDropInfo, i, szFilePath, MAX_PATH);
		strRelativePath = CFileInfo::ConvertRelativePath(szFilePath);
		CString strFileNameAndExtension = PathFindFileName(strRelativePath);
		lstrcpy(szFileName, strFileNameAndExtension.GetString()); 
		PathRemoveExtension(szFileName);
		m_ListBox.AddString(szFileName);
	}
	HorizontalScroll(); 
	UpdateData(FALSE); 
}

void CMapTool::HorizontalScroll()
{
	CString strName; 
	CSize tSize; 
	_int iCX = 0; 

	CDC* pDC = m_ListBox.GetDC();

	for (int i = 0 ; i < m_ListBox.GetCount(); ++i)
	{
		m_ListBox.GetText(i, strName); 
		tSize = pDC->GetTextExtent(strName);

		if (tSize.cx > iCX)
			iCX = tSize.cx; 
	}
	m_ListBox.ReleaseDC(pDC);

	if (m_ListBox.GetHorizontalExtent() < iCX)
		m_ListBox.SetHorizontalExtent(iCX); 

}


void CMapTool::OnLbnSelchangePicture()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString strFileName = L""; 
	_int iIndex = m_ListBox.GetCurSel(); 

	m_ListBox.GetText(iIndex, strFileName); 
	int i = 0;
	for (; i < strFileName.GetLength(); ++i)
	{
		if(isdigit(strFileName[i]))
			break;
	}
	strFileName.Delete(0, i);
	m_iDrawID = _ttoi(strFileName.GetString());
	
	const TEXINFO* pTexInfo = CTexture_Manager::GetInstance()->Get_TexInfo(L"Terrain", L"Tile", m_iDrawID);
	if (nullptr == pTexInfo)
		return; 
	float fCenterX = pTexInfo->tImageInfo.Width >> 1; 
	float fCenterY = pTexInfo->tImageInfo.Height >> 1; 

	_matrix matScale, matTrans, matWorld; 
	_float fRatioX = WINCX / float(TILECX); 
	_float fRatioY = WINCY / float(TILECY);
	D3DXMatrixScaling(&matScale,fRatioX, fRatioY , 0.f);
	D3DXMatrixTranslation(&matTrans, float(WINCX >> 1), float(WINCY >> 1), 0.f); 
	matWorld = matScale * matTrans; 


	UpdateData(FALSE);
}


void CMapTool::OnBnClickedNaviSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog Dlg(FALSE, L"dat", L"*.dat", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"Data File(*.dat) | *.dat||", this);
	TCHAR szCurPath[MAX_PATH] = L"";
	TCHAR szDataPath[MAX_PATH] = L"";
	GetCurrentDirectory(MAX_PATH, szCurPath);
	PathRemoveFileSpec(szCurPath);
	PathCombine(szDataPath, szCurPath, L"Data");
	Dlg.m_ofn.lpstrInitialDir = szDataPath;
	if (IDOK == Dlg.DoModal())
	{
		CString strPath = Dlg.GetPathName();
		HANDLE hFile = CreateFile(strPath.GetString(), GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

		if (INVALID_HANDLE_VALUE == hFile)
			return;
		CMainFrame* pMain = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
		CMFCToolView* pView = dynamic_cast<CMFCToolView*>(pMain->m_MainSplitter.GetPane(0, 1)); 

		CloseHandle(hFile);
	}
}
