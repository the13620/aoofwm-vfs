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
				_dirHandle		= INVALID_HANDLE_VALUE;
				ResetDirData();				
			}
			
			CDirectoryResource::~CDirectoryResource(void)
			{
				
			}

			const void				CDirectoryResource::ResetDirData(void)
			{
				_dirData	= EmptyData;
				_dirStatus	= false;
			}
			
			
			const bool				CDirectoryResource::Exists(void) const
			{
				WIN32_FILE_ATTRIBUTE_DATA	attr;

				if (IsOpen() || (GetFileAttributesEx(GetName()->GetURI().GetFullPath().c_str(), GetFileExInfoStandard, &attr) != 0))
				{
					return (IsOpen() || attr.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
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
				if (IsOpen() == false)
				{
					std::string	dirSpecifications	= GetName()->GetURI().GetFullPath() + "\\*";

					_dirHandle = FindFirstFile(dirSpecifications.c_str(), &_dirData);
					if (IsOpen())
					{
						_dirStatus = true;
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
				if ((IsOpen() == false) || (FindClose(_dirHandle) != 0))
				{
					_dirHandle = InvalidHandle;
					return (true);
				}
				_dirHandle = InvalidHandle;
				/*
				 * TODO:
				 * 	-throw exception (message taken from errno)
				 * 	-setLastError
				 */ 
				return (false);	
			}
			
			const bool				CDirectoryResource::Create(void)
			{
				bool	status			= true;

				if (IsOpen() == false)
				{
					char		DirName[256];
					const char*	pPath			= this->GetName()->GetURI().GetFullPath().c_str();
					char*		pDirName		= DirName;
					
					for (int i = 0; (pPath[i] != '\0') && (i < 256); i++)
					{
						if (((pPath[i] == '\\') || (pPath[i] == '/')) &&
							(pPath[i + 1] != '\0')) // avoid creating same directory twice
						{
							if ((i > 0) && (pPath[i - 1] != ':')) // do not care about root directories
							{
								CreateDirectory(DirName, NULL);
							}
						}
						*pDirName++ = pPath[i];
						*pDirName = '\0';
					}
					status = (CreateDirectory(DirName, NULL) != 0);
				}
				if (status == false)
				{
					/*
					 * TODO:
					 * 	-throw exception (message taken from errno)
					 * 	-setLastError
					 */ 
				}
				return (status);
			}
			
			const bool				CDirectoryResource::Delete(void)
			{
				if (IsOpen())
					Close();
				if (std::remove(GetName()->GetURI().GetFullPath().c_str()) == 0)
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
				if (IsOpen())
				{
					//rewinddir(_pDirHandle);
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
				if (IsOpen())
				{
					//seekdir(_pDirHandle, location);
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
				if (IsOpen())
				{
					return (0/*telldir(_pDirHandle)*/);
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
				/*DirStat	dirStat;
				
				if (stat(GetName()->GetPath().substr(0, GetName()->GetPath().length() - 1).c_str(), &dirStat) == 0)
				{
					return (dirStat.st_size);
				}*/
				/*
				 * TODO:
				 * 	-throw exception
				 * 	-setLastError
				 */ 
				return (0);
			}
	
	
			const bool				CDirectoryResource::Copy(const RsrcString& name)
			{
				bool				status	= false;
				SHFILEOPSTRUCT		shFileOp;
				char				pathFrom[4096];
				char				pathTo[4096];

				::ZeroMemory(&shFileOp, sizeof(shFileOp));
				::ZeroMemory(pathFrom, 4096);
				::ZeroMemory(pathTo, 4096);
				::GetShortPathName(GetName()->GetURI().GetFullPath().c_str(), pathFrom, 4095);
				::GetShortPathName(name.c_str(), pathTo, 4095);
				shFileOp.hwnd	= NULL;
				shFileOp.wFunc	= FO_COPY;
				shFileOp.pFrom	= pathFrom;
				shFileOp.pTo	= pathTo;
				shFileOp.fFlags	= FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_SILENT;
				shFileOp.fFlags	|= FOF_NORECURSION;
				if ((::SHFileOperation(&shFileOp)) == 0)
					status = true;
				else
				{
					//std::cout << "pathFrom:\t" << GetName()->GetURI().GetFullPath().c_str() << std::endl;
					//std::cout << "pathFrom:\t" << pathFrom << std::endl;
					//std::cout << "pathTo:\t" << name.c_str() << std::endl;
					//std::cout << "pathTo:\t" << pathTo << std::endl;
					//std::cout << "" << ::GetLastError() << std::endl;
					// TODO: setLastError
				}
				return (status);
			}
			
			const bool				CDirectoryResource::Move(const RsrcString& name)
			{
				return (Rename(name));
			}
			
			const bool				CDirectoryResource::Rename(const RsrcString& name)
			{
				if (rename(GetName()->GetURI().GetFullPath().c_str(), name.c_str()) == 0)
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
				if (IsOpen())
				{
					DWORD	dwError;

					if (_dirStatus == true)
					{
						std::string*	pFileName	= new std::string(_dirData.cFileName);

						ResetDirData();
						return (pFileName);
					}
					if ((FindNextFile(_dirHandle, &_dirData) != 0))
					{
						return (new std::string(_dirData.cFileName));
					}
					if (GetLastError() != ERROR_NO_MORE_FILES)
					{
						// smthg wrong happened here
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
				if (IsOpen())
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
				if (IsOpen())
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
					/*DirStat	dirStat;
				
					if (stat(GetName()->GetPath().substr(0, GetName()->GetPath().length() - 1).c_str(), &dirStat) == 0)
					{
						return ((dirStat.st_mode & O_RDWR) == O_RDWR);
					}*/
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
					/*DirStat	dirStat;
				
					if (stat(GetName()->GetPath().substr(0, GetName()->GetPath().length() - 1).c_str(), &dirStat) == 0)
					{
						return ((dirStat.st_mode & O_RDONLY) == O_RDONLY);
					}*/
				}
				return (false);
			}
			
			const bool				CDirectoryResource::IsOpen(void) const
			{
				return (_dirHandle != INVALID_HANDLE_VALUE);
			}
		}
	}
}

#endif
