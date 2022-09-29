#include <iostream>
using namespace std;

#define TYPE int

template <class T>
class Array
{
    T *arr;
    int size;

public:


    Array(int num)
    {
        arr = new T[num];
        size = num;
    }

    void displayArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void arrayInsertion()
    {
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    int LinearSearch(T value){
        for(int i=0;i<size;i++){
            if(arr[i]==value){
                return i;
            }
        }
        return -1;
    }

};

int main()
{

    int sizeOfArray;
    TYPE search;
    int check;
    cout << "Enter size of array : ";
    cin >> sizeOfArray;    

    Array<TYPE> a(sizeOfArray);
    cout<<"Enter elements of array : ";
    a.arrayInsertion();


    cout<<"Enter the value to be searched : ";
    cin>>search;
    if((check=a.LinearSearch(search))>=0){
        cout<<"Element is present in the array at index : "<<check;
    }
    else{
        cout<<"Element is not present in the array!!";
    }
    

    return 0;
}
