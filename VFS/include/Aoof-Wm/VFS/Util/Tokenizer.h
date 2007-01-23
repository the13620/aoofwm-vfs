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


#ifndef __AOOFWM_VFS_UTIL_TOKENIZER_H__
# define __AOOFWM_VFS_UTIL_TOKENIZER_H__

# include <string>
# include <vector>


namespace AoofWm
{
	namespace VFS
	{
		namespace Util
		{
			typedef std::string				TokString;
			typedef TokString::size_type	TokStringSizeType;
			typedef struct					sToken
			{
				TokString					token;
				TokStringSizeType			startOffset;
				TokStringSizeType			endOffset;
			}								Token;
			typedef std::vector<Token>		TokList;
			typedef TokList::size_type		TokListSizeType;


			class CTokenizer
			{
			private:
				TokString			_source;
				TokList				_tokens;
				TokListSizeType		_idx;
				TokString			_delimiters;
				TokStringSizeType	_startOffset;
				TokStringSizeType	_endOffset;


			public:
				CTokenizer(const TokString& source);
				CTokenizer(const TokString& source,
						   const TokString& delimiters = " \t",
						   TokStringSizeType startOffset = 0,
						   TokStringSizeType endOffset = -1);
				~CTokenizer(void);

				TokListSizeType	GetIndex(void) const;
				TokString		GetSource(void) const;
				TokList			GetTokens(void) const;
				TokListSizeType	GetTokensCount(void) const;

				void			Tokenize(const TokString& delimiters = " \t",
										 TokStringSizeType startOffset = 0,
										 TokStringSizeType endOffset = -1);
				void			Tokenize(TokList& tokens,
										 const TokString& delimiters = " \t",
										 TokStringSizeType startOffset = 0,
										 TokStringSizeType endOffset = -1);
				void			Tokenize(const TokString& source,
										 TokList& tokens,
										 const TokString& delimiters = " \t",
										 TokStringSizeType startOffset = 0,
										 TokStringSizeType endOffset = -1);
				static TokList	Tokenize(const TokString& source,
										 const TokString& delimiters = " \t",
										 TokStringSizeType startOffset = 0,
										 TokStringSizeType endOffset = TokString::npos);
				void			TokenizeByString(const TokString& delimiters = " ",
												 TokStringSizeType startOffset = 0,
												 TokStringSizeType endOffset = TokString::npos);
				void			TokenizeByString(TokList& tokens,
												 const TokString& delimiters = " ",
												 TokStringSizeType startOffset = 0,
												 TokStringSizeType endOffset = TokString::npos);
				void			TokenizeByString(const TokString& source,
												 TokList& tokens,
												 const TokString& delimiters = " ",
												 TokStringSizeType startOffset = 0,
												 TokStringSizeType endOffset = TokString::npos);
				static TokList	TokenizeByString(const TokString& source,
												 const TokString& delimiters = " ",
												 TokStringSizeType startOffset = 0,
												 TokStringSizeType endOffset = TokString::npos);

				bool			HasNextToken(void);
				Token			NextToken(void);
				TokString		NextTokenString(void);
				void			Clear(void);
				void			Reset(void);
			};
		}
	}
}


#endif // __AOOFWM_VFS_UTIL_TOKENIZER_H__
