#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0, mul = 1, sum = 0;
    for(int i = 0; i < num_list.size(); i++){
        mul *= num_list[i];
        sum += num_list[i];
    }
    if(mul < sum * sum) answer = 1;
    return answer;
}