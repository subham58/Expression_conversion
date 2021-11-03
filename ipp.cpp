// 4. Evaluation of postfix

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int postfixEvaluation(string s)
{
    stack<int> st; // creating a stack

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();

            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;

            case '-':
                st.push(op1 - op2);
                break;

            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
                

            }
        }
    }
    return st.top();
}
int main()
{
    string s;
    cout<<"Enter a postfix expression for evaluation"<<endl;
    getline(cin, s);
    cout<<postfixEvaluation(s)<<endl;
    return 0;
}

//5. Evaluation of prefix expression

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int prefixEvaluation(string s)
{
    stack<int> st;

    for(int i = s.length() - 1; i >= 0; i--)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op1 = st.top();
            st.pop();

            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;

            case '-':
                st.push(op1 - op2);
                break;

            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string s;
    cout<<"Enter a prefix expression for evaluation"<<endl;
    getline(cin, s);
    cout<<prefixEvaluation(s)<<endl;

    return 0;
}
