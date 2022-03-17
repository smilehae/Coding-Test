class Heap {
  constructor() {
    this.heap = [null];
  }
  push(value) {
    this.heap.push(value);

    let curIndex = this.heap.length - 1;
    let parentIndex = Math.floor(curIndex / 2);
    while (parentIndex !== 0 && this.heap[curIndex] > this.heap[parentIndex]) {
      const tmp = this.heap[curIndex];
      this.heap[curIndex] = this.heap[parentIndex];
      this.heap[parentIndex] = tmp;
      curIndex = parentIndex;
      parentIndex = Math.floor(curIndex / 2);
    }
  }
  pop() {
    const returnVal = this.heap[1];
    if (!returnVal) return -1;
    if (this.heap.length === 2) return this.heap.pop();
    const endNode = this.heap.pop();
    this.heap[1] = endNode;
    let curIndex = 1;
    let leftChild = 2;
    let rightChild = 3;
    while (
      (this.heap[leftChild] && this.heap[leftChild] > this.heap[curIndex]) ||
      (this.heap[rightChild] && this.heap[rightChild] > this.heap[curIndex])
    ) {
      //양쪽 자식이 둘 다 존재함
      if (this.heap[leftChild] && this.heap[rightChild]) {
        if (this.heap[leftChild] > this.heap[rightChild]) {
          //왼쪽이랑 바꿈
          const tmp = this.heap[leftChild];
          this.heap[leftChild] = this.heap[curIndex];
          this.heap[curIndex] = tmp;
          curIndex = leftChild;
        } else {
          //오른쪽이랑 바꿈
          const tmp = this.heap[rightChild];
          this.heap[rightChild] = this.heap[curIndex];
          this.heap[curIndex] = tmp;
          curIndex = rightChild;
        }
      }
      //왼쪽만 존재
      if (this.heap[leftChild]) {
        //왼쪽이랑 바꿈
        const tmp = this.heap[leftChild];
        this.heap[leftChild] = this.heap[curIndex];
        this.heap[curIndex] = tmp;
        curIndex = leftChild;
      } else {
        //오른쪽이랑 바꿈
        const tmp = this.heap[rightChild];
        this.heap[rightChild] = this.heap[curIndex];
        this.heap[curIndex] = tmp;
        curIndex = rightChild;
      }
      leftChild = curIndex * 2;
      rightChild = curIndex * 2 + 1;
    }
    return returnVal;
  }
  display() {
    console.log(this.heap);
  }
  addSum() {
    let sum = 0;
    for (let i = 1; i < this.heap.length; i++) {
      sum += this.heap[i] * this.heap[i];
    }
    return sum;
  }
}

function solution(no, works) {
  //N번 * works배열에서 가장 큰 값 찾기 = 큰 값 찾기가 logN시간 안에 되어야 함 = heap
  const container = new Heap();
  works.forEach((work) => {
    container.push(work);
  });
  let count = 0;
  while (count < no) {
    const biggestWork = container.pop() - 1;
    if (biggestWork) {
      container.push(biggestWork);
    }
    count++;
  }

  return container.addSum();
}
