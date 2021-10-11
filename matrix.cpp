//
//  matrix.cpp
//  matrix
//
//  Created by Amit Singh on 11/10/21.
//

#include "matrix.hpp"
using namespace std;


void multiplication_Matrix(int mat1[][C1], int mat2[][C2]) {
    int ans[R1][C2];
 
    cout << "Multiplication of given two matrices is:\n" << endl;
 
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            ans[i][j] = 0;
 
            for (int k = 0; k < R2; k++) {
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
 
            cout << ans[i][j] << "\t";
        }
 
        cout << endl;
    }
}

int determinant_Matrix(int mat1[R1][C1], int n)
{
    int D = 0;
  
    if (n == 1)
        return mat1[0][0];
  
    int temp[R1][C1];
  
    int sign = 1;
 
    for (int num = 0; num < n; num++)
    {
        // Getting Cofactor of mat[0][f]
        Co_factor(mat1, temp, 0, num, n);
        D += sign * mat1[0][num] * determinant_Matrix(temp, n - 1);
  
        // terms are to be added with alternate sign
        sign = -sign;
    }
  
    return D;
}

void Co_factor(int mat1[R1][C1], int temp[R1][C1], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat1[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

void adjoint(int mat1[R1][C1],int adj[R1][C1])
{
    if (R1 == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[R1][C1];
 
    for (int i=0; i<R1; i++)
    {
        for (int j=0; j<C1; j++)
        {
            Co_factor(mat1, temp, i, j, R1);
            if((i+j)%2==0){
                sign=1;}
            else{ sign=-1;}
            adj[j][i] = (sign)*(determinant_Matrix(temp, R1-1));
        }
    }
}

void display(int adj[R1][C1])
{
    for (int i=0; i<R1; i++)
    {
        for (int j=0; j<C1; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}



void inverse(int mat1[R1][C1], float inverse[R1][C1])
{
    // Find determinant of A[][]
    int det = determinant_Matrix(mat1, 4);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return;
    }
 
    // Find adjoint
    int adj[R1][C1];
    adjoint(mat1, adj);
 
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<R1; i++)
        for (int j=0; j<C1; j++)
            inverse[i][j] = adj[i][j]/float(det);
 
    for (int i=0; i<R1; i++)
    {
        for (int j=0; j<C1; j++)
            cout << inverse[i][j] << " ";
        cout << endl;
    }
}
