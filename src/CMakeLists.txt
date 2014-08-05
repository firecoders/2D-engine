# Files needed in libengine.a
file ( GLOB_RECURSE 2D_ENGINE_LIBRARY_SRC ${CMAKE_SOURCE_DIR} *.cpp )

# Create libengine and target alias
add_library ( engine ${2D_ENGINE_LIBRARY_SRC} )
add_custom_target ( libengine.a DEPENDS engine )
