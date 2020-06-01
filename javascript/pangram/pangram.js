export const isPangram = (sentence) => {
  let chars = Array.from({ length: 26 }).fill(0);
  for (const ch of sentence.toLowerCase()) {
    if (ch < 'a' || ch > 'z') {
        continue;
    }
    chars[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
  }
  return chars.every(item => item > 0);
};
