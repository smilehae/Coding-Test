function solution(s) {
  const length = s.length;
  if (length % 2 == 1) {
    return s[Math.floor(length / 2)];
  }
  const startPos = length / 2 - 1;
  return s.substr(startPos, 2);
}
