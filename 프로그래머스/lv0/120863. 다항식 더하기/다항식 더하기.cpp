#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    stack<char> st;
    int arr[2] = {0, };
    int tmp;
    for(int i = 0; i < polynomial.size(); i++){
        if(polynomial[i] == ' '){
            if(st.top() == '+') st.pop();
            else{
                if(st.top() == 'x'){
                    tmp = 0;
                    st.pop();
                    if(st.empty()) arr[0] += 1;
                }
                else tmp = 1;
                int up = 1;
                while(!st.empty()){
                    arr[tmp] += (st.top() - '0') * up;
                    up *= 10;
                    st.pop();
                }
            }
        }
        else st.push(polynomial[i]);
    }
    if(st.top() == 'x'){
        tmp = 0;
        st.pop();
        if(st.empty()) arr[0] += 1;
    }
    else tmp = 1;
    int up = 1;
    while(!st.empty()){
        arr[tmp] += (st.top() - '0') * up;
        up *= 10;
        st.pop();
    }
    string a = to_string(arr[0]), b = to_string(arr[1]);
    if(a != "0" && b != "0") {
        if(a != "1") answer = a;
        answer += ("x + " + b);
    }
    else if(a == "0" && b == "0") answer = "0";
    else if(a == "0") answer = b;
    else if(b == "0") {
        if(a != "1") answer = a;
        answer += "x";
    }
    return answer;
}