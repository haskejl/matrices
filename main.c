#include <stdio.h>
#include <stdlib.h>

#define RESET "\x1B[0m"
#define BRIGHT "\x1B[1m"
#define UNDERLINE "\x1B[4m"
#define RED "\x1B[31m"

struct Matrix {
    int mRows, nCols;
    double** data;
};

void flushInput() {
	char c = getchar();
	while(c != '\n' && c != EOF) {
		c = getchar();
	}
}

void setMRows(struct Matrix* m) {
    printf("Input the number of rows (2-10): ");
    scanf("%d", &m->mRows);
	flushInput();

    while(m->mRows < 2 || m->mRows > 10) {
        printf("Invalid value.\nInput a number between 2 and 10: ");
        scanf("%d", &m->mRows);
		flushInput();
    }
}
void setNCols(struct Matrix* m) {
    printf("Input the number of columns (2-10): ");
    scanf("%d", &m->nCols);
		flushInput();

    while(m->nCols < 2 || m->nCols > 10) {
        printf("Invalid value.\nInput a number between 2 and 10: ");
        scanf("%d", &m->nCols);
		flushInput();
    }
}

void setMatrixData(struct Matrix* m) {
	printf("Input your matrix with spaces between the numbers.\n");
	printf("You may hit return after each row.\n");
	for(int i=0; i<m->mRows; i++) {
		for(int j=0; j<m->nCols; j++) {
			scanf("%lf", &m->data[i][j]);
		}
	}
}

void printMatrix(struct Matrix* m) {
	for(int i=0; i<m->mRows; i++) {
		for(int j=0; j<m->nCols; j++) {
			printf("%1.2f ", m->data[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char** argv) {
    struct Matrix m1;
    struct Matrix m2;
    
	printf("Enter the dimensions of the first matrix.\n");
	setMRows(&m1);
	setNCols(&m1);
	system("clear");

	printf("Enter the dimensions of the second matrix.\n");
	setMRows(&m2);
	setNCols(&m2);
	system("clear");
    
    printf("The first matrix has %d rows and %d columns.\n", 
			m1.mRows, 
			m1.nCols);
    printf("The second matrix has %d rows and %d columns.\n", 
			m2.mRows, 
			m2.nCols);

	m1.data = (double**)malloc(sizeof(double*)*m1.mRows);
	m2.data = (double**)malloc(sizeof(double*)*m2.mRows);

	for(int i=0; i<m1.mRows; i++) {
		m1.data[i] = (double*)malloc(sizeof(double)*m1.nCols);
	}
	for(int i=0; i<m2.mRows; i++) {
		m2.data[i] = (double*)malloc(sizeof(double)*m2.nCols);
	}

	printf(UNDERLINE "\nSetup your matrices.\n" RESET);
	printf(UNDERLINE "Matrix 1:\n" RESET);
	setMatrixData(&m1);

	printf(UNDERLINE "Matrix 2:\n" RESET);
	setMatrixData(&m2);


	printf(UNDERLINE "\nMatrix 1:\n" RESET);
	printMatrix(&m1);

	printf(UNDERLINE "\nMatrix 2:\n" RESET);
	printMatrix(&m2);

    return 0;
}
