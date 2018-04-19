/** 1er Arduino */
/** Codificado en Haming en Paridad Par */

/** Se declaran las variables a nivel global */
int D1=1,D2=1,D3=1,D4=0;
int P1,P2,P3;

void setup()
{
  /** Configuracion de baudios del puerto serie */
  Serial.begin(9600);
  /** Configuracion de salidas digitales */
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  //Serial.println("Hola");
  int suma1 = D1 + D2 + D4;
  if (suma1%2 == 0)
  {
    P1 = 0;
  }
  else
  {
    P1 = 1;
  }
  
  int suma2 = D1 + D3 + D4;
  if (suma2%2 == 0)
  {
    P2 = 0;
  }
  else
  {
    P2 = 1;
  }
  
  int suma3 = D2 + D3 + D4;
  if (suma3%2 == 0)
  {
    P3 = 0;
  }
  else
  {
    P3 = 1;
  }
  
  /** Envio de informacion a las salidas digitales */
  digitalWrite(2, P1);
  digitalWrite(3, P2);
  digitalWrite(4, D1);
  digitalWrite(5, P3);
  digitalWrite(6, D2);
  digitalWrite(7, D3);
  digitalWrite(8, D4);
  
  
  /** Al monitor serie */
  Serial.print("1er Arduino: ");
  Serial.print(P1);
  Serial.print(P2);
  Serial.print(D1);
  Serial.print(P3);
  Serial.print(D2);
  Serial.print(D3);
  Serial.println(D4);
}