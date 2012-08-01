find_package(Freetype2 REQUIRED)
find_package(SigC++ REQUIRED)
                                                                    
include_directories( 
   ${Freetype2_INCLUDE_DIRS}
   ${SigC++_INCLUDE_DIRS}
    )


set(LIBS ${LIBS} 
    ${Freetype2_LIBRARIES} 
    ${SigC++_LIBRARIES}
    )

add_library( ${CMAKE_PROJECT_NAME}
                cppfreetype.cpp ) 
