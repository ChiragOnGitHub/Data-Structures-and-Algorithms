#include "StackHeaderForParenthesisValidator.hpp"
#include <iostream>
using namespace std;

bool bracketValidity(string expression){
    Stack bracket(expression.length());

    for(int i=0;i<expression.length();i++){
        if(expression[i]=='(' || expression[i]=='{' || expression[i]=='[')
            bracket.push(expression[i]);

        else if(expression[i]==')' || expression[i]=='}' || expression[i]==']'){
            if(bracket.isEmpty())
                return false;
            else if((char)bracket.topElement()=='(' && expression[i]==')' || (char)bracket.topElement()=='[' && expression[i]==']' || (char)bracket.topElement()=='{' && expression[i]=='}'){

                bracket.pop();
            }
            else{
                return false;
            }
        }
    }

    if(bracket.isEmpty())
        return true;
    else
        return false;
}

int main()
{
    string expression;
    cout << "Enter your string : ";
    cin>>expression;


    bool check= bracketValidity(expression);
    if(check)
        cout<<"This Expression is valid !! ";
    else
        cout<<"This Expression is not valid !! ";
    
    return 0;
}