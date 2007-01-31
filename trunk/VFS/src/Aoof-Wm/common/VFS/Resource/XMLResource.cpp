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

#include <Aoof-Wm/VFS/Resource/XMLResource.h>


namespace AoofWm
{
	namespace VFS
	{
		namespace Resource
		{
			CXMLResource::CXMLResource(const std::string& uri) : CAbstractResource(uri)
			{
				
			}
			
			CXMLResource::~CXMLResource(void)
			{
				
			}
			
			
			const bool				CXMLResource::Exists(void) const
			{
				if (IsOpen())
				{
					return (true);	
				}
				/*
				 * TODO:
				 * 	-throw exception
				 * 	-setLastError
				 */ 
				return (false);	
			}
	
	
			const bool				CXMLResource::Open(void)
			{
				if (IsOpen() == false)
				{
					return (true);	
					/*
				 	* TODO:
				 	* 	-throw exception
				 	* 	-setLastError
				 	*/
				 	return (false);	
				}
				return (true); // already open
			}
			
			const bool				CXMLResource::Close(void)
			{
				if (IsOpen())
				{
					return (true);
				}
				/*
				 * TODO:
				 * 	-throw exception (message taken from errno)
				 * 	-setLastError
				 */ 
				return (false);	
			}
			
			const bool				CXMLResource::Create(void)
			{
				if (Exists())
				{
					return (Open());
				}
				if (IsOpen() == false)
				{

					if (IsOpen())
					{
						return (true);	
					}
					/*
				 	* TODO:
				 	* 	-throw exception
				 	* 	-setLastError
				 	*/
				 	return (false);	
				}
				return (true); // already open
			}
			
			const bool				CXMLResource::Delete(void)
			{
				if (IsOpen())
					Close();
				if (std::remove(GetName()->GetPath().c_str()) == 0)
				{
					return (true);
				}
				/*
			 	* TODO:
			 	* 	-throw exception
			 	* 	-setLastError
			 	*/
				return (false);	
			}
			
			
			const bool				CXMLResource::Reset(void)
			{
				return (Seek(0));
			}
			
			const bool				CXMLResource::Seek(const unsigned long location)
			{
				if (IsOpen())
				{
					return (true);
				}
				return (false);
			}
			
			const unsigned long		CXMLResource::Tell(void)
			{
				if (IsOpen())
				{
					return (0);
				}
				return (0);
			}
			
					
			const unsigned long		CXMLResource::Size(void)
			{
				
				/*
				 * TODO:
				 * 	-throw exception
				 * 	-setLastError
				 */ 
				return (0);
			}
	
	
			const bool				CXMLResource::Copy(const RsrcString& name)
			{
				
				return (false);
			}
			
			const bool				CXMLResource::Move(const RsrcString& name)
			{
				return (Rename(name));
			}
			
			const bool				CXMLResource::Rename(const RsrcString& name)
			{
				if (rename(GetName()->GetPath().c_str(), name.c_str()) == 0)
				{
					return (true);	
				}
				/*
				 * TODO:
				 * 	-throw exception (message taken from errno)
				 * 	-setLastError
				 */ 
				return (false);	
			}
			
			
			const unsigned int		CXMLResource::Read(char buffer[], unsigned int size)
			{
				if (IsOpen())
				{
	
				}
				return (0);
			}
			
			const unsigned int		CXMLResource::Read(char buffer[], unsigned int offset, unsigned int size)
			{
				if (IsOpen())
				{
	
				}
				return (0);
			}
			
			const RsrcString*		CXMLResource::ReadLine(const RsrcString& delimiter)
			{
				if (IsOpen())
				{
					/*
					 * TODO: no time, later
					 */
					return (ReadLine(delimiter.c_str()[0]));
				}
				return (NULL);
			}
			
			const RsrcString*		CXMLResource::ReadLine(const char delimiter)
			{
				if (IsOpen())
				{
				}
				return (NULL);
			}
			
			const RsrcStringList*	CXMLResource::ReadLines(const RsrcString& delimiter)
			{
				if (IsOpen())
				{
					RsrcStringList*		pRsrcStringList;
					const RsrcString*	pLine;
					
					pRsrcStringList = new RsrcStringList();
					while ((pLine = ReadLine(delimiter)) != NULL)
					{
						pRsrcStringList->push_back(*pLine);
						delete pLine;
					}
					return (pRsrcStringList);
				}
				return (NULL);
			}
			
			const RsrcStringList*	CXMLResource::ReadLines(const char delimiter)
			{
				if (IsOpen())
				{
					RsrcStringList*		pRsrcStringList;
					const RsrcString*	pLine;
					
					pRsrcStringList = new RsrcStringList();
					while ((pLine = ReadLine(delimiter)) != NULL)
					{
						pRsrcStringList->push_back(*pLine);
						delete pLine;
					}
					return (pRsrcStringList);
				}
				return (NULL);
			}
			
			
			const bool				CXMLResource::IsWritable(void) const
			{
				if (Exists())
				{
				}
				return (false);
			}
			
			const bool				CXMLResource::IsHidden(void) const
			{
				return (Exists() && (GetName()->GetBaseName().substr(0, 1).c_str()[0] == '.'));
			}
			
			const bool				CXMLResource::IsReadable(void) const
			{
				if (Exists())
				{

				}
				return (false);
			}
			
			const bool				CXMLResource::IsOpen(void) const
			{
				return (false);
			}
			
			const bool				CXMLResource::IsOpen(void)
			{
				return (false);
			}
		}
	}
}
