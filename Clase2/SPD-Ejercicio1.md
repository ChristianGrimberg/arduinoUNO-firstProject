## Números negativos en binario
1. Expresar en los tres formatos: signo-magnitud, Ca1 y Ca2:

Número decimal | Signo Magnitud | Complemento a 1 (Magnitud) | Complemento a 2 (Magnitud)
------------ | ------------- | ------------- | -------------
__-47__ | 10101111 | 11010000 | 11010001
__-110__ | 11101110 | 10010001 | 10010010
__-68__ | 11000100 | 10111011 | 10111100

2. Completar el cuadro:

Número decimal | Signo Magnitud | Complemento a 1 (Magnitud) | Complemento a 2 (Magnitud)
------------ | ------------- | ------------- | -------------
-7 | __10000111__ | 11111000 | 11111001
-99 | 11100011 | __10011100__ | 10011101 
-100 | 11100100 | 10011011 | __10011100__

3. Suma de números con signo (8 bits):

Número | Operación | Resolución
------------ | ------------- | -------------
1 | __01111110 + 01001110__ | 01111110 + 01001110 = __1__ 1001100 con bit de signo incorrecto, por lo tanto es __overflow__: en decimales es 126 + 78, y el resultado de complemento a 2 convertido a decimales es -75.
2 | __01111110 + 00000001__ | 01111110 + 00000001 = 01111111, la suma de 126 + 1 es correcta teniendo en cuenta que el bit de signo es correcto, y su valor es 127 siendo el máximo valor entero en 8 bits con signo.
3 | __00010100 + 11111000__ | 00010100 + 11111000 = _1_ 00001100, se descarta último acarreo, siendo la suma en decimales de 20 + (-8) debido a que este último está denotado en Complemento a 2.
4 | __00010010 + 11100111__ | 00010010 + 11100111 = 11111001, donde el resultado en Complemento a 2 es -7 de la suma de 18 + (-25), estando el segundo operando también en Complemento a 2.
5 | __11100111 + 11110110__ | 11100111 + 11110110 = _1_ 11011101, se descarta último acarreo, siendo la suma de ambos operando en Complemento a 2 de (-25) + (-10) = (-35) también en Complemento a 2. 
6 | __10001000 + 10110000__ | 10001000 + 10110000 = _1_ 00111000 con bit de signo incorrecto por ser la suma de dos numeros en Complemento a 2, el cual debería contar con bit de signo negativo. Se descarta además el último acarreo, y la suma de (-120) + (-80) = (-72) ya que sobrepasa los enteros negativos de 8 bits con signo (-128), siendo entonces un __underflow__.