const TOKEN_MAP = {
  'G': 'C',
  'C': 'G',
  'T': 'A',
  'A': 'U',
};

export const toRna = (seq) => {
  return seq.split('').map(ch => TOKEN_MAP[ch]).join('');
};
