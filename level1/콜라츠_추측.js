function solution(num) {
  let count = 0;
  let changingNum = num;
  while (changingNum != 1) {
    if (count >= 500) {
      return -1;
    }
    if (changingNum % 2 === 0) {
      changingNum = changingNum / 2;
    } else {
      changingNum = changingNum * 3 + 1;
    }
    count++;
  }
  return count;
}
