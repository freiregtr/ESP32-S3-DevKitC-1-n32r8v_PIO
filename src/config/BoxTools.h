#ifndef BOXTOOLS_H
#define BOXTOOLS_H

#include <Arduino.h>
#include "FS.h"
#include "SPIFFS.h"

class BoxTools {
public:
    BoxTools(); // Constructor
    ~BoxTools(); // Destructor
 
    // Método para inicializar y verificar PSRAM
    static void initializePsram();       
    static void checkPsram(); 
    void checkHeap();
    // Método para obtener el tamaño total de PSRAM
    static size_t getPsramSize();        
    // Método para obtener la cantidad de PSRAM libre
    static size_t getFreePsram();
    // Método para obtener la cantidad de heap libre
    static size_t getFreeHeap();         
    void calculateSPIFFS();
    // Obtener el tamaño total de la memoria flash
    void getTotalFlashSpace();
};

#endif // BOXTOOLS_H