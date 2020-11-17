// UnitTool.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "UnitTool.h"
#include "afxdialogex.h"


// CUnitTool 대화 상자입니다.

IMPLEMENT_DYNAMIC(CUnitTool, CDialog)

CUnitTool::CUnitTool(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_UNITTOOL, pParent)
	, m_strData1(_T(""))
	, m_strData2(_T(""))
	, m_strName(_T(""))
	, m_iAtt(0)
	, m_iDef(0)
	, m_strFindName(_T(""))
{
}

CUnitTool::~CUnitTool()
{
	for (auto& rPair : m_mapUnitData)
		Safe_Delete(rPair.second); 
	m_mapUnitData.clear(); 
}

void CUnitTool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strData1);
	DDX_Text(pDX, IDC_EDIT2, m_strData2);
	DDX_Text(pDX, IDC_EDIT3, m_strName);
	DDX_Text(pDX, IDC_EDIT4, m_iAtt);
	DDX_Text(pDX, IDC_EDIT5, m_iDef);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_RADIO1, m_JopIndex[0]);
	DDX_Control(pDX, IDC_RADIO2, m_JopIndex[1]);
	DDX_Control(pDX, IDC_RADIO3, m_JopIndex[2]);

	DDX_Control(pDX, IDC_CHECK1, m_CheckBox[0]);
	DDX_Control(pDX, IDC_CHECK2, m_CheckBox[1]);
	DDX_Control(pDX, IDC_CHECK3, m_CheckBox[2]);

	DDX_Text(pDX, IDC_EDIT6, m_strFindName);
}


BEGIN_MESSAGE_MAP(CUnitTool, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CUnitTool::OnBnClickedPush)
	ON_BN_CLICKED(IDC_BUTTON2, &CUnitTool::OnBnClickedAddUnitData)
	ON_LBN_SELCHANGE(IDC_LIST1, &CUnitTool::OnLbnSelChangeClass)
	ON_BN_CLICKED(IDC_BUTTON3, &CUnitTool::OnBnClickedDelect)
	ON_EN_CHANGE(IDC_EDIT6, &CUnitTool::OnEnChangeFindName)
	ON_BN_CLICKED(IDC_BUTTON4, &CUnitTool::OnBnClickedSave)
	ON_BN_CLICKED(IDC_BUTTON5, &CUnitTool::OnBnClickedLoad)
END_MESSAGE_MAP()


// CUnitTool 메시지 처리기입니다.


void CUnitTool::OnBnClickedPush()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); 
	m_strData2 = m_strData1; 
	UpdateData(FALSE); 
}


void CUnitTool::OnBnClickedAddUnitData()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); 
	UNITINFO* pUnit = new UNITINFO; 

	pUnit->strName = m_strName; 
	pUnit->iAtt = m_iAtt; 
	pUnit->iDef = m_iDef; 
	pUnit->byItem = 0; 
	pUnit->byJopIndex = 0; 
	for (int i = 0 ; i < 3 ; ++i)
	{
		if (m_JopIndex[i].GetCheck())
		{
			pUnit->byJopIndex = i;
			break; 
		}
	}
	// 0000 0000 
	// 0000 0001 |
	// 0000 0001

	if (m_CheckBox[0].GetCheck())
		pUnit->byItem |= 강철검; 
	if (m_CheckBox[1].GetCheck())
		pUnit->byItem |= 지팡이;
	if (m_CheckBox[2].GetCheck())
		pUnit->byItem |= 나이프;

	m_ListBox.AddString(m_strName.GetString()); 
	m_mapUnitData.emplace(pUnit->strName, pUnit); 
	UpdateData(FALSE); 

}


void CUnitTool::OnLbnSelChangeClass()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); 
	for (int i = 0; i < 3; ++i)
	{
		m_CheckBox[i].SetCheck(0);
		m_JopIndex[i].SetCheck(0);
	}

	CString strName = L""; 
	int iSelectIndex = m_ListBox.GetCurSel();
	if (-1 == iSelectIndex)
		return; 

	m_ListBox.GetText(iSelectIndex, strName); 

	auto& iter_find = m_mapUnitData.find(strName); 
	if (m_mapUnitData.end() == iter_find)
		return; 

	m_strName = iter_find->second->strName; 
	m_iAtt = iter_find->second->iAtt; 
	m_iDef = iter_find->second->iDef; 
	m_JopIndex[iter_find->second->byJopIndex].SetCheck(1); 

	// 0000 0011
	// 0000 0001 &
	// 0000 0001

	if (iter_find->second->byItem & 강철검)
		m_CheckBox[0].SetCheck(1); 
	if (iter_find->second->byItem & 지팡이)
		m_CheckBox[1].SetCheck(1); 
	if (iter_find->second->byItem & 나이프)
		m_CheckBox[2].SetCheck(1); 

	UpdateData(FALSE); 
}


BOOL CUnitTool::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_JopIndex[0].SetCheck(1);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CUnitTool::OnBnClickedDelect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); 
	CString strName = L""; 

	int iSelect = m_ListBox.GetCurSel(); 
	m_ListBox.GetText(iSelect, strName); 

	auto& iter_find = m_mapUnitData.find(strName); 

	if (m_mapUnitData.end() == iter_find)
		return; 

	Safe_Delete(iter_find->second);
	m_mapUnitData.erase(strName); 
	m_ListBox.DeleteString(iSelect); 

	UpdateData(FALSE); 
}


