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
	VFS::Manager::API::IManager*	pVFSMgr = VFS::CVFS::GetDefaultManager();

	return (0);
}


int	main(int ac, char **av)
{
	vfs(ac, av);
	return (0);	
}
