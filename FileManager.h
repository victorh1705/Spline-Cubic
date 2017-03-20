/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileManager.h
 * Author: Usuario
 *
 * Created on 28 de Fevereiro de 2017, 16:45
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class FileManager {
public:
    static void leituraArquivo(string inputFilename,vector<double> *x, vector<double> *y);
    static int sizeFile(string filename);
private:
};

#endif /* FILEMANAGER_H */

