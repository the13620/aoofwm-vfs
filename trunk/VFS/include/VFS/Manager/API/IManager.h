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

#ifndef __VFS_MANAGER_API_IMANAGER_H__
# define __VFS_MANAGER_API_IMANAGER_H__

# include <string>
# include <map>

# include "VFS/Provider/Providers.h"

# include "VFS/Provider/API/IProvider.h"
# include "VFS/Resource/API/IResource.h"

namespace	VFS
{
	namespace	Manager
    {
    	typedef std::map<std::string, VFS::Resource::API::IResource*>	RsrcMap;
    	
    	namespace	API
		{
			class	IManager
		    {
			public:
				virtual VFS::Resource::API::IResource*		Resource(const std::string& uri) const						= 0;

				/*
				 * TODO: thinking about tagging the following methods as private,
				 * 		and the VFS being configured only automatically through
				 * 		configuration files, and not programmatically by the developers.
				 */

				virtual const VFS::Manager::RsrcMap&		GetResources(void) const 									= 0;
				virtual VFS::Resource::API::IResource*		GetResource(const std::string &key) const					= 0;

				virtual const VFS::Provider::ProvidersMap&	GetProviders(void) const									= 0; 

				virtual void								AddProvider(VFS::Provider::API::IProvider* pProvider) const	= 0;
				virtual void								RemoveProvider(const std::string& providerName) const		= 0;
				
				//virtual const ResourcesPool&				getResourcePool(void);
		    };
		}
    }
}

#endif	// __VFS_MANAGER_API_IMANAGER_H__
