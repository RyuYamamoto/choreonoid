
# @author Shin'ichiro Nakaoka

if(WIN32)
  option(BUILD_PYTHON_PLUGIN "Building Python Plugin" OFF)
else()
  option(BUILD_PYTHON_PLUGIN "Building Python Plugin" ON)
endif()

if(NOT BUILD_PYTHON_PLUGIN)
  return()
elesif(NOT ENABLE_PYTHON)
  message(FATAL_ERROR "PythonPlugin needs to ENABLE_PYTHON")
endif()

#set(CMAKE_BUILD_TYPE Debug)

set(target CnoidPythonPlugin)

set(sources
  PythonPlugin.cpp
  PythonExecutor.cpp
  PythonScriptItem.cpp
  PythonScriptItemImpl.cpp
  PythonConsoleView.cpp
  )

set(headers
  PythonPlugin.h
  PythonExecutor.h
  PythonScriptItem.h
  PythonScriptItemImpl.h
  )

make_gettext_mofiles(${target} mofiles)
add_cnoid_plugin(${target} SHARED ${sources} ${headers} ${mofiles})
target_link_libraries(${target} CnoidBase ${PYTHON_LIBRARIES} ${Boost_PYTHON_LIBRARY})

apply_common_setting_for_plugin(${target} "${headers}")

configure_file(rbimporter.py ${PROJECT_BINARY_DIR}/${CNOID_PYTHON_SUBDIR}/cnoid/ COPYONLY)
install(FILES rbimporter.py DESTINATION ${CNOID_PYTHON_SUBDIR}/cnoid
  CONFIGURATIONS Release Debug RelWithDebInfo MinSizeRel)

add_subdirectory(python)
