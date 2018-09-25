#include <LiquidCrystal.h>

int rs=8, en=9, d4=4, d5=5, d6=6, d7=7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float tempObjetivo = 24.0;
int umbral;

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A5, INPUT);
  pinMode(A4, OUTPUT);
}

void loop()
{
  int valor;
  char tecla[10];
  float temp = temperatura(analogRead(A5));
    
  valor = leerBoton();
  
  mostrarLCD(valor, temp);
  
  alarma(temp);
}

int leerBoton()
{
  int valorAux = analogRead(A0);
  int rango = -1;
  
  if(valorAux>=0 && valorAux<145-50)
    rango=0;
  if(valorAux>145-50 && valorAux<145+50)
    rango=1;
  if(valorAux>329-50 && valorAux<329+50)
    rango=2;
  if(valorAux>505-50 && valorAux<505+50)
    rango=3;
  if(valorAux>741-50 && valorAux<741+50)
    rango=4;
  
  //Serial.println(valorAux);
    
  return rango;
}

void mostrarLCD(int valor, float temperatura)
{
  lcd.setCursor(0, 0);
  lcd.print("SET: ");
  lcd.print(tempObjetivo);
  lcd.print(" (");
  lcd.print(umbral);
  lcd.print(")   ");

  //delay(10);
  
  switch(valor)
  {
    case 0:
      //lcd.print("RIGHT");
      umbral++;
      break;
    case 1:
      //lcd.print("UP");
      tempObjetivo+=0.5;
      break;
    case 2:
      //lcd.print("DOWN");
      tempObjetivo-=0.5;
      break;
    case 3:
      //lcd.print("LEFT");
      if(umbral>0)
        umbral--;
      break;
    //case 4:
      //lcd.print("SELECT");
      //break;
  }
  
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print(" C   ");  
}

float temperatura(int lectura)
{
  float tempCelcius = (5.0 * lectura * 100.0)/1024.0;

  delay(500);

  Serial.println(tempCelcius);
  
  return tempCelcius;
}

void alarma(float temperatura)
{
  if(temperatura>(tempObjetivo+umbral))
  {
    delay(500);
    digitalWrite(A4, LOW);
    delay(500);
    tone(A4, 2400);
  }
  else if(temperatura<(tempObjetivo-umbral))
  {
    digitalWrite(A4, LOW);
  }
}
