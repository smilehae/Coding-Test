class Node {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

class BinarySearchTree {
  constructor() {
    this.root = null;
  }
  insert(value) {
    const newNode = new Node(value);
    if (this.root === null) {
      this.root = newNode;
      console.log(`루트에 ${newNode.value}의 값을 넣습니다.`);
      return;
    }

    let curNode = this.root;
    while (curNode !== null) {
      if (curNode.value < value) {
        if (curNode.right === null) {
          curNode.right = newNode;
          break;
        }
        curNode = curNode.right;
      } else {
        if (curNode.left === null) {
          curNode.left = newNode;
          break;
        }
        curNode = curNode.left;
      }
    }
  }
  has(value) {
    let curNode = this.root;
    while (curNode !== null) {
      if (curNode.value === value) return true;
      if (curNode.value < value) {
        curNode = curNode.right;
      } else {
        curNode = curNode.right;
      }
    }
    return false;
  }
}

const tree = new BinarySearchTree();
tree.insert(5);
tree.insert(4);
tree.insert(7);
tree.insert(8);
console.log(tree.has(3));
