#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0, sz = 0;
    stack<int> s, t;
    int arr[4] = {1, 3, 2, 1};
    for(int i = 0; i < ingredient.size(); i++){
        s.push(ingredient[i]);
        if(s.size() >= 3){
            sz = s.size();
            for(int j = 0; j < sz; j++){
                if(s.top() == arr[j % 4]){
                    t.push(s.top());
                    s.pop();
                    if(t.size() == 4){
                        while(!t.empty()) t.pop();
                        answer++;
                    }
                }
                else{
                    while(!t.empty()){
                        s.push(t.top());
                        t.pop();
                    }
                    break;
                }
            }
        }
    }
    return answer;
}