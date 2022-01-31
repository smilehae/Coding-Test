function solution(s) {
  var answer = [];
  const tuples = [];
  const pickedNums = [];
  let count = -1;
  let inputNum = false;
  for (let i = 1; i < s.length - 1; i++) {
    if (s[i] === "{") {
      count++;
      tuples.push("");
      inputNum = true;
    } else if (s[i] === "}") {
      inputNum = false;
    } else if (inputNum) {
      tuples[count] += s[i];
    }
  }
  const changedTuples = tuples
    .sort((a, b) => a.length - b.length)
    .map((tuple) => {
      if (tuple.length === 1) {
        pickedNums.push(tuple[0]);
        return tuple[0];
      }
      const remainder = tuple
        .split(",")
        .filter((num) => !pickedNums.includes(num));
      pickedNums.push(remainder[0]);
      return remainder[0];
    });
  changedTuples.forEach((tuple) => answer.push(parseInt(tuple)));

  return answer;
}
