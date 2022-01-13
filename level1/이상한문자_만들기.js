function solution(s) {
  let answer = "";
  const words = s.split(" ").map((word) => {
    let changedWord = "";
    for (let i = 0; i < word.length; i++) {
      if (i % 2 == 1) {
        changedWord += word[i].toLowerCase();
      } else {
        changedWord += word[i].toUpperCase();
      }
    }
    return changedWord;
  });
  return words.join(" ");
}
