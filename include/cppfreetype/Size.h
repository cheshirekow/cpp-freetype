/*
 *  Copyright (C) 2012 Josh Bialkowski (jbialk@mit.edu)
 *
 *  This file is part of cppfreetype.
 *
 *  cppfreetype is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  cppfreetype is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with cppfreetype.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 *  \file   Size.h
 *
 *  \date   Aug 1, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef CPPFREETYPE_SIZE_H_
#define CPPFREETYPE_SIZE_H_

namespace freetype
{

/// A handle to an object used to model a face scaled to a given character
/// size.
/**
 *  Each FT_Face has an active FT_Size object that is used by functions like
 *  FT_Load_Glyph to determine the scaling transformation which is used to
 *  load and hint glyphs and metrics.
 *
 *  You can use FT_Set_Char_Size, FT_Set_Pixel_Sizes, FT_Request_Size or even
 *  FT_Select_Size to change the content (i.e., the scaling values) of the
 *  active FT_Size.
 *
 *  You can use FT_New_Size to create additional size objects for a given
 *  FT_Face, but they won't be used by other functions until you activate it
 *  through FT_Activate_Size. Only one size can be activated at any given time
 *  per face.
 */
class Size
{
    private:
        void*   m_ptr;

    public:
        /// wrap constructor, wraps the underlying FT_SIZE object
        Size( void* ptr );


};

} // namespace freetype 

#endif // SIZE_H_
