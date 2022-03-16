function solution(priorities, location) {
  const documents = priorities.map((priority, index) => {
    return { index, priority };
  });
  const realOrder = priorities.sort((a, b) => b - a);
  const printer = [];
  let count = 1;

  while (documents.length !== 0) {
    const document = documents.shift();
    if (document.priority !== realOrder[count - 1]) {
      documents.push(document);
    } else {
      document.count = count++;
      printer.push(document);
    }
  }

  return printer.find((document) => document.index === location).count;
}
