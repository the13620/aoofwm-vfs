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
#include <vector>

#include <Aoof-Wm/VFS/Util/Tokenizer.h>


namespace AoofWm
{
	namespace VFS
	{
		namespace Util
		{
			CTokenizer::CTokenizer(const TokString& source)
			{
				_idx = 0;
			}

			CTokenizer::CTokenizer(const TokString& source,
								   const TokString& delimiters,
								   TokStringSizeType startOffset,
								   TokStringSizeType endOffset)
			{
				_idx = 0;
			}

			CTokenizer::~CTokenizer(void)
			{
				Reset();
			}

			TokListSizeType	CTokenizer::GetIndex(void) const
			{
				return (_idx);
			}

			TokString		CTokenizer::GetSource(void) const
			{
				return (_source);
			}

			TokList			CTokenizer::GetTokens(void) const
			{
				return (_tokens);
			}

			TokListSizeType	CTokenizer::GetTokensCount(void) const
			{
				return (_tokens.size());
			}

			void			CTokenizer::Tokenize(const TokString& delimiters,
												 TokStringSizeType startOffset,
												 TokStringSizeType endOffset)
			{

			}

			void			CTokenizer::Tokenize(TokList& tokens,
												 const TokString& delimiters,
												 TokStringSizeType startOffset,
												 TokStringSizeType endOffset)
			{

			}

			void			CTokenizer::Tokenize(const TokString& source,
												 TokList& tokens,
												 const TokString& delimiters,
												 TokStringSizeType startOffset,
												 TokStringSizeType endOffset)
			{
				
			}

			TokList			CTokenizer::Tokenize(const TokString& source,
												 const TokString& delimiters,
												 TokStringSizeType startOffset,
												 TokStringSizeType endOffset)
			{
				TokList				tokens;
				TokStringSizeType	start;
				TokStringSizeType	end;

				if ((endOffset == TokString::npos) || (endOffset > source.size()))
				{
					endOffset = source.size();
				}
				if (startOffset <= endOffset)
				{
					const TokString	src = source.substr(startOffset, endOffset - startOffset);

					start	= src.find_first_not_of(delimiters, 0);
					end		= src.find_first_of(delimiters, start);
					while ((end != TokString::npos) || (start != TokString::npos))
					{
						Token	token = {src.substr(start, end - start), start + startOffset, end != TokString::npos ? end + startOffset : endOffset};

						tokens.push_back(token);
						if (end > endOffset)
								break;
						start	= src.find_first_not_of(delimiters, end);
						end		= src.find_first_of(delimiters, start);
					}
				}
				return (tokens);
			}

			void			CTokenizer::TokenizeByString(const TokString& delimiters,
														 TokStringSizeType startOffset,
														 TokStringSizeType endOffset)
			{

			}

			void			CTokenizer::TokenizeByString(TokList& tokens,
														 const TokString& delimiters,
														 TokStringSizeType startOffset,
														 TokStringSizeType endOffset)
			{

			}

			void			CTokenizer::TokenizeByString(const TokString& source,
														 TokList& tokens,
														 const TokString& delimiters,
														 TokStringSizeType startOffset,
														 TokStringSizeType endOffset)
			{

			}

			TokList			CTokenizer::TokenizeByString(const TokString& source,
														 const TokString& delimiters,
														 TokStringSizeType startOffset,
														 TokStringSizeType endOffset)
			{
				TokList				tokens;
				TokStringSizeType	start;
				TokStringSizeType	end;

				if ((endOffset == TokString::npos) || (endOffset > source.size()))
				{
					endOffset = source.size();
				}
				if (startOffset <= endOffset)
				{
					const TokString	src = source.substr(startOffset, endOffset - startOffset);

					start	= 0;
					end		= src.find(delimiters, 0);
					while ((end != TokString::npos) && (start != TokString::npos))
					{
						Token	token = {src.substr(start, end - start), start + startOffset, end != TokString::npos ? end + startOffset : endOffset};

						tokens.push_back(token);
						if (end > endOffset)
							break;
						start = end + 1;
						end	= src.find(delimiters, start);
					}
				}
				return (tokens);
			}

			bool			CTokenizer::HasNextToken(void)
			{
				return ((_idx + 1) < _tokens.size());
			}

			Token			CTokenizer::NextToken(void)
			{
				return (_tokens.at(++_idx));
			}

			TokString		CTokenizer::NextTokenString(void)
			{
				return (_tokens.at(++_idx).token);
			}

			void			CTokenizer::Clear(void)
			{
				_idx = 0;
				_tokens.clear();
			}

			void			CTokenizer::Reset(void)
			{
				_source = TokString();
				Clear();
			}
		}
	}
}
