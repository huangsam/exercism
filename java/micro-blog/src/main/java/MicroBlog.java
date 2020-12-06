class MicroBlog {

    private static final int MAX_CHARACTERS = 5;

    public String truncate(String input) {
        int numOfPoints = input.codePointCount(0, input.length());
        if (numOfPoints < MAX_CHARACTERS) {
            return input;
        }
        int offset = input.offsetByCodePoints(0, MAX_CHARACTERS);
        return input.substring(0, offset);
    }

}
