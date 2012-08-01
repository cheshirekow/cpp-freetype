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
 *  \file   Face.h
 *
 *  \date   Aug 1, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef CPPFREETYPE_FACE_H_
#define CPPFREETYPE_FACE_H_

#include <cppfreetype/types.h>

namespace freetype
{


/// A list of bit flags used in the ‘face_flags’ field of the FT_FaceRec
/// structure. They inform client applications of properties of the
/// corresponding face.
namespace faceflag
{
    /// Indicates that the face contains outline glyphs. This doesn't prevent
    /// bitmap strikes, i.e., a face can have both this and and
    /// FT_FACE_FLAG_FIXED_SIZES set.
    const ULong_t   SCALABLE            = ( 1L <<  0 );

    /// Indicates that the face contains bitmap strikes. See also the
    /// ‘num_fixed_sizes’ and ‘available_sizes’ fields of FT_FaceRec.
    const ULong_t   FIXED_SIZES         = ( 1L <<  1 );

    /// Indicates that the face contains fixed-width characters (like Courier,
    /// Lucido, MonoType, etc.).
    const ULong_t   FIXED_WIDTH         = ( 1L <<  2 );

    /// Indicates that the face uses the ‘sfnt’ storage scheme. For now, this
    /// means TrueType and OpenType.
    const ULong_t   SFNT                = ( 1L <<  3 );

    /// Indicates that the face contains horizontal glyph metrics. This should
    /// be set for all common formats.
    const ULong_t   HORIZONTAL          = ( 1L <<  4 );

    /// Indicates that the face contains vertical glyph metrics. This is only
    /// available in some formats, not all of them.
    const ULong_t   VERTICAL            = ( 1L <<  5 );

    /// Indicates that the face contains kerning information. If set, the
    /// kerning distance can be retrieved through the function FT_Get_Kerning.
    /// Otherwise the function always return the vector (0,0). Note that
    /// FreeType doesn't handle kerning data from the ‘GPOS’ table (as present
    /// in some OpenType fonts).
    const ULong_t   KERNING             = ( 1L <<  6 );

    /// THIS FLAG IS DEPRECATED. DO NOT USE OR TEST IT.
    const ULong_t   FAST_GLYPHS         = ( 1L <<  7 );

    /// Indicates that the font contains multiple masters and is capable of
    /// interpolating between them. See the multiple-masters specific API for
    /// details.
    const ULong_t   MULTIPLE_MASTERS    = ( 1L <<  8 );

    /// Indicates that the font contains glyph names that can be retrieved
    /// through FT_Get_Glyph_Name. Note that some TrueType fonts contain
    /// broken glyph name tables. Use the function FT_Has_PS_Glyph_Names when
    /// needed.
    const ULong_t   GLYPH_NAMES         = ( 1L <<  9 );

    /// Used internally by FreeType to indicate that a face's stream was
    /// provided by the client application and should not be destroyed when
    /// FT_Done_Face is called. Don't read or test this flag.
    const ULong_t   EXTERNAL_STREAM     = ( 1L << 10 );

    /// Set if the font driver has a hinting machine of its own. For example,
    /// with TrueType fonts, it makes sense to use data from the SFNT ‘gasp’
    /// table only if the native TrueType hinting engine (with the bytecode
    /// interpreter) is available and active.
    const ULong_t   HINTER              = ( 1L << 11 );

    /// Set if the font is CID-keyed. In that case, the font is not accessed
    /// by glyph indices but by CID values. For subsetted CID-keyed fonts this
    /// has the consequence that not all index values are a valid argument to
    /// FT_Load_Glyph. Only the CID values for which corresponding glyphs in
    /// the subsetted font exist make FT_Load_Glyph return successfully; in
    /// all other cases you get an ‘FT_Err_Invalid_Argument’ error.
    ///
    /// Note that CID-keyed fonts which are in an SFNT wrapper don't have
    /// this flag set since the glyphs are accessed in the normal way (using
    /// contiguous indices); the ‘CID-ness’ isn't visible to the application.
    const ULong_t   CID_KEYED           = ( 1L << 12 );

