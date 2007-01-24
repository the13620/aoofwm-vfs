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

#include <Aoof-Wm/VFS/Error/Error.h>
#include <Aoof-Wm/VFS/Manager/Manager.h>
#include <Aoof-Wm/VFS/Provider/Providers.h>
#include <Aoof-Wm/VFS/Resource/Resources.h>
#include <Aoof-Wm/VFS/Util/URI.h>


using namespace	AoofWm::VFS::Manager;

namespace AoofWm
{
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
				 //_providers["file"] = AoofWm::VFS::Provider::CFileProvider::CFileProvider::Construct;
				 //_providers["http"] = AoofWm::VFS::Provider::CHttpProvider::CHttpProvider::Construct;
				 //_providers["zip"] = AoofWm::VFS::Provider::CZipProvider::CZipProvider::Construct;
			}
			
			CManager::~CManager(void)
			{
				
			}
	
			
			AoofWm::VFS::Resource::API::IResource*		CManager::Resource(const std::string& uri) const
			{
				AoofWm::VFS::Resource::API::IResource*	pRsrc			= NULL;
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
					pRsrc = new AoofWm::VFS::Resource::CDirectoryResource(uri);
				}
				else
				{// File
					std::cout << "File Detection" << std::endl;
					pRsrc = new AoofWm::VFS::Resource::CFileResource(uri);
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
			
			const AoofWm::VFS::Manager::RsrcMap&						CManager::GetResources(void) const
			{
				return (_resources);
			}
			
			AoofWm::VFS::Resource::API::IResource*		CManager::GetResource(const std::string& key) const
			{
				AoofWm::VFS::Resource::API::IResource*	pRsrc	= NULL;
				
	//			AoofWm::VFS::Manager::RsrcMap::iterator	iFind = _resources.find(key);
	//			if (iFind != _resources.end() )
	//			{
	//    			pRsrc = *iterFind;
	//			}
				return (pRsrc);
			}
			
			const AoofWm::VFS::Provider::ProvidersMap&	CManager::GetProviders(void) const
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
}
