
#Auto Genrated CMake file by aura CLI
#None
cmake_minimum_required(VERSION 3.6...3.31)
project(focus VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(STATIC_LINK "Enable static linking" ON)

# Apply static linking if enabled
if(STATIC_LINK)
  message(STATUS "Static linking enabled")
  # Ensure static runtime linking on Windows
  if (WIN32)
      set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  else()
      set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
  endif()
endif()

set(COMPANY "None")
string(TIMESTAMP CURRENT_YEAR "%Y")
set(COPYRIGHT "Copyright(c) ${CURRENT_YEAR} ${COMPANY}.")
# add dependencies
include(external/CPM.cmake)

CPMAddPackage(
  NAME           saucer
  VERSION        6.0.1
  GIT_REPOSITORY "https://github.com/saucer/saucer"
)
include_directories(src ${CMAKE_BINARY_DIR})
configure_file(res/config.h.in focusconfig.h)

#@find Warning: Do not remove this line

file(GLOB SOURCES "src/*.cc" "src/*/*.cc")

add_executable(${PROJECT_NAME} ${SOURCES})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
#@link Warning: Do not remove this line
target_link_libraries(${PROJECT_NAME} saucer::saucer)
