import java.util.HashMap;
import java.util.Map;

class Scrabble {

    private String word;

    Scrabble(String word) {
        this.word = word;
    }

    HashMap<Character, Integer> getLetterValues() {
        // Define sequences from README
        HashMap<String, Integer> sequenceValues = new HashMap<String, Integer>();
        sequenceValues.put("AEIOULNRST", 1);
        sequenceValues.put("DG", 2);
        sequenceValues.put("BCMP", 3);
        sequenceValues.put("FHVWY", 4);
        sequenceValues.put("K", 5);
        sequenceValues.put("JX", 8);
        sequenceValues.put("QZ", 10);

        // Convert sequences to letters
        HashMap<Character, Integer> letterValues = new HashMap<Character, Integer>();
        for (Map.Entry<String, Integer> entry: sequenceValues.entrySet()) {
            String letters = entry.getKey();
            Integer letterValue = entry.getValue();
            for (int i = 0; i < letters.length(); i++) {
                letterValues.put(letters.charAt(i), letterValue);
            }
        }
        return letterValues;
    }

    int getScore() {
        int result = 0;
        HashMap<Character, Integer> letterValues = getLetterValues();
        for (int i = 0; i < word.length(); i++) {
            Character currentKey = Character.toUpperCase(word.charAt(i));
            result += letterValues.get(currentKey);
        }
        return result;
    }
}
