#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int m = (arr[0] < arr[1]) ? arr[0] : arr[1];
    for(int i = 2; i < arr.size(); i++) m = (m > arr[i]) ? arr[i] : m;
    
    vector<int> answer;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != m) answer.push_back(arr[i]);
    }
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}