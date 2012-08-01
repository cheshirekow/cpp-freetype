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

#ifndef CPPFREETYPE_TYPES_H_
#define CPPFREETYPE_TYPES_H_

#include <cstring>
#include <cstddef>

#include <sigc++/sigc++.h>

/// root namespace for freetype
namespace freetype
{
    extern const unsigned int MAJOR;
    extern const unsigned int MINOR;
    extern const unsigned int PATCH;

    typedef unsigned char   Byte_t;     ///< simple typedef unsigned char
    typedef Byte_t*         Bytes_t;    ///< a typedef for constant memory area
    typedef signed char     Char_t;     ///< simple typedef for signed char
    typedef signed int      Int_t;      ///< typedef for int
    typedef unsigned int    UInt_t;     ///< typedef for unsigned int
    typedef signed short    Int16_t;    ///< typedef for 16bit integer
    typedef unsigned short  UInt16_t;   ///< typedef for 16bit unsigned int
    // FIXME: compiler dependent
    typedef signed int      Int32_t;    ///< typedef for 32bit signed int
    // FIXME: compiler dependent
    typedef unsigned int    UInt32_t;   ///< typedef for 32bit unsigned int
    typedef signed short    Short_t;    ///< simlpe typedef for signed short
    typedef unsigned short  UShort_t;   ///< simple typedef for unsigned short
    typedef signed long     Long_t;     ///< simple typedef for signed long
    typedef unsigned long   ULong_t;    ///< simple typedef for unsigned long
    typedef unsigned char   Bool_t;     ///< used for simple booleans,
                                        /// 1=true, 0=false
    typedef size_t          Offset_t;   ///< the largest unsigned integer type
                                        ///  used to express a file size or
                                        ///  position or a memory block size
    typedef ptrdiff_t       PtrDist_t;  ///< the largest signed integer type
                                        ///  used to express a distance between
                                        ///  two pointers
    typedef char            String_t;   ///< simple typedef for char
    typedef UInt32_t        Tag_t;      ///< typedef for 32bit tags (as used in
                                        ///  the SFNT format)
    typedef int             Error_t;    ///< FreeType error code, a value of
                                        ///  0 is always interpreted as a
                                        ///  successful operation
    typedef signed long     Fixed_t;    ///< Used to store 16.16 fixed float
                                        ///  values, like scaling values or
                                        ///  matrix coefficients
    typedef void*           Pointer_t;  ///< simple typedef for typeless ptr
    typedef signed long     Pos_t;      ///< used to store vectoral coordinates.
                                        ///  depending on the context these
                                        ///  represent distances in integer
                                        ///  font units, or 16.16, or
                                        ///  26.6 fixed float pixel coords
    typedef signed short    FWord_t;    ///< signed 16bit integer used to
                                        ///  store distance in original font
                                        ///  units
    typedef unsigned short  UFWord_t;   ///< unsigned 16bit integer used to
                                        ///  store distance in original font
                                        ///  units
    typedef signed short    F2Dot14_t;  ///< signed 2.14 fixed float type used
                                        ///  for unit vectors
    typedef signed long     F26Dot6_t;  ///< signed 26.6 fixed float type used
                                        ///  for vectoral pixel coordinates

    /// namespace wrapper for PixelMode enumeration
    /**
     *  @see PixelMode
     */
    namespace pixelmode
    {
        /// An enumeration type used to describe the format of pixels in a
        /// given bitmap.

