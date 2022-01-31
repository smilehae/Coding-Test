class MaxHeap {
  constructor() {
    this.heap = [null];
  }
  push(value) {
    this.heap.push(value);
    let currIndex = this.heap.length - 1;
    let parentIndex = Math.floor(currIndex / 2);

    while (parentIndex != 0 && this.heap[parentIndex] < value) {
      const temp = this.heap[parentIndex];
      this.heap[parentIndex] = value;
      this.heap[currIndex] = temp;
      currIndex = parentIndex;
      parentIndex = Math.floor(currIndex / 2);
    }
  }
  pop() {
    const returnValue = this.heap[1];
    this.heap[1] = this.heap.pop();

    let currIndex = 1;
    let leftIndex = 2;
    let rightIndex = 3;

    while (
      this.heap[currIndex] < this.heap[leftIndex] ||
      this.heap[currIndex] < this.heap[rightIndex]
    ) {
      if (this.heap[leftIndex] > this.heap[rightIndex]) {
        const temp = this.heap[currIndex];
        this.heap[currIndex] = this.heap[leftIndex];
        this.heap[leftIndex] = temp;
        currIndex = leftIndex;
      } else {
        const temp = this.heap[currIndex];
        this.heap[currIndex] = this.heap[rightIndex];
        this.heap[rightIndex] = temp;
        currIndex = rightIndex;
      }
      leftIndex = currIndex * 2;
      rightIndex = currIndex * 2 + 1;
    }
    return returnValue;
  }
}

const heap = new MaxHeap();
heap.push(45);
heap.push(36);
heap.push(54);
heap.push(27);
heap.push(34);

const arr = [];
arr.push(heap.pop());
arr.push(heap.pop());
arr.push(heap.pop());

heap.push(100);

arr.push(heap.pop());
arr.push(heap.pop());
console.log(arr);
