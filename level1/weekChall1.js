function solution(price, money, count) {
  var answer = -1;
  const curPrice = price * count;

  //i를 변수로 count번 돌면서 price*(i) 해서 배열에 넣기
  const prices = [];
  for (let i = 1; i <= count; i++) {
    prices.push(price * i);
  }
  console.log(prices);
  const totalMoney = prices.reduce(function (total, curMoney) {
    return total + curMoney;
  });
  console.log(totalMoney);
  return answer;
}

console.log(solution(3, 20, 4));
