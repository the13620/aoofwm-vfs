#include <iostream>
#include <string>

#include "test.h"

#include "VFS/VFS.h"
#include "VFS/Manager/Manager.h"
#include "VFS/Manager/API/IManager.h"


int	unit(int ac, char **av)
{
	VFS::Util::URITestMain(ac, av);
	return (0);
}


const char*		glTestResources[]	=
{
	"file://file.txt",
	"file://file",
	
	"file://dir",
	"file://dir/",
	
	"file://dir/file.txt",
	"file://dir/file",
	
	"file://dir/dir",
	"file://dir/dir/",
	
	NULL
};


int	vfsCase(const std::string& rsrcUri)
{
	std::string	line;
	
	std::cout << "---------- VFS USE CASE EXAMPLE ----------" << std::endl;
	
	std::cout << " + Initializing the VFS" << std::endl;
	VFS::Manager::API::IManager*	pVFSMgr = VFS::CVFS::GetVFS()->GetDefaultManager();

	std::cout << " + Initializing/Resolving a Resource" << std::endl;
	VFS::Resource::API::IResource*	pRsrc = pVFSMgr->Resource(rsrcUri);

	if (pRsrc != NULL)
	{
		std::cout << " + Opening the resolved Resource" << std::endl;
		pRsrc->Open();
		
		std::cout << " + Readoing Resource's content" << std::endl;
	//	while ((line = pRsrc->Readline()) != std::string::npos)
	//	{
	//		std::cout << "\t\t" << line << std::endl;
	//	}
		std::cout << " + Closing Resource" << std::endl;
		pRsrc->Close();
	}

	std::cout << " + Destroying the Resource" << std::endl;
	delete pRsrc;
	
	std::cout << " + Destroying the VFS" << std::endl;
	delete VFS::CVFS::GetVFS();
	std::cout << "------------------------------------------" << std::endl;
	
	return (0);
}


int	vfs(int ac, char **av)
{
	for (int i = 0; glTestResources[i] != NULL; i++)
	{
		vfsCase(std::string(glTestResources[i]));
	}
	return (0);
}


int	main(int ac, char **av)
{
	vfs(ac, av);
	return (0);	
}
