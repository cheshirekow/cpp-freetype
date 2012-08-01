find_package(Freetype2 REQUIRED)
find_package(SigC++ REQUIRED)
                                                                    
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