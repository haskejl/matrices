#include <stdio.h>
#include <stdlib.h>

#define CLEARTERMINAL printf("\x1B[3J\x1B[1;1H");

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

void allocateMatrixMemory(struct Matrix* m) {
	m->data = (double**)malloc(m->mRows*sizeof(double*));

	for(int i=0; i<m->mRows; i++) {
		m->data[i] = (double*)malloc(m->nCols*sizeof(double));
	}
}

void freeMatrixMemory(struct Matrix* m) {
	for(int i=0; i<m->mRows; i++) {
		free(m->data[i]);
	}
	free(m->data);
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
	printf("Hit return after each row.\n");
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

void addMatrices(struct Matrix* m1, struct Matrix* m2, struct Matrix* result) {
	if(m1->mRows != m2->mRows || m1->nCols != m2->nCols) {
		printf("Matrices are incompatable for addition, no action performed.");
		return;
	}
	if(result->mRows != m1->mRows || result->nCols != m1->nCols) {
		// This might not be the most performant, but it's the simplest
		freeMatrixMemory(result);
		result->mRows = m1->mRows;
		result->nCols = m1->nCols;
		allocateMatrixMemory(result);
	}

	for(int i=0; i<m1->mRows; i++) {
		for(int j=0; j<m1->nCols; j++) {
			result->data[i][j] = m1->data[i][j] + m2->data[i][j];
		}
	}
}

int main(int argc, char** argv) {
    struct Matrix m1;
    struct Matrix m2;
	CLEARTERMINAL
    
	printf("Enter the dimensions of the first matrix.\n");
	setMRows(&m1);
	setNCols(&m1);
	CLEARTERMINAL

	printf("Enter the dimensions of the second matrix.\n");
	setMRows(&m2);
	setNCols(&m2);
	CLEARTERMINAL
    
    printf("The first matrix has %d rows and %d columns.\n", 
			m1.mRows, 
			m1.nCols);
    printf("The second matrix has %d rows and %d columns.\n", 
			m2.mRows, 
			m2.nCols);

	allocateMatrixMemory(&m1);
	allocateMatrixMemory(&m2);

	printf(BRIGHT "\nSetup your matrices.\n" RESET);
	printf(UNDERLINE "Matrix 1:\n" RESET);
	setMatrixData(&m1);

	printf(UNDERLINE "Matrix 2:\n" RESET);
	setMatrixData(&m2);


	printf(UNDERLINE "\nMatrix 1:\n" RESET);
	printMatrix(&m1);

	printf(UNDERLINE "\nMatrix 2:\n" RESET);
	printMatrix(&m2);

	freeMatrixMemory(&m1);
	freeMatrixMemory(&m2);
    return 0;
}
