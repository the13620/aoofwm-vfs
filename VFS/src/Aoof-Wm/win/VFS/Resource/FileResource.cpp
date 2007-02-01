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

#include <Aoof-Wm/VFS/Resource/FileResource.h>
#include <Aoof-Wm/VFS/Resource/ResourceName.h>
#include <Aoof-Wm/VFS/Util/String/StringUtil.h>


namespace AoofWm
{
	namespace VFS
	{
		namespace Resource
		{
			CFileResource::CFileResource(const std::string& uri) : CAbstractResource(uri)
			{
				
			}
			
			CFileResource::~CFileResource(void)
			{
				
			}
			
			
			const bool				CFileResource::Exists(void) const
			{
				WIN32_FILE_ATTRIBUTE_DATA	attr;

				if (IsOpen() || (GetFileAttributesEx(GetName()->GetURI().GetFullPath().c_str(), GetFileExInfoStandard, &attr) != 0))
				{
					return (!(attr.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY));
				}
				/*
				 * TODO:
				 * 	-throw exception
				 * 	-setLastError
				 */ 
				return (false);	
			}
	
	
			const bool				CFileResource::Open(void)
			{
				if (IsOpen() == false)
				{
					_stream.open(GetName()->GetURI().GetFullPath().c_str());
					if (_stream.is_open())
					{
						Reset();
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
			
			const bool				CFileResource::Close(void)
			{
				if (IsOpen() == false)
				{
					_stream.close();
					return (_stream.is_open() == false);
				}
				/*
				 * TODO:
				 * 	-throw exception (message taken from errno)
				 * 	-setLastError
				 */ 
				return (false);	
			}
			
			const bool				CFileResource::Create(void)
			{
				if (Exists())
				{
					return (Open());
				}
				if (IsOpen() == false)
				{
					_stream.open(GetName()->GetURI().GetFullPath().c_str(), std::ios::out);
					if (_stream.is_open())
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
			
			const bool				CFileResource::Delete(void)
			{
				if (IsOpen())
					Close();
				if (std::remove(GetName()->GetURI().GetFullPath().c_str()) == 0)
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
			
			
			const bool				CFileResource::Reset(void)
			{
				return (Seek(0));
			}
			
			const bool				CFileResource::Seek(const unsigned long location)
			{
				if (IsOpen())
				{
					_stream.seekp(location);
					_stream.seekg(location);
					_stream.clear(std::ios::goodbit);
					return (true);
				}
				return (false);
			}
			
			const unsigned long		CFileResource::Tell(void)
			{
				if (IsOpen())
				{
					return (_stream.tellg());
				}
				return (0);
			}
			
					
			const unsigned long		CFileResource::Size(void)
			{
				LARGE_INTEGER		lFileSize;

				if (GetFileSizeEx(_pFileHandle, &lFileSize) != 0)
				{
					return (lFileSize.QuadPart);
				}
				/*
				 * TODO:
				 * 	-throw exception
				 * 	-setLastError
				 */ 
				return (0);
			}
	
	
			const bool				CFileResource::Copy(const RsrcString& name)
			{
				std::string			pathFrom(GetName()->GetURI().GetFullPath());
				std::string			pathTo(name);
				bool				bStatus	= false;

				AoofWm::VFS::Util::String::CStringUtil::slashesToAntiSlashes(pathFrom);
				AoofWm::VFS::Util::String::CStringUtil::slashesToAntiSlashes(pathTo);
				if (Exists() && (CopyFile(pathFrom.c_str(), pathTo.c_str(), false) != 0))
					bStatus = true;
				else
				{
					// TODO: GetLastError
				}
				return (bStatus);
			}
			
			const bool				CFileResource::Move(const RsrcString& name)
			{
				return (Rename(name));
			}
			
			const bool				CFileResource::Rename(const RsrcString& name)
			{
				if (rename(GetName()->GetURI().GetFullPath().c_str(), name.c_str()) == 0)
				{
					delete _pRsrcName;
					_pRsrcName = new AoofWm::VFS::Resource::CResourceName(&(*this), name);
					return (true);	
				}
				if (errno)
				{
					
				}
				/*
				 * TODO:
				 * 	-throw exception (message taken from errno)
				 * 	-setLastError
				 */ 
				return (false);	
			}
			
			
			const unsigned int		CFileResource::Read(char buffer[], unsigned int size)
			{
				if (IsOpen())
				{
					/*
					 * TODO: no time, later
					 *  mostly use ReadLinr
					 */
				}
				return (0);
			}
			
			const unsigned int		CFileResource::Read(char buffer[], unsigned int offset, unsigned int size)
			{
				if (IsOpen())
				{
					/*
					 * TODO: no time, later
					 *  mostly use ReadLinr
					 */
				}
				return (0);
			}
			
			const RsrcString*		CFileResource::ReadLine(const RsrcString& delimiter)
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
			
			const RsrcString*		CFileResource::ReadLine(const char delimiter)
			{
				if (IsOpen())
				{
					if (_stream.eof() == false)
					{
						RsrcString*	pInput = new RsrcString();
						
						std::getline(_stream, *pInput, delimiter);
						return (pInput);
					}
				}
				return (NULL);
			}
			
			const RsrcStringList*	CFileResource::ReadLines(const RsrcString& delimiter)
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
			
			const RsrcStringList*	CFileResource::ReadLines(const char delimiter)
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
			
			
			const bool				CFileResource::IsWritable(void) const
			{
				if (Exists())
				{
					//FileStat	fileStat;
				
					//if (stat(GetName()->GetPath().c_str(), &fileStat) == 0)
					//{
					//	return ((fileStat.st_mode & O_RDWR) == O_RDWR);
					//}
				}
				return (false);
			}
			
			const bool				CFileResource::IsHidden(void) const
			{
				if (Exists())
				{
					WIN32_FILE_ATTRIBUTE_DATA attr;
				
					if (GetFileAttributesEx(GetName()->GetURI().GetFullPath().c_str(), GetFileExInfoStandard, &attr) != 0)
					{
						return (Exists() && (attr.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN));
					}
					// TODO: GetLastError
				}
				return (false);
			}
			
			const bool				CFileResource::IsReadable(void) const
			{
				if (Exists())
				{
					//FileStat	fileStat;
				
					//if (stat(GetName()->GetURI().GetFullPath().c_str(), &fileStat) == 0)
					//{
					//	return ((fileStat.st_mode & O_RDONLY) == O_RDONLY);
					//}
				}
				return (false);
			}
			
			const bool				CFileResource::IsOpen(void) const
			{
				return ((const_cast<std::fstream*>(&_stream))->is_open());
			}
			
			const bool				CFileResource::IsOpen(void)
			{
				return (_stream.is_open());
			}
		}
	}
}


#endif
