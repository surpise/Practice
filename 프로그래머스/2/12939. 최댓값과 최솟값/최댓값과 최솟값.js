function solution(s) {
    const arr = s.split(' ');
    let minV = arr[0];
    let maxV = arr[0];
    for(let i = 1; i < arr.length; i++){
        if(Number(arr[i]) > Number(maxV)) maxV = arr[i];
        if(Number(arr[i]) < Number(minV)) minV = arr[i];
    }
    const answer = `${minV} ${maxV}`;
    return answer;
}