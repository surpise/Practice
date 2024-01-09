#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int, int>> st;
    answer.resize(prices.size());
    
    for(int idx = 0; idx < prices.size(); idx++){
        if(!st.empty()){
            while(st.top().first > prices[idx]){
                answer[st.top().second] = idx - st.top().second;
                st.pop();
                
                if(st.empty()) break;
            }
        }
        st.push({prices[idx], idx});
    }
    
    while(!st.empty()){
        answer[st.top().second] = prices.size() - st.top().second - 1;
        st.pop();
    }
    
    return answer;
}