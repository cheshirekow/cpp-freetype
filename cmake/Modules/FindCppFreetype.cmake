# - Try to find CppFreetype
# Once done, this will define
#
#  CppFreetype_FOUND - system has CppFreetype
#  CppFreetype_INCLUDE_DIRS - the CppFreetype include directories
#  CppFreetype_LIBRARIES - link these to use CppFreetype

include(LibFindMacros)

# Include dir
find_path(CppFreetype_INCLUDE_DIR
  NAMES cppfreetype/cppfreetype.h
)

# Finally the library itself
find_library(CppFreetype_LIBRARY
  NAMES cppfreetype
)

# Set the include dir variables and the libraries and let libfind_process do the rest.
# NOTE: Singular variables for this library, plural for libraries this this lib depends on.
set(CppFreetype_PROCESS_INCLUDES CppFreetype_INCLUDE_DIR)
set(CppFreetype_PROCESS_LIBS CppFreetype_LIBRARY)
libfind_process(CppFreetype)

