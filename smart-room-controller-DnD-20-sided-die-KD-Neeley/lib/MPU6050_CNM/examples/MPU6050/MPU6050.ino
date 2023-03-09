/*
 * Project MPU6050
 * Description: Functastic Way to Engage with MPU6050
 * Author: Brian Rashap
 * Date: 08-MAR-2023
 */

#include "MPU6050_CNM.h"

const byte MPU_ADDR = 0x68;
const byte AX_ADDR = 0x3B;
const byte AY_ADDR = AX_ADDR + 0x02;
const byte AZ_ADDR = AX_ADDR + 0x04;
const byte FS = 0;

// Declare variables     
float accelX, accelY, accelZ;
unsigned int currentTime, lastTime;
float scalingFactor;

// Uncomment for testing on Serial Monitor and not connected to Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected,5000);
  scalingFactor = mpuBegin(MPU_ADDR,FS);
}

void loop() {
  currentTime = millis();
  if (currentTime - lastTime > 2500) {
    accelX = get16(MPU_ADDR,AX_ADDR)*scalingFactor;
    accelY = get16(MPU_ADDR,AY_ADDR)*scalingFactor;
    accelZ = get16(MPU_ADDR,AZ_ADDR)*scalingFactor;
    Serial.printf("Acceleration Data (in G's): x = %0.3f, y = %0.3f, z = %0.3f\n", accelX, accelY, accelZ);
    lastTime = currentTime;
  }
}