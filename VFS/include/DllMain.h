#ifndef __DLLMAIN_H__
# define __DLLMAIN_H__

# include <iostream>


static void loadDLL();
static void unloadDLL();

# if defined(_MSC_VER) && defined(DANUDLL)

#  include <windows.h>

extern "C" BOOL APIENTRY DllMain(	HINSTANCE anInstance, 	// handle to DLL module
									DWORD aReason, 			// reason for calling function
									LPVOID aReserved )		// Not used
{
	std::cout << "+ DllMain" << std::endl;

	switch(aReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			loadDLL();
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			unloadDLL();
			break;
		}
    }
	std::cout << "- DllMain" << std::endl;
    return TRUE;
}
# else //  linux and GCC on Windows

	static void _init() __attribute__((constructor));
	static void _fini() __attribute__((destructor));

  	static void _init()
	{
		std::cout << "+ _init" << std::endl;
		loadDLL();
		std::cout << "- _init" << std::endl;
	}

	static void _fini()
	{
		std::cout << "+ _fini" << std::endl;
		unloadDLL();
		std::cout << "- _fini" << std::endl;
	}
# endif // WIN32

#endif // DllMain_hpp
