#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int max = 0, sum = 0;
    for(int i = 0; i < 3; i++){
        if(sides[i] > max) max = sides[i];
        sum += sides[i];
    }
    int answer = (sum - max > max) ? 1 : 2;
    return answer;
}