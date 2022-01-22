//초기화
/*
const arr = new Array();
const arr2 = [];
const arr3 = [1, 2, 3, 4, 5];
const arr4 = new Array(5);
const arr5 = new Array(10).fill(3);
Array.from(초기값, 리턴 값이 배열에 들어가게 해주는 함수)
const arr6 = Array.from(Array(5), function (total, index) {
  return index + 1;
});
*/

// 편의성 함수 소개
/*
const arr1 = [1, 2, 3, 4];
const arr2 = [5, 6, 7];
// join
console.log(arr1.join(", "));
// reverse : 원래 함수에도 영향 감! 변함!
console.log(arr1.reverse());
// concat
console.log(arr1.concat(arr2));
*/

const arr = [1, 2, 3, 4, 5];

// push, pop
// arr.push(7);
// arr.push(8, 9);
// arr.pop();
// console.log(arr.pop());

// shift(맨 앞 제거) ,unshift(맨 앞 추가) 원본 변경
// arr.shift();
// arr.shift();
// arr.unshift(10);
// console.log(arr);

// slice (원본 그대로)
// console.log(arr.slice(2, 4));
// console.log(arr);

// splice (원본 변경) // 2번째 인덱스부터 2개 제거
// arr.splice(2, 2);
// console.log(arr);

for (let i = 0; i < 6; i++) {
  console.log(arr[i]);
}
