// Link : https://leetcode.com/problems/design-linked-list/

struct Node {
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class MyLinkedList {
    Node* head;
public:
    MyLinkedList() {
        this->head = nullptr;
    }
    
    int get(int index) {
        if (this->head == nullptr)
            return -1;
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
            if (temp == nullptr)
                return -1;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        if (this->head == nullptr) {
            this->head = new Node(val);
            return;
        }
        Node* temp = this->head;
        this->head = new Node(val);
        this->head->next = temp;
    }
    
    void addAtTail(int val) {
        if (this->head == nullptr) {
            this->head = new Node(val);
            return;
        }
        Node* temp = this->head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new Node(val);
    }
    
    void addAtIndex(int index, int val) {
        if (this->head == nullptr) {
            if (index != 0)
                return;
            this->head = new Node(val);
            return;
        }
        if (index == 0) {
            Node* n = new Node(val);
            n->next = head;
            head = n;
            return;
        }
        Node* temp = this->head;
        for (int i = 0; i < index-1; i++) {
            temp = temp->next;
            if (temp == nullptr)
                return;
        }
        Node* n = new Node(val);
        Node* n2 = temp->next;
        temp->next = n;
        n->next = n2;
    }
    
    void deleteAtIndex(int index) {
        if (this->head == nullptr)
            return;
        if (index == 0) {
            Node* temp = this->head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = this->head;
        for (int i = 0; i < index-1; i++) {
            temp = temp->next;
            if (temp == nullptr)
                return;
        }
        Node* del = temp->next;
        if (del == nullptr)
            return;
        temp->next = temp->next->next;
        delete del;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */