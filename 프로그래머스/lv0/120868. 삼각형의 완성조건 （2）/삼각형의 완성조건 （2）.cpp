#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sides) {
    int answer = 0, big = max(sides[0], sides[1]), small = min(sides[0], sides[1]);
    for(int i = 1; i < big + small; i++){
        if(i <= big){
            if(i + small > big) answer++;
        }
        else answer++;
    }
    return answer;
}