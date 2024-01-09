#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int totalT = prices.size();
    
    vector<int> answer;
    answer.resize(totalT);
    
    stack<pair<int, int>> st;
    
    for(int idx = 0; idx < totalT; idx++){
        while(!st.empty() && st.top().first > prices[idx]){
            answer[st.top().second] = idx - st.top().second;
            st.pop();
        }
        
        st.push({prices[idx], idx});
    }
    
    while(!st.empty()){
        answer[st.top().second] = totalT - st.top().second - 1;
        st.pop();
    }
    
    return answer;
}