#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int share = s / n;
    int remain = s % n;
    
    if(share == 0) return {-1};
    
    for(int i = 0; i < n; i++) answer.push_back(share);
    
    for(int i = 0; i < remain; i++) answer[n - 1 - i]++;
    
    return answer;
}