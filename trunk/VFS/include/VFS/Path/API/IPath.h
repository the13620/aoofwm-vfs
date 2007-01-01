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


#ifndef __VFS_PATH_API_IPATH_H__
# define __VFS_PATH_API_IPATH_H__

# include <string>
# include <vector>

# include "VFS/Path/API/IPathEntry.h"

namespace	VFS
{
	namespace	Path
	{
		typedef std::vector<const VFS::Path::API::IPathEntry*>	PathEntryList;

		namespace	API
		{
			class	IPath
			{
			public:
				virtual const std::string&		GetPath(void) const									= 0;
				virtual const PathEntryList&	GetEntries(void) const								= 0;
				virtual const API::IPathEntry*	GetEntry(const PathEntryList::size_type idx) const	= 0;
			};
		}
	}
}


#endif	// __VFS_PATH_API_IPATH_H__
