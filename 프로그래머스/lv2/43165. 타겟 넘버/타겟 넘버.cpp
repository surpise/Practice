#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<int> v;

void dfs(int cnt, int sum, int t){
    if(cnt == v.size()){
        if(sum == t){
            answer++;
        }
        return;
    }
    dfs(cnt + 1, sum + v[cnt], t);
    dfs(cnt + 1, sum - v[cnt], t);
}

int solution(vector<int> numbers, int target) {
    v = numbers;
    dfs(0, 0, target);
    return answer;
}