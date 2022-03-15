function solution(n) {
  var answer = [];
  const str = n + "";
  for (let i = 0; i < str.length; i++) {
    answer.push(parseInt(str[i]));
  }
  answer.reverse();
  return answer;
}
