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

#include "Aoof-Wm/VFS/VFS.h"


namespace AoofWm
{
	namespace VFS
	{
		CVFS*	CVFS::_pVFS	= NULL;
		
		
		CVFS::CVFS(void)
		{
			_pDefaultManager = NULL;
		}
		
		CVFS::~CVFS(void)
		{
			if (_pDefaultManager != NULL)
			{
				delete _pDefaultManager;
				_pDefaultManager = NULL;
			}
			CVFS::_pVFS = NULL;
		}
		
		
		AoofWm::VFS::Manager::API::IManager*	CVFS::CreateManager(void) const
		{
			return (NULL);
		}
		
		AoofWm::VFS::Manager::API::IManager*	CVFS::GetManager(void) const
		{
			return (NULL);
		}
		
		CVFS*							CVFS::GetVFS(void)
		{
			if (CVFS::_pVFS == NULL)
			{
				_pVFS = new CVFS();
			}
			return (_pVFS);
		}
		
		AoofWm::VFS::Manager::API::IManager*	CVFS::GetDefaultManager(void)
		{
			if (CVFS::GetVFS()->_pDefaultManager == NULL)
			{
				CVFS::GetVFS()->_pDefaultManager = new AoofWm::VFS::Manager::CManager();
			}
			return (CVFS::GetVFS()->_pDefaultManager);
		}
	}
}
