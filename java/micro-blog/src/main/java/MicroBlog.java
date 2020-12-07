class MicroBlog {

    private static final int MAX_CHARACTERS = 5;

    public String truncate(String input) {
        return input.codePoints()
                .limit(MAX_CHARACTERS) // shorten codePoints stream
                .collect(
                        StringBuilder::new, // supply constructor
                        StringBuilder::appendCodePoint, // create partial results
                        StringBuilder::append // combine partial results
                ).toString();
    }

}
