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

#include <Aoof-Wm/VFS/Util/Tokenizer.h>
#include <Aoof-Wm/VFS/Util/URI.h>


namespace AoofWm
{
	namespace VFS
	{
		namespace Util
		{
			CURI::CURI(void)
			{
				
			}
			
			CURI::CURI(const std::string& uri)
			{
				Parse(uri);
			}

			CURI::~CURI(void)
			{
			}
			
			
			CCredentials				CURI::GetCredentials(void) const
			{
				return (_credentials);
			}

			std::vector<std::string>	CURI::GetDirectories(void) const	
			{
				return (_directories);
			}

			const std::string&			CURI::GetFile(void) const
			{
				return (_file);
			}
			
			const std::string&			CURI::GetPath(void) const
			{
				return (_path);
			}

			const std::string&			CURI::GetQuery(void) const
			{
				return (_query);
			}
			
			const std::string&			CURI::GetScheme(void) const
			{
				return (_scheme);
			}
			
			const std::string&			CURI::GetURIString(void) const
			{
				return (_uri);
			}
			
			
			const bool					CURI::IsAbsolute(void) const
			{
				// TODO:
				return (true);
			}
			
			const bool					CURI::IsRelative(void) const
			{
				// TODO:
				return (true);
			}
			
			
			void						CURI::Parse(const std::string& uri)
			{
				_uri = uri;
				_scheme			= ExtractScheme();
				_directories	= ExtractDirectories();
				_file			= ExtractFile();
				_path			= ExtractPath();
				//_query			= ExtractQuery();
			}
			
			
			void						CURI::Print(void) const
			{
				std::cout << "\t{" << std::endl;
				std::cout << "\t   URI\t\t: " + _uri << std::endl;
				std::cout << "\t   Scheme\t: " + _scheme << std::endl;
				std::cout << "\t   Credentials\t: <" + _credentials.GetUser() + "> / <" + _credentials.GetPassword() + ">" << std::endl;
				std::cout << "\t   Directories\t: [" << std::endl;
				for (std::string::size_type i = 0; i < _directories.size(); i++)
				{
					std::cout << "\t              \t     " + _directories.at(i) << std::endl;
				}
				std::cout << "\t              \t  ]" << std::endl;
				std::cout << "\t   File\t\t: " + _file << std::endl;
				std::cout << "\t   Query\t: " + _query << std::endl;
				std::cout << "\t   QueryArgs\t: [" << std::endl;
				for (std::string::size_type i = 0; i < _queryArgs.size(); i++)
				{
					std::cout << "\t            \t     " + _queryArgs.at(i) << std::endl;
				}
				std::cout << "\t            \t  ]" << std::endl;
				std::cout << "\t}" << std::endl;
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
				std::vector<Token>		newTokens;

				if (_tokens.size() > 0)
				{
					offset = _tokens.at(0).endOffset + 3;
				}
				newTokens = CTokenizer::Tokenize(_uri, "/", offset);
				if (newTokens.size() > 0)
				{
					const std::string::size_type	offset	= newTokens.at(newTokens.size() - 1).endOffset;

					if (offset == _uri.length())
					{
						newTokens.pop_back();
					}
					if (newTokens.size())
					{
						for (unsigned int i = 0; i < newTokens.size(); i++)
						{
							_directories.push_back(newTokens.at(i).token);
						}
						_credentials = ExtractCredentials();
						if ((_credentials.GetUser() != "") && (_credentials.GetPassword() != ""))
						{
							const std::string::size_type	start = newTokens.at(1).endOffset + 1;

							_directories.at(0) = _uri.substr(start, _uri.find("/", start) - (start));
						}
						_tokens.clear();
						_tokens = newTokens;
					}
				}
				return (_directories);
			}

			const std::string&			CURI::ExtractFile(void)
			{
				std::string::size_type	offset = 0;
				
				_file = std::string();
				if (_tokens.size())
				{
					if (_directories.size())
					{
						offset = _tokens.at(_directories.size() - 1).endOffset + 1;
					}
					else
					{
						offset = _tokens.at(0).endOffset + 3;
					}
				}
				_tokens.clear();
				_tokens = CTokenizer::Tokenize(_uri, "/?=;", offset);
				if (_tokens.size() > 0)
				{
					_file = _tokens.at(0).token;
				}
				return (_file);
			}
			
			const std::string&			CURI::ExtractPath(void)
			{
				for (unsigned int i = 0; i < _directories.size(); i++)
				{
					_path.append(_directories.at(i) + "/");
				}
				_path.append(_file);
				return (_path);
			}
			

			const std::string&			CURI::ExtractQuery(void)
			{
				_query = std::string();
				return (_query);
			}
			
			const std::string&			CURI::ExtractScheme(void)
			{
				_scheme = std::string();
				_tokens = CTokenizer::TokenizeByString(_uri, "://");
				if (_tokens.size() > 0)
				{
					_scheme = _tokens.at(0).token;
				}
				return (_scheme);
			}
		}
	}
}
