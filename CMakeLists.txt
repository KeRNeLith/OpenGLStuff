# Project #-----------------------------------------------------------------------------------------
project ( appOpenGL )

cmake_minimum_required ( VERSION 2.8.9 )

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Load modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
# Search SDL2 using cmake/FindSDL2.cmake
find_package(SDL2 REQUIRED)

# C++ Warning Level #-------------------------------------------------------------------------------
if ( CMAKE_COMPILER_IS_GNUCXX )
        set ( CMAKE_CXX_FLAGS "-std=c++11 -Wall -pedantic -pedantic-errors -Wextra -Wcast-align -Wcast-qual -Wchar-subscripts -Wcomment -Wconversion -Wdisabled-optimization -Werror -Wformat -Wformat=2 -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wimport -Winit-self -Winline -Winvalid-pch	-Wunsafe-loop-optimizations -Wmissing-braces	-Wmissing-field-initializers -Wmissing-format-attribute	-Wmissing-include-dirs -Wmissing-noreturn -Wparentheses -Wpointer-arith -Wredundant-decls -Wreturn-type -Wsequence-point -Wshadow -Wsign-compare -Wstack-protector	-Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch -Wswitch-default -Wswitch-enum -Wtrigraphs -Wuninitialized -Wunknown-pragmas -Wunreachable-code -Wunused -Wunused-function -Wunused-label -Wunused-parameter -Wunused-value -Wunused-variable -Wvariadic-macros -Wvolatile-register-var -Wwrite-strings -Wfloat-equal -Weffc++ ${CMAKE_CXX_FLAGS}" )
endif()

# Sources #-----------------------------------------------------------------------------------------
include_directories ( src/ )

file(GLOB_RECURSE app_src src/*.cpp)
file(GLOB_RECURSE app_headers src/*.h)

# Include OpenGL GLUT and SDL2
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${SDL2_INCLUDE_DIR} )

# Executable #-------------------------------------------------------------------------------------
add_executable ( ${CMAKE_PROJECT_NAME}
                 ${app_headers}
                 ${app_src}
               )

# Build #-------------------------------------------------------------------------------------------
target_link_libraries(	${CMAKE_PROJECT_NAME} 
						${OPENGL_LIBRARIES} 
						${GLUT_LIBRARY} 
						${SDL2_LIBRARY}
					 )
