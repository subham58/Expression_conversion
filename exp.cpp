// 1. infix to postfix conversion

#include<iostream>
#include<stack>
using namespace std;

int prec(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '*' || c == '/') 
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1; // when there is opening parenthesis
    }
    
}

string infixtoPostfix(string s)
{
    stack<char> st;
    string res;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            res+= s[i];
        }
        else if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                res+= st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else  // for operator
        {
            while(!st.empty() && prec(st.top()) >= prec(s[i]))
            {
                res+= st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        res+= st.top();
        st.pop();
    }
    return res;
}

// int main()
// {
//     string str,postfix;
//     cout<<"Enter a string"<<endl;
//     getline(cin,str);
//     postfix = infixtoPostfix(str);
//     cout<<"The postfix exp is: "<<postfix<<endl;
//     return 0;
// }

// 2 infix to prefix conversion 

#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

int prec(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '*' || c == '/')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPrefix(string s)
{
    stack <char> st;
    string res;


    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            res+= s[i];
        }
        else if(s[i] == ')')
        {
            st.push(s[i]);
        }
        else if(s[i] == '(')
        {
            while(!st.empty() && st.top() != ')')
            {
                res+= st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else  // for operator
        {
            while(!st.empty() && prec(st.top()) > prec(s[i]))
            {
                res+= st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        res+= st.top();
        st.pop();
    }
    return res;
}



int main()
{
    string s,prefix;
    cout<<"Enter a string: "<<endl;
    getline(cin,s);
    reverse(s.begin(), s.end());
    prefix = infixToPrefix(s);
    reverse(prefix.begin(),prefix.end());
    cout<<"The prefix expression is: "<<prefix<<endl;
    return 0;
}
