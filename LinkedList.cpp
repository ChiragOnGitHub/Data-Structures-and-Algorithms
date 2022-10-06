#include <iostream>
using namespace std;

class Node{
    public:
        int element;
        Node* next;

    Node(int num){
        element=num;
        next=NULL;
    }
};

class LinkedList{
    Node* head;
    Node* tail;
    
    public:

    LinkedList(){
        head=NULL;
        tail=NULL;
    }

    //function to add node at the head of the linked List
    int addToHead(int element){
        Node* node= new Node(element);
        if (head==NULL){
            head=node;
            tail=node;
        }
        else{
            node->next=head;
            head=node;
        }

    }

    //function to add node at the tail of the linked List
    int addToTail(int element){
        Node* node= new Node(element);
        if (head==NULL){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }

    }

    void display(){
        Node* temp;
        temp=head;
        while(temp!=NULL){
            cout<<temp->element<<" -> ";
            temp=temp->next;

        }
        cout<<"Null"<<endl;
    }
};

int main(){
    LinkedList L;
    L.display();
    L.addToHead(11);
    L.display();
    L.addToHead(15);
    L.display();
    L.addToTail(17);
    L.display();
    L.addToTail(10);
    L.display();

    return 0;
}