#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int stringToNum(string str){
    int minus = 1;
    int idx = 0;
    
    if(str[0] == '-'){
        minus = -1;
        idx++;
    }
    
    int res = 0;
    for(idx; idx < str.length(); idx++){
        res *= 10;
        res += str[idx] - '0';
    }
    
    return minus * res;
}

vector<int> solution(vector<string> operations) {
    int size = 0;
    priority_queue<int> bigQ;
    priority_queue<int, vector<int>, greater<int>> smallQ;
    
    for(int idx = 0; idx < operations.size(); idx++){
        int v = stringToNum(operations[idx].substr(2));
        
        if(operations[idx][0] == 'I') {
            bigQ.push(v);
            smallQ.push(v);
            size++;
        }
        else if(operations[idx][0] == 'D'){
            if(size == 0) continue;

            stack<int> st;
            if(v == 1){
                bigQ.pop();
                while(!smallQ.empty()){
                    st.push(smallQ.top());
                    smallQ.pop();
                }
                
                st.pop();
                while(!st.empty()){
                    smallQ.push(st.top());
                    st.pop();
                }
            }
            
            if(v == -1){
                smallQ.pop();
                while(!bigQ.empty()){
                    st.push(bigQ.top());
                    bigQ.pop();
                }
                
                st.pop();
                while(!st.empty()){
                    bigQ.push(st.top());
                    st.pop();
                }
            }
            
            size--;
        }
    }
    
    vector<int> answer;
    if(size == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(bigQ.top());
        answer.push_back(smallQ.top());   
    }

    return answer;
}