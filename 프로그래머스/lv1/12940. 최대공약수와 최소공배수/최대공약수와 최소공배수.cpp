#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int s = min(n, m);
    for(int i = s; i > 0; i--){
        if(n % i == 0 && m % i == 0) {
            answer.push_back(i);
            break;
        }
    }
    answer.push_back(n * m / answer[0]);
    return answer;
}