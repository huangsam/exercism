class RaindropConverter {

    String convert(int number) {
        String output = "";
        boolean factorThree = (number % 3 == 0);
        boolean factorFive = (number % 5 == 0);
        boolean factorSeven = (number % 7 == 0);
        boolean factorNone = !factorThree && !factorFive && !factorSeven;
        if (factorNone) {
            return Integer.toString(number);
        }
        if (factorThree) {
            output += "Pling";
        }
        if (factorFive) {
            output += "Plang";
        }
        if (factorSeven) {
            output += "Plong";
        }
        return output;
    }

}
