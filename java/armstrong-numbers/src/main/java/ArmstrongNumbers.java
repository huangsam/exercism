class ArmstrongNumbers {

	boolean isArmstrongNumber(int numberToCheck) {
		int numOfDigits = (int) (Math.log10(numberToCheck) + 1);
		int sumOfDigits = 0;
		for (int leftOver = numberToCheck; leftOver > 0; leftOver /= 10) {
			sumOfDigits += Math.pow(leftOver % 10, numOfDigits);
		}
		return numberToCheck == sumOfDigits;
	}

}
