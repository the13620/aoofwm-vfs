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

#include <string>
#include <vector>

#include "Aoof-Wm/VFS/Util/Credentials.h"
#include "Aoof-Wm/VFS/Util/Tokenizer.h"

namespace AoofWm
{
	namespace VFS
	{
		namespace Util
		{
			CCredentials::CCredentials(void)
			{
				_user = std::string();
				_passwd = std::string();
			}
			
			CCredentials::CCredentials(const CCredentials& copy)
			{
				_user = copy.GetUser();
				_passwd = copy.GetPassword();
			}
			
			CCredentials::~CCredentials(void)
			{
			}

			CCredentials*	CCredentials::fromString(const std::string& source)
			{
				std::vector<Token>	tokens;

				tokens = CTokenizer::Tokenize(source, ":");
				if (tokens.size() > 1)
				{
					CCredentials	credentials = CCredentials(tokens.at(0).token, tokens.at(1).token);
					
					return (new CCredentials(tokens.at(0).token, tokens.at(1).token));
				}
				return (NULL);
			}

			std::string		CCredentials::GetUser(void) const
			{
				return (_user);
			}

			std::string		CCredentials::GetPassword(void) const
			{
				return (_passwd);
			}
		}
	}
}
