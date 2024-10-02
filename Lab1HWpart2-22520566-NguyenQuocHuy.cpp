//NguyenQuocHuy
//22520566
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    string URL;
    Node* prev;
    Node* next;

    Node(string URL) : URL(URL), prev(NULL), next(NULL) {}
};

class BrowserHistory {
public:
    Node* head;    // Node trang chu
    Node* current; // Node hien tai


    BrowserHistory(string homepage) {
        head = new Node(homepage);  // Tao trang chu
        current = head;             // Diem hien tai la head
    }


    void visit(string URL) {
        Node* newNode = new Node(URL);
        current->next = newNode;   // Ket noi current voi newNode
        newNode->prev = current;   // Ket noi newNode lai voi current
        current = newNode;         // Di chuyen current toi newNode
    }


    string back(int steps) {
        while (steps > 0 && current->prev != NULL) {
            if (current->prev == head) {
                current = current->prev; // Di den head
                break;
            }
            current = current->prev; // Di chuyen ve truoc
            steps--;
        }
        return current->URL; // Tra ve URL hien tai
    }


    string forward(int steps) {
        while (steps > 0 && current->next != NULL) {
            current = current->next; // Di chuyen toi node tiep theo
            steps--;
        }
        return current->URL; // Tra ve URL hien tai
    }


    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->URL << " -> "; // In URL
            temp = temp->next;
        }
        cout << "NULL" << endl; // Ket thuc
    }


    ~BrowserHistory() {
        Node* temp;
        while (head) { // Xoa cac node tu head
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void processBrowserHistory() {
    string homepage;
    cin >> homepage; // Nhap trang chu

    BrowserHistory* browserHistory = new BrowserHistory(homepage); // Tao doi tuong BrowserHistory
    cout << "null" << endl;
    
    string command;
    while (cin >> command) {
        if (command == "visit") {
            string URL;
            cin >> URL;  // Nhap URL
            browserHistory->visit(URL);
            cout << "null" << endl;  // Xuat null
        } else if (command == "back") {
            int steps;
            cin >> steps;  // Nhap so buoc
            cout << browserHistory->back(steps) << endl;  // Xuat URL sau khi quay lai
        } else if (command == "forward") {
            int steps;
            cin >> steps;  // Nhap so buoc
            cout << browserHistory->forward(steps) << endl;  // Xuat URL sau khi tien toi
        }
    }
    
    browserHistory->display(); 

}

int main() {
    processBrowserHistory();  
    return 0;
}
