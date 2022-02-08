class Heap {
  constructor() {
    this.heap = [null];
  }
  push(value) {
    this.heap.push(value);
    let curIndex = this.heap.length - 1;
    let parentIndex = Math.floor(curIndex / 2);
    while (parentIndex !== 0 && this.heap[curIndex] > this.heap[parentIndex]) {
      console.log(
        `${this.heap[curIndex]}이 ${this.heap[parentIndex]}보다 커서 위치를 바꿉니다. `
      );
      const tmp = this.heap[curIndex];
      this.heap[curIndex] = this.heap[parentIndex];
      this.heap[parentIndex] = tmp;
      curIndex = parentIndex;
      parentIndex = Math.floor(curIndex / 2);
    }
  }
  display() {
    console.log(this.heap);
  }
  pop() {
    if (this.heap.length === 1) return null;
    if (this.heap.length === 2) {
      return this.heap.pop();
    }
    const value = this.heap[1];
    this.heap[1] = this.heap.pop();
    let curIndex = 1;
    let leftIndex = 2;
    let rightIndex = 3;
    while (
      (this.heap[leftIndex] && this.heap[leftIndex] > this.heap[curIndex]) ||
      (this.heap[rightIndex] && this.heap[rightIndex] > this.heap[curIndex])
    ) {
      //양쪽 자식 전부 존재
      if (this.heap[leftIndex] && this.heap[rightIndex]) {
        if (this.heap[leftIndex] >= this.heap[rightIndex]) {
          console.log(
            "왼쪽 자식이 같거나 크므로 값을 바꿉니다 " +
              `${this.heap[curIndex]}=>${this.heap[leftIndex]}`
          );
          const tmp = this.heap[leftIndex];
          this.heap[leftIndex] = this.heap[curIndex];
          this.heap[curIndex] = tmp;
          curIndex = leftIndex;
        } else {
          console.log(
            "오른쪽 자식이 더 크므로 값을 바꿉니다 " +
              `${this.heap[curIndex]}=>${this.heap[rightIndex]}`
          );
          const tmp = this.heap[rightIndex];
          this.heap[rightIndex] = this.heap[curIndex];
          this.heap[curIndex] = tmp;
          curIndex = rightIndex;
        }
      } else if (this.heap[leftIndex]) {
        //왼쪽만 존재
        console.log(
          "왼쪽 자식만 존재하므로 값을 바꿉니다 " +
            `${this.heap[curIndex]}=>${this.heap[leftIndex]}`
        );
        const tmp = this.heap[leftIndex];
        this.heap[leftIndex] = this.heap[curIndex];
        this.heap[curIndex] = tmp;
        curIndex = leftIndex;
      } else {
        //오른쪽만 존재
        console.log(
          "오른쪽 자식만 존재하므로 값을 바꿉니다 " +
            `${this.heap[curIndex]}=>${this.heap[rightIndex]}`
        );
        const tmp = this.heap[rightIndex];
        this.heap[rightIndex] = this.heap[curIndex];
        this.heap[curIndex] = tmp;
        curIndex = rightIndex;
      }

      leftIndex = curIndex * 2;
      rightIndex = curIndex * 2 + 1;
    }
    return value;
  }
  getResults() {
    return this.heap.reduce((total, cur) => total + cur * cur, 0);
  }
}

function solution(no, works) {
  const heap = new Heap();

  works.forEach((work) => heap.push(work));

  while (no > 0) {
    let item = heap.pop() - 1;
    console.log(`${item + 1}꺼냄!`);
    heap.display();

    if (item > 0) heap.push(item);
    heap.display();
    no--;
  }

  return heap.getResults();
}
