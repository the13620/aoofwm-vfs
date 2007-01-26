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
	
	"C:/test/test.txt",
	"C:/test/test2.txt",
	
	"C:/test/newDir/",
	"C:/test/newDir/newFile.txt",
	
	"file://C:/test/",
	
	"file://C:/test/test.txt",
	"file://C:/test/test2.txt",
	
	"C:/test/newDir2/",
	"C:/test/newDir2/newFile2.txt",
	
	"testfile.txt",
//	"file://file.txt",
//	"file://file",
//	
//	"file://dir",
//	"file://dir/",
//	
//	"file://dir/file.txt",
//	"file://dir/file",
//	
//	"file://dir/dir",
//	"file://dir/dir/",
	
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
		std::cout << "\t[[" << pRsrc->GetName()->GetPath() << "]]" << std::endl;
		//pRsrc->GetName()->GetURI().Print();
		if (pRsrc->Exists())
		{
			const AoofWm::VFS::Resource::RsrcString*		line;
			const AoofWm::VFS::Resource::RsrcStringList*	lines;
			
			std::cout << " + Opening resolved Resource" << std::endl;
			if (pRsrc->Open())
			{
				std::cout << " + Retrieving Resource's size" << std::endl;
				std::cout << "\t\t> " << pRsrc->Size() << std::endl;
				
				std::cout << " + Reading Resource's content" << std::endl;
				while ((line = pRsrc->ReadLine()) != NULL)
				{
					std::cout << "\t\t> " << *line << std::endl;
					delete line;
				}
				
				std::cout << " + Resetting Resource's internal pointer" << std::endl;
				pRsrc->Reset();
				
				std::cout << " + Reading all Resource's content" << std::endl;
				lines = pRsrc->ReadLines();
				if (lines != NULL)
				{
					for (unsigned int i = 0; i < lines->size(); i++)
					{
						std::cout << "\t\t> " << lines->at(i) << std::endl;
					}
					delete lines;
				}
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
