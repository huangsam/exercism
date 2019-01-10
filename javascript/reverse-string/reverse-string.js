export function reverseString(seq) {
    if (seq.length <= 1) {
        return seq;
    }
    return reverseString(seq.substr(1, seq.length)) + seq[0];
}
