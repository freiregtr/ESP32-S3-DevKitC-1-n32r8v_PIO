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
  boxTools.initializePsram();  // Inicializar y verificar PSRAM
  boxTools.checkPsram();       // Comprobar el tamaño de la PSRAM y cuánta está libre
  boxTools.checkHeap();        // Comprobar cuánta memoria heap está disponible
  boxTools.calculateSPIFFS();
  boxTools.getTotalFlashSpace();
  
}

void loop() {
  
  // put your main code here, to run repeatedly:
}

