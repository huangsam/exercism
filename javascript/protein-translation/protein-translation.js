const CODONMAP = {
  'AUG': 'Methionine',
  'UUU': 'Phenylalanine',
  'UUC': 'Phenylalanine',
  'UUA': 'Leucine',
  'UUG': 'Leucine',
  'UCU': 'Serine',
  'UCC': 'Serine',
  'UCA': 'Serine',
  'UCG': 'Serine',
  'UAU': 'Tyrosine',
  'UAC': 'Tyrosine',
  'UGU': 'Cysteine',
  'UGC': 'Cysteine',
  'UGG': 'Tryptophan',
  'UAA': '',
  'UAG': '',
  'UGA': '',
};

const CODONSIZE = 3;

export const translate = (rna = '') => {
  let result = [];
  for (let i = 0; i < rna.length; i += CODONSIZE) {
    const codon = rna.substring(i, i + CODONSIZE);
    const protein = CODONMAP[codon];
    if (protein === '') {
      return result;
    } else if (protein === undefined) {
      throw new Error('Invalid codon');
    }
    result.push(protein);
  }
  return result;
};
