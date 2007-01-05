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


#ifndef __AOOFWM_VFS_UTIL_URI_H__
# define __AOOFWM_VFS_UTIL_URI_H__

# include <string>
# include <vector>
# include <map>

# include "VFS/Util/Credentials.h"
# include "VFS/Util/Tokenizer.h"


namespace AoofWm
{
	namespace VFS
	{
		namespace Util
		{
			class CQuery
			{
			private:
				std::string							_query;
				std::map<std::string, std::string>	_args;

			public:
				CQuery(void);
				~CQuery(void);
			};

			class CURI
			{
			private:
				std::vector<Token>			_tokens;

				CCredentials				_credentials;
				std::vector<std::string>	_directories;
				std::string					_file;
				std::string					_path;
				std::string					_query;
				std::string					_queryArgs;				
				std::string					_scheme;
				std::string					_uri;

			public:
				CURI(void);
				CURI(const std::string& uri);
				~CURI(void);

				CCredentials				GetCredentials(void) const ;
				std::vector<std::string>	GetDirectories(void) const;
				const std::string&			GetFile(void) const;
				const std::string&			GetPath(void) const;
				const std::string&			GetQuery(void) const;
				const std::string&			GetScheme(void) const;
				const std::string&			GetURIString(void) const;

				const bool					IsAbsolute(void) const;
				const bool					IsRelative(void) const;

				void						Parse(const std::string& uri);

				void						Print(void) const;

			private:
				CCredentials				ExtractCredentials(void);
				std::vector<std::string>&	ExtractDirectories(void);
				const std::string&			ExtractFile(void);
				const std::string&			ExtractPath(void);
				const std::string&			ExtractQuery(void);
				const std::string&			ExtractScheme(void);
			};
		}
	}
}


#endif // __AOOFWM_VFS_UTIL_URI_H__
