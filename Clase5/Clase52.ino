void setup()
{
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
}

void loop()
{
    int i, j;
    int tiempo = 1;
    int ciclo = 256;

    for (i = 0; i < ciclo; i++)
    {
        delay(tiempo);
        analogWrite(3, i);
        analogWrite(5, ciclo - i);
    }

    for (j = ciclo; j > 0; j--)
    {
        delay(tiempo);
        analogWrite(3, j);
        analogWrite(5, ciclo - j);
    }
}