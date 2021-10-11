//
//  main.cpp
//  matrix
//
//  Created by Amit Singh on 11/10/21.
//
#include<bits/stdc++.h>
#include "matrix.hpp"

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int mat1[R1][C1];
    int mat2[R2][C2];
    for(int i=0;i<R1;i++){
        for(int j=0;j<C1;j++){
            cin>>mat1[i][j];
        }
    }
    for(int i=0;i<R2;i++){
        for(int j=0;j<C2;j++){
            cin>>mat2[i][j];
        }
    }
    
    /*
    int mat1[R1][C1]={{1,2,3,4},
                      {2,3,4,5},
                      {1,6,5,3},
                      {1,7,5,2}};
    int mat2[R2][C2]={{2,6,5,3},
                      {2,7,5,1},
                      {1,8,5,9},
                      {9,4,6,5}};
*/
    multiplication_Matrix(mat1,mat2);
    cout<<endl;
    int d=determinant_Matrix(mat1,4);
    cout<<"Determinant of Matrix is:"<<" "<<d;
    cout<<endl;
     int adj[R1][C1];
     float inv[R1][C1];
     cout<<"The adjoint of matrix is :"<<endl;
     adjoint(mat1,adj);
     display(adj);
     cout<<endl;
       cout << "The Inverse is :"<<endl;
    inverse(mat1, inv);

    
}
