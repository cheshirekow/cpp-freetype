# - Try to find Freetype2
# Once done, this will define
#
#  Freetype2_FOUND - system has Freetype2
#  Freetype2_INCLUDE_DIRS - the Freetype2 include directories
#  Freetype2_LIBRARIES - link these to use Freetype2

include(LibFindMacros)

# Use pkg-config to get hints about paths
libfind_pkg_check_modules(Freetype2_PKGCONF freetype2)

# Include dir
find_path(Freetype2_FT2BUILD_INCLUDE_DIR
  NAMES ft2build.h
  HINTS ${Freetype2_PKGCONF_INCLUDE_DIRS}
)

find_path(Freetype2_INCLUDE_DIR
  NAMES freetype/config/ftheader.h
  HINTS ${Freetype2_PKGCONF_INCLUDE_DIRS}
)

# Finally the library itself
find_library(Freetype2_LIBRARY
  NAMES freetype
  HINTS ${Freetype2_PKGCONF_LIBRARY_DIRS}
)

# Set the include dir variables and the libraries and let libfind_process do the rest.
# NOTE: Singular variables for this library, plural for libraries this this lib depends on.
set(Freetype2_PROCESS_INCLUDES Freetype2_FT2BUILD_INCLUDE_DIR Freetype2_INCLUDE_DIR)
set(Freetype2_PROCESS_LIBS Freetype2_LIBRARY)
libfind_process(Freetype2)

