function solution(record) {
  let answer = [];
  const users = {};
  record.forEach((user) => {
    const [order, id, name] = user.split(" ");
    if (order === "Enter" || order === "Change") {
      users[`${id}`] = name;
    }
  });
  record.forEach((user) => {
    const [order, id] = user.split(" ");
    if (order !== "Change") {
      const str =
        users[`${id}`] +
        `님이 ${order === "Enter" ? "들어왔습니다." : "나갔습니다."}`;
      answer.push(str);
    }
  });

  return answer;
}
