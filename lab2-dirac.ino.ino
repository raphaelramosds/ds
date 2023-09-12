// C++ code
//
void setup()
{
  DDRH = 0x20; 
}

void loop()
{
  PORTH = 0x20;
  PORTH = 0x0;
  delay(5);
}