const myMap = new Map();
myMap.set("mihae",123);
myMap.set("hahae",456);

console.log(myMap.get("mihae"));
console.log(myMap.size);
console.log(myMap)

for(let [key, value] of myMap){
	console.log(`${key}->${value}`);
}
const mySet = new Set();
mySet.add(1);
mySet.add("hi");
console.log(mySet.has(1));
console.log(mySet);