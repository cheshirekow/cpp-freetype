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
    
set( LIBRARY_SOURCES
        cppfreetype.cpp
        Face.cpp
        GlyphSlot.cpp
        Library.cpp
        Memory.cpp
        Module.cpp
        ModuleClass.cpp
        OpenArgs.cpp
        Outline.cpp
        Untag.cpp )

add_library( ${CMAKE_PROJECT_NAME} SHARED
             ${LIBRARY_SOURCES}    ) 
                
add_library( ${CMAKE_PROJECT_NAME}_static STATIC
             ${LIBRARY_SOURCES} ) 
                
INSTALL( TARGETS ${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_static
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)


else()
    message( WARNING 
        "freetype2 was not found, disabling build of cppfreetype library"
        "you may still build the doc target"  )  
endif()