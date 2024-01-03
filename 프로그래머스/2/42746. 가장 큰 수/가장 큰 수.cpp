#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int num1, int num2){
    string str1 = to_string(num1);
    string str2 = to_string(num2);
    
    string tStr1 = (str1 + str1 + str1).substr(0, 3);
    string tStr2 = (str2 + str2 + str2).substr(0, 3);
    
    if(tStr1 > tStr2) return true;
    
    else if(tStr1 == tStr2){
        if(str1 + str2 > str2 + str1) return true;
    }
    
    return false;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), cmp);
    
    string answer = "";
    bool checkZero = true;
    
    for(int idx = 0; idx < numbers.size(); idx++){
        if(numbers[idx] != 0) checkZero = false;
        answer += to_string(numbers[idx]);
    }
    
    if(checkZero) answer = "0";
    
    return answer;
}