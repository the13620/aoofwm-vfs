#include <iostream>
#include <string>

#include "test.h"

#include <Aoof-Wm/VFS/VFS.h>
#include <Aoof-Wm/VFS/Manager/Manager.h>
#include <Aoof-Wm/VFS/Manager/API/IManager.h>
#include <Aoof-Wm/VFS/Resource/FileResource.h>


int	unit(int ac, char **av)
{
	AoofWm::VFS::Util::URITestMain(ac, av);
	return (0);
}


const char*		glTestResources[]	=
{
	"C:/test/",
	//
	//"C:/test/nodir",
	//"C:/test/nodir/",
	//"C:/test/nofile",
	//
	//"C:/test/test.txt",
	//"C:/test/test2.txt",
	//
	//"C:/test/newDir/",
	//"C:/test/newDir/newFile.txt",
	//
	//"file://C:/test/",
	//
	//"file://C:/test/test.txt",
	//"file://C:/test/test2.txt",
	//
	//"C:/test/newDir2/",
	//"C:/test/newDir2/newFile2.txt",

	//"C:/test/XML/XMLfile.txt",
	//"C:/test/XML/config.xml",
	//
	//"testfile.txt",
	//"file://testfile.txt",
	//
	//"file://file.txt",
	//"file://file",
	//
	//"file://dir",
	//"file://dir/",
	//
	//"file://dir/file.txt",
	//"file://dir/file",
	//
	//"file://dir/dir",
	//"file://dir/dir/",
	
	NULL
};




int	vfsCase(const std::string& rsrcUri)
{
	AoofWm::VFS::Manager::API::IManager*			pVFSMgr;
	AoofWm::VFS::Resource::API::IResource*			pRsrc;

	std::cout << "---------- VFS USE CASE EXAMPLE ----------" << std::endl;
	std::cout << " + Initializing VFS" << std::endl;
	pVFSMgr = AoofWm::VFS::CVFS::GetVFS()->GetDefaultManager();

	std::cout << " + Initializing/Resolving Resource" << std::endl;
	pRsrc = pVFSMgr->Resource(rsrcUri);

	if (pRsrc != NULL)
	{
		std::cout << "\t[[" << pRsrc->GetName()->GetURI().GetFullPath() << "]]" << std::endl;
		//pRsrc->GetName()->GetURI().Print();
		if (pRsrc->Exists())
		{
			const AoofWm::VFS::Resource::RsrcString			newName(pRsrc->GetName()->GetURI().GetPath() + "copy." + pRsrc->GetName()->GetName());
			const AoofWm::VFS::Resource::RsrcString			copyDestination("C:/copies/");
			const AoofWm::VFS::Resource::RsrcString*		pLine;
			const AoofWm::VFS::Resource::RsrcStringList*	pLines;
			
			std::cout << " + Opening resolved Resource" << std::endl;
			if (pRsrc->Open())
			{
				std::cout << " + Retrieving Resource's size" << std::endl;
				std::cout << "\t\t> " << pRsrc->Size() << std::endl;
				
				std::cout << " + Reading Resource's content" << std::endl;
				for (int i = 0; (pLine = pRsrc->ReadLine()) != NULL && i < 3; i++)
				{
					std::cout << "\t\t> " << *pLine << std::endl;
					delete pLine;
				}
				
				std::cout << " + Resetting Resource's internal pointer" << std::endl;
				pRsrc->Reset();
				
				std::cout << " + Reading all Resource's content" << std::endl;
				pLines = pRsrc->ReadLines();
				if (pLines != NULL)
				{
					for (unsigned int i = 0; i < pLines->size(); i++)
						std::cout << "\t\t> " << pLines->at(i) << std::endl;
					delete pLines;
				}

				std::cout << " + Copying Resource to [" << copyDestination << "]"<< std::endl;
				pRsrc->Copy(copyDestination);

				//std::cout << " + Renaming Resource [" << newName << "]"<< std::endl;
				//pRsrc->Rename(newName);
			}
			else
			{
				std::cout << "/!\\ - Could not open Resource" << std::endl;
			}
		}
		else
		{
			std::cout << " + Creating new Resource" << std::endl;
			pRsrc->Create();
		}
		if (pRsrc->IsOpen())
		{
			std::cout << " + Closing Resource" << std::endl;
			pRsrc->Close();
		}
	}
	else
	{
		std::cout << "/!\\ - Could not resolve Resource" << std::endl;
	}

	std::cout << " + Destroying Resource" << std::endl;
	delete pRsrc;
	
	std::cout << " + Destroying VFS" << std::endl;
	delete AoofWm::VFS::CVFS::GetVFS();
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
//	AoofWm::VFS::Util::URITestMain(ac, av);
	vfs(ac, av);
	return (0);	
}
