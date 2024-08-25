# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ProcessInfo_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ProcessInfo_autogen.dir/ParseCache.txt"
  "ProcessInfo_autogen"
  )
endif()
