#include "StackHeaderFileForPostfix.hpp"
#include <iostream>
#include <string>
using namespace std;

void insertOperator(Stack<char> &stack, char ch, string &postfix)
{
    if (!stack.isEmpty())
    {
        while (true)
        {
            if (stack.topElement() == '/' && (ch == '+' || ch == '-' || ch == '*' || ch == '/'))
            {
                postfix += stack.topElement();
                stack.pop();
            }
            else if (stack.topElement() == '*' && (ch == '+' || ch == '-' || ch == '/' || ch == '*'))
            {
                postfix += stack.topElement();
                stack.pop();
            }
            else if (stack.topElement() == '+' && (ch == '-' || ch == '+'))
            {
                postfix += stack.topElement();
                stack.pop();
            }
            else if (stack.topElement() == '-' && (ch == '+' || ch == '-'))
            {
                postfix += stack.topElement();
                stack.pop();
            }
            else
            {
                stack.push(ch);
                break;
            }
        }
    }
    else
    {
        stack.push(ch);
    }
}

string infixToPostfix(string Expression)
{
    string postfix;
    Stack<char> stack(Expression.length());
    for (int i = 0; i < Expression.length(); i++)
    {
        if (Expression[i] < '0')
        {
            insertOperator(stack, Expression[i], postfix);
        }
        else if (Expression[i] >= '0' and Expression[i] <= '9')
        {
            postfix += Expression[i];
        }
    }

    // To Insert all the operator left in stack into Final Postfix
    while (!stack.isEmpty())
    {
        postfix += stack.topElement();
        stack.pop();
    }

    return postfix;
}

double valueAdder(double operand1,double operand2,char operator1)
{
    switch (operator1)
    {
        case '*':
            return operand1*operand2;
        case '/':
            return operand1/operand2;
        case '+':
            return operand1+operand2;
        case '-':
            return operand1-operand2;
        default:
            return 0;
    }
}

double postfixEvaluator(string Expression){
    double value;
    double operand1,operand2;
    Stack<double> stack(Expression.length());
    for (int i = 0; i < Expression.length(); i++)
    {
        if (Expression[i] < '0')
        {
            operand2=stack.topElement();
            stack.pop();
            operand1=stack.topElement();
            stack.pop();

            value=valueAdder(operand1, operand2,Expression[i]);
            stack.push(value);
        }
        else if (Expression[i] >= '0' and Expression[i] <= '9')
        {
            stack.push((int)Expression[i]-48);
        }
    }

    return stack.topElement();
    
}

int main()
{

    string Expression;
    cout << "Enter the expression : ";
    cin >> Expression;

    string postfix=infixToPostfix(Expression);
    cout << "Postfix Expression is : " << postfix<<endl;

    double postfixValue=postfixEvaluator(postfix);
    cout << "Value of Expression is : " << postfixValue<<endl;



    return 0;
}