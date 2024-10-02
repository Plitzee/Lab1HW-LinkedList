//NguyenQuocHuy
//22520566
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:

    string song;
    Node* next;
    Node* prev;

    Node(string value) : song(value), next(NULL), prev(NULL) {}
};

class LinkedList {
public:
    Node* head;
    Node* current;

    LinkedList() : head(NULL), current(NULL) {}

    void addsong(string song) {
        Node* newNode = new Node(song);
        if (head == NULL) {
            head = newNode; 
            head->next = head; 
            head->prev = head; 
            current = head; 
        } else {
            Node* tail = head->prev; 
            tail->next = newNode; 
            newNode->prev = tail; 
            newNode->next = head; 
            head->prev = newNode; 
        }
    }

    void nextsong() {
        if (current != NULL) {
            current = current->next;
        }
    }


    void playprev() {
        if (current != NULL) {
            current = current->prev;
        }
    }


     void removeSong(string songName) {
        if (head == NULL) return; 

        Node* temp = head;

        do {
            if (temp->song == songName) {
               
                if (temp->next == temp) {
                    delete temp;
                    head = NULL;
                    current = NULL;
                    return;
                }

             
                if (temp == head) {
                    head->prev->next = head->next; 
                    head->next->prev = head->prev; 
                    head = head->next; 
                } else {
                   
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }

                if (current == temp) {
                    current = temp->next; 
                }

                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
    void display() {
        if (head == NULL) {
            cout << "No songs." << endl;
            return;
        }

        Node* temp = current;

       while (temp != current){
            cout << temp->song << " ";
            temp = temp->next;
        } 
    }
};

int main() {
    LinkedList playlist;
    long n;
    cout <<"please enter numbers of operators: "<<endl;
    cin >> n;
    string command;
    string song;

    for (int i = 0; i < n; ++i) {
        cout<<"please enter the command(add/next/prev/remove/display): "<<endl;
        cin >> command;
        if (command == "add") {
            cin >> song;
            playlist.addsong(song);
        } 
        else if (command == "next") {
            playlist.nextsong();
        } 
        else if (command == "prev") {
            playlist.playprev();
        } 
        else if (command == "remove") {
            cin >> song;
            playlist.removesong(song);
        } 
        else if (command == "display") {
            playlist.display(); 
        }
    }

    return 0;
}

