class Darts {

    private double x;
    private double y;

    private static double OUTER_RADIUS = 10;
    private static double MIDDLE_RADIUS = 5;
    private static double INNER_RADIUS = 1;

    private static int OUTER_POINTS = 1;
    private static int MIDDLE_POINTS = 5;
    private static int INNER_POINTS = 10;

    Darts(double x, double y) {
        this.x = x;
        this.y = y;
    }

    boolean isWithinRadius(double radius) {
        return Math.abs(x) <= radius && Math.abs(y) <= radius;
    }

    int score() {
        if (isWithinRadius(INNER_RADIUS)) {
            return INNER_POINTS;
        } else if (isWithinRadius(MIDDLE_RADIUS)) {
            return MIDDLE_POINTS;
        } else if (isWithinRadius(OUTER_RADIUS)) {
            return OUTER_POINTS;
        }
        return 0;
    }

}
