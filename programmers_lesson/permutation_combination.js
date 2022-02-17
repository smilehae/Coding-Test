//코딩테스트에서 쓰이는 순열과 조합! 이 자체가 시간복잡도가 크므로 n이 보통 작음 . 그래서 재귀로 푸는 것이 직관적이라 좋음!
//array에서 n개를 뽑는데 순서 상관 있음!
function permutations(arr, n) {
  //1개만 뽑는다면 그대로 순열을 반환한다. 탈출 조건!
  if (n === 1) return arr.map((item) => [item]);
  const result = [];

  //각 요소의 값 , 인덱스 , 전체  array
  arr.forEach((item, idx, arr) => {
    //index번째가 선택되었을때, 나머지 값과 조합을 추츨한다.

    //해당 인덱스를 제외한 배열 만들기
    const rest = arr.filter((item, index) => index !== idx);
    //나머지 값을 재귀 호출
    const perms = permutations(rest, n - 1);
    //선택된 요소와, 재귀 호출된 순열을 합친다.
    //선택된 것 + perms에서 받은 값들을 합쳐놓음!
    const combine = perms.map((v) => [item, ...v]);
    result.push(combine);
  });
  return result;
}

function combinations(arr, n) {
  if (n === 1) return arr.map((item) => [item]);
  const result = [];

  arr.forEach((item, idx, arr) => {
    //현재 인덱스 이후 요소를 추출한다.
    const rest = arr.slice(idx + 1);

    const combis = combinations(rest, n - 1);
    const combine = combis.map((v) => [item, ...v]);
    result.push(combine);
  });
  return result;
}

console.log(permutations([2, 3, 5], 2));
console.log(combinations([2, 3, 5], 2));
