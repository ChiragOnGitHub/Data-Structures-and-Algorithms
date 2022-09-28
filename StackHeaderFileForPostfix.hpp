//Stack Template

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