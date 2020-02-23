#include "DriveName.h"
#include <Windows.h>
#include <iostream>
#include <locale>
#include <codecvt>

using std::wcout;
using std::endl;

// #pragma comment(lib, "windows.lib")

std::wstring s2ws(const std::string& str)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.from_bytes(str);
}

std::string ws2s(const std::wstring& wstr)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.to_bytes(wstr);
}

std::string drivename::getDriveName(std::string driveMountPoint) 
{
	std::string result = "";
	std::wstring wDriveMountPoint = s2ws(driveMountPoint);
	WCHAR szVolumeName[MAX_PATH];

	BOOL bSucceeded = GetVolumeInformationW(wDriveMountPoint.c_str(),
											szVolumeName,
											MAX_PATH,
											NULL,
											NULL,
											NULL,
											NULL,
											0);

	if (bSucceeded) 
	{
		result = ws2s(szVolumeName);
	}

    return result;
}
