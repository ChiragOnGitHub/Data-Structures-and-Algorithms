#include <iostream>
using namespace std;

#define TYPE float

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

    int binarySearch(T value){
        int start=0;
        int end=size-1;
        int mid;
        while(start<=end){
            mid =(start+end)/2;
            if(arr[mid]==value)
                return mid;
            else if(arr[mid]>value)
                end=mid-1;
            else
                start=mid+1;
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
    if((check=a.binarySearch(search))>=0){
        cout<<"Element is present in the array at index : "<<check;
    }
    else{
        cout<<"Element is not present in the array!!";
    }
    

    return 0;
}
