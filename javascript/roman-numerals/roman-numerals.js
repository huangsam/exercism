const ROMAN_MAP = [
  [1000, 'M'],
  [900, 'CM'],
  [500, 'D'],
  [400, 'CD'],
  [100, 'C'],
  [90, 'XC'],
  [50, 'L'],
  [40, 'XL'],
  [10, 'X'],
  [9, 'IX'],
  [5, 'V'],
  [4, 'IV'],
  [1, 'I'],
]

export const toRoman = (n) => {
  let chars = [];
  for (let [val, ch] of ROMAN_MAP) {
    while (n >= val) {
      n -= val;
      chars.push(ch);
    }
  }
  return chars.join('');
};
