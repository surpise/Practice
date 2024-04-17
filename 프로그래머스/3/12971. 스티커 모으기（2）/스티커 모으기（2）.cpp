#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    if(sticker.size() == 1) return sticker[0];
    
    int arr[2][100000] = {{sticker[0], sticker[0]}, {0, sticker[1]}};
    
    for(int idx = 2; idx < sticker.size(); idx++){
        arr[0][idx] = max(arr[0][idx - 1], sticker[idx] + arr[0][idx - 2]);
        arr[1][idx] = max(arr[1][idx - 1], sticker[idx] + arr[1][idx - 2]);
    }
    
    if(arr[0][sticker.size() - 2] > arr[1][sticker.size() - 1]){
        return arr[0][sticker.size() - 2];
    }
    else{
        return arr[1][sticker.size() - 1];
    }
}