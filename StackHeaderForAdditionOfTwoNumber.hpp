class Stack{
    int* arr;
    int top;
    int size;

    public:
        Stack(int num){
            arr= new int[num];
            top=-1;
            size=num;
        }

        ~Stack(){
            delete[] arr;
        }

        int topElement(){
            if(isEmpty()){
                return -1; //means stack is empty
            }
            else
                return arr[top];
        }

        int push(int num){
            if(isFull()){
                return -1; // means Stack is full
            }
            top++;
            arr[top]=num; 
            return 0; //means successful push
        }

        int pop(){
            if(isEmpty()){
                return -1; // means Stack Empty
            }
            top--;
            return 0; // means successful pop
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