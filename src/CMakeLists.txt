add_library(game ${CMAKE_SOURCE_DIR}/src/game.cpp ${CMAKE_SOURCE_DIR}/include/game.h)
target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(game PUBLIC raylib)

add_library(render ${CMAKE_SOURCE_DIR}/src/render.cpp ${CMAKE_SOURCE_DIR}/include/render.h)
target_include_directories(render PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(render PUBLIC raylib)
