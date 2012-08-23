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

        void reference();
        void drop();

    public:
        /// -------------------------------------------------------------------
        ///                       Wrapper Overhead
        /// -------------------------------------------------------------------

        /// wrap constructor, wraps the underlying FT_FACE pointer
        /**
         * @param[in]   ptr         underlying FT_FACE pointer
         * @param[in]   reference   if true, increments the reference count
         */
        Face( void* ptr=0, bool reference=false );

        /// copy constructor, increases reference count of underlying FT_FACE
        /// object
        Face( const Face& other );

        /// assignment operator, decremetns reference count of currently
        /// contained pointer and increments reference count of the other
        Face& operator=(const Face& other);

        /// desctructor decrements the reference count of the object
        ~Face();

        void* get_ptr();
        const void* get_ptr() const;

        void invalidate();

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
        bool is_tricky();



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

        /// Calls FT_Request_Size to request the nominal size (in points)
        /**
         *  @param[in]  char_width          The nominal width, in 26.6
         *                                  fractional points.
         *  @param[in]  char_height         The nominal height, in 26.6
         *                                  fractional points.
         *  @param[in]  horz_resolution     The horizontal resolution in dpi.
         *  @param[in]  vert_resolution     The vertical resolution in dpi.
         *
         *  @return FreeType error code. 0 means success.
         *
         *  If either the character width or height is zero, it is set equal
         *  to the other value.
         *
         *  If either the horizontal or vertical resolution is zero, it is set
         *  equal to the other value.
         *
         *  A character width or height smaller than 1pt is set to 1pt; if
         *  both resolution values are zero, they are set to 72dpi.
         *
         *  Don't use this function if you are using the FreeType cache API.
         */
        Error_t set_char_size(
                        F26Dot6_t   char_width,
                        F26Dot6_t   char_height,
                        UInt_t      horz_resolution,
                        UInt_t      vert_resolution );

        /// This function calls FT_Request_Size to request the nominal size
        /// (in pixels).
        /**
         *  @param[in]  pixel_width     The nominal width, in pixels.
         *  @param[in]  pixel_height    The nominal height, in pixels.
         *
         *  @return FreeType error code. 0 means success.
         */
        Error_t set_pixel_sizes(
                        UInt_t  pixel_width,
                        UInt_t  pixel_height    );

        /// A function used to load a single glyph into the glyph slot of a
        /// face object.
        /**
         *  @param[in]  glyph_index     The index of the glyph in the font
         *                              file. For CID-keyed fonts (either in
         *                              PS or in CFF format) this argument
         *                              specifies the CID value.
         *  @param[in]  load_flags      A flag indicating what to load for
         *                              this glyph. The FT_LOAD_XXX constants
         *                              can be used to control the glyph
         *                              loading process (e.g., whether the
         *                              outline should be scaled, whether to
         *                              load bitmaps or not, whether to hint
         *                              the outline, etc).
         *
         *  @return FreeType error code. 0 means success.
         *
         *  The loaded glyph may be transformed. See FT_Set_Transform for the
         *  details.
         *
         *  For subsetted CID-keyed fonts, ‘FT_Err_Invalid_Argument’ is
         *  returned for invalid CID values (this is, for CID values which
         *  don't have a corresponding glyph in the font). See the discussion
         *  of the FT_FACE_FLAG_CID_KEYED flag for more details.
         */
        Error_t load_glyph(
                        UInt_t  glyph_index,
                        Int32_t load_flags );

        /// A function used to load a single glyph into the glyph slot of a
        /// face object, according to its character code.
        /**
         *  @param[in]  char_code   The glyph's character code, according to
         *              the current charmap used in the face.
         *  @param[in]  load_flags  A flag indicating what to load for this
         *              glyph. The FT_LOAD_XXX constants can be used to
         *              control the glyph loading process (e.g., whether the
         *              outline should be scaled, whether to load bitmaps or
         *              not, whether to hint the outline, etc).
         *
         *  @return FreeType error code. 0 means success.
         *
         *  This function simply calls FT_Get_Char_Index and FT_Load_Glyph.
         */
        Error_t load_char(
                        ULong_t char_code,
                        Int32_t load_flags );

        /// Retrieve the ASCII name of a given glyph in a face. This only
        /// works for those faces where FT_HAS_GLYPH_NAMES(face) returns 1.
        /**
         *  @param[in]  glyph_index     The glyph index.
         *  @param[out] buffer          A pointer to a target buffer where the
         *                              name is copied to.
         *  @param[in]  buffer_max      The maximum number of bytes available
         *                              in the buffer.
         *
         *  @return FreeType error code. 0 means success.
         *
         *  An error is returned if the face doesn't provide glyph names or if
         *  the glyph index is invalid. In all cases of failure, the first
         *  byte of ‘buffer’ is set to 0 to indicate an empty name.
         *
         *  The glyph name is truncated to fit within the buffer if it is too
         *  long. The returned string is always zero-terminated.
         *
         *  Be aware that FreeType reorders glyph indices internally so that
         *  glyph index 0 always corresponds to the ‘missing glyph’ (called
         *  ‘.notdef’).
         *
         *  This function is not compiled within the library if the config
         *  macro ‘FT_CONFIG_OPTION_NO_GLYPH_NAMES’ is defined in
         *  ‘include/freetype/config/ftoptions.h’.
         */
        Error_t get_glyph_name(
                        UInt_t      glyph_index,
                        Pointer_t   buffer,
                        UInt_t      buffer_max );

        /// Retrieve the ASCII PostScript name of a given face, if available.
        /// This only works with PostScript and TrueType fonts.
        /**
         *  @return A pointer to the face's PostScript name. NULL if
         *          unavailable.
         *  @note   The returned pointer is owned by the face and is destroyed
         *          with it.
         */
        const char* get_postscript_name();

        /// Select a given charmap by its encoding tag (as listed in
        /// ‘freetype.h’).
        /**
         *  @param[in]  encoding   handle to the selected encoding
         *
         *  @return FreeType error code. 0 means success.
         *
         *  This function returns an error if no charmap in the face
         *  corresponds to the encoding queried here.
         *
         *  Because many fonts contain more than a single cmap for Unicode
         *  encoding, this function has some special code to select the one
         *  which covers Unicode best (‘best’ in the sense that a UCS-4 cmap
         *  is preferred to a UCS-2 cmap). It is thus preferable to
         *  FT_Set_Charmap in this case.
         */
        Error_t select_charmap( Encoding encoding );

        /// Return the glyph index of a given character code. This function
        /// uses a charmap object to do the mapping.
        /**
         *  @param[in]  charcode    The character code.
         *
         *  @return The glyph index. 0 means ‘undefined character code’.
         *
         *  If you use FreeType to manipulate the contents of font files
         *  directly, be aware that the glyph index returned by this function
         *  doesn't always correspond to the internal indices used within the
         *  file. This is done to ensure that value 0 always corresponds to
         *  the ‘missing glyph’. If the first glyph is not named ‘.notdef’,
         *  then for Type 1 and Type 42 fonts, ‘.notdef’ will be moved into
         *  the glyph ID 0 position, and whatever was there will be moved to
         *  the position ‘.notdef’ had. For Type 1 fonts, if there is no
         *  ‘.notdef’ glyph at all, then one will be created at index 0 and
         *  whatever was there will be moved to the last index -- Type 42
         *  fonts are considered invalid under this condition.
         */
        UInt_t get_char_index( ULong_t charcode );

        /// This function is used to return the first character code in the
        /// current charmap of a given face. It also returns the corresponding
        /// glyph index.
        /**
         *  @param[out] agindex     Glyph index of first character code.
         *                          0 if charmap is empty.
         *
         *  @return  The charmap's first character code.
         *
         *  You should use this function with FT_Get_Next_Char to be able to
         *  parse all character codes available in a given charmap. The code
         *  should look like this:
         *
         * \code
FT_ULong  charcode;
FT_UInt   gindex;


charcode = FT_Get_First_Char( face, &gindex );
while ( gindex != 0 )
{
    //... do something with (charcode,gindex) pair ...

    charcode = FT_Get_Next_Char( face, charcode, &gindex );
}
\endcode
         *
         *  Note that ‘*agindex’ is set to 0 if the charmap is empty. The
         *  result itself can be 0 in two cases: if the charmap is empty or if
         *  the value 0 is the first valid character code.
         */
        ULong_t get_first_char( UInt_t& agindex );

        /// This function is used to return the next character code in the
        /// current charmap of a given face following the value ‘char_code’,
        /// as well as the corresponding glyph index.
        /**
         *  @param[in]  char_code   The starting character code.
         *  @param[out] agindex     Glyph index of next character code.
         *                          0 if charmap is empty.
         *
         *  @return The charmap's next character code.
         *
         *  You should use this function with FT_Get_First_Char to walk over
         *  all character codes available in a given charmap. See the note for
         *  this function for a simple code example.
         *
         *  Note that ‘*agindex’ is set to 0 when there are no more codes in
         *  the charmap.
         */
        ULong_t get_next_char( ULong_t char_code, UInt_t& agindex );

        /// Return the glyph index of a given glyph name. This function uses
        /// driver specific objects to do the translation.
        /**
         *  @param[in]  glyph_name  The glyph name.
         *
         *  @return The glyph index. 0 means ‘undefined character code’.
         */
        UInt_t get_name_index( String_t* glyph_name );

        /// Return the fsType flags for a font
        /**
         *  @return The fsType flags, FT_FSTYPE_XXX.
         *
         *  Use this function rather than directly reading the ‘fs_type’ field
         *  in the PS_FontInfoRec structure which is only guaranteed to
         *  return the correct results for Type 1 fonts.
         */
        UShort_t get_fstype_flags();

};

} // namespace freetype 

#endif // FACE_H_
