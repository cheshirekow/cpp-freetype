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
 */








