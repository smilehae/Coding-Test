function solution(n) {
  //   const arr = Array.from({ length: n + 1 }, (item, index) => {
  //     if (index <= 1) return undefined;
  //     return true;
  //   });

  //위의 코드 대신 아래처럼 쓸 수 있다! spread 이용 깔끔하게
  const arr = [undefined, undefined, ...Array(n - 1).fill(true)];
  for (let i = 2; i < n; i++) {
    for (let j = 2; i * j <= n; j++) {
      arr[i * j] = false;
    }
  }
  answer = arr.filter((item) => item === true).length;
  return answer;
}
