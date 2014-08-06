# Files needed in libengine.a
file ( GLOB_RECURSE 2D_ENGINE_LIBRARY_SRC ${CMAKE_SOURCE_DIR} *.cpp )

# Create libengine and target alias
add_library ( 2D-engine ${2D_ENGINE_LIBRARY_SRC} )
add_custom_target ( lib2D-engine.a DEPENDS 2D-engine )
install ( TARGETS 2D-engine ARCHIVE DESTINATION lib )
