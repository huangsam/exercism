export const isIsogram = (word) => {
  let chars = Array(26).fill(0);
  let normalized = word.toLowerCase().replace(/[\s-]+/, '');
  for (const ch of normalized) {
    chars[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
  }
  return chars.every(count => count <= 1);
};
