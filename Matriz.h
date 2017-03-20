/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matriz.h
 * Author: Usuario
 *
 * Created on 7 de Março de 2017, 11:03
 */

#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <string>
#include <vector>
#include "FileManager.h"

using namespace std;

class Matriz {
public:
    Matriz();
    ~Matriz();

    void buildSpline();
private:
    vector<double> x, y;
    vector<double> a, b, c, d;
    void resolveMatriz(int size);
    void imprimeSpline();
    void acheY(double X,double index);
    int acheIndex(double X);
};

#endif /* MATRIZ_H */

