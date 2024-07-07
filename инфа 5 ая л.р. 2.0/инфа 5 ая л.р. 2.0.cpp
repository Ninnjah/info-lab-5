#include <iostream>
using namespace std;

int rows, cols;
int matrix[10][10];


void printMatrix() {
    printf("Текущее состояние матрицы:\n");
    for (int col = 0; col < cols; col++){
        for (int row = 0; row < rows; row++) {
            printf("%d\t", matrix[col][row]);
        }
        printf("\n\n");
    }
}


void loadMatrix() {
    for (int col = 0; col < cols; col++) {
        printf("Введите %d строку:\n", col+1);
        for (int row = 0; row < rows; row++) {
            scanf("%d", &matrix[col][row]);
        }
    }
}


void processMatrix() {
    for (int row = 0; row < rows; row++) {
        int maxElement = 0;
        int count = 0;
        for (int col = 0; col < cols; col++) {
            if ((matrix[col][row] % 7 == 0) && (matrix[col][row] != 0)) {
                count++;
                if ((matrix[col][row] > maxElement) || (maxElement == 0)) {
                    maxElement = matrix[col][row];
                }
            }
        }
        if (count % 2 == 0) {
            for (int col = 0; col < cols; col++) {
                if (matrix[col][row] == maxElement) {
                    matrix[col][row] = 0;
                }
            }
        }
    }
}


void inputArraySize() {
    printf("Введите длину и ширину массива через пробел: ");
    scanf("%d %d", &cols, &rows);
}


int main() {
    setlocale(LC_ALL, "RU");

    inputArraySize();
    loadMatrix();
    printMatrix();
    processMatrix();
    printMatrix();

    return 0;
}


/*
-7 2 14 15
-21 22 23 24
1 32 77 34
0 42 43 44

7 2
14 7

*/
