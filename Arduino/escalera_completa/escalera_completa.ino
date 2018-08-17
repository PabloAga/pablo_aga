const int M1 = 1; // Pulsadores
const int M2 = 2;
const int M3= 3;

const int R1= 4;  //Infrarrojo 1
const int R2= 5;  //Infrarrojo 2

const int La= 6; //Leds
const int Lb= 7;
const int Lc= 8;
const int Ld= 9;
const int Le= 10;
int x=0;
int y=0;
int z=0;
int u=0;

unsigned long tiempo1 = 0; 
unsigned long tiempo2 = 0;
unsigned long tiempo3 = 0;
unsigned long tiempo4 = 0;
unsigned long tiempo5 = 0;
unsigned long diferenciaTiempo = 0;
unsigned long diferenciaTiempo2 = 0;
unsigned long diferenciaTiempo3 = 0;
unsigned long diferenciaTiempo4 = 0;
unsigned long t = 0;
unsigned long w = 0;


void setup() {

  pinMode(M1, INPUT);  //DEFINO PINES DE ENTRADAS Y SALIDAS
  pinMode(M2, INPUT);  
  pinMode(M3, INPUT); 

  pinMode(R1, INPUT); 
  pinMode(R2, INPUT); 

  pinMode(La, OUTPUT); 
  pinMode(Lb, OUTPUT); 
  pinMode(Lc, OUTPUT); 
  pinMode(Ld, OUTPUT); 
  pinMode(Le, OUTPUT); 

  digitalWrite(La , LOW);
  digitalWrite(Lb , LOW);
  digitalWrite(Lc , LOW);
  digitalWrite(Ld , LOW);
  digitalWrite(Le , LOW);

  
}
void loop()  
{
  digitalWrite(M1 ,HIGH); //INICIALIZO LAS ENTRADAS 
  digitalWrite(M2 ,HIGH);
  digitalWrite(M3 ,HIGH);
  delay(150);


  int value= digitalRead(M1); //LEO EL VALOR DEL PULSADOR 1
    if(value == LOW)//CONDICION SI SE toca EL PULSADOR 1
     {delay(200);
      tiempo1 = millis();  //TOMA EL TIEMPO DESDE QUE SE ENCENDIO EL ARDUINO 
      while(x<150)
      {
        digitalWrite(La , HIGH); //ENCIENDE EL LED1
        digitalWrite(Lb , HIGH); //ENCIENDE EL LED2
        int value2= digitalRead(R1);  //LEO EL VALOR DEL PIR 1
        if(  value2==HIGH) //condicion si toma el infrarrojo
        { 
          tiempo2 = millis();
          diferenciaTiempo = tiempo2-tiempo1; //GUARDA LA DIFERENCIA ENTRE EL TIEMPO1 Y TIEMPO2 en milisegundos 
          digitalWrite(Lc ,HIGH); //ENCIENDE EL LED3
          digitalWrite(La ,LOW);   //APAGA EL LED1

            while(t<=diferenciaTiempo)
            {
              if(digitalRead(R2) == HIGH)// SI La persona llega al IR 2
                {  
                  tiempo3 = millis();
                  digitalWrite(Ld ,HIGH); //ENCIENDE EL LED d
                  digitalWrite(Lb ,LOW); //APAGA EL LED b
                  diferenciaTiempo4 = (tiempo3-tiempo2)/2; //GUARDA LA DIFERENCIA ENTRE EL TIEMPO2 Y TIEMPO3 en milisegundos y guarda la mitad
                  digitalWrite(Le , HIGH); //ENCIENDE EL LED e
                  digitalWrite(Lc ,LOW); //APAGA EL LED c
                  delay(diferenciaTiempo4); //Tiempo para salir por la puerta del 2do piso
                  digitalWrite(Ld , LOW);//APAGA EL LED d
                  digitalWrite(Le ,LOW); //APAGA EL LED e
                  y=1;
                }
              delay(1);
              t=t+1;
 /*>=POR== */  if(y==1){ //CONDICION PARA EL CASO QUE DETECTO EL PIR2 SALGA DEL BUCLE DEL RETARDO DEL PIR1
                  t=(diferenciaTiempo)+1;
                  u=1;//CONDICION PARA NO ENTRAR
                  y=0;
                 }
            }
              if(u<1)
              {
                digitalWrite(Ld , HIGH); //ENCIENDE EL LED4
                digitalWrite(Lb ,LOW); //APAGA EL LED2
                while(w<=diferenciaTiempo)
                  {
                    int value3= digitalRead(R2);
                    if(value3==HIGH)
                      {
                        tiempo3 = millis();
                        diferenciaTiempo4 = (tiempo3-tiempo2)/2; //GUARDA LA DIFERENCIA ENTRE EL TIEMPO2 Y TIEMPO3 en milisegundos y guarda la mitad
                        digitalWrite(Le , HIGH); //ENCIENDE EL LED5
                        digitalWrite(Lc ,LOW); //APAGA EL LED3
                        delay(diferenciaTiempo4);
                        digitalWrite(Ld , LOW);//APAGA EL LED4
                        digitalWrite(Le ,LOW); //APAGA EL LED5
                        y=1;
                      }
                    delay(1);
                    w=w+1;
                    if(y>=1)
                      {
                         w=diferenciaTiempo+1;
                         y=0;                  //  Ver esto
                      }
                  }
                digitalWrite(Lc , LOW); //Apaga EL LED3  en el caso que la persona haya salido por la puerta2
                digitalWrite(Ld , LOW); //APAGA EL LED4

              }
            x=149;
         }
       delay(100);
       x++;
      }
    }else{
        digitalWrite(La , LOW); //APAGA EL LED1
        digitalWrite(Lb , LOW); //APAGA EL LED2
      }


 //PULSADOR2
digitalWrite(M2 ,HIGH);
delay(200);

int valuen= digitalRead(M2);
   if(valuen == LOW)//CONDICION SI SE APRETO EL PULSADOR 1
  {delay(200);
  tiempo1 = millis();  //TOMA EL TIEMPO DESDE QUE SE ENCENDIO EL ARDUINO 
  while(x<150)
    {
      digitalWrite(Lc , HIGH); //ENCIENDE EL LED1
      digitalWrite(Ld , HIGH); //ENCIENDE EL LED2
      digitalWrite(Lb , HIGH); //ENCIENDE EL LED2
      int valuen2= digitalRead(R2);
     if(  valuen2==HIGH)//condicion si toma el infrarrojo
     { 
        tiempo2 = millis();
        diferenciaTiempo = tiempo2-tiempo1; //GUARDA LA DIFERENCIA ENTRE EL TIEMPO1 Y TIEMPO2 en milisegundos 
        digitalWrite(Lb , LOW); //ENCIENDE EL LED2
        digitalWrite(Le , HIGH); //ENCIENDE EL LED3
        digitalWrite(Lc ,LOW); //APAGA EL LED1
        delay(diferenciaTiempo);
               digitalWrite(Ld , LOW);//APAGA EL LED4
               digitalWrite(Le ,LOW); //APAGA EL LED5
               x=149;
     } 
     //CASO QUE DESCIENDA POR ESCALERA
      int valuen3= digitalRead(R1);
     if( valuen3==HIGH)//condicion si toma el infrarrojo
     { 
        tiempo2 = millis();
        diferenciaTiempo = tiempo2-tiempo1; //GUARDA LA DIFERENCIA ENTRE EL TIEMPO1 Y TIEMPO2 en milisegundos 
        digitalWrite(Ld , LOW); //ENCIENDE EL LED D
        digitalWrite(La , HIGH); //ENCIENDE EL LED A
        digitalWrite(Lc ,LOW); //APAGA EL LED C
        delay(diferenciaTiempo);
               digitalWrite(Lb , LOW);//APAGA EL LED B
               digitalWrite(La ,LOW); //APAGA EL LED A
               x=149;
     }
      delay(100);
    x++;
   
}
digitalWrite(Lc , LOW); //APAGA EL LED C
   digitalWrite(Ld , LOW); //APAGA EL LED D
   digitalWrite(Lb , LOW); //ENCIENDE EL LED B2
   
  }
  else{
    digitalWrite(Lc , LOW); //APAGA EL LED C
   digitalWrite(Ld , LOW); //APAGA EL LED D
   digitalWrite(Lb , LOW); //ENCIENDE EL LED B
  }
  
//PULSADOR3
//delay(100);
  int valuel= digitalRead(M3);
   if(valuel == LOW)//CONDICION SI SE APRETO EL PULSADOR 1
  {delay(200);
   tiempo1 = millis();  //TOMA EL TIEMPO DESDE QUE SE ENCENDIO EL ARDUINO 
    while(x<150)
    {
      digitalWrite(Le , HIGH); //ENCIENDE EL LED1
      digitalWrite(Ld , HIGH); //ENCIENDE EL LED2
      int valuel2= digitalRead(R2);
     if(  valuel2==HIGH)//condicion si toma el infrarrojo
     { 
        tiempo2 = millis();
        diferenciaTiempo = tiempo2-tiempo1; //GUARDA LA DIFERENCIA ENTRE EL TIEMPO1 Y TIEMPO2 en milisegundos y lo duplica
        diferenciaTiempo2 = tiempo2-tiempo1; // tiempo al 75%
        diferenciaTiempo3=tiempo2-tiempo1; //tiempo para que se apague led3
        digitalWrite(Lc , HIGH); //ENCIENDE EL LED3
        digitalWrite(Le ,LOW); //APAGA EL LED1

        while(t<=diferenciaTiempo2)
         {
          int valuel3= digitalRead(R1);
           if(valuel3 == HIGH){
               tiempo3 = millis();
               digitalWrite(Lb , HIGH); //ENCIENDE EL LED4
               digitalWrite(Ld ,LOW); //APAGA EL LED2
               diferenciaTiempo4 = (tiempo3-tiempo2)/2; //GUARDA LA DIFERENCIA ENTRE EL TIEMPO2 Y TIEMPO3 en milisegundos y guarda la mitad
               digitalWrite(La , HIGH); //ENCIENDE EL LED5
               digitalWrite(Lc ,LOW); //APAGA EL LED3
               delay(diferenciaTiempo4);
               digitalWrite(Lb , LOW);//APAGA EL LED4
               digitalWrite(La ,LOW); //APAGA EL LED5
              y=1;
            }
            delay(1);
          t=t+1;
            if(y>=1){
              t=diferenciaTiempo2+1;
               u=1;
              y=0;
            }
        }
        if(u<1)
        {
      
         
            while(w<=diferenciaTiempo3)
          { 
            
            digitalWrite(Lb , HIGH); //ENCIENDE EL LED4
          digitalWrite(Ld ,LOW); //APAGA EL LED2
            int valuel4= digitalRead(R1);
            if(valuel4==HIGH)
            {
              tiempo3 = millis();
               diferenciaTiempo4 = (tiempo3-tiempo2)/2; //GUARDA LA DIFERENCIA ENTRE EL TIEMPO2 Y TIEMPO3 en milisegundos y guarda la mitad
              digitalWrite(La , HIGH); //ENCIENDE EL LED5
              digitalWrite(Lc ,LOW); //APAGA EL LED3
              delay(diferenciaTiempo4);
              digitalWrite(Lb , LOW);//APAGA EL LED4
              digitalWrite(La ,LOW); //APAGA EL LED5
              y=1;
           
            }
            delay(1);
            w=w+1;
             if(y>=1){
              w=diferenciaTiempo3+1;
              y=0;
              }
              
          }
        digitalWrite(Lc , LOW); //Apaga EL LED3  en el caso que la persona halla salido por la puerta2
        digitalWrite(Lb , LOW);//APAGA EL LED4

     }
    x=149;
    }
    delay(100);
    x++;
    }
  }else{
   digitalWrite(Le , LOW); //APAGA EL LED1
   digitalWrite(Ld , LOW); //APAGA EL LED2
  }
  x=0;
  u=0;
  t=0;
  w=0;
  delay(100);
 //infrarrojo 1
  int pir1= digitalRead(R1); //LEO EL VALOR DEL PIR1
   if(pir1 == HIGH){//CONDICION SI RECONOCE MOVIMIENTO PIR1
   delay(200);
   tiempo1 = millis();  //TOMA EL TIEMPO DESDE QUE SE ENCENDIO EL ARDUINO 
   while(x<150)
    {
      digitalWrite(La , HIGH); //ENCIENDE EL LED1
      digitalWrite(Lb , HIGH); //ENCIENDE EL LED2
      digitalWrite(Lc ,HIGH); //ENCIENDE EL LED3
      digitalWrite(Ld ,HIGH); //ENCIENDE EL LED4
      int pir2= digitalRead(R2);
            if(pir2 == HIGH)
            {
              tiempo2 = millis();
              diferenciaTiempo = (tiempo2-tiempo1)/2; //GUARDA LA DIFERENCIA ENTRE EL TIEMPO2 Y TIEMPO3 en milisegundos y guarda la mitad
              digitalWrite(Le , HIGH); //ENCIENDE EL LED5
              digitalWrite(La ,LOW); //APAGA EL LED1
              digitalWrite(Lb ,LOW); //APAGA EL LED2
              delay(diferenciaTiempo);
              digitalWrite(Lc , LOW);//APAGA EL LED3
              digitalWrite(Ld , LOW);//APAGA EL LED4
              digitalWrite(Le ,LOW); //APAGA EL LED5
              x=149;
              y=1;
             }
       delay(100);
       x++;
    }
      if(y!=1){
        digitalWrite(La ,LOW); //APAGA EL LED1  en el caso que la persona haya salido por la puerta2
        digitalWrite(Lb , LOW); //Apaga EL LED2 
        digitalWrite(Lc , LOW); //Apaga EL LED3
        digitalWrite(Ld , LOW); //APAGA EL LED4
        y=0;
      }

  }
   //infrarrojo2
  int pir2= digitalRead(R2); //LEO EL VALOR DEL PIR2
   if(pir2 == HIGH){//CONDICION SI RECONOCE MOVIMIENTO PIR1
      digitalWrite(Lc ,HIGH); //ENCIENDE EL LED3
      digitalWrite(Ld ,HIGH); //ENCIENDE EL LED4
      digitalWrite(Le , HIGH); //ENCIENDE EL LED5
      delay(7000); //RETARDO 7 SEGUNDOS
      digitalWrite(Lc , LOW);//APAGA EL LED3
      digitalWrite(Ld , LOW);//APAGA EL LED4
      digitalWrite(Le ,LOW); //APAGA EL LED5
    }
}
