#include <Arduino.h>
#include "config/BoxTools.h"
#include "FS.h"
#include "SPIFFS.h"

// Crear una instancia de BoxTools
BoxTools boxTools;

void setup() {
  Serial.begin(115200); // Inicializar Serial
  while (!Serial); // Esperar a que el puerto serial esté listo

  // inicializacion del sistema SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("No se pudo montar el sistema de archivos SPIFFS");
    return;
  }

  // Llamar a los métodos de la instancia de BoxTools
  boxTools.initializePsram();  
  boxTools.checkPsram(); 
  boxTools.checkHeap();
  boxTools.calculateSPIFFS();
  boxTools.getTotalFlashSpace();
  
}

void loop() {
  
  // codigo de ejemplo
}

