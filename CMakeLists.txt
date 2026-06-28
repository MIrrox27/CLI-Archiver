# author github.com/MIrrox27/CLI-Archiver
# CMakelists.txt

cmake_minimum_required(VERSION 3.15)
project(CLI-Archiver VERSION 1.0 LANGUAGES CXX)

# Включаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Говорим, где искать заголовочные файлы (.h)
include_directories(include)

# Собираем все файлы .cpp в папке src автоматически
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Создаем исполняемый файл axarch из найденных исходников
add_executable(axarch ${SOURCES})