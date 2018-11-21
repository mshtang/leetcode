#include <iostream>
#include <stack>
#include <string>

int longestValidParentheses(std::string s)
{
    int n = s.length(), longest = 0;
    std::stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            if (!st.empty())
            {
                if (s[st.top()] == '(')
                    st.pop();
                else
                    st.push(i);
            }
            else
                st.push(i);
        }
    }
    if (st.empty())
        longest = n;
    else
    {
        int a = n, b = 0;
        while (!st.empty())
        {
            b = st.top();
            st.pop();
            longest = std::max(longest, a - b - 1);
            a = b;
        }
        longest = std::max(longest, a);
    }
    return longest;
}

int main()
{
    std::cout << longestValidParentheses("()(((())") << std::endl;
    std::cin.get();
}