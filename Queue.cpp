#include <iostream>
using namespace std;
#define TYPE char

template <class T>
class Queue{
    private:
        T *arr;
        int size; // size of queue
        int front;
        int end;
        bool checkFull;//  variable to check if queue is full  
        bool checkEmpty;//  variable to check if queue is empty 

    public:
        Queue(int num){
            arr= new T[num];
            front=0;
            end=0;
            size=num;
            checkFull=false;
            checkEmpty=true;
        }

        int enqueue(T num){
            if(isFull()){
                return -1;
            }

            //Entering an element in the queue
            // then increasing the end circularly
            arr[end]=num;
            if(end==size-1)
                end=0;
            else
                end++;
            
            //checking if queue become full now or not
            if(front==end)
                checkFull=true;
            else
                checkFull=false;

            checkEmpty=false;
            return 0;
        }

        int dequeue(){
            if(isEmpty())
                return -1;

            //decreasing the front circularly
            if(front==size-1)
                front=0;
            else
                front++;

            //checking if queue become empty or not
            if(front==end)
                checkEmpty=true;
            else
                checkEmpty=false;

            checkFull=false;

            return 0;
        }

        int frontElement(){
            if(isEmpty())
                return -1;
            return arr[front];
        }
        
        bool isEmpty(){
            return checkEmpty;
        }

        bool isFull(){
            return checkFull;
        }

};

int main()
{   
    int size;
    cout<<"Enter Size of Queue : ";
    cin>>size;

    TYPE value;
    int check;
    int option;

    Queue<TYPE> a(size);
    
    do
    {   
        cout<<endl;
        cout<<"Press 1 for Enqueue : "<<endl;
        cout<<"Press 2 for Dequeue : "<<endl;
        cout<<"Press 3 to access front element : "<<endl;
        cout<<"Press 4 to quit : "<<endl;
        cout<<endl;

        cout<<"Enter Your Choice : "<<endl;
        cin>>option;

        switch (option)
        {
        case 1:
            if(a.isFull()){
                cout<<"Overflow !! ";
            }
            else{
                cout<<"Enter the Number :";
                cin>>value;
                a.enqueue(value);
                cout<< value<<" is enqueued in the queue "<<endl;
            }
            break;

        case 2:
            if(a.isEmpty()){
                cout<<"Underflow !! ";
            }
            else{
                a.dequeue();
                cout<<"Element is dequeued from the queue "<<endl;
            }
            break;
        
        case 3:
            if(a.isEmpty()){
                cout<<"Underflow!! "<<endl;
            }
            else{
                cout<<"Front element is : "<<a.frontElement()<<endl;
            }
            break;

        case 4:
            break;
            
        default:
            cout<<"Invalid Choice !!"<<endl;
            break;
        }
    }
    while(option!=4);

    return 0;
}