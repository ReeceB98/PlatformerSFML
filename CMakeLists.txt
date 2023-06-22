cmake_minimum_required(VERSION 3.14)
project(PlatformerSFML)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()

set(CMAKE_PREFIX_PATH C:/)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h src/GameObject.h src/GameObject.cpp src/Coin.cpp src/Coin.h src/Vector2.cpp src/Vector2.h src/Menu.cpp src/Menu.h src/Platform.cpp src/Platform.h src/WinScreen.cpp src/WinScreen.h src/LoseScreen.cpp src/LoseScreen.h src/Lives.cpp src/Lives.h src/Score.cpp src/Score.h)
add_executable(PlatformerSFML ${SOURCE_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

target_link_libraries (PlatformerSFML sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)