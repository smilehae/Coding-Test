function solution(s) {
  let pCount = 0;
  let yCount = 0;
  for (const elem of s) {
    const char = elem.toLowerCase();
    if (char === "p") pCount++;
    else if (char === "y") yCount++;
  }
  if (pCount === yCount) return true;
  else return false;
}
