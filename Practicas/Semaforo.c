#include <16F877a.h>
#device ADC=10
#use delay(crystal=20000000)
#FUSES NOWDT, NOBROWNOUT, NOLVP

#USE STANDARD_IO(B)
#USE STANDARD_IO(C)

int8 num[3] = {
0b00000000,
0b00000001,
0b00000010,
};
               
int GREEN = 0;
int RED = 0;

Void main(){

port_b_pullups(true);

   while (true){
   
      for(int GREEN = 0; GREEN < 20 ; GREEN++){
         output_b(num[1]);
         delay_ms(100);
            if(input(PIN_C0)==1){   //si se presiona el boton, el led verde sale del for y se va a amarillo
            GREEN = 40;      
            //Encender el led verde por 5 segundos y apagarlo.
            //Si se presiona el botón durante la secuencia del led verde, este deberá de apagarse y continuar al parpadeo del led amarillo.
            }
          }
          
          For (int YELLOW = 0; YELLOW < 4; YELLOW++){    //genera 4 pulsos, uno cada 350ms
           output_b(num[2]); 
             delay_ms(350);
            output_low(PIN_B1);     //no hay instruccion de boton, por lo tanto no sucede nada
            delay_ms(350);
            //Encender el led verde por 5 segundos y apagarlo.
            //Si se presiona el botón durante el parpadeo del led amarillo no habrá reacción alguna y la secuencia seguirá su rutina normal.
          }
          
          for(int RED = 0; RED < 30; RED++){
             output_high(PIN_B2); 
             delay_ms(50);
               if(input(PIN_C1)==1){   //si se presiona el boton la cuenta se regresa a 0
                RED=0;
                //Encender el led rojo por 8 segundos y apagarlo.
                //Si se presiona el botón durante la secuencia del led rojo se volverá a empezar el conteo de los 8 segundos.
                }
               }
              }
  }
