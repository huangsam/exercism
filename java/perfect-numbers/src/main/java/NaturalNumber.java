import java.util.ArrayList;
import java.util.List;

class NaturalNumber {

    private int value;

    NaturalNumber(int value) {
        if (value < 1) {
            throw new IllegalArgumentException("You must supply a natural number (positive integer)");
        }
        this.value = value;
    }

    private List<Integer> getPrimes() {
        List<Integer> primes = new ArrayList<Integer>();
        for (int i = 1; i < this.value; i++) {
            if (this.value == i) {
                continue;
            }
            if (this.value != i && this.value % i == 0) {
                primes.add(i);
            }
        }
        return primes;
    }

    Classification getClassification() {
        Classification result = null;
        List<Integer> primes = getPrimes();
        int sum = 0;
        for (int i: primes) {
            sum += i;
        }
        if (sum < this.value) {
            result = Classification.DEFICIENT;
        } else if (sum == this.value) {
            result = Classification.PERFECT;
        } else {
            result = Classification.ABUNDANT;
        }
        return result;
    }

}