        /**
         *  @note: additional formats may be added in the future.
         */
        enum PixelMode
        {
            NONE    = 0,    ///< reserved
            MONO,   ///<  A monochrome bitmap, using 1 bit per pixel. Note that
                    ///   pixels are stored in most-significant order (MSB),
                    ///   which means that the left-most pixel in a byte has
                    ///   value 128.
            GRAY,   ///<  An 8-bit bitmap, generally used to represent
                    ///   anti-aliased glyph images. Each pixel is stored in
                    ///   one byte. Note that the number of ‘gray’ levels is
                    ///   stored in the ‘num_grays’ field of the FT_Bitmap
                    ///   structure (it generally is 256).
            GRAY2,  ///<  A 2-bit per pixel bitmap, used to represent embedded
                    ///   anti-aliased bitmaps in font files according to the
                    ///   OpenType specification. We haven't found a single
                    ///   font using this format, however.
            GRAY4,  ///<  A 4-bit per pixel bitmap, representing embedded
                    ///   anti-aliased bitmaps in font files according to the
                    ///   OpenType specification. We haven't found a single
                    ///   font using this format, however.
            LCD,    ///<  An 8-bit bitmap, representing RGB or BGR decimated
                    ///   glyph images used for display on LCD displays; the
                    ///   bitmap is three times wider than the original glyph
                    ///   image. See also FT_RENDER_MODE_LCD.
            LCD_V,  ///<  An 8-bit bitmap, representing RGB or BGR decimated
                    ///   glyph images used for display on rotated LCD
                    ///   displays; the bitmap is three times taller than the
                    ///   original glyph image. See also FT_RENDER_MODE_LCD_V.
            MAX     ///<  used for iterating over enum
        };

    }

    /// template used to replace the FT_IMAGE_TAG macro: converts four-letter
    /// tags into an unsigned long type
    /**
     * @note Since many 16-bit compilers don't like 32-bit enumerations, you
     *       should redefine this macro in case of problems to something like
     *       this:
     *       @code
#define FT_IMAGE_TAG( value, _x1, _x2, _x3, _x4 )  value
@endcode
     *       to get a simple enumeration without assigning special numbers.
     */
    template < ULong_t x1, ULong_t x2, ULong_t x3, ULong_t x4 >
    struct ImageTag
    {
        static const ULong_t value =
                  ( (ULong_t) x1 << 24 )
                | ( (ULong_t) x2 << 16 )
                | ( (ULong_t) x3 <<  8 )
                | ( (ULong_t) x4 <<  0 );
    };

    /// namespace wrapper for GlyphFormat enumeration
    /**
     *  @see GlyphFormat
     */
    namespace glyphformat
    {
        /// An enumeration type used to describe the format of a given glyph
        /// image.
        /**
         *  @note   Note that this version of FreeType only supports two image
         *          formats, even though future font drivers will be able to
         *          register their own format.
         */
        enum GlyphFormat
        {
            /// The value 0 is reserved.
            NONE        = ImageTag<0,0,0,0>::value,

            /// The glyph image is a composite of several other images. This
            /// format is only used with FT_LOAD_NO_RECURSE, and is used to
            /// report compound glyphs (like accented characters).
            COMPOSITE   = ImageTag<'c','o','m','p'>::value,

            /// The glyph image is a bitmap, and can be described as an
            /// FT_Bitmap. You generally need to access the ‘bitmap’ field of
            /// the FT_GlyphSlotRec structure to read it.
            BITMAP      = ImageTag<'b','i','t','s'>::value,

            /// The glyph image is a vectorial outline made of line segments
            ///  and Bézier arcs; it can be described as an FT_Outline; you
            /// generally want to access the ‘outline’ field of the
            /// FT_GlyphSlotRec structure to read it.
            OUTLINE     = ImageTag<'o','u','t','l'>::value,

            /// The glyph image is a vectorial path with no inside and outside
            /// contours. Some Type 1 fonts, like those in the Hershey family,
            /// contain glyphs in this format. These are described as
            /// FT_Outline, but FreeType isn't currently capable of rendering
            /// them correctly.
            PLOTTER     = ImageTag<'p','l','o','t'>::value
        };
    }

    /// Describe a function used to destroy the ‘client’ data of any FreeType
    /// object. See the description of the FT_Generic type for details of usage.
    /**
     *  input: The address of the FreeType object which is under finalization.
     *         Its client data is accessed through its ‘generic’ field.
     */
    typedef sigc::slot<void,void*>  GenericFinalizer_t;



}














#endif // CPPFREETYPE_H_
