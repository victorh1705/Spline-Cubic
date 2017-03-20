/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template inputFile, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileManager.cpp
 * Author: Usuario
 * 
 * Created on 28 de Fevereiro de 2017, 16:45
 */

#include <math.h>

#include "FileManager.h"

void FileManager::leituraArquivo(string inputFilename,vector<double> *x, vector<double> *y) {
    
    string line;
    unsigned int size = sizeFile(inputFilename);
    fstream inputFile(inputFilename.c_str());
    cout << size << endl;
    x->resize(size);
    y->resize(size);

    if (!inputFile) {
      //erro durante leitura
    }
    
    while ( !inputFile.eof() ) {
      
        getline(inputFile, line);
        char* pEnd;
        double auxDouble  = strtod(line.c_str(), &pEnd);
        
        char * writable = new char[line.size() + 1];
        copy(line.begin(), line.end(), writable);
        writable[line.size()] = '\0';
        
        char* testeString = strtok( writable ," ");        
        auxDouble = strtod( testeString, &pEnd);
//        x->push_back( auxDouble );
        cout << "x-" << auxDouble;
        
        testeString = strtok( pEnd ,NULL);
        auxDouble = strtod( testeString, &pEnd);
//        y->push_back( auxDouble );
        cout << " y-" << auxDouble<< endl;
    }
    
    inputFile.close();
}

int FileManager::sizeFile(string filename) {
    
    fstream inputFile(filename.c_str());
    int lenght = 0;
    string line;
    
    while ( getline(inputFile,line) ){
       lenght++;
    }
    
    inputFile.close();
    return lenght;
}
