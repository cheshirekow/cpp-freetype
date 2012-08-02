find_package(Freetype2 )
find_package(SigC++ )

if( (Freetype2_FOUND) AND (SigC++_FOUND) )
                                                                    
include_directories( 
   ${Freetype2_INCLUDE_DIRS}
   ${SigC++_INCLUDE_DIRS}
    )


set(LIBS ${LIBS} 
    ${CMAKE_PROJECT_NAME}
    ${Freetype2_LIBRARIES} 
    ${SigC++_LIBRARIES}
    )

add_executable(tutorial main.cpp )

target_link_libraries( tutorial ${LIBS} )

else()
    message( WARNING 
        "freetype2 was not found, disabling build of cppfreetype tutorial"
        "you may still build the doc target"  )  
endif()