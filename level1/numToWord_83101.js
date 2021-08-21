function solution(s) {
  var answer = 0;
  const numbers = [
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
  ];
  let newString;

  numbers.forEach((number, index) => {
    if (s.includes(number)) {
      console.log(
        `it has ${number} on ${s.search(number)} it's size is ${number.length}`
      );
      console.log(index);
      newString = s.replace(`${number}`, "2");
    }
  });
  //   if (s.includes("seven")) {
  //     console.log("it has on " + s.search("one"));
  //   }
  console.log(newString);
  return answer;
}

console.log(solution("one4seveneight"));
