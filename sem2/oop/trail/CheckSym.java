public class CheckSym {
    public static boolean isSymmetric(int[][] matrix) {
        int rows = matrix.length;
        if (rows == 0) {
            return true;
        }
        
        int cols = matrix[0].length;
        if (rows != cols) {
            return false;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    public static void printMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        int[][] matrix1 = {
            {1, 2, 3},
            {2, 4, 5},
            {3, 5, 6}
        };
        
        System.out.println("Matrix 1:");
        printMatrix(matrix1);
        System.out.println("Is Symmetric? " + isSymmetric(matrix1));
        
        int[][] matrix2 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        
        System.out.println("\nMatrix 2:");
        printMatrix(matrix2);
        System.out.println("Is Symmetric? " + isSymmetric(matrix2));
        
        int[][] matrix3 = {
            {5, 1, 2},
            {1, 3, 4},
            {2, 4, 7}
        };
        
        System.out.println("\nMatrix 3:");
        printMatrix(matrix3);
        System.out.println("Is Symmetric? " + isSymmetric(matrix3));
    }
}
