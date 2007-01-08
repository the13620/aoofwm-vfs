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

#include "Aoof-Wm/VFS/Resource/ResourceType.h"


namespace AoofWm
{
	namespace VFS
	{
		namespace Resource
		{
			CResourceType::CResourceType(const AoofWm::VFS::Resource::API::IResource* pRsrc)
			{
				_pResource = pRsrc;
			}
			
			CResourceType::~CResourceType(void)
			{
				
			}
			
				
			const AoofWm::VFS::Resource::API::IResource*	CResourceType::GetResource(void) const
			{
				return (_pResource);
			}
			
				
			const std::string&						CResourceType::GetResourceTypeName(void) const
			{
				return (_strTypeName);
			}
			
			const eVFSResourceTypeCode				CResourceType::GetResourceTypeCode(void) const
			{
				return (_eTypeCode);
			}
			
	
			const bool								CResourceType::HasChildren(void) const
			{
				return (true);	// TODO: useless for now
			}
			
			const bool								CResourceType::CResourceType::HasContent(void) const
			{
				return (true);	// TODO: useless for now
			}
		}
	}
}
