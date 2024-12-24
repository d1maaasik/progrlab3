cmake_minimum_required(VERSION 3.10)
project(Containers LANGUAGES CXX)

set(HEADERS
    "Array/DynamicArray.hpp"
    "List/DoublyLinkedList.hpp"
    "List/SinglyLinkedList.hpp")

add_library(Containers INTERFACE ${HEADERS})