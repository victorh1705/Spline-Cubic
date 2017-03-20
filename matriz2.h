/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matriz2.h
 * Author: Usuario
 *
 * Created on 20 de Março de 2017, 12:51
 */

#ifndef MATRIZ2_H
#define MATRIZ2_H

#include <iostream>
#include <string>
#include <vector>
#include "FileManager.h"

using namespace std;

class Matriz2 {
public:
    Matriz2();
    ~Matriz2();

    void buildSpline();
private:
    vector<double> x, y;
    vector<double> a, b, c, d;
    void resolveMatriz(int size);
    void imprimeSpline();
    void acheY(double X,double index);
    int acheIndex(double X);
};

#endif /* MATRIZ2_H */

