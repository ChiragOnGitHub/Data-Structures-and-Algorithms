#include "StackHeaderForAdditionOfTwoNumber.hpp"
#include <iostream>
using namespace std;

// function to convert string into stack
void stringToStack(string str, Stack &stack)
{
    for (int i = 0; i < str.length(); i++)
    {
        stack.push(int(str[i]) - 48);
    }
}

// to return the array size of final array
int arraySize(int num1, int num2)
{
    if (num1 > num2)
        return num1 + 1;
    else
        return num2 + 1;
}

// to print stack
void displayStack(Stack stack)
{
    while (!stack.isEmpty())
    {
        cout << stack.topElement() << " ";
        stack.pop();
    }
}

// return 0 when stack is empty else return top element
int top(Stack &stack)
{
    if (stack.isEmpty())
    {
        return 0;
    }
    return stack.topElement();
}

int main()
{
    string string1, string2;

    // input two number as strings
    cout << "Enter 1st Number : ";
    cin >> string1;
    cout << "Enter 2nd Number : ";
    cin >> string2;

    // creating stack of size of string
    Stack stack1(string1.length());
    Stack stack2(string2.length());

    stringToStack(string1, stack1);
    stringToStack(string2, stack2);

    int carry = 0;
    Stack stackSum(arraySize(string1.length(), string2.length()));

    while (!stack1.isEmpty() || !stack2.isEmpty())
    {
        stackSum.push((top(stack1) + top(stack2) + carry) % 10);
        carry = (top(stack1) + top(stack2) + carry) / 10;
        stack1.pop();
        stack2.pop();
    }
    if (carry != 0)
        stackSum.push(carry);

    cout << "Summation of Two entered Numbers is : ";
    displayStack(stackSum);

    return 0;
}