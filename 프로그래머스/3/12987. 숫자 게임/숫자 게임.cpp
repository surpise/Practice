#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int aIdx = 0, bIdx = 0, sz = A.size();
    while(bIdx < sz){       
        if(A[aIdx] < B[bIdx]){
            answer++;
            aIdx++;
            if(aIdx == sz) aIdx = sz - 1;
        }

        bIdx++;
    }
    
    return answer;
}