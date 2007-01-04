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


#ifndef __VFS_RESOURCE_ABSTRACTRESOURCE_H__
# define __VFS_RESOURCE_ABSTRACTRESOURCE_H__

# include <VFS/Resource/ResourceTypes.h>

# include <VFS/Resource/API/IResource.h>

namespace	VFS
{
	namespace	Resource
	{
		class	CAbstractResource : public virtual VFS::Resource::API::IResource
		{
		private:
			API::IResourceContent*	_pRsrcContent;
			API::IResourceName*		_pRsrcName;
			API::IResourceType*		_pRsrcType;
			
			
		public:
			CAbstractResource(void);
			CAbstractResource(const std::string& uri);
			CAbstractResource(const CAbstractResource& rsrc);
			virtual ~CAbstractResource(void);
			
			
			const API::IResourceContent*			GetContent(void) const;
	      	const API::IResourceName*				GetName(void) const;
	      	const API::IResourceType*				GetType(void) const;

			const bool								Exists(void) const;

			const bool								Open(void) const;
			const bool								Close(void) const;
			const bool								Create(void) const;
			const bool								Delete(void) const;

			const bool								Copy(void) const;
			const bool								Move(void) const;
			const bool								Rename(void) const;
						
			const unsigned int						Read(char buffer[], unsigned int size) const;
			const unsigned int						Read(char buffer[], unsigned int offset, unsigned int size) const;
			const VFS::Resource::RsrcString&		ReadLine(const VFS::Resource::RsrcString& delimiter = "\n") const;
			const VFS::Resource::RsrcString&		ReadLine(const char delimiter = '\n') const;
			const VFS::Resource::RsrcStringList&	ReadLines(const VFS::Resource::RsrcString& delimiter = "\n") const;
			const VFS::Resource::RsrcStringList&	ReadLines(const char delimiter = '\n') const;

			const bool								IsWritable(void) const;
			const bool								IsHidden(void) const;
			const bool								IsReadable(void) const;
			const bool								IsOpen(void) const;
		};
	}
}


#endif	// __VFS_RESOURCE_ABSTRACTRESOURCE_H__
