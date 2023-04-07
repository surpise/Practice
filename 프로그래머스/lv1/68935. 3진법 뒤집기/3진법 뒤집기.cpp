#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    while(n > 0){
        v.push_back(n % 3);
        n /= 3;
    }
    
    for(auto e = v.begin(); e != v.end(); e++){
        answer *= 3;
        answer += *e;
    }
    return answer;
}