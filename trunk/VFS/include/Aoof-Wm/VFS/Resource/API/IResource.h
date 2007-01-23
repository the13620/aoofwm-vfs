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

#ifndef __AOOFWM_VFS_RESOURCE_API_IRESOURCE_H__
# define __AOOFWM_VFS_RESOURCE_API_IRESOURCE_H__

# include <iostream>
# include <map>
# include <string>
# include <vector>

# include <Aoof-Wm/VFS/Resource/ResourceTypes.h>

# include <Aoof-Wm/VFS/Resource/API/IResourceContent.h>
# include <Aoof-Wm/VFS/Resource/API/IResourceName.h>
# include <Aoof-Wm/VFS/Resource/API/IResourceType.h>


namespace	AoofWm
{
	namespace	VFS
	{
		namespace	Resource
	    {
	    	namespace	API
			{
				class	IResource
		    	{
		      	public:
		      		virtual ~IResource(void) {};
		      		
					virtual const IResourceContent*					GetContent(void) const												= 0;
			      	virtual const IResourceName*					GetName(void) const													= 0;
			      	virtual const IResourceType*					GetType(void) const													= 0;
	
					virtual const bool								Exists(void) const													= 0;
	
					virtual const bool								Open(void)															= 0;
					virtual const bool								Close(void)															= 0;
					virtual const bool								Create(void)														= 0;
					virtual const bool								Delete(void)														= 0;
					
					virtual const bool								Reset(void)															= 0;
					virtual const bool								Seek(const unsigned long location)									= 0;
					virtual const unsigned long						Tell(void)															= 0;
					
					virtual const unsigned long						Size(void)															= 0;
	
					virtual const bool								Copy(const AoofWm::VFS::Resource::RsrcString& name)							= 0;
					virtual const bool								Move(const AoofWm::VFS::Resource::RsrcString& name)							= 0;
					virtual const bool								Rename(const AoofWm::VFS::Resource::RsrcString& name)						= 0;
					
					virtual const unsigned int						Read(char buffer[], unsigned int size)								= 0;
					virtual const unsigned int						Read(char buffer[], unsigned int offset, unsigned int size)			= 0;
					virtual const AoofWm::VFS::Resource::RsrcString*		ReadLine(const AoofWm::VFS::Resource::RsrcString& delimiter = "\n")			= 0;
					virtual const AoofWm::VFS::Resource::RsrcString*		ReadLine(const char delimiter)										= 0;
					virtual const AoofWm::VFS::Resource::RsrcStringList*	ReadLines(const AoofWm::VFS::Resource::RsrcString& delimiter = "\n")		= 0;
					virtual const AoofWm::VFS::Resource::RsrcStringList*	ReadLines(const char delimiter)										= 0;
	
					/*
					 * TODO:	define a Selector architecture
					 */
					//virtual const bool									Find(VFS::Selector::API::ISelector *pSelector, AoofWm::VFS::Resource::API::IResource *pSearchRoot) const		= 0;
	
					virtual const bool								IsWritable(void) const												= 0;
					virtual const bool								IsHidden(void) const												= 0;
					virtual const bool								IsReadable(void) const												= 0;
					virtual const bool								IsOpen(void) const													= 0;
	
	
					/*
					 * TODO: integrate hierarchical filesytem management within IResource
					 */
					//virtual const IResource*		GetChild(RsrcString name) const	= 0;
					//virtual const std::map<RsrcString, IResource *>	GetChildren(void) const	= 0;
					//virtual const bool			FindChildren() const	= 0;
			    };
			}
	    }
	}
}

#endif	// __AOOFWM_VFS_RESOURCE_API_IRESOURCE_H__
