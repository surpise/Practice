#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "", a = "", b = "";
    int k = 1;
    for(int i = 1; i < food.size(); i++){
        for(int j = 0; j < food[i] / 2; j++) {
            a += to_string(k);
            b = to_string(k) + b;
        }
        k++;
    }
    answer = a + "0" + b;
    return answer;
}