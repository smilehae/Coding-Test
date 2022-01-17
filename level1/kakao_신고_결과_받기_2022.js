function solution(id_list, report, k) {
  let answer = [];
  const reportedCount = {};
  const whoReported = {};

  id_list.forEach((id) => {
    reportedCount[id] = 0;
    whoReported[id] = [];
  });

  report.forEach((item) => {
    const [user, reportedUser] = item.split(" ");
    if (!whoReported[user].includes(reportedUser)) {
      whoReported[user].push(reportedUser);
      reportedCount[reportedUser] += 1;
    }
  });

  //K번 이상 신고당한 사람 이름!
  const banUser = id_list.filter((id) => reportedCount[id] >= k);
  id_list.forEach((id) => {
    const reportUsers = whoReported[id].filter((user) =>
      banUser.includes(user)
    );
    answer.push(reportUsers.length);
  });

  return answer;
}
