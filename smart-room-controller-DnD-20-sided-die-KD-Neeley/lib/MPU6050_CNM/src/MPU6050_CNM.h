#ifndef _MPU6050_CNM_H_
#define _MPU6050_CNM_H_

#include <math.h>

// Declare variables

const byte AX_ADDR = 0x3B;
const byte AY_ADDR = AX_ADDR + 0x02;
const byte AZ_ADDR = AX_ADDR + 0x04;
float _scaleFactor;

// Declare Functions with defaults
float mpuBegin(byte addr, byte fullscale = 0); 
float setFS(byte addr, byte fullscale = 0);
float get16(byte addr, byte reg);
void getAccArray(byte addr, float *accelArray);


// Start I2C bus, wake-up MPU, set Full Scale, returns float scaleFactor
float mpuBegin(byte addr, byte fullscale) {
  float scaleFactor;

  Wire.begin();  
  Wire.beginTransmission(addr); 
  Wire.write(0x6B);
  Wire.write(0x00); // set to 0 (wakes up MPU-6050)
  Wire.endTransmission(true);

  scaleFactor = setFS(addr, fullscale);
  _scaleFactor = scaleFactor;
  return scaleFactor;
}

// Set Full Scale of MPU
float setFS(byte addr, byte fullscale) {
  float scaling;

  Wire.begin();  
  Wire.beginTransmission(addr); 
  Wire.write(0x1C);
  Wire.write(fullscale << 3); 
  Wire.endTransmission(true);

  scaling = 1 / (16384.0 / pow(2,fullscale));
  Serial.printf("Scaling Factor is: %0.8f\n",scaling);
  return scaling;
}


// Return signed 16 bit number from big endian registers
float get16(byte addr, byte reg) {
  byte msb, lsb;
  int16_t value16;

  Wire.beginTransmission(addr);
  Wire.write(reg); 
  Wire.endTransmission(false); // keep active.

  Wire.requestFrom(addr, 2, true);
  msb = Wire.read(); 
  lsb = Wire.read(); 

  value16 = msb << 8 | lsb;
  //Serial.printf("MSB = %02X, LSB = %02X, Value = %04X (%i)\n",msb, lsb, value16, value16);

  return value16;

}


void getAccArray(byte addr, float *accelArray) {
    accelArray[0] = get16(addr,AX_ADDR)*_scaleFactor;
    accelArray[1] = get16(addr,AY_ADDR)*_scaleFactor;
    accelArray[2] = get16(addr,AZ_ADDR)*_scaleFactor;
}


#endif // _MPU6050_CNM_H_
