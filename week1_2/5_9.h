#ifndef H_5_10_H
#define H_5_10_H

void solve3by3(double **A, double *b, double *u);
double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double ** matrix);
void PrintTriangular(double** A, double* b, int n);
void PrintSquareMatrix(double** A, int n);

#endif
