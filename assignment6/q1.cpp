#include <iostream>
using namespace std;

class DLLNode {
public:
    int data;
    DLLNode *prev, *next;
    DLLNode(int d) : data(d), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    DLLNode *head, *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() { clear(); }

    void clear() {
        for (DLLNode *p = head; p;) {
            DLLNode *n = p->next;
            delete p;
            p = n;
        }
        head = tail = nullptr;
    }

    void push_front(int x) {
        DLLNode *n = new DLLNode(x);
        n->next = head;
        if (head) head->prev = n;
        else tail = n;
        head = n;
    }

    void push_back(int x) {
        DLLNode *n = new DLLNode(x);
        n->prev = tail;
        if (tail) tail->next = n;
        else head = n;
        tail = n;
    }

    bool insert_after(int key, int x) {
        for (DLLNode *p = head; p; p = p->next)
            if (p->data == key) {
                DLLNode *n = new DLLNode(x);
                n->prev = p;
                n->next = p->next;
                if (p->next) p->next->prev = n;
                else tail = n;
                p->next = n;
                return true;
            }
        return false;
    }

    bool insert_before(int key, int x) {
        for (DLLNode *p = head; p; p = p->next)
            if (p->data == key) {
                if (p == head) return push_front(x), true;
                DLLNode *n = new DLLNode(x);
                n->next = p;
                n->prev = p->prev;
                p->prev->next = n;
                p->prev = n;
                return true;
            }
        return false;
    }

    bool erase_value(int x) {
        for (DLLNode *p = head; p; p = p->next)
            if (p->data == x) {
                if (p->prev) p->prev->next = p->next;
                else head = p->next;
                if (p->next) p->next->prev = p->prev;
                else tail = p->prev;
                delete p;
                return true;
            }
        return false;
    }

    bool search(int x) const {
        for (DLLNode *p = head; p; p = p->next)
            if (p->data == x) return true;
        return false;
    }

    int size() const {
        int c = 0;
        for (DLLNode *p = head; p; p = p->next) ++c;
        return c;
    }

    void print() const {
        for (DLLNode *p = head; p; p = p->next)
            cout << p->data << " ";
        cout << "\n";
    }
};

class CNode {
public:
    int data;
    CNode *next;
    CNode(int d) : data(d), next(this) {}
};

class CircularList {
    CNode *head;

public:
    CircularList() : head(nullptr) {}
    ~CircularList() { clear(); }

    void clear() {
        if (!head) return;
        CNode *p = head->next;
        while (p != head) {
            CNode *n = p->next;
            delete p;
            p = n;
        }
        delete head;
        head = nullptr;
    }

    void push_front(int x) {
        CNode *n = new CNode(x);
        if (!head) { head = n; return; }
        CNode *tail = head;
        while (tail->next != head) tail = tail->next;
        n->next = head;
        tail->next = n;
        head = n;
    }

    void push_back(int x) {
        CNode *n = new CNode(x);
        if (!head) { head = n; return; }
        CNode *tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = n;
        n->next = head;
    }

    bool insert_after(int key, int x) {
        if (!head) return false;
        CNode *p = head;
        do {
            if (p->data == key) {
                CNode *n = new CNode(x);
                n->next = p->next;
                p->next = n;
                return true;
            }
            p = p->next;
        } while (p != head);
        return false;
    }

    bool insert_before(int key, int x) {
        if (!head) return false;
        if (head->data == key) return push_front(x), true;
        CNode *prev = head, *cur = head->next;
        while (cur != head) {
            if (cur->data == key) {
                CNode *n = new CNode(x);
                n->next = cur;
                prev->next = n;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    bool erase_value(int x) {
        if (!head) return false;
        CNode *cur = head, *prev = nullptr;
        do {
            if (cur->data == x) {
                if (cur == head) {
                    if (head->next == head) { delete head; head = nullptr; return true; }
                    CNode *tail = head;
                    while (tail->next != head) tail = tail->next;
                    head = head->next;
                    tail->next = head;
                    delete cur;
                    return true;
                } else {
                    prev->next = cur->next;
                    delete cur;
                    return true;
                }
            }
            prev = cur;
            cur = cur->next;
        } while (cur != head);
        return false;
    }

    bool search(int x) const {
        if (!head) return false;
        CNode *p = head;
        do {
            if (p->data == x) return true;
            p = p->next;
        } while (p != head);
        return false;
    }

    int size() const {
        if (!head) return 0;
        int c = 0;
        CNode *p = head;
        do { ++c; p = p->next; } while (p != head);
        return c;
    }

    void print_once() const {
        if (!head) { cout << "\n"; return; }
        CNode *p = head;
        do { cout << p->data << " "; p = p->next; } while (p != head);
        cout << "\n";
    }

    void print_with_head_repeat() const {
        if (!head) { cout << "\n"; return; }
        CNode *p = head;
        do { cout << p->data << " "; p = p->next; } while (p != head);
        cout << head->data << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DoublyLinkedList dll;
    CircularList cll;

    while (true) {
        cout << "\n1) DLL insert front/back/after/before\n"
             << "2) DLL delete\n3) DLL search\n4) DLL size\n5) DLL print\n"
             << "6) CLL insert front/back/after/before\n"
             << "7) CLL delete\n8) CLL search\n9) CLL size\n"
             << "10) CLL print once\n11) CLL print with head repeat\n12) Exit\nChoice: ";

        int ch; if (!(cin >> ch)) break;

        if (ch == 1) {
            int t; cout << "1 front 2 back 3 after 4 before: "; cin >> t;
            if (t == 1) { int x; cin >> x; dll.push_front(x); }
            else if (t == 2) { int x; cin >> x; dll.push_back(x); }
            else if (t == 3) { int k, x; cin >> k >> x; cout << (dll.insert_after(k, x) ? "OK\n" : "NotFound\n"); }
            else if (t == 4) { int k, x; cin >> k >> x; cout << (dll.insert_before(k, x) ? "OK\n" : "NotFound\n"); }
        } 
        else if (ch == 2) { int x; cin >> x; cout << (dll.erase_value(x) ? "Deleted\n" : "NotFound\n"); }
        else if (ch == 3) { int x; cin >> x; cout << (dll.search(x) ? "Found\n" : "NotFound\n"); }
        else if (ch == 4) cout << dll.size() << "\n";
        else if (ch == 5) dll.print();
        else if (ch == 6) {
            int t; cout << "1 front 2 back 3 after 4 before: "; cin >> t;
            if (t == 1) { int x; cin >> x; cll.push_front(x); }
            else if (t == 2) { int x; cin >> x; cll.push_back(x); }
            else if (t == 3) { int k, x; cin >> k >> x; cout << (cll.insert_after(k, x) ? "OK\n" : "NotFound\n"); }
            else if (t == 4) { int k, x; cin >> k >> x; cout << (cll.insert_before(k, x) ? "OK\n" : "NotFound\n"); }
        }
        else if (ch == 7) { int x; cin >> x; cout << (cll.erase_value(x) ? "Deleted\n" : "NotFound\n"); }
        else if (ch == 8) { int x; cin >> x; cout << (cll.search(x) ? "Found\n" : "NotFound\n"); }
        else if (ch == 9) cout << cll.size() << "\n";
        else if (ch == 10) cll.print_once();
        else if (ch == 11) cll.print_with_head_repeat();
        else if (ch == 12) break;
    }
}
