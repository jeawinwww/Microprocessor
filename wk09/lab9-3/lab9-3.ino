#include <SPI.h>
bool toggle;
volatile int timer1 = 3200;
int clk_pin = 13; //SHCP 
int ss_pin = 10; //STCP 
int data_pin = 11; //DS 
int map7seg[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int i = 1;

void setup()
{
  noInterrupts(); 
  TCCR1A = 0;
  TCCR1B = 0; 
  TCNT1 = timer1;
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << TOIE1);
  interrupts();
  pinMode(clk_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);
  pinMode(ss_pin, OUTPUT);
}

void loop(){
}

ISR(TIMER1_OVF_vect)
{
  TCNT1 = timer1;
  spi_write1(map7seg[i]);
  i++; 
  if(i>9)
    i = 0;
}

void spi_write1(unsigned char cData)
{
  shiftOut(data_pin, clk_pin, MSBFIRST, cData);
  digitalWrite(ss_pin, HIGH);
  digitalWrite(ss_pin, LOW);
}
