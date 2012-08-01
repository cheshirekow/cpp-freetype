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
                cppfreetype.cpp
                Face.cpp
                Library.cpp
                Memory.cpp
                Module.cpp
                ModuleClass.cpp
                OpenArgs.cpp
                Parameter.cpp
                Size.cpp
                SizeRequest.cpp ) 
                
                
INSTALL( TARGETS ${CMAKE_PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)