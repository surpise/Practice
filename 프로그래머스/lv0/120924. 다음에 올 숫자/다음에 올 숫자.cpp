#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int a = common[1] - common[0], b = common[2] - common[1];
    if(a==b) answer = common[common.size() - 1] + a;
    else answer = common[common.size() - 1] * (b / a);
    return answer;
}