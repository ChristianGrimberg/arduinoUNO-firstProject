void setup()
{
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int valor;
  valor = analogRead(A0);
  //valor = analogToLed(valor);
  valor = map(valor, 0, 1023, 0, 255);
  Serial.println(valor);
  analogWrite(6, valor); 
}

int analogToLed(int valor)
{
  return valor/4;
}
