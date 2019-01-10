export function compute(a, b) {
    if (a.length !== b.length) {
        throw new Error('left and right strands must be of equal length');
    }
    let result = 0;
    for (let i = 0; i < a.length; i++) {
        if (a[i] !== b[i]) {
            result += 1;
        }
    }
    return result;
}
