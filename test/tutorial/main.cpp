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
 *  \file   main.cpp
 *
 *  \date   Aug 1, 2012
 *  \author Josh Bialkowski (jbialk@mit.edu)
 *  \brief  
 */


#include <cppfreetype/cppfreetype.h>
#include <sigc++/sigc++.h>
#include <iostream>

int main( int argc, char** argv )
{

    using namespace freetype;

    if(argc < 2 )
    {
        std::cerr << "Provide font file path as parameter please" << std::endl;
        return 1;
    }

    Error_t result;
    RefPtr<Library> freetype;
    (freetype,result) = init_e();

    if(result)
    {
        std::cerr << "Failed to initialize freetype" << std::endl;
        return 1;
    }

    // artificial scope... we dont want a dangling Face pointer hanging
    // around trying to free itself after we call ft::done
    {
        RefPtr<Face> face;
        (face,result) = freetype->new_face_e( argv[1], 0 );

        if(result)
        {
            std::cerr << "Freetype failed to read " << argv[1]
                      << " as a font file " << std::endl;
            return 1;
        }

        std::cout << "Some info about the font: "
          << "\n      filepath: " << argv[1]
          << "\n        family: " << face->family_name()
          << "\n      n glyphs: " << face->num_glyphs()
          << "\n  units per EM: " << face->units_per_EM()
          << "\n"
          << std::endl;
    }

    result = done(freetype);
    return 0;
}



