find_package(Freetype2 )
find_package(SigC++ )

if( (Freetype2_FOUND) AND (SigC++_FOUND) )
                                                                    
include_directories( 
   ${Freetype2_INCLUDE_DIRS}
   ${SigC++_INCLUDE_DIRS}
    )


set(LIBS ${LIBS} 
    ${Freetype2_LIBRARIES} 
    ${SigC++_LIBRARIES}
    )

add_library( ${CMAKE_PROJECT_NAME}
                cppfreetype.cpp
                Face.cpp
                GlyphSlot.cpp
                Library.cpp
                Memory.cpp
                Module.cpp
                ModuleClass.cpp
                OpenArgs.cpp
                SizeRequest.cpp ) 
                
                
INSTALL( TARGETS ${CMAKE_PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)


else()
    message( WARNING 
        "freetype2 was not found, disabling build of cppfreetype library"
        "you may still build the doc target"  )  
endif()