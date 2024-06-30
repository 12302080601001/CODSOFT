#include<iostream>
using namespace std;
class Addition
{
    public:
    void Sum(float a,float b)
    {
        float sum = a+b;
        cout<<"SUM="<<sum<<endl;
    }
};
class Subtraction
{
    public:
    void Sub(float a,float b)
    {
        float sub = a-b;
        cout<<"SUB="<<sub<<endl;
    }
};
class Multiplication
{
    public:
    void Multi(float a, float b)
    {
        float multi= a*b;
        cout<<"MULTI="<<multi<<endl;
    }
};
class Division
{
    public:
    void Div(float a, float b)
    {
        float div= a/b;
        if(b==0)
        {
            cout<<"Invalid logic"<<endl;
        }
        else
        {
            cout<<"Div="<<div<<endl;
        }
    }
};
int main()
{
    Addition A;
    Subtraction S;
    Multiplication M;
    Division D;
    float number1;
    float number2;
    cout<<"Enter number1:"<<endl;
    cin>>number1;
    cout<<"Enter number2:"<<endl;
    cin>>number2;
    char op;
    cout<<"Enter your choice:"<<endl;
    cin>>op;
    switch (op)
    {
    case '+':
        A.Sum(number1,number2);
        break;
    case '-':
        S.Sub(number1,number2);
        break;
    case '*':
        M.Multi(number1,number2);
        break;
    case '/':
        D.Div(number1,number2);
        break;
    default:
        break;
    }
}