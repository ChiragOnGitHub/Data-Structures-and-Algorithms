#include <iostream>
using namespace std;

#define TYPE char

template <class T>
class Array
{
    T *arr;
    int size;

    void swap(int i, int j)
    {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

public:


    Array(int num)
    {
        arr = new T[num];
        size = num;
    }

    void selectionSort()
    {
        int smallestIndex=0;
        for (int i = 0; i < size-1; i++)
        {
            smallestIndex = i;
            
            for (int j = i+1; j < size; j++)
            {
                if (arr[j] < arr[smallestIndex])
                {
                    smallestIndex = j;
                }
            }
            if(smallestIndex!=i){
                swap(smallestIndex, i);
            }
        }
    }

    void bubbleSort()
    {
        for (int i = 0; i < size-1; i++)
            for (int j = 0; j < size - i-1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(j, j + 1);
                }
            }
    }

    void insertionSort()
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(j, j + 1);
                }
                else
                {
                    break;
                }
            }
        }
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

};

int main()
{
    int sizeOfArray;
    cout << "Enter size of array : ";
    cin >> sizeOfArray;
    char choice;


    Array<TYPE> a(sizeOfArray);
    cout<<"Enter elements of array : ";
    a.arrayInsertion();

    cout<<"\nPress 1 for insertion sort\nPress 2 for bubble sort\nPress 3 for selection sort\n\nEnter Your Choice : ";
    cin>>choice;

    switch(choice){
        case '1':
            a.insertionSort();
            cout<<"\nArray after sorting using insertion sort : ";
            a.displayArray();
            cout<<endl;
            break;

        case '2':
            cout<<"\nArray after sorting using bubble sort    : ";
            a.bubbleSort();
            a.displayArray();
            cout<<endl;
            break;

        case '3':
            cout<<"\nArray after sorting using selection sort : ";
            a.selectionSort();
            a.displayArray();
            cout<<endl;
            break;

        default:
            cout<<"\nInvalid Choice !! ";
    }

    return 0;
}
