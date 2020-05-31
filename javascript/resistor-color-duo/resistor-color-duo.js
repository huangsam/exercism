const colorCode = (color) => {
  return COLORS.indexOf(color);
};

const COLORS = [
  "black", "brown", "red", "orange", "yellow",
  "green", "blue", "violet", "grey", "white",
];

export const decodedValue = (resistors) => {
  const [first, second, ...rest] = resistors
  return colorCode(first) * 10 + colorCode(second);
};
