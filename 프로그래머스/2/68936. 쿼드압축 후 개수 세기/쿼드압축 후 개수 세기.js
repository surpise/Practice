const calcSection = (arr, _r, _c, nextSz) => {
        let zeroCnt = 0;
        let oneCnt = 0;

        for(let r = _r; r < _r + nextSz; r++){
            for(let c = _c; c < _c + nextSz; c++){
                if(arr[r][c]) oneCnt++;
                else zeroCnt++;
            }
        }
    
    return [zeroCnt, oneCnt];
}

const coord = (arr, _r, _c, sz, res) => {
    if(arr.length === 1){
        if(arr[0]) return [0, 1];
        else return [1, 0];
    }
    
    const nextSz = sz / 2;
    const d = [[_r, _c], [_r, _c + nextSz], [_r + nextSz, _c], [_r + nextSz, _c + nextSz]];
    
    for(let cnt = 0; cnt < 4; cnt++){
        const tmp = calcSection(arr, d[cnt][0], d[cnt][1], nextSz);
        if(tmp[0] === 0) res[1]++;
        else if(tmp[1] === 0) res[0]++;
        else {
            const qRes = coord(arr, d[cnt][0], d[cnt][1], nextSz, [0, 0]);
            res[0] += qRes[0];
            res[1] += qRes[1];
        }
    }
    
    return res;
}

function solution(arr) {
    var answer = [0, 0];

    const tmp = calcSection(arr, 0, 0, arr.length);
    
    if(tmp[0] === 0) answer[1]++;
    else if(tmp[1] === 0) answer[0]++;
    else{
        const res = coord(arr, 0, 0, arr.length, [0, 0]);
        answer[0] = res[0];
        answer[1] = res[1];
    }
    
    return answer;
}