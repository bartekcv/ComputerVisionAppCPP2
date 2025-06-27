cmake_minimum_required(VERSION 3.14)
project(ComputerVisionApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(/usr/include)
link_directories(/usr/lib/x86_64-linux-gnu)


# Qt
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

# OpenCV
find_package(OpenCV REQUIRED)

find_package(CURL REQUIRED)



set(JSON_BuildTests OFF CACHE BOOL "Disable building json tests" FORCE)

# nlohmann::json (header-only)
include(FetchContent)
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)



# Automatically collect all source files
file(GLOB_RECURSE SRC
    CONFIGURE_DEPENDS
    main.cpp
    #core/*.cpp core/*.h
    #filters/*.cpp filters/*.h
    tools/*.cpp tools/*.h
    gui/*.cpp gui/*.h
)

add_executable(${PROJECT_NAME} ${SRC})

# Add include directory for nlohmann/json
target_include_directories(${PROJECT_NAME} PRIVATE ${json_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    Qt5::Core Qt5::Widgets Qt5::Gui
    ${OpenCV_LIBS}
    ${CURL_LIBRARIES}
    #nlohmann_json::nlohmann_json
    -ltiff
)