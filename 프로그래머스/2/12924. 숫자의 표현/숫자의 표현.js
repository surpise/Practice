function solution(n) {
    const arr = [0, ];
    for(let i = 1; i <= n; i++){
        arr[i] = i + arr[i - 1];
    }
    
    let idx1 = 0, idx2 = 0;
    let answer = 0;
    while(idx2 <= n && idx1 <= idx2){
        if(arr[idx2] - arr[idx1] < n){
            idx2++;
        }
        else if(arr[idx2] - arr[idx1] >= n){
            if(arr[idx2] - arr[idx1] === n){
                answer++;
                if(idx2 === n) break;
            }
            idx1++;
        }

    }

    return answer;
}