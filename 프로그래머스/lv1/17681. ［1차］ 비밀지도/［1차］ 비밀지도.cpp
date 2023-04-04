#include <string>
#include <vector>

using namespace std;
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string tmp;
    for(int i = 0; i < arr1.size(); i++){
        tmp = "";
        for(int j = 0; j < n; j++){
            if(arr1[i] % 2 == 1 || arr2[i] % 2 == 1) tmp = "#" + tmp;
            else tmp = " " + tmp;
            arr1[i] /= 2;
            arr2[i] /= 2;
        }
        answer.push_back(tmp);
    }
    return answer;
}