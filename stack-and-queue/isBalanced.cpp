#include <iostream>
#include <stack>

bool isBalanced(const std::string& s) {
    std::stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        if(c == ')' && st.top() == '(') {
            st.pop();
        }
        if(c == ']' && st.top() == '[') {
            st.pop();
        }
        if(c == '}' && st.top() == '{') {
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    std::cout << isBalanced("({[]})") << '\n';  
    std::cout << isBalanced("([)]") << '\n';    
    std::cout << isBalanced("{[}]") << '\n';
    return 0;
}