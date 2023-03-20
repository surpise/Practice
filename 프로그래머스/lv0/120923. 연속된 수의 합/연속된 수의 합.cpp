#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    for(int i = 1000; i >= -1000; i--){
        int sum = 0;
        for(int j = 0; j < num; j++){
            sum += i - j;
        }
        if(sum == total){
            for(int j = num - 1; j >= 0; j--) answer.push_back(i - j);
            break;
        }
    }
    return answer;
}