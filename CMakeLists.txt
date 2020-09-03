cmake_minimum_required(VERSION 3.17)
project(03_cub3d C)


set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "")
set(CMAKE_EXE_LINKER_FLAGS "-framework OpenGL -framework AppKit")

include_directories(includes)
include_directories(lib/libft/includes)
include_directories(lib/mlx)

SET(HEADER_FILES
        lib/libft/includes/libft.h
        includes/cub3d.h
        includes/ft_parser.h
)

set(SRC_FILES
        src/cub3d.c
        src/parser/ft_parser.c
)

link_directories(${CMAKE_SOURCE_DIR}/lib/mlx)

set(LIBS
        ${CMAKE_SOURCE_DIR}/lib/libft/libft.a
        ${CMAKE_SOURCE_DIR}/lib/mlx/libmlx.a)

add_executable(03_cub3d
        ${HEADER_FILES}
        ${SRC_FILES})

target_link_libraries(03_cub3d ${LIBS})
