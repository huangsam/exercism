export const isIsogram = (word) => {
  let charMap = Array.from({ length: 26 }).fill(0);
  let normWord = word.toLowerCase().replace(/[\s-]+/, '');
  for (const ch of normWord) {
    charMap[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
  }
  return charMap.every(count => count <= 1);
};
