import java.util.LinkedList;
import java.util.Map;

import static java.util.Map.entry;

public class Say {

    private static final long SAY_MIN = 0L;
    private static final long SAY_MAX = 1_000_000_000_000L - 1L;
    private static final Map<Long, String> KNOWN = Map.ofEntries(
            entry(0L, "zero"),
            entry(1L, "one"),
            entry(2L, "two"),
            entry(3L, "three"),
            entry(4L, "four"),
            entry(5L, "five"),
            entry(6L, "six"),
            entry(7L, "seven"),
            entry(8L, "eight"),
            entry(9L, "nine"),
            entry(10L, "ten"),
            entry(11L, "eleven"),
            entry(12L, "twelve"),
            entry(13L, "thirteen"),
            entry(14L, "fourteen"),
            entry(15L, "fifteen"),
            entry(16L, "sixteen"),
            entry(17L, "seventeen"),
            entry(18L, "eighteen"),
            entry(19L, "nineteen"),
            entry(20L, "twenty"),
            entry(30L, "thirty"),
            entry(40L, "forty"),
            entry(50L, "fifty"),
            entry(60L, "sixty"),
            entry(70L, "seventy"),
            entry(80L, "eighty"),
            entry(90L, "ninety"),
            entry(1000L, "thousand"),
            entry(1000000L, "million"),
            entry(1000000000L, "billion")
    );

    public String say(long number) throws IllegalArgumentException {
        // Handle invalid numbers
        if (number < SAY_MIN) {
            throw new IllegalArgumentException(String.format("%d is too small", number));
        } else if (number > SAY_MAX) {
            throw new IllegalArgumentException(String.format("%d is too large", number));
        }

        // Handle 0 through 999
        if (number < 20L) {
            return KNOWN.get(number);
        } else if (number < 100L) {
            long factor = number / 10L;
            long remainder = number % 10L;
            if (remainder > 0L) {
                return String.format("%s-%s", KNOWN.get(factor * 10L), KNOWN.get(remainder));
            } else {
                return KNOWN.get(factor * 10L);
            }
        } else if (number < 1000L) {
            long factor = number / 100L;
            long remainder = number % 100L;
            if (remainder > 0L) {
                return String.format("%s hundred %s", KNOWN.get(factor), say(remainder));
            } else {
                return String.format("%s hundred", KNOWN.get(factor));
            }
        }

        // Handle groups of 10^3
        LinkedList<String> results = new LinkedList<>();
        long power = 0L;
        while (number > 0L) {
            long digits = number % 1000L;
            if (power > 0L && digits > 0L) {
                long base = (long) Math.pow(1000L, power);
                String result = String.format("%s %s", say(digits), KNOWN.get(base));
                results.addFirst(result);
            } else if (power == 0L && digits > 0L) {
                results.addFirst(say(digits));
            }
            number /= 1000L;
            power += 1L;
        }

        return String.join(" ", results);
    }

}
