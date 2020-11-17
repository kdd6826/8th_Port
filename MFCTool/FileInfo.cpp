#include "stdafx.h"
#include "FileInfo.h"


CFileInfo::CFileInfo()
{
}


CFileInfo::~CFileInfo()
{
}

CString CFileInfo::ConvertRelativePath(const CString & strAbsolutePath)
{
	TCHAR szRelativePath[MAX_PATH] = L""; 
	TCHAR szCurDirectory[MAX_PATH] = L""; 
	GetCurrentDirectory(MAX_PATH, szCurDirectory);
	PathRelativePathTo(szRelativePath, szCurDirectory, FILE_ATTRIBUTE_DIRECTORY, strAbsolutePath, FILE_ATTRIBUTE_DIRECTORY); 

	return CString(szRelativePath);
}
