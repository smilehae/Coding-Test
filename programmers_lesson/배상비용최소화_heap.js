//max-heap을 이용해줘서, N만큼 pop해서 값을 하나씩 줄여서 push! 다 끝난 후 heap에 남은 값을 제곱해서 더해주면 결과 완성!
//각 값 중 가장 큰 값을 줄이는 것이 최소값을 가장 작게 만드는 방법이다.
class Heap {
  constructor() {
    this.heap = [null];
    this.size = 0;
  }
  push(value) {
    this.heap.push(value);
    let curIndex = this.heap.length - 1;
    let parentIndex = Math.floor(curIndex / 2);

    while (parentIndex !== 0 && this.heap[curIndex] > this.heap[parentIndex]) {
      console.log(
        this.heap[curIndex] +
          "가 " +
          this.heap[parentIndex] +
          "보다 커서 자리를 바꿉니다."
      );
      const tmp = this.heap[curIndex];
      this.heap[curIndex] = this.heap[parentIndex];
      this.heap[parentIndex] = tmp;
      curIndex = parentIndex;
      parentIndex = Math.floor(curIndex / 2);
    }
    this.size++;
  }
  pop() {
    if (this.size === 1) {
      this.size = 0;
      return this.heap.pop();
    }

    if (this.size === 0) {
      return -1;
    }

    const returnValue = this.heap[1];
    this.heap[1] = this.heap.pop();
    let curIndex = 1;
    let leftIndex = 2;
    let rightIndex = 3;

    while (
      (this.heap[leftIndex] && this.heap[curIndex] < this.heap[leftIndex]) ||
      (this.heap[rightIndex] && this.heap[curIndex] < this.heap[rightIndex])
    ) {
      if (!this.heap[rightIndex]) {
        const tmp = this.heap[leftIndex];
        this.heap[leftIndex] = this.heap[curIndex];
        this.heap[curIndex] = tmp;
        curIndex = leftIndex;
      } else if (!this.heap[leftIndex]) {
        const tmp = this.heap[rightIndex];
        this.heap[rightIndex] = this.heap[curIndex];
        this.heap[curIndex] = tmp;
        curIndex = rightIndex;
      } else {
        if (this.heap[leftIndex] >= this.heap[rightIndex]) {
          const tmp = this.heap[leftIndex];
          this.heap[leftIndex] = this.heap[curIndex];
          this.heap[curIndex] = tmp;
          curIndex = leftIndex;
        } else {
          const tmp = this.heap[rightIndex];
          this.heap[rightIndex] = this.heap[curIndex];
          this.heap[curIndex] = tmp;
          curIndex = rightIndex;
        }
      }

      leftIndex = curIndex * 2;
      rightIndex = curIndex * 2 + 1;
    }
    this.size--;
    return returnValue;
  }
  display() {
    console.log(this.heap);
  }
  getTotalSquare() {
    return this.heap.reduce((total, cur) => total + cur * cur, 0);
  }
}
function solution(no, works) {
  const heap = new Heap();

  for (const item of works) {
    heap.push(item);
  }

  for (let i = 0; i < no; i++) {
    let item = heap.pop();
    if (item > 1) {
      heap.push(item - 1);
    }
  }

  heap.display();
  return heap.getTotalSquare();
}