    /// Set if the font is ‘tricky’, this is, it always needs the font
    /// format's native hinting engine to get a reasonable result. A typical
    /// example is the Chinese font ‘mingli.ttf’ which uses TrueType bytecode
    /// instructions to move and scale all of its subglyphs.
    ///
    /// It is not possible to autohint such fonts using FT_LOAD_FORCE_AUTOHINT;
    /// it will also ignore FT_LOAD_NO_HINTING. You have to set both
    /// FT_LOAD_NO_HINTING and FT_LOAD_NO_AUTOHINT to really disable hinting;
    /// however, you probably never want this except for demonstration
    /// purposes.
    ///
    /// Currently, there are about a dozen TrueType fonts in the list of
    /// tricky fonts; they are hard-coded in file ‘ttobjs.c’.
    const ULong_t   TRICKY              = ( 1L << 13 );
}


/// A list of bit-flags used to indicate the style of a given face. These are
/// used in the ‘style_flags’ field of FT_FaceRec.
/**
 *  @note   The style information as provided by FreeType is very basic. More
 *          details are beyond the scope and should be done on a higher level
 *          (for example, by analyzing various fields of the ‘OS/2’ table in
 *          SFNT based fonts).
 */
namespace styleflag
{
    /// Indicates that a given face style is italic or oblique.
    const UInt_t    ITALIC  = ( 1 << 0 );

    /// Indicates that a given face is bold.
    const UInt_t    BOLD    = ( 1 << 1 );


}





/// A handle to a given typographic face object. A face object models a given
/// typeface, in a given style.
/**
 *  Each face object also owns a single FT_GlyphSlot object, as well as one or
 *  more FT_Size objects.
 *
 *  Use FT_New_Face or FT_Open_Face to create a new face object from a given
 *  filepathname or a custom input stream.
 *
 *  Use FT_Done_Face to destroy it (along with its slot and sizes).
 *
 *  Faces are reference counted, as such there is an appropriate copy
 *  constructor, assignment operator, and destructor for managing the
 *  reference counts. Because of it's nature, you should probably not be
 *  passing around pointers to Face objects
 *
 *  @note   Fields may be changed after a call to FT_Attach_File or
 *          FT_Attach_Stream.
 */
class Face
{
    private:
        void* m_ptr;    ///< FT_FACE handle to underlying object

    public:
        /// -------------------------------------------------------------------
        ///                       Wrapper Overhead
        /// -------------------------------------------------------------------

        /// wrap constructor, wraps the underlying FT_FACE pointer
        /**
         * @param[in]   ptr         underlying FT_FACE pointer
         * @param[in]   reference   if true, increments the reference count
         */
        Face( void* ptr, bool reference=true );

        /// copy constructor, increases reference count of underlying FT_FACE
        /// object
        Face( const Face& other );

        /// assignment operator, decremetns reference count of currently
        /// contained pointer and increments reference count of the other
        Face& operator=(const Face& other);

        /// desctructor decrements the reference count of the object
        ~Face();

        /// returns true if contained pointer is not null
        bool is_valid();



        /// -------------------------------------------------------------------
        ///                    Structure Accessors
        /// -------------------------------------------------------------------

        /// The number of faces in the font file. Some font formats can have
        /// multiple faces in a font file.
        Long_t&           num_faces();
        const Long_t&     num_faces() const;

        /// The index of the face in the font file. It is set to 0 if there is only one face in the font file.
        Long_t&           face_index();
        const Long_t&     face_index() const;

        /// A set of bit flags that give important information about the face; see FT_FACE_FLAG_XXX for the details.
        Long_t&           face_flags();
        const Long_t&     face_flags() const;

        /// A set of bit flags indicating the style of the face; see FT_STYLE_FLAG_XXX for the details.
        Long_t&           style_flags();
        const Long_t&     style_flags() const;

        /// The number of glyphs in the face. If the face is scalable and has sbits (see ‘num_fixed_sizes’), it is set to the number of outline glyphs.
        /// For CID-keyed fonts, this value gives the highest CID used in the font.
        Long_t&           num_glyphs();
        const Long_t&     num_glyphs() const;

        /// The face's family name. This is an ASCII string, usually in English, which describes the typeface's family (like ‘Times New Roman’, ‘Bodoni’, ‘Garamond’, etc). This is a least common denominator used to list fonts. Some formats (TrueType & OpenType) provide localized and Unicode versions of this string. Applications should use the format specific interface to access them. Can be NULL (e.g., in fonts embedded in a PDF file).
        String_t*         family_name();
        const String_t*   family_name() const;

