import java.util.Random;
import java.util.Arrays;

class DnDCharacter {

    private static final int baseHitPoints = 10;
    private static final Random random = new Random();

    private int strength = -1;
    private int dexterity = -1;
    private int constitution = -1;
    private int intelligence = -1;
    private int wisdom = -1;
    private int charisma = -1;

    public DnDCharacter() {
        strength = ability();
        dexterity = ability();
        constitution = ability();
        intelligence = ability();
        wisdom = ability();
        charisma = ability();
    }

    private int throwDice() {
        return random.nextInt(6) + 1; // [0..5] + 1
    }

    public int ability() {
        int[] scores = {throwDice(), throwDice(), throwDice(), throwDice()};
        Arrays.sort(scores);
        int result = 0;
        for (int i = 1; i < 4; i++) {
            result += scores[i];
        }
        return result;
    }

    public int modifier(int input) {
        double doubleDifference = input - baseHitPoints;
        return (int) Math.floor(doubleDifference / 2.0);
    }

    public int getStrength() {
        return strength;
    }

    public int getDexterity() {
        return dexterity;
    }

    public int getConstitution() {
        return constitution;
    }

    public int getIntelligence() {
        return intelligence;
    }

    public int getWisdom() {
        return wisdom;
    }

    public int getCharisma() {
        return charisma;
    }

    public int getHitpoints() {
        return baseHitPoints + modifier(getConstitution());
    }

}
