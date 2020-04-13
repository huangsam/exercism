public class RnaTranscription {

    public String transcribe(String dnaStrand) {
        String result = "";
        for (int i = 0; i < dnaStrand.length(); i++) {
            char dnaChar = dnaStrand.charAt(i);
            switch (dnaChar) {
                case 'G':
                    result += 'C';
                    break;
                case 'C':
                    result += 'G';
                    break;
                case 'T':
                    result += 'A';
                    break;
                case 'A':
                    result += 'U';
                    break;
                case 'U':
                    result += 'A';
                    break;
            }
        }
        return result;
    }

}
