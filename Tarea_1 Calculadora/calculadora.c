#include <16F877a.h>
#device ADC = 10
#use delay(crystal = 20000000)
#FUSES NOWDT, NOBROWNOUT, NOLVP

//Directiva para utilizar puerto USART
#use rs232(BAUD=9600, XMIT = PIN_C6, RCV=PIN_C7)

int8 restar(int8 a, int8 b)
{
   int8 resultado = a - b;
    int8 resultado = a + b;
   return resultado;
}

void main()
{
   setup_uart(9600); //Configurar baudios
   
   printf("Hola mundo\n\r");
   
   int8 num1 = 5;
   int8 num2 = 3;
   int8 res;
   int8 res2;
   
   res = num1 - num2;
   res2 = num1 + num2;
   
   printf("%u - %u: %u\n\r",num1,num2,res); 
   printf("%u + %u: %u\n\r",num1,num2,res2);
   while (1)
    {
    
    }
}
