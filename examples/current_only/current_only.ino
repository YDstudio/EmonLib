// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3

#include "EmonLib.h"                   // Include Emon Library
Adafruit_MCP3008 mcp3008;
EnergyMonitor emon1;                   // Create an instance

void setup() {
  Serial.begin(9600);
  mcp3008.begin();
  emon1.setMCP3008(&mcp3008);
  emon1.current(1, 111.1);             // Current: input pin, calibration.
}

void loop() {
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  Serial.print(Irms*230.0);            // Apparent power
  Serial.print(" ");
  Serial.println(Irms);                // Irms
}
