#include "radio.h"

void Radio_start() {
  const byte rxAddr[6] = "00001";
  
  radio.begin();
  radio.openReadingPipe(0, rxAddr);
  radio.setChannel(120);   // выбираем канал (в котором нет шумов!)
  
  radio.setPALevel (RF24_PA_MAX); //уровень мощности передатчика. На выбор RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate (RF24_250KBPS); //скорость обмена. На выбор RF24_2MBPS, RF24_1MBPS, RF24_250KBPS
  
  radio.startListening();
}

