class Queue {
  constructor(maxSize) {
    this.maxSize = maxSize;
    this.rear = 0;
    this.front = 0;
    this.size = 0;
    this.queue = [];
  }

  enqueue(value) {
    if (this.isFull()) {
      console.log("queue가 꽉 찼습니다.");
      return;
    }
    this.queue[this.rear] = value;
    this.rear = (this.rear + 1) % this.maxSize;
    this.size++;
  }
  dequeue() {
    const value = this.queue[this.front];
    delete this.queue[this.front];
    this.front = (this.front + 1) % this.maxSize;
    this.size--;
    return value;
  }
  isFull() {
    return this.size === this.maxSize;
  }
  peek() {
    return this.queue[this.front];
  }
}

const queue = new Queue(4);
queue.enqueue(1);
queue.enqueue(2);
queue.enqueue(4);
queue.enqueue(8);
queue.enqueue(16);
console.log(queue.dequeue());
console.log(queue.dequeue());
console.log(queue.size);
console.log(queue.peek());
