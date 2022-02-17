class Queue {
  constructor() {
    this.size = 0;
    this.queue = [];
    this.front = 0;
    this.back = 0;
  }
  enqueue(value) {
    this.queue[this.back++] = value;
    this.size++;
  }
  dequeue() {
    if (this.size === 0) return -1;
    this.size--;
    return this.queue[this.front++];
  }
  display() {
    console.log(this.queue);
  }
  //방법 1 : set에 priority를 저장해서 크기 순으로 정렬 후 가장 큰 값 리턴하는 메소드 제작
  getBiggestPriority() {
    if (this.size === 0) return 0;
    const prioritySet = new Set();
    for (let i = this.front; i < this.back; i++) {
      prioritySet.add(this.queue[i][0]);
    }
    return [...prioritySet].sort((a, b) => b - a)[0];
  }
}

function solution(priorities, location) {
  const papers = priorities.map((priority, index) => [priority, index]);
  const printer = new Queue();
  const order = Array(priorities.length).fill(0);
  let count = 0;
  papers.forEach((paper) => {
    printer.enqueue(paper);
  });

  //방법 2 : priorities를 sort하면, 가장 앞쪽의 priority와 같은 값을 가진 것부터 하나씩 인쇄되게 된다.
  //따라서 priority를 정렬한 후, count번째의 값보다 작은지만 보면 된다..!

  priorities.sort((a, b) => b - a);

  while (printer.size > 0) {
    const curPaper = printer.dequeue();
    // const biggestPriority = printer.getBiggestPriority(); //방법 1
    const biggestPriority = priorities[count];
    if (curPaper[0] < biggestPriority) {
      printer.enqueue(curPaper);
    } else {
      order[curPaper[1]] = ++count;
    }
  }

  return order[location];
}
