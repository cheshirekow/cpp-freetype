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

/// -------------------------------------------------------------------
///                       Wrapper Overhead
/// -------------------------------------------------------------------

Face::Face(void* ptr, bool reference)
{
    m_ptr = ptr;
    if (reference)
        FT_Reference_Face((FT_Face)(ptr));
}
Face::Face(const Face& other)
{
    if (m_ptr)
        FT_Done_Face ((FT_Face)(m_ptr));

    m_ptr  = other.m_ptr;
    if (m_ptr)
        FT_Reference_Face((FT_Face)(m_ptr));
}

Face& Face::operator =(const Face& other)
{
    if (m_ptr)
        FT_Done_Face ((FT_Face)(m_ptr));

    m_ptr = other.m_ptr;

    if (m_ptr)
        FT_Reference_Face((FT_Face)(m_ptr));

    return *this;
}

Face::~Face()
{
    if (m_ptr)
        FT_Done_Face ((FT_Face)(m_ptr));
}

bool Face::is_valid()
{
    return (m_ptr != 0);
}



/// -------------------------------------------------------------------
///                    Structure Accessors
/// -------------------------------------------------------------------



Long_t& Face::num_faces()
{
    return ((FT_Face)m_ptr)->num_faces;
}

const Long_t& Face::num_faces() const
{
    return ((FT_Face)m_ptr)->num_faces;
}

Long_t& Face::face_index()
{
    return ((FT_Face)m_ptr)->face_index;
}

const Long_t& Face::face_index() const
{
    return ((FT_Face)m_ptr)->face_index;
}

Long_t& Face::face_flags()
{
    return ((FT_Face)m_ptr)->face_flags;
}

const Long_t& Face::face_flags() const
{
    return ((FT_Face)m_ptr)->face_flags;
}

Long_t& Face::style_flags()
{
    return ((FT_Face)m_ptr)->style_flags;
}

const Long_t& Face::style_flags() const
{
    return ((FT_Face)m_ptr)->style_flags;
}

Long_t& Face::num_glyphs()
{
    return ((FT_Face)m_ptr)->num_glyphs;
}

const Long_t& Face::num_glyphs() const
{
    return ((FT_Face)m_ptr)->num_glyphs;
}

String_t* Face::family_name()
{
    return ((FT_Face)m_ptr)->family_name;
}

const String_t* Face::family_name() const
{
    return ((FT_Face)m_ptr)->family_name;
}

String_t* Face::style_name()
{
    return ((FT_Face)m_ptr)->style_name;
}

const String_t* Face::style_name() const
{
    return ((FT_Face)m_ptr)->style_name;
}

Int_t& Face::num_fixed_sizes()
{
    return ((FT_Face)m_ptr)->num_fixed_sizes;
}

const Int_t& Face::num_fixed_sizes() const
{
    return ((FT_Face)m_ptr)->num_fixed_sizes;
}

Int_t& Face::num_charmaps()
{
    return ((FT_Face)m_ptr)->num_charmaps;
}

const Int_t& Face::num_charmaps() const
{
    return ((FT_Face)m_ptr)->num_charmaps;
}

UShort_t& Face::units_per_EM()
{
    return ((FT_Face)m_ptr)->units_per_EM;
}

const UShort_t& Face::units_per_EM() const
{
    return ((FT_Face)m_ptr)->units_per_EM;
}

Short_t& Face::ascender()
{
    return ((FT_Face)m_ptr)->ascender;
}

const Short_t& Face::ascender() const
{
    return ((FT_Face)m_ptr)->ascender;
}

Short_t& Face::descender()
{
    return ((FT_Face)m_ptr)->descender;
}

const Short_t& Face::descender() const
{
    return ((FT_Face)m_ptr)->descender;
}

Short_t& Face::height()
{
    return ((FT_Face)m_ptr)->height;
}

const Short_t& Face::height() const
{
    return ((FT_Face)m_ptr)->height;
}

Short_t& Face::max_advance_width()
{
    return ((FT_Face)m_ptr)->max_advance_width;
}

const Short_t& Face::max_advance_width() const
{
    return ((FT_Face)m_ptr)->max_advance_width;
}

Short_t& Face::max_advance_height()
{
    return ((FT_Face)m_ptr)->max_advance_height;
}

const Short_t& Face::max_advance_height() const
{
    return ((FT_Face)m_ptr)->max_advance_height;
}

