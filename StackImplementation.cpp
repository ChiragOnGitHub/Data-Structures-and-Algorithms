#include <iostream>
using namespace std;
#define TYPE int

template <class T>
class Stack{
    T* arr;
    int top;
    int size;

    public:
        Stack(int num){
            arr= new T[num];
            top=-1;
            size=num;
        }

        ~Stack(){
            delete[] arr;
        }

        T topElement(){
            if(isEmpty()){
                return -1;
            }
            else
                return arr[top];
        }

        int push(T num){
            if(isFull()){
                return -1;
            }
            top++;
            arr[top]=num; 
            return 0; 
        }

        int pop(){
            if(isEmpty()){
                return -1;
            }
            top--;
            return 0; 
        }

        bool isFull(){
            if(top==size-1)
                return true;
            return false;
        }

        bool isEmpty(){
            if(top==-1)
                return true;
            return false;
        }

};

int main()
{   
    int size;
    cout<<"Enter Size of Stack : ";
    cin>>size;

    TYPE value;
    int option;
    Stack<TYPE> a(size);
    
    do
    {   
        cout<<endl;
        cout<<"Press 1 for Push "<<endl;
        cout<<"Press 2 for Pop "<<endl;
        cout<<"Press 3 to access top element "<<endl;
        cout<<"Press 4 to quit "<<endl;
        cout<<endl;

        cout<<"Enter Your Choice : ";
        cin>>option;

        switch (option)
        {
        case 1:
            if(a.isFull()){
                cout<<"\t"<<"Overflow!! "<<endl;
            }
            else{
                cout<<"Enter the Value :";
                cin>>value;
                a.push(value);
                cout<<"\t"<<value<<" is pushed in the stack "<<endl;
            }
            break;
        case 2:
            if(a.isEmpty()){
                cout<<"\t"<<"Underflow!! "<<endl;
            }
            else{
                a.pop();
                cout<<"\t"<<"Element is Popped from the stack "<<endl;
            }
            break;
        
        case 3:
            if(a.isEmpty()){
                cout<<"\t"<<"Underflow!! "<<endl;
            }
            else{
                cout<<"\t"<<"Top element is : "<<a.topElement()<<endl;
            }
            break;

        case 4:
            break;
            
        default:
            cout<<"\t"<<"Invalid Choice !!"<<endl;
            break;
        }
    }
    while(option!=4);

    return 0;
}