import java.util.HashMap;

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
        known.put(100L, "hundred");
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
            long base = number / 10L * 10L;
            long remainder = number % 10L;
            return (remainder > 0L)
                    ? String.format("%s-%s", known.get(base), known.get(remainder))
                    : known.get(base);
        }

        // TODO: Handle 10^2 through 10^12 - 1
        return "unknown";
    }

}
