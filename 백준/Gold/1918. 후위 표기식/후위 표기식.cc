#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string str, ans = "";
    stack<char> st;

    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '+' || str[i] == '-'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        else if(str[i] == '*' || str[i] == '/'){
            if(!st.empty() && (st.top() == '*' || st.top() == '/')){
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        else if(str[i] == '('){
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else ans += str[i];
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    cout << ans;
}