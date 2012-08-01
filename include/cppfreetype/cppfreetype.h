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
 *  \file   cppfreetype.h
 *
 *  \date   Aug 1, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef CPPFREETYPE_CPPFREETYPE_H_
#define CPPFREETYPE_CPPFREETYPE_H_

#include <cppfreetype/types.h>
#include <cppfreetype/Face.h>
#include <cppfreetype/Memory.h>
#include <cppfreetype/ModuleClass.h>
#include <cppfreetype/Library.h>

/// root namespace for freetype
namespace freetype
{
    /// Initialize a new FreeType library object. The set of modules that are
    /// registered by this function is determined at build time.
    /**
     * @param[out]  error FreeType error code. 0 means success.
     * @return      A handle to a new library object
     *
     * @note    In case you want to provide your own memory allocating
     *          routines, use Library::new instead, followed by a call to
     *          Library::add_default_modules (or a series of calls to
     *          Library::add_module).
     *
     * @note    For multi-threading applications each thread should have its
     *          own Library object.
     */
    Library init(Error_t& error);

    /// Destroy a given FreeType library object and all of its children,
    /// including resources, drivers, faces, sizes, etc.
    /**
     *  @param[in]  library     handle to the library object to destroy,
     *                          must have been created with freetype::init
     *  @return FeeType error code. 0 means success
     */
    Error_t done(Library library);


}














#endif // CPPFREETYPE_H_
