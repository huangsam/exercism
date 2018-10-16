import java.util.HashMap;
import java.util.Set;

class Yacht {

    private int score;

    Yacht(int[] dice, YachtCategory yachtCategory) {
        this.score = 0;

        HashMap<Integer, Integer> diceFrequency = new HashMap<Integer, Integer>(0);
        int sum = 0;

        for (int i = 0; i < dice.length; i++) {
            diceFrequency.put(dice[i], diceFrequency.getOrDefault(dice[i], 0) + 1);
            sum += dice[i];
        }

        Set<Integer> keys = diceFrequency.keySet();

        switch (yachtCategory) {
            case YACHT:
                if (diceFrequency.size() == 1) {
                    this.score = 50;
                }
                break;
            case ONES:
                this.score = 1 * diceFrequency.getOrDefault(1, 0);
                break;
            case TWOS:
                this.score = 2 * diceFrequency.getOrDefault(2, 0);
                break;
            case THREES:
                this.score = 3 * diceFrequency.getOrDefault(3, 0);
                break;
            case FOURS:
                this.score = 4 * diceFrequency.getOrDefault(4, 0);
                break;
            case FIVES:
                this.score = 5 * diceFrequency.getOrDefault(5, 0);
                break;
            case SIXES:
                this.score = 6 * diceFrequency.getOrDefault(6, 0);
                break;
            case FULL_HOUSE:
                boolean twoFound = false;
                boolean threeFound = false;
                for (Integer key: keys) {
                    if (diceFrequency.get(key) == 2) {
                        twoFound = true;
                    } else if (diceFrequency.get(key) == 3) {
                        threeFound = true;
                    }
                }
                if (twoFound && threeFound) {
                    this.score = sum;
                }
                break;
            case FOUR_OF_A_KIND:
                for (Integer key: keys) {
                    if (diceFrequency.get(key) >= 4) {
                        this.score = key * 4;
                    }
                }
                break;
            case LITTLE_STRAIGHT:
                if (diceFrequency.size() == 5 && !diceFrequency.containsKey(6)) {
                    this.score = 30;
                }
                break;
            case BIG_STRAIGHT:
                if (diceFrequency.size() == 5 && !diceFrequency.containsKey(1)) {
                    this.score = 30;
                }
                break;
            case CHOICE:
                this.score = sum;
                break;
        }
    }

    int score() {
        return score;
    }

}
