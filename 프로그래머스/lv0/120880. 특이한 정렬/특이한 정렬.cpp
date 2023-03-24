#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    if(abs(a) == abs(b)){
        return b < a;
    }
    return abs(a) < abs(b);
}
vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    for(int i = 0; i < numlist.size(); i++){
        answer.push_back(numlist[i] - n);
    }
    sort(answer.begin(), answer.end(), compare);
    for(int i = 0; i < answer.size(); i++) answer[i] += n;
    return answer;
}