const repr = ([freq, char] = tup) => {
  return freq > 1 ? `${freq}${char}` : char;
}

export const encode = (plaintext) => {
  let stack = [];
  let [freq, current] = [1, undefined];
  for (const ch of plaintext) {
    if (current === undefined) {
      current = ch;
      continue;
    }
    if (ch != current) {
      stack.push([freq, current]);
      [freq, current] = [1, ch];
    } else {
      freq++;
    }
  }
  stack.push([freq, current]);
  return stack.map(repr).join('');
};

export const decode = (ciphertext) => {
  let stack = [];
  let count = [];
  for (const ch of ciphertext) {
    if (ch >= '0' && ch <= '9') {
      count.push(ch);
    } else if (count.length == 0) {
      stack.push(ch);
    } else {
      const freq = Number(count.join(''));
      stack.push(ch.repeat(freq));
      count = [];
    }
  }
  return stack.join('');
};
