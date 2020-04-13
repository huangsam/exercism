import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

class ProteinTranslator {

    private final String STOP = "STOP";
    private Map<String, String> proteinMap;

    public ProteinTranslator() {
        proteinMap = new HashMap<String, String>();
        multiPut("Methionine", "AUG");
        multiPut("Phenylalanine", "UUU", "UUC");
        multiPut("Leucine", "UUA", "UUG");
        multiPut("Serine", "UCU", "UCC", "UCA", "UCG");
        multiPut("Tyrosine", "UAU", "UAC");
        multiPut("Cysteine", "UGU", "UGC");
        multiPut("Tryptophan", "UGG");
        multiPut(STOP, "UAA", "UAG", "UGA");
    }

    void multiPut(String value, String... keys){
        for(String key : keys) {
            proteinMap.put(key, value);
        }
    }

    String getProtein(String codon) {
        return proteinMap.get(codon);
    }

    List<String> translate(String rnaSequence) {
        List<String> result = new ArrayList<String>();
        int sequenceLength = rnaSequence.length();
        int chunks = sequenceLength / 3;
        for (int i = 0; i < chunks; i++) {
            String codon = rnaSequence.substring(i * 3, i * 3 + 3);
            String protein = getProtein(codon);
            if (protein.equals(STOP)) {
                break;
            }
            result.add(protein);
        }
        return result;
    }

}
