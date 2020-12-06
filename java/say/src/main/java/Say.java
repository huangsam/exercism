import java.util.HashMap;
import java.util.LinkedList;

public class Say {

    private final HashMap<Long, String> known = new HashMap<>();

    public Say() {
        known.put(0L, "zero");
        known.put(1L, "one");
        known.put(2L, "two");
        known.put(3L, "three");
        known.put(4L, "four");
        known.put(5L, "five");
        known.put(6L, "six");
        known.put(7L, "seven");
        known.put(8L, "eight");
        known.put(9L, "nine");
        known.put(10L, "ten");
        known.put(11L, "eleven");
        known.put(12L, "twelve");
        known.put(13L, "thirteen");
        known.put(14L, "fourteen");
        known.put(15L, "fifteen");
        known.put(16L, "sixteen");
        known.put(17L, "seventeen");
        known.put(18L, "eighteen");
        known.put(19L, "nineteen");
        known.put(20L, "twenty");
        known.put(30L, "thirty");
        known.put(40L, "forty");
        known.put(50L, "fifty");
        known.put(60L, "sixty");
        known.put(70L, "seventy");
        known.put(80L, "eighty");
        known.put(90L, "ninety");
        known.put(1000L, "thousand");
        known.put(1000000L, "million");
        known.put(1000000000L, "billion");
    }

    public String say(long number) throws IllegalArgumentException {
        // Handle invalid numbers
        if (number <= -1L) {
            throw new IllegalArgumentException(String.format("%d is too small", number));
        } else if (number >= 1_000_000_000_000L) {
            throw new IllegalArgumentException(String.format("%d is too large", number));
        }

        // Handle 0 through 99
        if (number < 20L) {
            return known.get(number);
        } else if (number < 100L) {
            long factor = number / 10L;
            long remainder = number % 10L;
            if (remainder > 0L) {
                return String.format("%s-%s", known.get(factor * 10L), known.get(remainder));
            } else {
                return known.get(factor * 10L);
            }
        }

        // Handle 100 through 999
        if (number < 1000L) {
            long factor = number / 100L;
            long remainder = number % 100L;
            if (remainder > 0L) {
                return String.format("%s hundred %s", known.get(factor), say(remainder));
            } else {
                return String.format("%s hundred", known.get(factor));
            }
        }

        // Handle 10^3 through 10^12 - 1
        LinkedList<String> results = new LinkedList<>();
        long power = 0L;
        while (number > 0L) {
            long digits = number % 1000L;
            if (power > 0L && digits > 0L) {
                long base = (long) Math.pow(1000L, power);
                String result = String.format("%s %s", say(digits), known.get(base));
                results.push(result);
            } else if (power == 0L && digits > 0L) {
                results.push(say(digits));
            }
            number /= 1000L;
            power += 1L;
        } // while handling 3-digit groups from low to high

        return String.join(" ", results);
    }

}
