export const isArmstrongNumber = (n) => {
  const power = Math.floor(Math.log10(n) + 1);
  let [sum, remainder] = [0, n];
  while (remainder) {
    sum += Math.pow(remainder % 10, power);
    remainder = Math.floor(remainder / 10);
  }
  return sum == n;
};
