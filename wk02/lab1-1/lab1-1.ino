void setup()
{
 
  DDRD = 0b11111111;
  DDRB = 0b11111111;
  
}

void loop()
{
  for(int i=0;i<4;i++)
  {
    PORTB = 0b00001000 >> i;
    delay (500);
  }
  PORTB=0b00000000;
  for(int i=0;i<4;i++)
  {
    PORTD = 0b10000000 >> i;
    delay (500);
  }
  PORTD=0b00000000;
}
