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
 *  along with Fontconfigmm.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 *  \file   Library.cpp
 *
 *  \date   Aug 1, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <cppfreetype/Library.h>

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_MODULE_H

namespace freetype
{

/// overload for RefPtr<Library>::reference
template <>
void RefPtr<Library>::reference()
{
    if(m_ptr)
        FT_Reference_Library( m_ptr );
}

template <>
void RefPtr<Library>::dereference()
{
    if(m_ptr)
        FT_Done_Library( m_ptr );
}




//
//Library Library::create( Memory memory, Error_t& error )
//{
//    FT_Library ptr;
//    error = FT_New_Library( (FT_Memory) memory.get_ptr(), &ptr );
//    return Library( (void*) ptr );
//}
//
//void Library::add_default_modules()
//{
//    FT_Add_Default_Modules( (FT_Library) m_ptr );
//}
//
//Module Library::get_module( const char* module_name )
//{
//    return Module( (void*)
//        FT_Get_Module( (FT_Library)m_ptr, module_name )
//    );
//}
//
//Error_t Library::remove_module( Module module )
//{
//    return FT_Remove_Module(
//            (FT_Library)m_ptr,
//            (FT_Module) module.get_ptr() );
//}
//
//Face Library::new_face( const char* filepath,
//                        Long_t      face_index,
//                        Error_t&    error )
//{
//    FT_Face ptr;
//    error = FT_New_Face( (FT_Library)m_ptr, filepath, face_index, &ptr );
//    return Face(ptr);
//}





} // namespace freetype 
