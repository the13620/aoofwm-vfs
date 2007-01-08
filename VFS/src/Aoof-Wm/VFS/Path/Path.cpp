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

#include <vector>

#include "Aoof-Wm/VFS/Path/Path.h"
#include "Aoof-Wm/VFS/Path/PathEntry.h"
#include "Aoof-Wm/VFS/Util/URI.h"

using namespace AoofWm::VFS::Path;


namespace AoofWm
{
	namespace VFS
	{
		namespace Path
		{
			CPath::CPath(const std::string& path)
			{
				AoofWm::VFS::Util::CURI	uri(path);
				
				
				for (unsigned int i = 0; i < uri.GetDirectories().size(); i++)
				{
					const std::string&	pathEntryString = uri.GetDirectories().at(i);
					
					_path += pathEntryString + "/";
					_entries.push_back(new CPathEntry(pathEntryString));
				}
			}
	
			CPath::~CPath(void)
			{
				for (unsigned int i = 0; i < _entries.size(); i++)
				{
					delete _entries.at(i);
				}
				_entries.clear();
			}
			
			
			const std::string&		CPath::GetPath(void) const
			{
				return (_path);
			}
			
			const PathEntryList&	CPath::GetEntries(void) const
			{
				return (_entries);
			}
			
			const API::IPathEntry*	CPath::GetEntry(const PathEntryList::size_type idx) const
			{
				if ((idx >= 0) && (idx < _entries.size()))
				{
					return (_entries.at(idx));
				}
				return (NULL);
			}
		}
	}
}
