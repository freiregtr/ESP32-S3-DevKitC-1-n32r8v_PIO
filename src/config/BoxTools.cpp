#include "BoxTools.h"

BoxTools::BoxTools() {
    // Constructor
}

BoxTools::~BoxTools() {
    // Destructor
}

void BoxTools::initializePsram() {
    Serial.println("BoxTools.cpp: Inicializando PSRAM...");
    if (psramFound()) {
        Serial.println("BoxTools.cpp: PSRAM encontrada y accesible.");
    } else {
        Serial.println("BoxTools.cpp: PSRAM no encontrada.");
    }
}

void BoxTools::checkPsram() {
    Serial.println("BoxTools.cpp: Inicializando PSRAM...");
    if (psramFound()) {
        Serial.println("BoxTools.cpp: PSRAM encontrada y accesible.");
        size_t psramSize = ESP.getPsramSize();
        size_t freePsram = ESP.getFreePsram();
        Serial.printf("BoxTools.cpp: Tamaño de PSRAM: %.2f MB\n", psramSize / 1048576.0);
        Serial.printf("BoxTools.cpp: PSRAM libre: %.2f MB\n", freePsram / 1048576.0);
    } else {
        Serial.println("BoxTools.cpp: PSRAM no encontrada.");
    }
}

void BoxTools::calculateSPIFFS(){
    // Obtener el tamaño total y el tamaño utilizado de la partición SPIFFS
    unsigned int totalBytes = SPIFFS.totalBytes();
    unsigned int usedBytes = SPIFFS.usedBytes();

    // Calcular el espacio libre
    unsigned int freeBytes = totalBytes - usedBytes;

    Serial.print("BoxTools.cpp: Total de espacio en SPIFFS: ");
    Serial.print(totalBytes / 1048576.0, 2); // Convertir a MB
    Serial.println(" MB");

    Serial.print("BoxTools.cpp: Espacio usado en SPIFFS: ");
    Serial.print(usedBytes / 1048576.0, 2); // Convertir a MB
    Serial.println(" MB");

    Serial.print("BoxTools.cpp: Espacio libre en SPIFFS: ");
    Serial.print(freeBytes / 1048576.0, 2); // Convertir a MB
    Serial.println(" MB");
}

void BoxTools::checkHeap() {
    Serial.print("BoxTools.cpp: Memoria heap disponible antes de deserializar: ");
    Serial.println(ESP.getFreeHeap());
}

size_t BoxTools::getPsramSize() {
    if (psramFound()) {
        return ESP.getPsramSize();
    }
    return 0; // Si no hay PSRAM, retorna 0
}

size_t BoxTools::getFreePsram() {
    if (psramFound()) {
        return ESP.getFreePsram();
    }
    return 0; // Si no hay PSRAM, retorna 0
}

size_t BoxTools::getFreeHeap() {
    return ESP.getFreeHeap();
}

void BoxTools::getTotalFlashSpace(){
    unsigned int flashChipSize = ESP.getFlashChipSize();
  
    Serial.print("BoxTools.cpp: Tamaño total de la memoria flash: ");
    Serial.print(flashChipSize);
    Serial.println(" bytes");
  
    // Para mostrar el tamaño en MB, dividimos por 1024 dos veces
    float flashChipSizeMB = flashChipSize / 1024.0 / 1024.0;
    Serial.print("BoxTools.cpp: En megabytes: ");
    Serial.print(flashChipSizeMB);
    Serial.println(" MB");
}
