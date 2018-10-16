class Acronym {

    private String phrase;

    Acronym(String phrase) {
        this.phrase = phrase;
    }

    String get() {
        String result = "";
        for (String word: this.phrase.split(" ")) {
            for (String sub: word.split("-")) {
                result += sub.charAt(0);
            }
        }
        return result.toUpperCase();
    }

}
