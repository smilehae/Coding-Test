function solution(n, lost, reserve) {
  const clothCounts = Array(n).fill(1);

  for (const student of reserve) {
    clothCounts[student - 1] += 1;
  }
  for (const student of lost) {
    clothCounts[student - 1] -= 1;
  }
  for (let i = 0; i < n; i++) {
    if (clothCounts[i] > 1) {
      if (i === 0) {
        if (!clothCounts[i + 1]) {
          clothCounts[i + 1] = 1;
          clothCounts[i] -= 1;
        }
      } else if (i === n - 1) {
        if (!clothCounts[i - 1]) {
          clothCounts[i - 1] = 1;
          clothCounts[i] -= 1;
        }
      } else {
        if (!clothCounts[i - 1]) {
          clothCounts[i - 1] = 1;
          clothCounts[i] -= 1;
        } else if (!clothCounts[i + 1]) {
          clothCounts[i + 1] = 1;
          clothCounts[i] -= 1;
        }
      }
    }
  }
  return clothCounts.filter((cloth) => cloth >= 1).length;
}
