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
 *  \file   SizeRequest.h
 *
 *  \date   Aug 1, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */

#ifndef CPPFREETYPE_SIZEREQUEST_H_
#define CPPFREETYPE_SIZEREQUEST_H_

#include <cppfreetype/types.h>

namespace freetype
{

/// namespace wrapper for SizeRequestType
/**
 *  @see SizeRequestType
 */
namespace size_request_type
{
    /// An enumeration type that lists the supported size request types.
    /**
     *  @note   The above descriptions only apply to scalable formats. For
     *          bitmap formats, the behaviour is up to the driver.
     *
     *          See the note section of FT_Size_Metrics if you wonder how
     *          size requesting relates to scaling values.
     */
    enum SizeRequestType
    {
        NOMINAL,    ///< The nominal size. The ‘units_per_EM’ field of
                    ///  FT_FaceRec is used to determine both scaling values.
        REAL_DIM,   ///< The real dimension. The sum of the the ‘ascender’ and
                    ///  (minus of) the ‘descender’ fields of FT_FaceRec are
                    ///  used to determine both scaling values.
        BBOX,       ///< The font bounding box. The width and height of the
                    ///  ‘bbox’ field of FT_FaceRec are used to determine the
                    ///  horizontal and vertical scaling value, respectively.
        CELL,       ///< The ‘max_advance_width’ field of FT_FaceRec is used
                    ///  to determine the horizontal scaling value; the
                    ///  vertical scaling value is determined the same way as
                    ///  FT_SIZE_REQUEST_TYPE_REAL_DIM does. Finally, both
                    ///  scaling values are set to the smaller one. This type
                    ///  is useful if you want to specify the font size for,
                    ///  say, a window of a given dimension and 80x24 cells.
        SCALES,     ///< Specify the scaling values directly.
        MAX         ///< MAX
    };
}

typedef size_request_type::SizeRequestType SizeRequestType;

class SizeRequest;


#ifdef THIS_IS_NOT_DEFINED
namespace size_request
{
    namespace fields
    {
        enum Enum
        {
            type,
            width,
            height,
            horizResolution,
            vertResolution
        };
    }

    typedef fields::Enum Field;

    template < Field F > struct TypeMap;
    template <> struct TypeMap<fields::type>             { typedef SizeRequestType&  Type; };
    template <> struct TypeMap<fields::width>            { typedef Long_t&           Type; };
    template <> struct TypeMap<fields::height>           { typedef Long_t&           Type; };
    template <> struct TypeMap<fields::horizResolution>  { typedef UInt_t&           Type; };
    template <> struct TypeMap<fields::vertResolution>   { typedef UInt_t&           Type; };

    /// Templatized accessor to fields of opaque data structure
    /**
     *  Usage:
     *
     *  \code
SizeRequest sr;
{
    using namespace size_request::fields;
    f<type>(sr)             = size_request_type::SCALES;
    f<width>(sr)            = 10;
    f<height>(sr)           = 20;
    f<horizResolution>(sr)  = 300;
    f<horizResolution>(sr)  = 300;
}
\endcode
     *
     *      P.S., this is a failed experiment, it doesn't save us anything over
     *      simply
     *
     *      \code
SizeRequest sr;
sr->type()  = size_request_type::SCALES:
sr->width() = 10;
sr->height()= 20;
\endcode
     */
    template < Field F >
    typename TypeMap<F>::Type field( SizeRequest& obj );

    template <> SizeRequestType&    field<fields::type>(             SizeRequest& obj );
    template <> Long_t&             field<fields::width>(            SizeRequest& obj );
    template <> Long_t&             field<fields::height>(           SizeRequest& obj );
    template <> UInt_t&             field<fields::horizResolution>(  SizeRequest& obj );
    template <> UInt_t&             field<fields::vertResolution>(   SizeRequest& obj );

}
#endif

/// A structure used to model a size request.
class SizeRequest
{
    private:
        void* m_ptr;    ///< underlying FT_SIZE_REQUEST handle

    public:

};




} // namespace freetype 

#endif // SIZEREQUEST_H_
