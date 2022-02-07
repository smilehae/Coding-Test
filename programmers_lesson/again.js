//배열

let arr = [];
arr.push(1, 2);
arr[3] = 2;

let arr1 = Array(5).fill(3);
//Array.from(배열, (각 원소, 인덱스)=> 리턴할 것)
let arr2 = Array.from({ length: 100 }, (_, i) => i);
let arr3 = Array.from([1, 2, 3], (x, i) => x * 3);
arr3.splice(1, 1, 100);
arr3.reverse();
const arr4 = [...arr3, 2, 4];
for (let i = 0; i < arr3.length; i++) {
  //   console.log(arr3[i]);
}
arr3.forEach((item) => {
  //   console.log(item);
});
for (const item of arr3) {
  //   console.log(item);
}

// 객체
const obj1 = new Object();
obj1.name = "hahae";
const obj2 = {
  name: "mihae",
  hobby: "voice acting",
};
obj2["birth"] = "19990218";
delete obj2.birth;
// console.log("name" in obj2);
// console.log(Object.keys(obj2));
// console.log(Object.values(obj2));

for (const key in obj2) {
  //   console.log(key, obj2[key]);
}

//연결 리스트
//구현해야 하는 것 : 가장 끝에 append. 특정 value를 find, 특정 value를 remove, 특정 위치에 특정 값을 insert
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
  append(value) {
    const newNode = new Node(value);
    if (this.tail === null) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
  }
  display() {
    let currNode = this.head;
    let displayString = "";
    while (currNode !== null) {
      displayString += `${currNode.value} -> `;
      currNode = currNode.next;
    }
    console.log(displayString);
  }
  remove(value) {
    //바로 헤드일 경우, 제거하고 해드를 변경
    if (this.head.value === value) {
      this.head = this.head.next;
    } else {
      let prevNode = this.head;
      while (prevNode.next) {
        if (prevNode.next.value === value) {
          prevNode.next = prevNode.next.next;
        }
        prevNode = prevNode.next;
      }
    }
  }
  insert(node, value) {
    const newNode = new Node(value);
    newNode.next = node.next;
    node.next = newNode;
  }
}

const linkedList = new SinglyLinkedList();
linkedList.append(1);
linkedList.append(2);
linkedList.append(3);
linkedList.append(5);
linkedList.display();
console.log(linkedList.find(3));
linkedList.remove(3);
linkedList.display();
linkedList.insert(linkedList.find(2), 10);
linkedList.display();
