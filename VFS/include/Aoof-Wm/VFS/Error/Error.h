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


#ifndef __AOOFWM_VFS_ERROR_ERROR_H__
# define __AOOFWM_VFS_ERROR_ERROR_H__

# include <Aoof-Wm/VFS/Error/API/IError.h>

namespace	AoofWm
{
	namespace	VFS
	{
		namespace	Error
		{
			class	CError : public virtual AoofWm::VFS::Error::API::IError
			{
			private:
				static AoofWm::VFS::Error::API::IError*	_lastError;
				
			public:
				std::string		_message;
				eErrorCode		_code;
				
			public:
				CError(const eErrorCode code = ecVFSError, const std::string& message = "");
				~CError(void);
				
				static const AoofWm::VFS::Error::API::IError*	Fire(const eErrorCode code = ecVFSError, const std::string& message = "");
				static const AoofWm::VFS::Error::API::IError*	GetLastError(void);
				
				const eErrorCode						GetCode(void) const;
				const std::string&						GetMessage(void) const;
				
				static AoofWm::VFS::Error::API::IError*			GetError(void);
			};
		}
	}
}

#endif	// __AOOFWM_VFS_ERROR_ERROR_H__
