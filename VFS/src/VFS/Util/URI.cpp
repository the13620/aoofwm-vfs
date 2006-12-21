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
#include <iostream>
#include <vector>

#include "VFS/Util/Tokenizer.h"
#include "VFS/Util/URI.h"


namespace AoofWm
{
	namespace VFS
	{
		namespace Util
		{
			CURI::CURI(const std::string& uri)
			{
				_uri = uri;
				Parse();

				std::cout << "\t{" << std::endl;
				std::cout << "\t   URI\t\t: " + _uri << std::endl;
				std::cout << "\t   Scheme\t: " + _scheme << std::endl;
				std::cout << "\t   Credentials\t: <" + _credentials.GetUser() + "> / <" + _credentials.GetPassword() + ">" << std::endl;
				std::cout << "\t   Directories\t: [" << std::endl;
				for (int  i = 0; i < _directories.size(); i++)
				{
					std::cout << "\t              \t     " + _directories.at(i) << std::endl;
				}
				std::cout << "\t              \t  ]" << std::endl;
				std::cout << "\t   File\t\t: " + _file << std::endl;
				std::cout << "\t   Query\t: " + _query << std::endl;
				std::cout << "\t   QueryArgs\t: [" << std::endl;
				for (int  i = 0; i < _queryArgs.size(); i++)
				{
					std::cout << "\t            \t     " + _queryArgs.at(i) << std::endl;
				}
				std::cout << "\t            \t  ]" << std::endl;
				std::cout << "\t}" << std::endl;
			}


			CURI::~CURI(void)
			{
			}


			void						CURI::Parse(void)
			{
				_scheme			= ExtractScheme();
				_directories	= ExtractDirectories();
				//_file			= ExtractFile();
				//_query			= ExtractQuery();
			}


			std::string					CURI::GetURIString(void) const
			{
				return (_uri);
			}

			std::string					CURI::GetScheme(void) const
			{
				return (_scheme);
			}

			CCredentials				CURI::GetCredentials(void) const
			{
				return (_credentials);
			}

			std::vector<std::string>	CURI::GetDirectories(void) const	
			{
				return (_directories);
			}

			std::string					CURI::GetFile(void) const
			{
				return (_file);
			}

			std::string					CURI::GetQuery(void) const
			{
				return (_query);
			}

			std::string&				CURI::ExtractScheme(void)
			{
				_scheme = std::string();
				_tokens = CTokenizer::TokenizeByString(_uri, "://");
				if (_tokens.size() > 0)
				{
					_scheme = _tokens.at(0).token;
				}
				return (_scheme);
			}

			CCredentials				CURI::ExtractCredentials(void)
			{
				if (_tokens.size() > 0)
				{
					std::string::size_type	startOffset = _tokens.at(0).startOffset;
					std::string::size_type	endOffset = _uri.rfind("@", _tokens.at(0).endOffset);

					if (endOffset != std::string::npos)
					{
						_tokens.clear();
						_tokens = CTokenizer::Tokenize(_uri, ":", startOffset, endOffset);
						if (_tokens.size() > 1)
						{
							_credentials = CCredentials(_tokens.at(0).token, _tokens.at(1).token);
						}
					}
				}
				return (_credentials);
			}

			std::vector<std::string>&	CURI::ExtractDirectories(void)
			{
				std::string::size_type	offset = 0;

				if (_tokens.size() > 0)
				{
					offset = _tokens.at(0).endOffset + 3;
				}
				_tokens.clear();
				_tokens = CTokenizer::Tokenize(_uri, "/", offset);
				for (int i = 0; i < _tokens.size(); i++)
				{
					_directories.push_back(_tokens.at(i).token);
				}
				_credentials = ExtractCredentials();
				if ((_credentials.GetUser() != "") && (_credentials.GetPassword() != ""))
				{
					const std::string::size_type	start = _tokens.at(1).endOffset + 1;

					_directories.at(0) = _uri.substr(start, _uri.find("/", start) - (start));
				}
				return (_directories);
			}

			std::string&				CURI::ExtractFile(void)
			{
				_file = std::string();
				return (_file);
			}

			std::string&				CURI::ExtractQuery(void)
			{
				_query = std::string();
				return (_query);
			}
		}
	}
}