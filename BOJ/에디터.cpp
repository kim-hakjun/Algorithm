#include <iostream>
#include <string>

// 링크드 리스트 구현 연습

using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;

    Node() {
        prev = next = NULL;
        data = ' ';
    }

    Node(char i, Node* ptr) {
        data = i;
        prev = ptr;
        next = ptr->next;
        next->prev = prev->next = this;
    }

    void deleteNode() {
        prev->next = next;
        next->prev = prev;
        delete this;
    }
};

struct DLinkedList {
    Node* head;
    Node* tail;

    DLinkedList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void insertFirst(char i) {
        new Node(i, head);
    }

    void insertEnd(char i) {
        new Node(i, tail->prev);
    }

    void deleteFirst() {
        if (head->next != tail) head->next->deleteNode();
    }

    void deleteEnd() {
        if (tail->prev == head) return;
        tail->prev->deleteNode();
    }

    void printAll() {
        Node* tmp = head;
        while (tmp->next != NULL) {
            cout << tmp->next->data;
            tmp = tmp->next;
        }
    }

    // 1406번을 위한 함수
    void moveLeft() {
        if (tail->prev != head) {
            tail = tail->prev;
        }
    }

    void moveRight() {
        if (tail->data != ' ') {
            tail = tail->next;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int turn;
    char inp;

    cin >> str >> turn;

    DLinkedList* root = new DLinkedList();
    for (int i = 0; i < str.length(); i++) {
        root->insertEnd(str[i]);
    }

    for (int i = 0; i < turn; i++) {
        cin >> inp;
        if (inp == 'L') {
            root->moveLeft();
        }
        else if (inp == 'D') {
            root->moveRight();
        }
        else if (inp == 'B') {
            root->deleteEnd();
        }
        else if (inp == 'P') {
            cin >> inp;
            root->insertEnd(inp);
        }
    }

    root->printAll();
    return 0;
}