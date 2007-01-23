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


#ifndef __AOOFWM_VFS_PATH_CPATH_H__
# define __AOOFWM_VFS_PATH_CPATH_H__

# include <Aoof-Wm/VFS/Path/API/IPath.h>
# include <Aoof-Wm/VFS/Path/API/IPathEntry.h>

namespace	AoofWm
{
	namespace	VFS
	{
		namespace	Path
		{
			class	CPath : public AoofWm::VFS::Path::API::IPath
			{
			private:
				std::string		_path;
				PathEntryList	_entries;
				
			public:
				CPath(const std::string& path);
				virtual ~CPath(void);
			
				const std::string&		GetPath(void) const;
				const PathEntryList&	GetEntries(void) const;
				const API::IPathEntry*	GetEntry(const PathEntryList::size_type idx) const;
			};
		}
	}
}

#endif	// __AOOFWM_VFS_PATH_CPATH_H__
