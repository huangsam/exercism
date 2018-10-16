import java.util.*;
import java.util.stream.Stream;

class Matrix {

    private String matrixAsString;

    Matrix(String matrixAsString) {
        this.matrixAsString = matrixAsString;
    }

    int[] getRow(int rowNumber) {
        int[] result = new int[getColumnsCount()];
        String[] rows = matrixAsString.split("\n");
        String[] columns = rows[rowNumber].split(" ");
        for (int i = 0; i < columns.length; i++) {
            result[i] = Integer.parseInt(columns[i]);
        }
        return result;
    }

    int[] getColumn(int columnNumber) {
        int[] result = new int[getRowsCount()];
        String[] rows = matrixAsString.split("\n");
        for (int i = 0; i < rows.length; i++) {
            String[] columns = rows[i].split(" ");
            result[i] = Integer.parseInt(columns[columnNumber]);
        }
        return result;
    }

    int getRowsCount() {
        String[] rows = matrixAsString.split("\n");
        return rows.length;
    }

    int getColumnsCount() {
        int count = 0;
        String firstRow = matrixAsString.split("\n")[0];
        String[] columns = firstRow.split(" ");
        return columns.length;
    }
}
