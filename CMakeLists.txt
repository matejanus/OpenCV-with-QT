cmake_minimum_required(VERSION 3.15)

project(QtOpencv LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set( SRC
    Sources/main.cpp
    Sources/qcvwidget.cpp
    Sources/opencvworker.cpp

)

set( HEADERS
    Headers/qcvwidget.h
    Headers/opencvworker.h
)

set( UI
    qcvwidget.ui
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package( OpenCV REQUIRED )

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/Headers)


add_executable(QtOpencv
  Sources/main.cpp
  Sources/qcvwidget.cpp
  Headers/qcvwidget.h
  Headers/opencvworker.h
  Sources/opencvworker.cpp
  Sources/qcvwidget.ui
)

#add_executable( QtOpencv ${SRC} ${HEADERS} ${UI} )

target_link_libraries(QtOpencv PRIVATE Qt5::Widgets ${OpenCV_LIBS})
