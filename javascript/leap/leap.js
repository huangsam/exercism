export function isLeap(year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 == 0 && year % 400 != 0) {
        return false;
    }
    return true;
}