Short_t& Face::underline_position()
{
    return ((FT_Face)m_ptr)->underline_position;
}

const Short_t& Face::underline_position() const
{
    return ((FT_Face)m_ptr)->underline_position;
}

Short_t& Face::underline_thickness()
{
    return ((FT_Face)m_ptr)->underline_thickness;
}

const Short_t& Face::underline_thickness() const
{
    return ((FT_Face)m_ptr)->underline_thickness;
}

bool Face::has_horizontal()
{
    return FT_HAS_HORIZONTAL( ((FT_Face)m_ptr) );
}

bool Face::has_vertical()
{
    return FT_HAS_VERTICAL( ((FT_Face)m_ptr) );
}

bool Face::has_kerning()
{
    return FT_HAS_KERNING( ((FT_Face)m_ptr) );
}

bool Face::is_scalable()
{
    return FT_IS_SCALABLE( ((FT_Face)m_ptr) );
}

bool Face::is_sfnt()
{
    return FT_IS_SFNT( ((FT_Face)m_ptr) );
}

bool Face::is_fixed_width()
{
    return FT_IS_FIXED_WIDTH( ((FT_Face)m_ptr) );
}

bool Face::has_fixed_sizes()
{
    return FT_HAS_FIXED_SIZES( ((FT_Face)m_ptr) );
}

bool Face::has_fast_glyphs()
{
    return FT_HAS_FAST_GLYPHS( ((FT_Face)m_ptr) );
}

bool Face::has_glyph_names()
{
    return FT_HAS_GLYPH_NAMES( ((FT_Face)m_ptr) );
}

bool Face::has_multiple_masters()
{
    return FT_HAS_MULTIPLE_MASTERS( ((FT_Face)m_ptr) );
}

bool Face::is_cid_keyed()
{
    return FT_IS_CID_KEYED( ((FT_Face)m_ptr) );
}

bool Face::is_tricky()
{
    return FT_IS_TRICKY( ((FT_Face)m_ptr) );
}

/// -------------------------------------------------------------------
///                       Member Functions
/// -------------------------------------------------------------------

Error_t Face::select_size(Int_t strike_index)
{
    return FT_Select_Size((FT_Face)(m_ptr), strike_index);
}

Error_t Face::set_char_size(F26Dot6_t char_width, F26Dot6_t char_height,
        UInt_t horz_resolution, UInt_t vert_resolution)
{
    return FT_Set_Char_Size((FT_Face)(m_ptr), char_width, char_height,
            horz_resolution, vert_resolution);
}


Error_t Face::set_pixel_sizes(UInt_t pixel_width, UInt_t pixel_height)
{
    return FT_Set_Pixel_Sizes((FT_Face)(m_ptr), pixel_width, pixel_height);
}

Error_t Face::load_glyph(UInt_t glyph_index, Int32_t load_flags)
{
    return FT_Load_Glyph( (FT_Face)m_ptr, glyph_index, load_flags );
}

Error_t Face::load_char(ULong_t char_code, Int32_t load_flags)
{
    return FT_Load_Char( (FT_Face)m_ptr, char_code, load_flags );
}

Error_t Face::get_glyph_name(
                        UInt_t      glyph_index,
                        Pointer_t   buffer,
                        UInt_t      buffer_max )
{
    return FT_Get_Glyph_Name( (FT_Face)m_ptr, glyph_index, buffer, buffer_max );
}

const char* Face::get_postscript_name()
{
    return FT_Get_Postscript_Name( (FT_Face)m_ptr );
}

Error_t Face::select_charmap( Encoding encoding )
{
    return FT_Select_Charmap( (FT_Face)m_ptr, (FT_Encoding)encoding );
}

UInt_t Face::get_char_index( ULong_t charcode )
{
    return FT_Get_Char_Index( (FT_Face)m_ptr, charcode );
}

ULong_t Face::get_first_char( UInt_t& agindex )
{
    return FT_Get_First_Char( (FT_Face)m_ptr, &agindex );
}

ULong_t Face::get_next_char( ULong_t char_code, UInt_t& agindex )
{
    return FT_Get_Next_Char( (FT_Face)m_ptr, char_code, &agindex );
}

UInt_t Face::get_name_index( String_t* glyph_name )
{
    return FT_Get_Name_Index( (FT_Face)m_ptr, glyph_name) ;
}

UShort_t Face::get_fstype_flags()
{
    return FT_Get_FSType_Flags( (FT_Face)m_ptr );
}

} // namespace freetype 
