const empty = (m, n) => {
  return Array(m).fill().map(() => Array(n));
};

export class Matrix {
  constructor(input) {
    const lines = input.split('\n');
    const numRow = lines.length;
    const numCol = lines[0].split(' ').length;
    this.byRow = empty(numRow, numCol);
    this.byCol = empty(numCol, numRow);
    for (let i = 0; i < numRow; i++) {
      const line = lines[i].split(' ').map(s => Number(s));
      for (let j = 0; j < numCol; j++) {
        this.byRow[i][j] = this.byCol[j][i] = line[j];
      }
    }
  }

  get rows() {
    return this.byRow;
  }

  get columns() {
    return this.byCol;
  }
}
