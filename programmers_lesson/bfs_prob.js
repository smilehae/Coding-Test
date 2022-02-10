function solution(n, vertex) {
  //graph를 만들때, C++에서 무조건 2차원 배열 만들었던 것에 반해 여기선 1차원 배열 + 각자 Array로 인접한 갑만 가져오도록 만듦!

  const graph = Array.from(Array(n + 1), () => []);
  const distance = Array(n + 1).fill(0);

  for (const [src, dest] of vertex) {
    graph[src].push(dest);
    graph[dest].push(src);
  }

  const queue = [1];
  distance[1] = 1;
  while (queue.length > 0) {
    const src = queue.shift();
    for (const dest of graph[src]) {
      if (distance[dest] === 0) {
        queue.push(dest);
        distance[dest] = distance[src] + 1;
      }
    }
  }

  const max = Math.max(...distance);
  return distance.filter((item) => item === max).length;
}
