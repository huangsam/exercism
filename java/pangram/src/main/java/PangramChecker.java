import java.util.HashSet;

public class PangramChecker {

    public boolean isPangram(String input) {
        HashSet<Character> allChars = new HashSet<Character>();
        for (char a = 'a'; a <= 'z'; a++) {
            allChars.add(a);
        }
        for (int i = 0; i < input.length(); i++) {
            char letter = Character.toLowerCase(input.charAt(i));
            allChars.remove(letter);
        }
        return allChars.size() == 0;
    }

}
