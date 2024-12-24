#pragma once
#include <iostream>

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t length;

public:
    
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    
    ~DoublyLinkedList() {
        clear();
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    
    DoublyLinkedList(DoublyLinkedList&& other) noexcept
        : head(other.head), tail(other.tail), length(other.length) {
        other.head = nullptr;
        other.tail = nullptr;
        other.length = 0;
    }

    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            length = other.length;

            other.head = nullptr;
            other.tail = nullptr;
            other.length = 0;
        }
        return *this;
    }

    
    void push_back(int value) {
        Node* new_node = new Node(value);
        if (!tail) { // Если список пуст
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        ++length;
    }

    
    void insert(size_t index, int value) {
        if (index > length) throw std::out_of_range("Index out of range");

        Node* new_node = new Node(value);
        if (index == 0) {
            new_node->next = head;
            if (head) {
                head->prev = new_node;
            }
            head = new_node;
            if (!tail) {
                tail = head;
            }
        } else if (index == length) {
            push_back(value);
        } else {
            Node* current = head;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            new_node->next = current;
            new_node->prev = current->prev;
            if (current->prev) {
                current->prev->next = new_node;
            }
            current->prev = new_node;
        }
        ++length;
    }

    
    void erase(size_t index) {
        if (index >= length) throw std::out_of_range("Index out of range");

        Node* current = head;
        if (index == 0) {
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            if (current == tail) {
                tail = nullptr;
            }
            delete current;
        } else {
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            if (current->prev) {
                current->prev->next = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            if (current == tail) {
                tail = current->prev;
            }
            delete current;
        }
        --length;
    }

    
    size_t size() const {
        return length;
    }

    
    class Iterator {
    private:
        Node* node;

    public:
        Iterator(Node* n) : node(n) {}

        int& operator*() {
            return node->data;
        }

        Iterator& operator++() {
            node = node->next;
            return *this;
        }

        Iterator& operator--() {
            node = node->prev;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return node != other.node;
        }
    };

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    
    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};