#include <iostream>
#include <stack>

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, x;
    cin >> n;

    stack<pair<int, int>> st;
    for(int i = 1; i <= n; i++){
        cin >> x;
        while(!st.empty()){
            if(st.top().first > x){
                cout << st.top().second << " ";
                break;
            }
            st.pop();
        }
        if(st.empty()){
            cout << "0 "; 
        }
        
        st.push({x, i});
    }
}