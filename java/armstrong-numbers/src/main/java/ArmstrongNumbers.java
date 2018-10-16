class ArmstrongNumbers {

	boolean isArmstrongNumber(int numberToCheck) {
		String s = String.valueOf(numberToCheck);
		int numOfDigits = s.length();
		int sumOfDigits = 0;
		for (int i = 0; i < numOfDigits; i++) {
			sumOfDigits += Math.pow(Character.getNumericValue(s.charAt(i)), numOfDigits);
		}
		return numberToCheck == sumOfDigits;
	}

}
