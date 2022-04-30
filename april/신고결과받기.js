function solution(id_list, report, k) {
  const callMap = new Map();
  const reportedCount = new Map();
  id_list.forEach((id) => {
    callMap.set(id, []);
    reportedCount.set(id, 0);
  });

  report.forEach((callString) => {
    const [caller, callee] = callString.split(" ");
    const calleeList = callMap.get(caller);
    const calleeCount = reportedCount.get(callee);
    if (!calleeList.includes(callee)) {
      callMap.set(caller, [...calleeList, callee]);
      reportedCount.set(callee, calleeCount + 1);
    }
  });

  const badUser = [...reportedCount]
    .filter(([_, count]) => count >= k)
    .map(([user, _]) => user);

  const result = [...callMap]
    .map(([caller, callee]) => callee)
    .map((dataList) => {
      let badUserCount = 0;
      dataList.forEach((data) => {
        if (badUser.includes(data)) {
          badUserCount += 1;
        }
      });
      return badUserCount;
    });

  return result;
}
