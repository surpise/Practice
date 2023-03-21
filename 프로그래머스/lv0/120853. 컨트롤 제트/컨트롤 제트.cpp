#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<int> st, sum;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            int up = 1;
            int tmp = 0;
            while(!st.empty()){
                if(st.top() == '-') tmp *= -1;
                else{
                    tmp += st.top() * up;
                    up *= 10;   
                }
                st.pop();
            }
            sum.push(tmp);
        }
        else if(s[i] == 'Z'){
            sum.pop();
            i++;
        }
        else{
            if(s[i] != '-') st.push(s[i] - '0');
            else st.push(s[i]);
        }
    }
    int up = 1;
    int tmp = 0;
    while(!st.empty()){
        if(st.top() == '-') tmp *= -1;
        else{
            tmp += st.top() * up;
            up *= 10;   
        }
        st.pop();
    }
    sum.push(tmp);
    while(!sum.empty()) {
        answer += sum.top();
        sum.pop();
    }
    return answer;
}