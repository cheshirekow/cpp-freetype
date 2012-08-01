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
 *  \file   Parameter.h
 *
 *  \date   Aug 1, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef CPPFREETYPE_PARAMETER_H_
#define CPPFREETYPE_PARAMETER_H_

#include <cppfreetype/types.h>

namespace freetype
{

/// A simple structure used to pass more or less generic parameters to
/// FT_Open_Face.
/**
 *  The ID and function of parameters are driver-specific. See the various
 *  FT_PARAM_TAG_XXX flags for more information.
 */
class Parameter
{
    private:
        void* m_ptr;

    public:
        ULong_t&    tag();  ///< four-byte identification tag
        Pointer_t&  data(); ///< pointer to parameter data
};

} // namespace freetype 

#endif // PARAMETER_H_
