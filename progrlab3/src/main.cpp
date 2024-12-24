#include <iostream>
#include "Containers/Array/DynamicArray.hpp"       
#include "Containers/List/SinglyLinkedList.hpp"   
#include "Containers/List/DoublyLinkedList.hpp"
#include <locale>

int main() {
    std::cout << "=== Динамический массив ===" << std::endl;
    DynamicArray dynamicArray;

    for (int i = 0; i < 10; ++i) {
        dynamicArray.push_back(i);
    }

    
    std::cout << "После добавления 10 элементов: ";
    for (auto it = dynamicArray.begin(); it != dynamicArray.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    std::cout << "Размер контейнера: " << dynamicArray.size() << std::endl;

    
    dynamicArray.erase(4);  
    dynamicArray.erase(5);  

    
    std::cout << "После удаления 5-го и 7-го элементов: ";
    for (auto it = dynamicArray.begin(); it != dynamicArray.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    dynamicArray.insert(0, 10);

    
    dynamicArray.insert(dynamicArray.size() / 2, 20);

    
    dynamicArray.push_back(30);

     
    std::cout << "После добавления 10 в начало, 20 в середину и 30 в конец: ";
    for (auto it = dynamicArray.begin(); it != dynamicArray.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    DynamicArray movedArray = std::move(dynamicArray);

    
    std::cout << "После перемещения (новый массив): ";
    for (auto it = movedArray.begin(); it != movedArray.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    std::cout << "Размер оригинального массива после перемещения: " << dynamicArray.size() << std::endl;


    
    std::cout << "\n=== Однонаправленный список ===" << std::endl;
    SinglyLinkedList singlyLinkedList;

    
    for (int i = 0; i < 10; ++i) {
        singlyLinkedList.push_back(i);
    }

    
    std::cout << "После добавления 10 элементов: ";
    for (auto it = singlyLinkedList.begin(); it != singlyLinkedList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    std::cout << "Размер контейнера: " << singlyLinkedList.size() << std::endl;

    
    singlyLinkedList.erase(4);  
    singlyLinkedList.erase(5);  

    
    std::cout << "После удаления 5-го и 7-го элементов: ";
    for (auto it = singlyLinkedList.begin(); it != singlyLinkedList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    singlyLinkedList.insert(0, 10);

    
    singlyLinkedList.insert(singlyLinkedList.size() / 2, 20);

    
    singlyLinkedList.push_back(30);

     
    std::cout << "После добавления 10 в начало, 20 в середину и 30 в конец: ";
    for (auto it = singlyLinkedList.begin(); it != singlyLinkedList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    SinglyLinkedList movedSinglyList = std::move(singlyLinkedList);

    
    std::cout << "После перемещения (новый список): ";
    for (auto it = movedSinglyList.begin(); it != movedSinglyList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    std::cout << "Размер оригинального списка после перемещения: " << singlyLinkedList.size() << std::endl;


    
    std::cout << "\n=== Двунаправленный список ===" << std::endl;
    DoublyLinkedList doublyLinkedList;

    
    for (int i = 0; i < 10; ++i) {
        doublyLinkedList.push_back(i);
    }

    
    std::cout << "После добавления 10 элементов: ";
    for (auto it = doublyLinkedList.begin(); it != doublyLinkedList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    std::cout << "Размер контейнера: " << doublyLinkedList.size() << std::endl;

    
    doublyLinkedList.erase(4);  
    doublyLinkedList.erase(5);  

    
    std::cout << "После удаления 5-го и 7-го элементов: ";
    for (auto it = doublyLinkedList.begin(); it != doublyLinkedList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    doublyLinkedList.insert(0, 10);

    doublyLinkedList.insert(doublyLinkedList.size() / 2, 20);

    doublyLinkedList.push_back(30);

    std::cout << "После добавления 10 в начало, 20 в середину и 30 в конец: ";
    for (auto it = doublyLinkedList.begin(); it != doublyLinkedList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    DoublyLinkedList movedDoublyList = std::move(doublyLinkedList);

    
    std::cout << "После перемещения (новый список): ";
    for (auto it = movedDoublyList.begin(); it != movedDoublyList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    std::cout << "Размер оригинального списка после перемещения: " << doublyLinkedList.size() << std::endl;

    return 0;
}