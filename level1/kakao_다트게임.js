function solution(dartResult) {
  var answer = 0;
  const matchKeyword = {
    S: 1,
    D: 2,
    T: 3,
  };
  const results = [];
  let scoreString = "";
  let count = 0;
  for (let i = 0; i < dartResult.length; i++) {
    if (dartResult[i] in matchKeyword) {
      const result = Math.pow(Number(scoreString), matchKeyword[dartResult[i]]);
      results.push(result);
      scoreString = "";
      count++;
    } else if (dartResult[i] === "#") {
      results[count - 1] = results[count - 1] * -1;
    } else if (dartResult[i] === "*") {
      results[count - 1] = results[count - 1] * 2;
      if (count !== 1) {
        results[count - 2] = results[count - 2] * 2;
      }
    } else {
      scoreString += dartResult[i];
    }
  }

  answer = results.reduce((prev, cur) => {
    return prev + cur;
  });

  return answer;
}
