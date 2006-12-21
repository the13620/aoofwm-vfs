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

#ifndef __VFS_RESOURCE_API_IRESOURCE_H__
# define __VFS_RESOURCE_API_IRESOURCE_H__

# include <string>

# include <VFS/Resource/API/IResourceName.h>
# include <VFS/Resource/API/IResourceType.h>

namespace	VFS
{
	namespace	Resource
    {
    	namespace	API
		{
			typedef std::string	RsrcString;
			
			class	IResourceContent;
			
			class	IResource
	    	{
	      	public:
				virtual const IResourceContent*	GetContent(void) const	= 0;
		      	virtual const IResourceName*	GetName(void) const		= 0;
		      	virtual const IResourceType*	GetType(void) const		= 0;

				virtual const bool				Open(void) const		= 0;
				virtual const bool				Close(void) const		= 0;
				virtual const bool				Create(void) const		= 0;
				virtual const bool				Delete(void) const		= 0;

				virtual const bool				Copy(void) const		= 0;
				virtual const bool				Move(void) const		= 0;
				virtual const bool				Rename(void) const		= 0;

				/*
				 * TODO:	define a Selector architecture
				 */
				//virtual const bool									Find(VFS::Selector::API::ISelector *pSelector, VFS::Resource::API::IResource *pSearchRoot) const		= 0;

				virtual const bool				IsWritable(void) const	= 0;
				virtual const bool				IsHidden(void) const	= 0;
				virtual const bool				IsReadable(void) const	= 0;
				virtual const bool				IsOpen(void) const		= 0;


				/*
				 * TODO: integrate hierarchical filesytem management within IResource
				 */
				//virtual const IResource*		GetChild(std::string name) const	= 0;
				//virtual const std::map<std::string, IResource *>	GetChildren(void) const	= 0;
				//virtual const bool			FindChildren() const	= 0;
		    };
		}
    }
}

#endif	// __VFS_RESOURCE_API_IRESOURCE_H__