        /// The face's style name. This is an ASCII string, usually in English, which describes the typeface's style (like ‘Italic’, ‘Bold’, ‘Condensed’, etc). Not all font formats provide a style name, so this field is optional, and can be set to NULL. As for ‘family_name’, some formats provide localized and Unicode versions of this string. Applications should use the format specific interface to access them.
        String_t*         style_name();
        const String_t*   style_name() const;

        /// The number of bitmap strikes in the face. Even if the face is scalable, there might still be bitmap strikes, which are called ‘sbits’ in that case.
        Int_t&            num_fixed_sizes();
        const Int_t&      num_fixed_sizes() const;

        /// An array of FT_Bitmap_Size for all bitmap strikes in the face. It is set to NULL if there is no bitmap strike.
        //FT_Bitmap_Size*   available_sizes;

        /// The number of charmaps in the face.
        Int_t&            num_charmaps();
        const Int_t&      num_charmaps() const;

        /// An array of the charmaps of the face.
        //CharMap_t*        charmaps;

        /// A field reserved for client uses. See the FT_Generic type description.
        //FT_Generic        generic;

        // The following member variables (down to `underline_thickness')
        // are only relevant to scalable outlines; cf. @FT_Bitmap_Size
        // for bitmap fonts.

        /// The font bounding box. Coordinates are expressed in font units (see ‘units_per_EM’). The box is large enough to contain any glyph from the font. Thus, ‘bbox.yMax’ can be seen as the ‘maximum ascender’, and ‘bbox.yMin’ as the ‘minimum descender’. Only relevant for scalable formats.
        /// Note that the bounding box might be off by (at least) one pixel for hinted fonts. See FT_Size_Metrics for further discussion.
        //FT_BBox           bbox;

        /// The number of font units per EM square for this face. This is typically 2048 for TrueType fonts, and 1000 for Type 1 fonts. Only relevant for scalable formats.
        UShort_t&         units_per_EM();
        const UShort_t&   units_per_EM() const;

        /// The typographic ascender of the face, expressed in font units. For font formats not having this information, it is set to ‘bbox.yMax’. Only relevant for scalable formats.
        Short_t&          ascender();
        const Short_t&    ascender() const;

        /// The typographic descender of the face, expressed in font units. For font formats not having this information, it is set to ‘bbox.yMin’. Note that this field is usually negative. Only relevant for scalable formats.
        Short_t&          descender();
        const Short_t&    descender() const;

        /// The height is the vertical distance between two consecutive baselines, expressed in font units. It is always positive. Only relevant for scalable formats.
        Short_t&          height();
        const Short_t&    height() const;

        /// The maximum advance width, in font units, for all glyphs in this face. This can be used to make word wrapping computations faster. Only relevant for scalable formats.
        Short_t&          max_advance_width();
        const Short_t&    max_advance_width() const;

        /// The maximum advance height, in font units, for all glyphs in this face. This is only relevant for vertical layouts, and is set to ‘height’ for fonts that do not provide vertical metrics. Only relevant for scalable formats.
        Short_t&          max_advance_height();
        const Short_t&    max_advance_height() const;

        /// The position, in font units, of the underline line for this face. It is the center of the underlining stem. Only relevant for scalable formats.
        Short_t&          underline_position();
        const Short_t&    underline_position() const;

        /// The thickness, in font units, of the underline for this face. Only relevant for scalable formats.
        Short_t&          underline_thickness();
        const Short_t&    underline_thickness() const;

        /// The face's associated glyph slot(s).
        //FT_GlyphSlot      glyph;

        /// The current active size for this face.
        //FT_Size            size();

        /// The current active charmap for this face.
        //FT_CharMap        charmap;

        bool has_horizontal();
        bool has_vertical();
        bool has_kerning();
        bool is_scalable();
        bool is_sfnt();
        bool is_fixed_width();
        bool has_fixed_sizes();
        bool has_fast_glyphs();
        bool has_glyph_names();
        bool has_multiple_masters();
        bool is_cid_keyed();
        bool is_trickey();



        /// -------------------------------------------------------------------
        ///                       Member Functions
        /// -------------------------------------------------------------------

        /// Select a bitmap strike
        /**
         *  @param[in]  strike_index    the index of the bitmap strike in the
         *                              `available_sizes` field of the
         *                              underlying struct
         *  @return FreeType error code. 0 means success.
         */
        Error_t select_size( Int_t strike_index );

};

} // namespace freetype 

#endif // FACE_H_