void CUnitTool::OnEnChangeFindName()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	UpdateData(TRUE); 
	for (int i = 0 ; i < 3 ; ++i)
	{
		m_JopIndex[i].SetCheck(0); 
		m_CheckBox[i].SetCheck(0); 
	}
	map<CString, UNITINFO*>::iterator& iter_find = m_mapUnitData.find(m_strFindName);

	if (m_mapUnitData.end() == iter_find)
		return; 

	int iIndex = m_ListBox.FindString(0, m_strFindName); 

	if (LB_ERR == iIndex)
		return; 

	m_ListBox.SetCurSel(iIndex); 
	m_strName = m_strFindName; 
	m_iAtt = iter_find->second->iAtt; 
	m_iDef = iter_find->second->iDef; 
	m_JopIndex[iter_find->second->byJopIndex].SetCheck(1); 

	if (iter_find->second->byItem & 강철검)
		m_CheckBox[0].SetCheck(1); 
	if (iter_find->second->byItem & 지팡이)
		m_CheckBox[1].SetCheck(1);
	if (iter_find->second->byItem & 나이프)
		m_CheckBox[2].SetCheck(1);
	UpdateData(FALSE); 
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CUnitTool::OnBnClickedSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog Dlg(FALSE,L"dat", L"*.dat", OFN_HIDEREADONLY| OFN_OVERWRITEPROMPT,L"Data File(*.dat) | *.dat||", this);
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
		DWORD dwByte = 0; 
		DWORD dwstrByte = 0; 
		for (auto& rPair : m_mapUnitData)
		{
			dwstrByte = sizeof(TCHAR) * (rPair.first.GetLength() + 1);
			WriteFile(hFile, &dwstrByte, sizeof(DWORD), &dwByte, nullptr); 
			WriteFile(hFile, rPair.first.GetString(), dwstrByte, &dwByte, nullptr); 
			WriteFile(hFile, &rPair.second->iAtt, sizeof(rPair.second->iAtt), &dwByte, nullptr);
			WriteFile(hFile, &rPair.second->iDef, sizeof(rPair.second->iDef), &dwByte, nullptr);
			WriteFile(hFile, &rPair.second->byJopIndex, sizeof(rPair.second->byJopIndex), &dwByte, nullptr);
			WriteFile(hFile, &rPair.second->byItem, sizeof(rPair.second->byItem), &dwByte, nullptr);

			
		}
		CloseHandle(hFile);
	}
}


void CUnitTool::OnBnClickedLoad()
{
	UpdateData(TRUE); 
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog Dlg(TRUE, L"dat", L"*.dat", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"Data File(*.dat) | *.dat||", this);
	TCHAR szCurPath[MAX_PATH] = L"";
	TCHAR szDataPath[MAX_PATH] = L"";
	GetCurrentDirectory(MAX_PATH, szCurPath);
	PathRemoveFileSpec(szCurPath);
	PathCombine(szDataPath, szCurPath, L"Data");
	Dlg.m_ofn.lpstrInitialDir = szDataPath;
	if (IDOK == Dlg.DoModal())
	{
		CString strPath = Dlg.GetPathName();
		HANDLE hFile = CreateFile(strPath.GetString(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

		if (INVALID_HANDLE_VALUE == hFile)
			return;
		DWORD dwByte = 0;
		DWORD dwstrByte = 0;
		UNITINFO* pUnit = nullptr; 
		while (true)
		{
			ReadFile(hFile, &dwstrByte, sizeof(DWORD), &dwByte, nullptr);
			TCHAR* szName = new TCHAR[dwstrByte];
			pUnit = new UNITINFO; 
			ReadFile(hFile, szName, dwstrByte, &dwByte, nullptr);
			pUnit->strName = szName; 
			Safe_Delete_Array(szName); 

			ReadFile(hFile, &pUnit->iAtt, sizeof(pUnit->iAtt), &dwByte, nullptr);
			ReadFile(hFile, &pUnit->iDef, sizeof(pUnit->iDef), &dwByte, nullptr);
			ReadFile(hFile, &pUnit->byJopIndex, sizeof(pUnit->byJopIndex), &dwByte, nullptr);
			ReadFile(hFile, &pUnit->byItem, sizeof(pUnit->byItem), &dwByte, nullptr);
			if (0 == dwByte)
			{
				Safe_Delete(pUnit); 
				break; 
			}
			m_mapUnitData.emplace(pUnit->strName, pUnit); 
			for (int i = 0; i < 3; ++i)
			{
				m_JopIndex[i].SetCheck(0);
				m_CheckBox[i].SetCheck(0);
			}

			m_ListBox.AddString(pUnit->strName); 
			m_iAtt = pUnit->iAtt;
			m_iDef = pUnit->iDef;
			m_JopIndex[pUnit->byJopIndex].SetCheck(1);

			if (pUnit->byItem & 강철검)
				m_CheckBox[0].SetCheck(1);
			if (pUnit->byItem & 지팡이)
				m_CheckBox[1].SetCheck(1);
			if (pUnit->byItem & 나이프)
				m_CheckBox[2].SetCheck(1);

		}
		CloseHandle(hFile);
	}
	UpdateData(FALSE); 
}
