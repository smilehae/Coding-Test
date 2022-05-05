function isLetter(str) {
  return (
    str[0].toLowerCase() != str[0].toUpperCase() &&
    str[1].toLowerCase() != str[1].toUpperCase()
  );
}

function min(a, b) {
  if (a >= b) return b;
  else return a;
}

function max(a, b) {
  if (a >= b) return a;
  else return b;
}

function solution(str1, str2) {
  const str1Map = new Map();
  const str2Map = new Map();

  str1 = str1.toLowerCase();
  str2 = str2.toLowerCase();

  for (let i = 0; i < str1.length - 1; i++) {
    const str1Element = `${str1[i]}${str1[i + 1]}`;
    if (!isLetter(str1Element)) continue;
    const str1Count = str1Map.get(str1Element);
    if (str1Count) {
      str1Map.set(str1Element, str1Count + 1);
    } else {
      str1Map.set(str1Element, 1);
    }
  }

  for (let i = 0; i < str2.length - 1; i++) {
    const str2Element = `${str2[i]}${str2[i + 1]}`;
    if (!isLetter(str2Element)) continue;
    const str2Count = str2Map.get(str2Element);
    if (str2Count) {
      str2Map.set(str2Element, str2Count + 1);
    } else {
      str2Map.set(str2Element, 1);
    }
  }

  let allCount = 0;
  let bothCount = 0;

  for ([key, value] of str1Map) {
    const str2Count = str2Map.get(key);
    if (str2Count) {
      allCount += max(value, str2Count);
      bothCount += min(value, str2Count);
    } else {
      allCount += value;
    }
  }
  for ([key, value] of str2Map) {
    const str1Count = str1Map.get(key);
    if (!str1Count) {
      allCount += value;
    }
  }

  const rate =
    allCount === 0 && bothCount === 0
      ? 65536
      : Math.floor((bothCount / allCount) * 65536);
  return rate;
}
