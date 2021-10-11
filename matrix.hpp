//
//  matrix.hpp
//  matrix
//
//  Created by Amit Singh on 11/10/21.
//

#ifndef matrix_hpp
#define matrix_hpp
#include<bits/stdc++.h>
using namespace std;

#define R1 4
#define C1 4
#define R2 4
#define C2 4

void Co_factor(int mat1[R1][C1], int temp[R1][C1], int p, int q, int n) ;
void multiplication_Matrix(int mat1[][C1], int mat2[][C2]);
int determinant_Matrix(int mat1[R1][C1], int n);
void adjoint(int mat1[R1][C1],int adj[R1][C1]);
void display(int adj[R1][C1]);
void inverse(int mat1[R1][C1], float inverse[R1][C1]);


#endif /* matrix_hpp */
