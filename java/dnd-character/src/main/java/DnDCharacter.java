import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Random;

class DnDCharacter {

    private static final int baseHitPoints = 10;
    private static final int diceCount = 4;
    private static final Random random = new Random();

    private int strength;
    private int dexterity;
    private int constitution;
    private int intelligence;
    private int wisdom;
    private int charisma;

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

    protected int ability() {
        PriorityQueue<Integer> queue = new PriorityQueue<Integer>(diceCount, Collections.reverseOrder());
        for (int i = 0; i < diceCount; i++) {
            queue.add(throwDice());
        }
        return queue.poll() + queue.poll() + queue.poll();
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
