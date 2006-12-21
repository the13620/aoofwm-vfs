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


int	vfs(int ac, char **av)
{
	std::cout << "---------- VFS USE CASE EXAMPLE ----------" << std::endl;
	
	std::cout << " + Initializing the VFS" << std::endl;
	VFS::Manager::API::IManager*	pVFSMgr = VFS::CVFS::GetDefaultManager();

	std::cout << " + Initializing a Resource" << std::endl;
	VFS::Resource::API::IResource*	pRsrc = pVFSMgr->Resource("file://test.txt");

	std::cout << " + Destroying the Default Manager" << std::endl;
	delete pVFSMgr;
	
	std::cout << " + Destroying everything" << std::endl;
	delete VFS::CVFS::GetVFS();
	std::cout << "------------------------------------------" << std::endl;
	return (0);
}


int	main(int ac, char **av)
{
	vfs(ac, av);
	return (0);	
}
