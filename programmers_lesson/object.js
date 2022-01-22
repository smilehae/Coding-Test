const obj = { name: "편미해", company: "카카오" };

obj["email"] = "mimihae@mihae.com";
obj.hobby = "voice acting";
console.log(obj);

delete obj.email;
console.log(obj);

console.log("email" in obj);
console.log("hobby" in obj);

console.log(Object.keys(obj));
console.log(Object.values(obj));

for (const key in obj) {
  console.log(key, obj[key]);
}
