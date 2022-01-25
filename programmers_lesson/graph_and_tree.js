// 그래프. 노드와 엣지로 구성된 비선형 자료구조.
// 인접 행렬로 구현
const graph = Array.from(Array(5), () => Array(5).fill(false));
graph[0][1] = true;
graph[0][3] = true;
// console.log(graph)

const graph2 = Array.from(Array(5), () => []);
graph2[0].push(1);
graph2[2].push(3);
// console.log(graph2);

//트리. 방향 그래프의 일종. 정점을 가리키는 간선이 하나밖에 없는 구조!
const tree = [undefined, 9, 3, 8, 2, 5, undefined, 7, undefined, undefined, 4];

// 이진트리
class Queue {
  constructor() {
    this.front = 0;
    this.rear = 0;
    this.size = 0;
    this.queue = [];
  }
  enqueue(value) {
    this.queue[this.rear++] = value;
    this.size++;
  }
  dequeue() {
    const value = this.queue[this.front++];
    this.size--;
    return value;
  }
}
class Node {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}
class Tree {
  constructor(node) {
    this.root = node;
  }
  display() {
    const queue = new Queue();
    queue.enqueue(this.root);
    while (queue.size) {
      const currentNode = queue.dequeue();
      console.log("현재 노드 : ", currentNode);
      if (currentNode.left) queue.enqueue(currentNode.left);
      if (currentNode.right) queue.enqueue(currentNode.right);
    }
  }
}

const binaryTree = new Tree(new Node(9));
binaryTree.root.left = new Node(3);
binaryTree.root.right = new Node(8);
binaryTree.root.left.left = new Node(2);
binaryTree.root.left.right = new Node(5);
binaryTree.root.left.right.right = new Node(4);
binaryTree.root.right.right = new Node(7);
binaryTree.display();
