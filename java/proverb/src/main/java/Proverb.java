class Proverb {

    private String[] words;

    Proverb(String[] words) {
        this.words = words;
    }

    String reciteLine(String a, String b) {
        return "For want of a " + a + " the " + b + " was lost.";
    }

    String reciteTail(int linesLeft, int currentIndex, int nextIndex) {
        if (linesLeft == 0) {
            return "";
        } else if (linesLeft == 1) {
            return "And all for the want of a " + this.words[0] + ".";
        }
        return reciteLine(this.words[currentIndex], this.words[nextIndex]) + "\n" +
                reciteTail(linesLeft - 1, currentIndex + 1, nextIndex + 1);
    }

    String recite() {
        return reciteTail(this.words.length, 0, 1);
    }

}
