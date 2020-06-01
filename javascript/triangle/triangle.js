export class Triangle {
  constructor(a, b, c) {
    this.equal = [a == b, b == c, c == a];
    this.triangle = (
      (a > 0 && b > 0 && c > 0) &&
      (a + b > c && b + c > a && c + a > b)
    );
  }

  isEquilateral() {
    return this.triangle && this.equal.every(eq => eq);
  }

  isIsosceles() {
    return this.triangle && this.equal.some(eq => eq);
  }

  isScalene() {
    return this.triangle && !this.equal.some(eq => eq);
  }
}
