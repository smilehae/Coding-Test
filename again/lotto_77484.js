const myLotto = [44,1,0,0,31,25];
const winNum = [31,10,45,1,6,19];

function giveRank(count){
    if(count<=1) return 6;
    else return 7-count;
}

function solution(lottos, win_nums) {
    const answer = [];
    let zeroCount=0;
    let matchCount=0;
    for(let i=0;i<6;i++){
        if(lottos[i]==0){
            zeroCount++;
            console.log(`there's ${zeroCount} zeros!`);
        }
        else{
            if(win_nums.includes(lottos[i])){
                matchCount++;
                console.log("it matches!");
            }
        }
    }
    answer.push(giveRank(matchCount+zeroCount));
    answer.push(giveRank(matchCount));
    return answer;
}

console.log(solution(myLotto,winNum));