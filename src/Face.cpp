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
 *  \file   Face.cpp
 *
 *  \date   Aug 1, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#include <cppfreetype/Face.h>

#include <ft2build.h>
#include FT_FREETYPE_H

namespace freetype
{

/// overload for RefPtr<Face>::reference
template <>
void RefPtr<Face>::reference()
{
    if(m_ptr)
        FT_Reference_Face( m_ptr );
}

/// overload for RefPtr<Face>::dereference
template <>
void RefPtr<Face>::dereference()
{
    if(m_ptr)
        FT_Done_Face( m_ptr );
}

/// -------------------------------------------------------------------
///                    Structure Accessors
/// -------------------------------------------------------------------



Long_t& FaceDelegate::num_faces()
{
    return (m_ptr)->num_faces;
}

const Long_t& FaceDelegate::num_faces() const
{
    return (m_ptr)->num_faces;
}

Long_t& FaceDelegate::face_index()
{
    return (m_ptr)->face_index;
}

const Long_t& FaceDelegate::face_index() const
{
    return (m_ptr)->face_index;
}

Long_t& FaceDelegate::face_flags()
{
    return (m_ptr)->face_flags;
}

const Long_t& FaceDelegate::face_flags() const
{
    return (m_ptr)->face_flags;
}

Long_t& FaceDelegate::style_flags()
{
    return (m_ptr)->style_flags;
}

const Long_t& FaceDelegate::style_flags() const
{
    return (m_ptr)->style_flags;
}

Long_t& FaceDelegate::num_glyphs()
{
    return (m_ptr)->num_glyphs;
}

const Long_t& FaceDelegate::num_glyphs() const
{
    return (m_ptr)->num_glyphs;
}

String_t* FaceDelegate::family_name()
{
    return (m_ptr)->family_name;
}

const String_t* FaceDelegate::family_name() const
{
    return (m_ptr)->family_name;
}

String_t* FaceDelegate::style_name()
{
    return (m_ptr)->style_name;
}

const String_t* FaceDelegate::style_name() const
{
    return (m_ptr)->style_name;
}

Int_t& FaceDelegate::num_fixed_sizes()
{
    return (m_ptr)->num_fixed_sizes;
}

const Int_t& FaceDelegate::num_fixed_sizes() const
{
    return (m_ptr)->num_fixed_sizes;
}

Int_t& FaceDelegate::num_charmaps()
{
    return (m_ptr)->num_charmaps;
}

const Int_t& FaceDelegate::num_charmaps() const
{
    return (m_ptr)->num_charmaps;
}

UShort_t& FaceDelegate::units_per_EM()
{
    return (m_ptr)->units_per_EM;
}

const UShort_t& FaceDelegate::units_per_EM() const
{
    return (m_ptr)->units_per_EM;
}

Short_t& FaceDelegate::ascender()
{
    return (m_ptr)->ascender;
}

const Short_t& FaceDelegate::ascender() const
{
    return (m_ptr)->ascender;
}

Short_t& FaceDelegate::descender()
{
    return (m_ptr)->descender;
}

const Short_t& FaceDelegate::descender() const
{
    return (m_ptr)->descender;
}

Short_t& FaceDelegate::height()
{
    return (m_ptr)->height;
}

const Short_t& FaceDelegate::height() const
{
    return (m_ptr)->height;
}

Short_t& FaceDelegate::max_advance_width()
{
    return (m_ptr)->max_advance_width;
}

const Short_t& FaceDelegate::max_advance_width() const
{
    return (m_ptr)->max_advance_width;
}

Short_t& FaceDelegate::max_advance_height()
{
    return (m_ptr)->max_advance_height;
}

const Short_t& FaceDelegate::max_advance_height() const
{
    return (m_ptr)->max_advance_height;
}

Short_t& FaceDelegate::underline_position()
{
    return (m_ptr)->underline_position;
}

const Short_t& FaceDelegate::underline_position() const
{
    return (m_ptr)->underline_position;
}

Short_t& FaceDelegate::underline_thickness()
{
    return (m_ptr)->underline_thickness;
}

const Short_t& FaceDelegate::underline_thickness() const
{
    return (m_ptr)->underline_thickness;
}

bool FaceDelegate::has_horizontal()
{
    return FT_HAS_HORIZONTAL( (m_ptr) );
}

bool FaceDelegate::has_vertical()
{
    return FT_HAS_VERTICAL( (m_ptr) );
}

bool FaceDelegate::has_kerning()
{
    return FT_HAS_KERNING( (m_ptr) );
}

bool FaceDelegate::is_scalable()
{
    return FT_IS_SCALABLE( (m_ptr) );
}

bool FaceDelegate::is_sfnt()
{
    return FT_IS_SFNT( (m_ptr) );
}

bool FaceDelegate::is_fixed_width()
{
    return FT_IS_FIXED_WIDTH( (m_ptr) );
}

bool FaceDelegate::has_fixed_sizes()
{
    return FT_HAS_FIXED_SIZES( (m_ptr) );
}

bool FaceDelegate::has_fast_glyphs()
{
    return FT_HAS_FAST_GLYPHS( (m_ptr) );
}

bool FaceDelegate::has_glyph_names()
{
    return FT_HAS_GLYPH_NAMES( (m_ptr) );
}

bool FaceDelegate::has_multiple_masters()
{
    return FT_HAS_MULTIPLE_MASTERS( (m_ptr) );
}

bool FaceDelegate::is_cid_keyed()
{
    return FT_IS_CID_KEYED( (m_ptr) );
}

bool FaceDelegate::is_tricky()
{
    return FT_IS_TRICKY( (m_ptr) );
}

/// -------------------------------------------------------------------
///                       Member Functions
/// -------------------------------------------------------------------
//
//Error_t Face::select_size(Int_t strike_index)
//{
//    return FT_Select_Size((FT_Face)(m_ptr), strike_index);
//}
//
//Error_t Face::set_char_size(F26Dot6_t char_width, F26Dot6_t char_height,
//        UInt_t horz_resolution, UInt_t vert_resolution)
//{
//    return FT_Set_Char_Size((FT_Face)(m_ptr), char_width, char_height,
//            horz_resolution, vert_resolution);
//}
//
//
//Error_t Face::set_pixel_sizes(UInt_t pixel_width, UInt_t pixel_height)
//{
//    return FT_Set_Pixel_Sizes((FT_Face)(m_ptr), pixel_width, pixel_height);
//}
//
//Error_t Face::load_glyph(UInt_t glyph_index, Int32_t load_flags)
//{
//    return FT_Load_Glyph( (FT_Face)m_ptr, glyph_index, load_flags );
//}
//
//Error_t Face::load_char(ULong_t char_code, Int32_t load_flags)
//{
//    return FT_Load_Char( (FT_Face)m_ptr, char_code, load_flags );
//}
//
//Error_t Face::get_glyph_name(
//                        UInt_t      glyph_index,
//                        Pointer_t   buffer,
//                        UInt_t      buffer_max )
//{
//    return FT_Get_Glyph_Name( (FT_Face)m_ptr, glyph_index, buffer, buffer_max );
//}
//
//const char* Face::get_postscript_name()
//{
//    return FT_Get_Postscript_Name( (FT_Face)m_ptr );
//}
//
//Error_t Face::select_charmap( Encoding encoding )
//{
//    return FT_Select_Charmap( (FT_Face)m_ptr, (FT_Encoding)encoding );
//}
//
//UInt_t Face::get_char_index( ULong_t charcode )
//{
//    return FT_Get_Char_Index( (FT_Face)m_ptr, charcode );
//}
//
//ULong_t Face::get_first_char( UInt_t& agindex )
//{
//    return FT_Get_First_Char( (FT_Face)m_ptr, &agindex );
//}
//
//ULong_t Face::get_next_char( ULong_t char_code, UInt_t& agindex )
//{
//    return FT_Get_Next_Char( (FT_Face)m_ptr, char_code, &agindex );
//}
//
//UInt_t Face::get_name_index( String_t* glyph_name )
//{
//    return FT_Get_Name_Index( (FT_Face)m_ptr, glyph_name) ;
//}
//
//UShort_t Face::get_fstype_flags()
//{
//    return FT_Get_FSType_Flags( (FT_Face)m_ptr );
//}

} // namespace freetype 
