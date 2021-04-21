cmake_minimum_required(VERSION 3.10.2)

# set project name

project(Pendu)

include_directories(include)

set(SOURCES src/dico.c
			src/main.c)
			

# add the executable
add_executable(Pendu
               ${SOURCES})			