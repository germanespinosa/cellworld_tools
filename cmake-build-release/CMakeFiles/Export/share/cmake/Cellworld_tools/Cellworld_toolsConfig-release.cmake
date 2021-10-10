#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cellworld_tools" for configuration "Release"
set_property(TARGET cellworld_tools APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(cellworld_tools PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libcellworld_tools.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS cellworld_tools )
list(APPEND _IMPORT_CHECK_FILES_FOR_cellworld_tools "${_IMPORT_PREFIX}/lib/libcellworld_tools.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
