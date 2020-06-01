const CODON_MAP = {
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

const CODON_SIZE = 3;

export const translate = (rna = '') => {
  let result = [];
  for (let i = 0; i < rna.length; i += CODON_SIZE) {
    const codon = rna.substring(i, i + CODON_SIZE);
    const protein = CODON_MAP[codon];
    if (protein === '') {
      return result;
    } else if (protein === undefined) {
      throw new Error('Invalid codon');
    }
    result.push(protein);
  }
  return result;
};
