#ifndef H_5_10_H
#define H_5_10_H

void guassian_elimination(double **A, double *b, double *u, int n);
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols);
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows);
void FillPkn(double **P, int k, int n, int N);
double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double ** matrix);

#endif
