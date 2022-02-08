class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class SinglyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
  }
  find(value) {
    let currNode = this.head;
    while (currNode && currNode.value !== value) {
      currNode = currNode.next;
    }
    return currNode;
  }
  append(newValue) {
    const newNode = new Node(newValue);
    if (this.head === null) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
  }
  insert(node, newValue) {
    const newNode = new Node(newValue);
    if (node === this.tail) {
      this.tail = newNode;
    }
    newNode.next = node.next;
    node.next = newNode;
  }
  remove(value) {
    let prevNode = this.head;
    if (this.head.value === value) {
      this.head = this.head.next;
      return;
    }
    while (prevNode.next && prevNode.next.value !== value) {
      prevNode = prevNode.next;
    }
    if (prevNode.next !== null) {
      if (prevNode.next === this.tail) {
        this.tail = prevNode;
      }
      prevNode.next = prevNode.next.next;
    }
  }

  display() {
    let currNode = this.head;
    let displayString = "[";
    while (currNode) {
      displayString += `${currNode.value}, `;
      currNode = currNode.next;
    }
    displayString += "]";
    console.log(displayString);
  }
}

const myList = new SinglyLinkedList();
myList.append(1);
myList.append(3);
myList.insert(myList.find(1), 2);
myList.remove(3);
myList.append(32);
myList.append(23);
myList.remove(23);
myList.append(100);
myList.display();
