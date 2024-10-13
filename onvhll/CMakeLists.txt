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
    include/On_vHLL.hpp
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/DataSketches")
