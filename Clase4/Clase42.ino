/** 2do Arduino */
/** Decodificado en Haming en Paridad Par */

/** Se declaran las variables a nivel global */
int P1,P2,D1,P3,D2,D3,D4;

void setup()
{
  /** Configuracion de baudios del puerto serie */
  Serial.begin(9600);
  /** Configuracion de salidas digitales */
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
}

void loop()
{
  /** Se leen los valores recibidos en cada pin */
  P1 = digitalRead(2);
  P2 = digitalRead(3);
  D1 = digitalRead(4);
  P3 = digitalRead(5);
  D2 = digitalRead(6);
  D3 = digitalRead(7);
  D4 = digitalRead(8);
  
  /** Se calcula la decodificacion en Hamming paridad par */
  int b1, b2, b3;
  int suma1 = P3 + D2 + D3 + D4;
  int suma2 = P2 + D1 + D3 + D4;
  int suma3 = P1 + D1 + D2 + D4;
  
  /** Validacion par para decodificar Hamming en paridad par */
  if (suma1%2 == 0)
  {
    b1 = 0;
  }
  else
  {
    b1 = 1;
  }
  
  if (suma2%2 == 0)
  {
    b2 = 0;
  }
  else
  {
    b2 = 1;
  }
  
  if (suma3%2 == 0)
  {
    b3 = 0;
  }
  else
  {
    b3 = 1;
  }
  
  /** Correccion de paridad par con Hamming */
  if (b1 == 0 && b2 == 1 && b3 == 1)
  {
    D1 = 1 - D1;
  }
  
  if (b1 == 1 && b2 == 0 && b3 == 1)
  {
    D2 = 1 - D2;
  }
  
  if (b1 == 1 && b2 == 1 && b3 == 0)
  {
    D3 = 1 - D3;
  }
  
  if (b1 == 1 && b2 == 1 && b3 == 1)
  {
    D4 = 1 - D4;
  }
  
  /** Al monitor serie */
  Serial.print("2do Arduino: ");
  Serial.print(D1);
  Serial.print(D2);
  Serial.print(D3);
  Serial.println(D4);
}