#ifndef __LINKED_LIST__
#define __LINKED_LIST__

template <typename T>
class LinkedList {
    private:
        struct Node {
            T data;
            Node* next;

            Node(const T& val) : data(val), next(nullptr) {}
        };

        Node* head;
        int current_size;

    public:
        LinkedList() : head(nullptr), current_size(0) {}

        ~LinkedList() {
            clear();
        }

        // Add element to the front of the list
        bool push_front(const T& element) {
            Node* new_node = new Node(element);
            if (new_node == nullptr) {
                return false; // memory allocation failed
            }
            new_node->next = head;
            head = new_node;
            current_size++;
            return true;
        }

        // Add element to the back of the list
        bool push_back(const T& element) {
            Node* new_node = new Node(element);
            if (new_node == nullptr) {
                return false; // memory allocation failed
            }
            
            if (head == nullptr) {
                head = new_node;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = new_node;
            }
            current_size++;
            return true;
        }

        // Remove element from the front
        bool pop_front() {
            if (head == nullptr) {
                return false; // list is empty
            }
            Node* temp = head;
            head = head->next;
            delete temp;
            current_size--;
            return true;
        }

        // Get the first element (read-only)
        const T& front() const {
            return head->data;
        }

        // Get the first element (read-write)
        T& front() {
            return head->data;
        }

        // Get element at index (read-only)
        const T& at(int index) const {
            Node* current = head;
            for (int i = 0; i < index && current != nullptr; i++) {
                current = current->next;
            }
            return current->data;
        }

        // Get element at index (read-write)
        T& at(int index) {
            Node* current = head;
            for (int i = 0; i < index && current != nullptr; i++) {
                current = current->next;
            }
            return current->data;
        }

        // Get the current size
        int size() const {
            return current_size;
        }

        // Check if list is empty
        bool empty() const {
            return current_size == 0;
        }

        // Clear the entire list
        void clear() {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            current_size = 0;
        }

        // Remove element at index
        bool remove(int index) {
            if (index < 0 || index >= current_size || head == nullptr) {
                return false;
            }

            if (index == 0) {
                return pop_front();
            }

            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            current_size--;
            return true;
        }
};

#endif
