class IsbnVerifier {

    boolean isValid(String stringToVerify) {
        int sum = 0;
        int charsLeft = 10;
        for (int i = 0; i < stringToVerify.length(); i++) {
            char currentChar = stringToVerify.charAt(i);
            int currentDigit = -1;
            if (i == stringToVerify.length() - 1 && currentChar == 'X') {
                currentDigit = 10;
            } else if (Character.isDigit(currentChar)) {
                currentDigit = Character.digit(currentChar, 10);
            } else if (currentChar == '-') {
                continue;
            } else {
                return false;
            }
            sum += currentDigit * charsLeft;
            charsLeft -= 1;
        }
        return charsLeft == 0 && sum % 11 == 0;
    }

}
