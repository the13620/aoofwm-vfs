/*
** This file is part of The Toy'd Project (http://www.toyd.org).
**
** The Toy'd Project is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** The Toy'd Project is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with The Toy'd Project; if not, write to the Free Software
** Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*
** This software has been written in EPITECH <http://www.epitech.net>
** EPITECH is computer science school in Paris - FRANCE -
** under the direction of Flavien Astraud <http://www.epita.fr/~flav>,
** Jerome Landrieu and Launiau Severin.
**
** Project : The Toy'd Project
**
*/

#include <string>
#include <iostream>

#include "VFS/Manager/Manager.h"
#include "VFS/Provider/Providers.h"
#include "VFS/Resource/Resources.h"
#include "VFS/Util/URI.h"


using namespace	VFS::Manager;

namespace VFS
{
	namespace Manager
	{
		CManager::CManager(void)
		{
			/*
			 * Available Providers List initialization.
			 * TODO:	replace / combine with auto-detected
			 * 			Providers' shared libraries
			 */
			 _providers["file"] = VFS::Provider::CFileProvider::CFileProvider::Construct;
			 //_providers["http"] = VFS::Provider::CHttpProvider::CHttpProvider::Construct;
			 //_providers["zip"] = VFS::Provider::CZipProvider::CZipProvider::Construct;
		}
		
		CManager::~CManager(void)
		{
			
		}

		
		VFS::Resource::API::IResource*		CManager::Resource(const std::string& uri) const
		{
			VFS::Resource::API::IResource*	pRsrc			= NULL;
			AoofWm::VFS::Util::CURI			rsrcURI(uri);

			/*
			 * TODO:
			 * 	Recode previous version of the ResourceType selector
			 *  with the new Path/PathEntry hierarchy & Providers' system.
			 * 
			 *  For now it's just a basic selector only suitable for
			 *  the FileProvider with no advanced detection system at all.
			 */
			if (rsrcURI.GetFile().empty())
			{// Directory
				std::cout << "Directory Detection" << std::endl;
				pRsrc = new VFS::Resource::CDirectoryResource(uri);
			}
			else
			{// File
				std::cout << "File Detection" << std::endl;
				pRsrc = new VFS::Resource::CFileResource(uri);
			}
			/*
			 *	PROCESS:
			 * 		-select Provider from scheme.
			 * 		-select Driver from filetype.
			 * 		-check path existence and file existence
			 * 			1-if file exists, get type.
			 * 			2a-if file doesn't exist, use abstract blank type
			 * 			   (don't know yet if the user wants a directory or
			 *              a file in the end).
			 * 			2b-if file doesn't exist, user has to use trailing '/' to specify
			 * 			   a directory is targeted, otherwise we consider it a file.
			 */
			return (pRsrc);
		}
		
		const VFS::Manager::RsrcMap&						CManager::GetResources(void) const
		{
			return (_resources);
		}
		
		VFS::Resource::API::IResource*		CManager::GetResource(const std::string& key) const
		{
			VFS::Resource::API::IResource*	pRsrc	= NULL;
			
//			VFS::Manager::RsrcMap::iterator	iFind = _resources.find(key);
//			if (iFind != _resources.end() )
//			{
//    			pRsrc = *iterFind;
//			}
			return (pRsrc);
		}
		
		const VFS::Provider::ProvidersMap&	CManager::GetProviders(void) const
		{
			return (_providers);
		}
		
		void								CManager::AddProvider(VFS::Provider::API::IProvider* pProvider) const
		{
			
		}
		
		void								CManager::RemoveProvider(const std::string& providerName) const
		{
			
		}
	}
}
