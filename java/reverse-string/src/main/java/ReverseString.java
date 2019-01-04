class ReverseString {

    String reverse(String inputString) {
        if (inputString.length() == 0) {
            return inputString;
        }
        return reverse(inputString.substring(1)) + inputString.charAt(0);
    }

}
