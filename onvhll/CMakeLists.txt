add_library(onvhll INTERFACE)

add_library(${PROJECT_NAME}::ONVHLL ALIAS onvhll)

target_include_directories(onvhll
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>
)

if (BUILD_TESTS)
  add_subdirectory(test)
endif()


target_link_libraries(onvhll INTERFACE common)

install(TARGETS onvhll
  EXPORT ${PROJECT_NAME}
)

install(FILES 
		include/AccessStatics.hpp
    include/EMatrix.hpp
    include/Histogram.hpp
    include/leader_zero.h
    include/leader_zero.cpp
    include/On_vHLL.hpp
    include/TwoTupleSketch.h
    include/xxhash32.h
    include/CardinalityMap.hpp
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/DataSketches")
