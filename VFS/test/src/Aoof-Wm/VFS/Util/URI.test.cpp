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

#include <iostream>
#include <string>

#include <Aoof-Wm/VFS/Util/URI.h>
#include <Aoof-Wm/VFS/Util/URI.test.h>


namespace	AoofWm
{
	namespace	VFS
	{
		namespace	Util
		{
			void	URITest(const std::string uriStr)
			{
				std::cout << "[" + uriStr + "]" << std::endl;
			
				AoofWm::VFS::Util::CURI		uri(uriStr);
			
				std::string	end;
				end.append(uriStr.size(), '-');
				std::cout << "[" + end + "]\n" << std::endl;
			}
			
			void	URITest(const char* pUriStr)
			{
				URITest(std::string(pUriStr));
			}
			
			
			int		URITestMain(int ac, char **av)
			{
				if (ac > 1)
				{
					for (int i = 1; i < ac; i++)
					{
						URITest(std::string(av[i]));
					}
				}
				else
				{
					URITest(std::string("http://u:p@d.net/path/subpath/a.gz/subdir/file.ext?k1=v1;k2=v2;k3"));
					URITest(std::string("file://dir/subdir/file.ext"));
					URITest(std::string("file:///dir/subdir/file.ext"));
					URITest(std::string("file://C:/dir/subdir/file.ext"));
					URITest(std::string("file://../dir//subdir/file.ext"));
					URITest(std::string("C:/dir/subdir/file.ext"));
					URITest(std::string("dir/subdir.file.ext"));
					URITest(std::string("/dir/subdir.file.ext"));
					URITest(std::string("../dir/subdir.file.ext"));
					URITest(std::string("mysql://localhost:3306/DB/table"));
				}
				return (0);
			}
		}
	}
}
