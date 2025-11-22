add_library(game ${CMAKE_SOURCE_DIR}/src/game.cpp ${CMAKE_SOURCE_DIR}/include/game.h)
target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(game PUBLIC raylib)
