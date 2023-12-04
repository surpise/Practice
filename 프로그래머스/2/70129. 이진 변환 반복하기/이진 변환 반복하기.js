function solution(s) {
    const answer = [0, 0];
    let str = s;
    while(str !== "1"){
        let cnt = 0;
        for(let i = 0; i < str.length; i++){
            if(str[i] === "0"){
                cnt++;
            }
        }
        answer[0]++;
        answer[1] += cnt;
        cnt = str.length - cnt;
        str = cnt.toString(2);
    }
    return answer;
}