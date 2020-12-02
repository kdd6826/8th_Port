#pragma once

template<class T>
void Safe_Delete(T& rObj)
{
	if (rObj)
	{
		delete rObj; 
		rObj = nullptr; 
	}
}
template<class T>
void Safe_Delete_Array(T& rObj)
{
	if (rObj)
	{
		delete[] rObj;
		rObj = nullptr;
	}
}
template<class T>
void Safe_Release(T& rObj)
{
	if (rObj)
		rObj->Release(); 
}

////CCW 알고리즘으로 시계방향 체크
//int CCW(D3DXVECTOR3 vec1, D3DXVECTOR3 vec2, D3DXVECTOR3 vec3)
//{
//	float temp1 = (vec2.z - vec1.z)*(vec3.x - vec1.x) + vec1.z*(vec2.x - vec1.x);
//	float temp2 = (vec2.x - vec1.x)*vec3.z;
//
//	
//	if (temp1 < temp2)//반시계
//		return 1;
//	else if (temp1 > temp2)//시계
//		return -1;
//	else //일직선
//		return 0;
//}


namespace Client
{
	template <typename T>
	DWORD Safe_Release(T& pointer)
	{
		DWORD	dwRefCnt = 0;
		if (NULL != pointer)
		{
			dwRefCnt = pointer->Release();

			if (dwRefCnt == 0)
				pointer = NULL;
		}
		return dwRefCnt;
	}

	template <typename T>
	DWORD Safe_Release_Delete(T& pointer)
	{
		DWORD	dwRefCnt = 0;
		if (NULL != pointer)
		{
			dwRefCnt = pointer->Release();
			if (dwRefCnt == 0)
			{
				delete pointer;
				pointer = NULL;
			}
		}
		return dwRefCnt;
	}

	template <typename T>
	void Safe_Single_Destory(T& pointer)
	{
		if (NULL != pointer)
		{
			pointer->DestroyInstance();
			pointer = NULL;
		}
	}

	template <typename T>
	void Safe_Delete(T& pointer)
	{
		if (NULL != pointer)
		{
			delete pointer;
			pointer = NULL;
		}
	}

	template <typename T>
	void Safe_Delete_Array(T& pointer)
	{
		if (NULL != pointer)
		{
			delete[] pointer;
			pointer = NULL;
		}
	}


}