# Files needed in libengine.a
file ( GLOB_RECURSE 2D_ENGINE_LIBRARY_SRC ${CMAKE_SOURCE_DIR} *.cpp )

# Include headers from src
include_directories ( ${CMAKE_CURRENT_SOURCE_DIR} )

# Create libengine and target alias
add_library ( engine ${2D_ENGINE_LIBRARY_SRC} )
add_custom_target ( libengine.a DEPENDS engine )
