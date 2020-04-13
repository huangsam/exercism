class ResistorColorDuo {

    private static final String[] bandColors = {
            "black", "brown", "red", "orange", "yellow",
            "green", "blue", "violet", "grey", "white"
    };

    private int colorCode(String color) {
        for (int i = 0; i < bandColors.length; i++) {
            if (bandColors[i] == color) {
                return i;
            }
        }
        return -1;
    }

    public int value(String[] colors) {
        int result = 0;
        for (int i = 0; i < colors.length; i++) {
            if (result / 10 > 0) {
                break;
            }
            result = result * 10 + colorCode(colors[i]);
        }
        return result;
    }
}
