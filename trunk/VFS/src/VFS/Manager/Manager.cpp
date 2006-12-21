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

#include "VFS/Manager/Manager.h"
#include "VFS/Util/URI.h"



namespace VFS
{
	namespace Manager
	{
		CManager::CManager(void)
		{
		}
		
		CManager::~CManager(void)
		{
		}
		
		
		VFS::Resource::API::IResource*	CManager::Resource(const std::string& uri)
		{
			AoofWm::VFS::Util::CURI	rsrcURI(uri);
			
			/*
			 *	TODO:
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
			return (NULL);
		}
		
		VFS::Provider::ProvidersMap&	CManager::GetProviders(void)
		{
			return (_providers);
		}
		
		void							CManager::AddProvider(VFS::Provider::API::IProvider* pProvider)
		{
			
		}
		
		void							CManager::RemoveProvider(const std::string& providerName)
		{
			
		}
	}
}
