#include "stdafx.h"

#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	auto scHandle = ::OpenSCManager(nullptr, nullptr, SC_MANAGER_CONNECT);
	auto simpleServiceHandle = ::OpenService(scHandle, L"SimpleService", SERVICE_USER_DEFINED_CONTROL);

	SERVICE_STATUS serviceStatus = { 0 };
	BOOL result = ::ControlService(simpleServiceHandle, 666, &serviceStatus);
	::CloseServiceHandle(scHandle);
	::CloseServiceHandle(simpleServiceHandle);

	if (!result)
	{
		return 1;
	}
	return 0;
}

