/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matriz.cpp
 * Author: Usuario
 * 
 * Created on 7 de Março de 2017, 11:03
 */

#include <math.h>

#include "Matriz2.h"

Matriz2::Matriz2() {
    x = {0.9,1.3,1.9,2.1,2.6,3.0,3.9,4.4,4.7,5.0,6.0,7.0,8.0,9.2,10.5,11.3,11.6,12.0,12.6,13.0,13.3};
    y = {1.3,1.5,1.85,2.1,2.6,2.7,2.4,2.15,2.05,2.1,2.25,2.3,2.25,1.95,1.4,0.9,0.7,0.6,0.5,0.4, 0.25};
//    x = {1,2,3};
//    y = {2,3,5};
    buildSpline();
}

Matriz2::~Matriz2() {
    x.clear();
    y.clear();
    a.clear();
    b.clear();
    c.clear();
    d.clear();

}

void Matriz2::buildSpline() {

    unsigned int size = x.size();

    a.resize( size );
    b.resize( size );
    c.resize( size );
    d.resize( size );
    
    a = y;
    
    resolveMatriz(size);
    
    // solve for coefficients of linear system
    for ( long i = 0; i < size - 1; i++ ){

        double diffx1 = x[i  ] - x[i-1];
        double diffx2 = x[i+1] - x[i  ];
        double diffy1 = y[i  ] - y[i-1];
        double diffy2 = y[i+1] - y[i  ];

        b[i] = (diffy2/diffx2) - ( ( diffx2*( c[i+1] + 2*c[i]) )/3);
        d[i] = ( c[i+1] - c[i])/(3*diffx2);
    }
//    imprimeSpline();
    
    double i = 0.9;
    while( i < 13.3){
        int index = acheIndex(i);
//        cout << index << "\t";
        acheY(i,index);
        i += 0.1;
    }
//    for ( double i = 0.9; i < 13.3; i + 0.1 ) {
//        int index = acheIndex(i);
//        acheY(i,index);
//        cout << i << endl;
//    }

        
}

void Matriz2::resolveMatriz(int size) {
    
    double A[size][size] = {0},
        B[size] = {0},
        X[size] = {0},
        l[size] = {1},
        u[size] = {0},
        z[size] = {0};
    
    A[0][0] = A[size-1][size-1] = 1;
    
    for ( int i = 1; i < size - 1; i++ ) {
        
        double diffh1 = x[i  ] - x[i-1],
               diffh2 = x[i+1] - x[i  ],
               diffa1 = a[i  ] - a[i-1],
               diffa2 = a[i+1] - a[i  ];
        
        A[i][i-1] = diffh1;
        A[i][i  ] = 2*(diffh1 +diffh2);
        A[i][i+1] = diffh2;
        
        B[i] = (3*(diffa2) )/diffh2 - (3*(diffa1) )/diffh1;
        
        l[i] = 2*(x[i+1] - x[i-1]) - diffh1*u[i-1];
        u[i] = diffh2/l[i];
        z[i] = (B[i] - diffh1*z[i-1])/l[i];
    }
    
    
//    for ( int i = 0; i < size; i++ ) {
//        
//        double sum = 0;
//        
//        for ( int j = 0; j < i; j++ )
//            sum += A[i][j] * X[j];
//            
//        for ( int j = i + 1; j < size; j++ ) 
//            sum += A[i][j] * X[j];
//        
//        sum = sum/A[i][i];
//        
//        X[i] = c[i] = (B[i] - sum)/A[i][i];
//    }

    for ( int i = size - 1 ; i >= 0; i-- ) {
        c[i] = z[i] - u[i]*c[i+1];
    }
}

void Matriz2::imprimeSpline() {
    
    for ( int i = 0; i < x.size() - 1 ; i++ ) {
        double h1 = x[i];
        printf("S[%d] = %.2f + %.2f*(x - %.2f) + %.2f*(x - %.2f)^2 + %.2f*(x - %.2f)^3 \n", i, a[i], b[i], h1, c[i], h1, d[i], h1);
//        cout << b[i] << endl;
    }

}

void Matriz2::acheY(double X, double index) {
    double termo1 = a[index],
           termo2 = b[index]*(X -  x[index]),
           termo3 = c[index]* ( pow( X -  x[index], 2) ),
           termo4 = d[index]*( pow(X -  x[index], 3) );
    
    double resultado =  termo1 + termo2 + termo3 + termo4;
    
    cout << resultado << endl;
}

int Matriz2::acheIndex(double X) {
    int size = x.size(),
        menorIndex = 0;
    double diferenca = X - x[0];
    for ( int i = 1; i < size - 1; i++ ) {
        
        double h1 = X - x[i];
        if( h1 < 0 ) break;
        
        if( h1 < diferenca){
            menorIndex = i;
            diferenca = h1;
        }
    }
    return menorIndex;
}
