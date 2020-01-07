/*Created by David Cruz Ramírez*/

#include <SoftwareSerial.h>
#include <String.h>

SoftwareSerial mySerial(11,10);

#define MOTORD_AIN1    7
#define MOTORD_AIN2  8
#define MOTORD_PWM    3

#define MOTORI_AIN1    10
#define MOTORI_AIN2  9
#define MOTORI_PWM    5

#define PUSH1       2
#define PUSH2     4
#define PUSH3     6

char Arreglo[50];
  int tope=0;
  int parte1, parte2, parte3, parte4, parte5, parte6, parte7;
  int parte8, parte9, parte10, parte11, parte12;

  int PWMI, PWMD;
  int ValPre1, ValPre2;
  int DIRI, DIRD;

  int rango=500;
  float factorMult=0.51;
  int division=204;

  /*int stop=0;
  int stop2=0;*/
  

void setup() {

pinMode(MOTORI_AIN1, OUTPUT);
pinMode(MOTORI_AIN2, OUTPUT);
pinMode(MOTORI_PWM, OUTPUT);

pinMode(MOTORD_AIN1, OUTPUT);
pinMode(MOTORD_AIN2, OUTPUT);
pinMode(MOTORD_PWM, OUTPUT);




 
 Serial.begin(4800); //57600
  while (!Serial) {
  }
  mySerial.begin(9600);//9600
  }

void loop() {
 if (mySerial.available()>0) {
  //Serial.write(mySerial.read());
 char lectura=mySerial.read();
 
 /*Created by David Cruz Ramírez*/
 if(lectura=='*'){
   tope=0;
 }else if(lectura=='#')
 {
         parte1= ((Arreglo[0]-48));
         parte2= ((Arreglo[1]-48));
         parte3= ((Arreglo[2]-48));
         parte4= ((Arreglo[3]-48));
         parte5= ((Arreglo[4]-48));
         parte6= ((Arreglo[5]-48));
         parte7= ((Arreglo[6]-48));
         parte8= ((Arreglo[7]-48));
         parte9= ((Arreglo[8]-48));
         parte10= ((Arreglo[9]-48));
    

        Serial.print(parte1);
        Serial.print(parte2);
        Serial.print(parte3);
        Serial.print(parte4);
        Serial.print(parte5);
        Serial.print(parte6);
        Serial.print(parte7);
        Serial.print(parte8);
        Serial.print(parte9);
        Serial.println(parte10);
       
/*Created by David Cruz Ramírez*/

          ValPre1= ((parte3*100)+(parte4*10)+(parte5)); //100 a 500
          ValPre2= ((parte8*100)+(parte9*10)+(parte10)); //100 a 500

  
          //FORMULA PWM 
         // =PRODUCTO((150-100)*(0.51)*(255/204))
          //((valorObtenido-ValorMinimo)*(valormaximopwm*(255/division))
         
          PWMI=((ValPre1-100)*(factorMult)*(255/division));
          PWMD=((ValPre2-100)*(factorMult)*(255/division));

          DIRI=parte1;
          DIRD=parte6;
 }else{
 Arreglo[tope++]=lectura;  
 }

  }
      //CASOS si stop y stop1=0 se movera, sino, se queda quieto
      //Dependiendo la direccion es hacia el sentido
     
    /* if(stop=1){
       //ADELANTE IZQUIERDO
     digitalWrite(MOTORI_AIN1, HIGH);
     digitalWrite(MOTORI_AIN2, LOW);
     analogWrite(MOTORI_PWM, 0);
       
     }

     if(stop2=1){
     //ADELANTE DERECHO
     digitalWrite(MOTORD_AIN1, HIGH);
     digitalWrite(MOTORD_AIN2, LOW);
     analogWrite(MOTORD_PWM, 0); 
     }*/


     if(DIRI==0){
        //ADELANTE IZQUIERDO
     digitalWrite(MOTORI_AIN1, HIGH);
     digitalWrite(MOTORI_AIN2, LOW);
     analogWrite(MOTORI_PWM, PWMI);
     }else if(DIRI==1){
         //ADELANTE IZQUIERDO
     digitalWrite(MOTORI_AIN1, LOW);
     digitalWrite(MOTORI_AIN2, HIGH);
     analogWrite(MOTORI_PWM, PWMI);
     }

     if(DIRD==0){
        //ADELANTE IZQUIERDO
     digitalWrite(MOTORD_AIN1, HIGH);
     digitalWrite(MOTORD_AIN2, LOW);
     analogWrite(MOTORD_PWM, PWMD);
     }else if(DIRD==1){
         //ADELANTE IZQUIERDO
     digitalWrite(MOTORD_AIN1, LOW);
     digitalWrite(MOTORD_AIN2, HIGH);
     analogWrite(MOTORD_PWM, PWMD);
     }


   



}

/*Created by David Cruz Ramírez*/

/*Created by David Cruz Ramírez*/
