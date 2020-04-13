class ResistorColor {

    private static final String[] bandColors = {
            "black", "brown", "red", "orange", "yellow",
            "green", "blue", "violet", "grey", "white"
    };

    public int colorCode(String color) {
        for (int i = 0; i < bandColors.length; i++) {
            if (bandColors[i] == color) {
                return i;
            }
        }
        return -1;
    }

    public String[] colors() {
        return bandColors;
    }
}
