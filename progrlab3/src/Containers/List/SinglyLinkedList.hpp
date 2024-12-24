class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    size_t length;

public:
    SinglyLinkedList() : head(nullptr), length(0) {}

    ~SinglyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    SinglyLinkedList(SinglyLinkedList&& other) noexcept : head(other.head), length(other.length) {
        other.head = nullptr;
        other.length = 0;
    }

    SinglyLinkedList& operator=(SinglyLinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            length = other.length;
            other.head = nullptr;
            other.length = 0;
        }
        return *this;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        length = 0;
    }

    
    void push_back(int value) {
        Node* new_node = new Node(value);
        if (!head) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
        ++length;
    }

    
    void insert(size_t index, int value) {
        if (index > length) throw std::out_of_range("Index out of range");
        Node* new_node = new Node(value);
        if (index == 0) {
            new_node->next = head;
            head = new_node;
        } else {
            Node* current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
        ++length;
    }

    
    void erase(size_t index) {
        if (index >= length) throw std::out_of_range("Index out of range");
        Node* temp;
        if (index == 0) {
            temp = head;
            head = head->next;
        } else {
            Node* current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            temp = current->next;
            current->next = temp->next;
        }
        delete temp;
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