#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> st;
    st.push(s[0]);
    
    for(int idx = 1; idx < s.size(); idx++){
        if(!st.empty() && st.top() == s[idx]) st.pop();
        else st.push(s[idx]);
    }
    
    if(st.empty()) return 1;
    else return 0;
}