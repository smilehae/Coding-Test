//stack을 사용해서, 값을 하나씩 넣었을 때, 바로 직전의 값과 자신의 값이 같으면 둘다 pop pop.
//최종적으로 length가 0이면 true, length가 1이면 false

function solution(s) {
  const stack = [];
  if (s.length <= 1) return 0;

  for (let i = 0; i < s.length; i++) {
    if (stack.length === 0) stack.push(s[i]);
    else {
      if (s[i] === stack[stack.length - 1]) {
        stack.pop();
      } else {
        stack.push(s[i]);
      }
    }
  }
  if (stack.length === 0) return 1;
  else return 0;
}
