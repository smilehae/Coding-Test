//트라이. 문자열을 저장하고 찾기 위한 트리 형태의 자료구조. 자동완성, 사전에 사용된다.
//루트는 비어있고, 간선은 추가될 문자를 키로 가진다.
//각 정점은 이전 정점의 값 + 간선의 키를 값으로 가진다.
//해시 테이블과 연결 리스트로 구현.

class Node {
  constructor(value = "") {
    this.value = value;
    this.children = new Map();
  }
}

class Trie {
  constructor() {
    this.root = new Node();
  }
  insert(string) {
    let curNode = this.root;
    for (const char of string) {
      if (!curNode.children.has(char)) {
        curNode.children.set(char, new Node(curNode.value + char));
      }
      curNode = curNode.children.get(char);
    }
  }
  has(string) {
    let curNode = this.root;
    for (const char of string) {
      if (!curNode.children.get(char)) {
        return false;
      }
      curNode = curNode.children.get(char);
    }
    return true;
  }
}

const trie = new Trie();
trie.insert("hello");
trie.insert("hawaii");
console.log(trie.has("hello"));
console.log(trie.has("hi"));
