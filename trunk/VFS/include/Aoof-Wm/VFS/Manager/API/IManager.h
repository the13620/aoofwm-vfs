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

#ifndef __AOOFWM_VFS_MANAGER_API_IMANAGER_H__
# define __AOOFWM_VFS_MANAGER_API_IMANAGER_H__

# include <string>
# include <map>

# include <Aoof-Wm/VFS/Provider/Providers.h>

# include <Aoof-Wm/VFS/Provider/API/IProvider.h>
# include <Aoof-Wm/VFS/Resource/API/IResource.h>

namespace	AoofWm
{
	namespace	VFS
	{
		namespace	Manager
	    {
	    	typedef std::map<std::string, AoofWm::VFS::Resource::API::IResource*>	RsrcMap;
	    	
	    	namespace	API
			{
				class	IManager
			    {
				public:
					virtual AoofWm::VFS::Resource::API::IResource*		Resource(const std::string& uri) const						= 0;
	
					/*
					 * TODO: thinking about tagging the following methods as private,
					 * 		and the VFS being configured only automatically through
					 * 		configuration files, and not programmatically by the developers.
					 */
	
					virtual const AoofWm::VFS::Manager::RsrcMap&		GetResources(void) const 									= 0;
					virtual AoofWm::VFS::Resource::API::IResource*		GetResource(const std::string &key) const					= 0;
	
					virtual const AoofWm::VFS::Provider::ProvidersMap&	GetProviders(void) const									= 0; 
	
					virtual void								AddProvider(VFS::Provider::API::IProvider* pProvider) const	= 0;
					virtual void								RemoveProvider(const std::string& providerName) const		= 0;
					
					//virtual const ResourcesPool&				getResourcePool(void);
			    };
			}
	    }
	}
}

#endif	// __AOOFWM_VFS_MANAGER_API_IMANAGER_H__
