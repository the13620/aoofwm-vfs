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

#ifdef WIN32

#include <string>

#include <Aoof-Wm/VFS/Resource/DirectoryResource.h>


namespace AoofWm
{
	namespace VFS
	{
		namespace Resource
		{
			CDirectoryResource::CDirectoryResource(const std::string& uri) : CAbstractResource(uri)
			{
				_pDirHandle = NULL;
				_pDirData = NULL;
			}
			
			CDirectoryResource::~CDirectoryResource(void)
			{
				
			}
			
			
			const bool				CDirectoryResource::Exists(void) const
			{
				DirStat	dirStat;
				
				if (stat(GetName()->GetPath().substr(0, GetName()->GetPath().length() - 1).c_str(), &dirStat) == 0)
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
	
	
			const bool				CDirectoryResource::Open(void)
			{
				if (_pDirHandle == NULL)
				{
					_pDirHandle = opendir(GetName()->GetPath().c_str());
					if (_pDirHandle != NULL)
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
			
			const bool				CDirectoryResource::Close(void)
			{
				if ((_pDirHandle == NULL) || (closedir(_pDirHandle) == 0))
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
			
			const bool				CDirectoryResource::Create(void)
			{
				if (mkdir(GetName()->GetPath().c_str()) == 0)
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
			
			const bool				CDirectoryResource::Delete(void)
			{
				if (std::remove(GetName()->GetPath().c_str()) == 0)
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
			
			
			const bool				CDirectoryResource::Reset(void)
			{
				if (_pDirHandle != NULL)
				{
					rewinddir(_pDirHandle);
					return (true);
				}
				/*
				 * TODO:
				 * 	-throw exception
				 * 	-setLastError
				 */
				return (false);
			}
			
			const bool				CDirectoryResource::Seek(const unsigned long location)
			{
				if (_pDirHandle != NULL)
				{
					seekdir(_pDirHandle, location);
					return (true);
				}
				/*
				 * TODO:
				 * 	-throw exception
				 * 	-setLastError
				 */
				return (false);
			}
			
			const unsigned long		CDirectoryResource::Tell(void)
			{
				if (_pDirHandle != NULL)
				{
					return (telldir(_pDirHandle));
				}
				/*
				 * TODO:
				 * 	-throw exception
				 * 	-setLastError
				 */
				return (0);
			}
			
					
			const unsigned long		CDirectoryResource::Size(void)
			{
				DirStat	dirStat;
				
				if (stat(GetName()->GetPath().substr(0, GetName()->GetPath().length() - 1).c_str(), &dirStat) == 0)
				{
					return (dirStat.st_size);
				}
				/*
				 * TODO:
				 * 	-throw exception
				 * 	-setLastError
				 */ 
				return (0);
			}
	
	
			const bool				CDirectoryResource::Copy(const RsrcString& name)
			{
				/*
				 * TODO:
				 * 	Recursive directory copy
				 */
				return (true);
			}
			
			const bool				CDirectoryResource::Move(const RsrcString& name)
			{
				return (Rename(name));
			}
			
			const bool				CDirectoryResource::Rename(const RsrcString& name)
			{
				if (_pDirHandle != NULL)
				{
					if (rename(GetName()->GetPath().c_str(), name.c_str()) == 0)
					{
						/*
						 * TODO:
						 *  here we should juste rename the URI
						 */
						return (true);	
					}
					/*
					 * TODO:
					 * -throw exception (message taken from errno)
					 * -setLastError
					 */
					 return (false);
				}
				return (true);
			}
			
			
			const unsigned int		CDirectoryResource::Read(char buffer[], unsigned int size)
			{
				/*
				 *	Don't really allow to do that on a directory... for now :-)
				 */
				return (0);
			}
			
			const unsigned int		CDirectoryResource::Read(char buffer[], unsigned int offset, unsigned int size)
			{
				/*
				 *	Don't really allow to do that on a directory... for now :-)
				 */
				return (0);
			}
			
			const RsrcString*		CDirectoryResource::ReadLine(const RsrcString& delimiter)
			{
				if (_pDirHandle != NULL)
				{
					DirData	*pent;
				
					pent = readdir(_pDirHandle);
					if (pent != NULL)
					{
						return (new std::string(pent->d_name));
					}
					if (errno)
					{// error if errno set.
						/*
				 		* TODO:
				 		* 	-throw exception (message taken from errno)
				 		* 	-setLastError
				 		*/
					}
				}
				/*
				 * TODO:
				 * 	-throw exception (message taken from errno)
				 * 	-setLastError
				 */
				return (NULL);
			}
			
			const RsrcString*		CDirectoryResource::ReadLine(const char delimiter)
			{
				return (ReadLine());
			}
			
			const RsrcStringList*	CDirectoryResource::ReadLines(const RsrcString& delimiter)
			{
				if (_pDirHandle != NULL)
				{
					RsrcStringList*		pRsrcStringList;
					const RsrcString*	pLine;
				
					pRsrcStringList = new RsrcStringList();
					while ((pLine = ReadLine()) != NULL)
					{
						pRsrcStringList->push_back(*pLine);
						delete pLine;
					}
					return (pRsrcStringList);
				}
				return (NULL);
			}
			
			const RsrcStringList*	CDirectoryResource::ReadLines(const char delimiter)
			{
				if (_pDirHandle != NULL)
				{
					RsrcStringList*		pRsrcStringList;
					const RsrcString*	pLine;
					
					pRsrcStringList = new RsrcStringList();
					while ((pLine = ReadLine()) != NULL)
					{
						pRsrcStringList->push_back(*pLine);
						delete pLine;
					}
					return (pRsrcStringList);
				}
				return (NULL);
			}
			
			
			const bool				CDirectoryResource::IsWritable(void) const
			{
				if (Exists())
				{
					DirStat	dirStat;
				
					if (stat(GetName()->GetPath().substr(0, GetName()->GetPath().length() - 1).c_str(), &dirStat) == 0)
					{
						return ((dirStat.st_mode & O_RDWR) == O_RDWR);
					}
				}
				return (false);
			}
			
			const bool				CDirectoryResource::IsHidden(void) const
			{
				return (GetName()->GetBaseName().substr(0, 1).c_str()[0] == '.');
			}
			
			const bool				CDirectoryResource::IsReadable(void) const
			{
				if (Exists())
				{
					DirStat	dirStat;
				
					if (stat(GetName()->GetPath().substr(0, GetName()->GetPath().length() - 1).c_str(), &dirStat) == 0)
					{
						return ((dirStat.st_mode & O_RDONLY) == O_RDONLY);
					}
				}
				return (false);
			}
			
			const bool				CDirectoryResource::IsOpen(void) const
			{
				return (_pDirHandle != NULL);
			}
		}
	}
}

#endif
