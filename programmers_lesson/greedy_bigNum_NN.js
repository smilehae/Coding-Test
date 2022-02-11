//num = number.length-k 뺀거 : 전체 자리수.
//0~num-1 까지 중에서 가장 큰 거 고름 = jndex
//jndex+1~num-2 까지 중에서 가장 큰 거 고름 = jndex
function solution(number, k) {
  var answer = "";
  let max = 0;
  let minIndex = 0;
  for (let maxIndex = k; maxIndex < number.length; maxIndex++) {
    max = -1;
    for (let j = minIndex; j <= maxIndex; j++) {
      if (+number[j] > max) {
        max = +number[j];
        minIndex = j + 1;
      }
    }
    answer += max;
  }
  return answer;
}
