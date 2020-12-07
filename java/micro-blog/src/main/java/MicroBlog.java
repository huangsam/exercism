class MicroBlog {

    private static final long MAX_CHARACTERS = 5L;

    public String truncate(String input) {
        return input.codePoints()
                .limit(MAX_CHARACTERS) // shorten codePoints stream
                .collect(
                        StringBuilder::new, // supply constructor
                        StringBuilder::appendCodePoint, // build partial results
                        StringBuilder::append // combine partial results
                ).toString();
    }

}
