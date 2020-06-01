export const isPangram = (sentence) => {
  let chars = Array(26).fill(0);
  let normalized = sentence.toLowerCase().replace(/[\s-]+/, '');
  for (const ch of normalized) {
    chars[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
  }
  return chars.every(item => item > 0);
};
