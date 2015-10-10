#include <iostream>
#include <Windows.h>
using namespace std;

extern "C" __declspec(dllexport) BOOL APIENTRY DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
			// attach to process, return FALSE to fail
			break;

		case DLL_PROCESS_DETACH:
			// detaching from process
			break;

		case DLL_THREAD_ATTACH:
			// attach to thread within process
			break;

		case DLL_THREAD_DETACH:
			// detach from thread within process
			break;
	}

	// return success
	return true;
}