/**
 *  \file   mainpage.h
 *  \brief  Starting point for documentation (no code)
 *  \author Joshua Bialkowski (jbialk@mit.edu)
 *  \date   Apr 8, 2011
 *
 *  \mainpage   Documentation
 *
 *  cppfreetype is a C++ wrapper around the FreeType2 library. It is a simple,
 *  thin wrapper that doesn't do much on it's own. I wouldn't consider it
 *  very useful except to vain C++ programs who want the font config objects
 *  to be nicely namespaced and to eliminate the FT_ macros from their code.
 *
 *  cppfreetype mostly just provides objects which wrap freetype pointers
 *  with the methods of the underlying object
 *
 *  Note-to-self: You probably want to link against this library using
 *  Link Time Optimization (LTO) (i.e. the -flto switch with gcc). It can
 *  inline functions that are declared in this library in the code that
 *  uses it.
 *
 *  As an example, here is a simple program which loads a font file and
 *  displays some information from it:
 *
 *  \include test/tutorial/main.cpp
 *
 *  The output of this program looks like the following
 *
 *  \verbatim
josh@Nadie:~/Codes/cpp/builds/cppfreetype/test$ ./test /usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-R.ttf
Some info about the font:
      filepath: /usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-R.ttf
        family: Ubuntu
      n glyphs: 1264
  units per EM: 1000

josh@Nadie:~/Codes/cpp/builds/cppfreetype/test$

\endverbatim
 *
 */








