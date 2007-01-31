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


#ifndef __AOOFWM_UNIX_VFS_RESOURCE_FILERESOURCE_H__
# define __AOOFWM_UNIX_VFS_RESOURCE_FILERESOURCE_H__

# include <cstdio>
# include <fstream>
# include <iostream>

# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

# include <Aoof-Wm/VFS/Resource/AbstractResource.h>

namespace	AoofWm
{
	namespace	VFS
	{
		namespace	Resource
		{
			class	CFileResource : public virtual AoofWm::VFS::Resource::CAbstractResource
			{
	//			typedef FILE			FileHandle;
				typedef struct stat		FileStat;
				
			private:
				static const unsigned int	BUFFER_SIZE	= 1024;
				
				std::fstream	_stream;
	//			FileHandle*		_pFileHandle;
	//			char			_buffer[BUFFER_SIZE];
	//			unsigned int	_bufferCount;
							
				
			public:
				CFileResource(const std::string& uri);
				~CFileResource(void);
				
				const bool				Exists(void) const;
	
				const bool				Open(void);
				const bool				Close(void);
				const bool				Create(void);
				const bool				Delete(void);
				
				const bool				Reset(void);
				const bool				Seek(const unsigned long location);
				const unsigned long		Tell(void);
					
				const unsigned long		Size(void);
	
				const bool				Copy(const RsrcString& name);
				const bool				Move(const RsrcString& name);
				const bool				Rename(const RsrcString& name);
				
				const unsigned int		Read(char buffer[], unsigned int size);
				const unsigned int		Read(char buffer[], unsigned int offset, unsigned int size);
				const RsrcString*		ReadLine(const RsrcString& delimiter = "\n");
				const RsrcString*		ReadLine(const char delimiter);
				const RsrcStringList*	ReadLines(const RsrcString& delimiter = "\n");
				const RsrcStringList*	ReadLines(const char delimiter);
				
				const bool				IsWritable(void) const;
				const bool				IsHidden(void) const;
				const bool				IsReadable(void) const;
				const bool				IsOpen(void) const;
				const bool				IsOpen(void);
			};
		}
	}
}

#endif	// __AOOFWM_UNIX_VFS_RESOURCE_FILERESOURCE_H__
