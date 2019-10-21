//#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT.h>
#include <timer.h>
#include <Servo.h>
#include <Stepper.h>


void Activo_Alarma (void);
void Desactivo_Alarma (void);
bool ALARMA = false;


//Y CONTADORES PULSADORES PARA ILUMINACION//
char letra = 'a';
int CONT_H1 = 0;
int CONT_H2 = 0;
int CONT_H3 = 0;
int CONT_H4 = 0;
int CONT_H5 = 0;
int CONT_H6 = 0;
int CONT_H7 = 0;

#define PULSADOR_1 2
#define PULSADOR_2 3
#define PULSADOR_3 4
#define PULSADOR_4 5
#define PULSADOR_5 6
#define PULSADOR_6 7
#define PULSADOR_7 8
////////////////////////


//SALIDAS DE ILUMINACION//
#define HABITACION_1 53
#define HABITACION_2 51
#define HABITACION_3 49
#define HABITACION_4 47
#define HABITACION_5 45
#define HABITACION_6 43
#define HABITACION_7 41
//////////////////////////


//////////PUERTA Y ALGO MAS?////////////
#define SERVO_PUERTA_1 26
#define LDR_SENSOR  15
#define pin_sensor_hume 38
#define PULSADOR_PUERTA 33
#define SENSOR_PUERTA 35
#define SENSOR_CORTINA 13
//////////PUERTA Y ALGO MAS?////////////



//REFRIGERACION//
#define COOLER 52
#define ROJO 50
#define VERDE 48
//FIN REFRIGERACION//


////SENSOR PIR////
#define SENSOR_PIR 36
#define LED_PIR 23
#define BUZZER 24
#define LED_DETECTOR 31
////FIN SENSOR PIR////

///PINES PARA ALARMA///
#define SENSOR_FUEGO 30
#define SENSOR_SONIDO 28
#define BUZZER 24
#define BOTON_ALARMA 41
#define LED_ROJO_INDICADOR_ALARMA 46
#define LED_VERDE_INDICADOR_ALARMA 44
#define REDSWITCH 34
#define PULSADOR_ALARMA 37
/// FIN PINES PARA ALARMA ///

///SENSOR DE LUZ, CORTINA///
int LuzSensor = 0; // ES LA LUZ QUE RECIVE EL SENSOR
int Poscicion = 0; // ES LA POCOCION DEL MOTOR PASO A PASO
int Luzled = 0;
int Led = 0; //ES LA CANTIDAD DE LUZ DEL LED
int PosAux = 0; //ES LA SEGUNDA VARIABLE QUE UTILIZAMOS PARA PASO A PASO
boolean estado = true;
/// FIN SENSOR DE LUZ, CORTINA///


/////PUERTA////
int flag = 0 ;
int flag_5_seg = 0;
int puerta_abierta = 0;
///FIN PUERTA///


///SENSOR DHT11///
int pinDHT11 = pin_sensor_hume;
DHT sensor (2, DHT11);
float temperatura = 0;
float humedad = 0;
///FIN SENSOR DHT11////

///ALARMA///
int estado_buzzer = 0; // si estado_buzzer  = 0 -> el buzzer esta apagado     // si estado_buzzer  = 1 -> el buzzer esta prendido
int Detecta_Alguien = 0;
int Alarma_Activada = 0;
int Alarma_Desactivada = 0;
///FIN ALARMA///

auto timer = timer_create_default(); //configuramos el hadware para el timer

Servo Puerta_Garaje;
Servo Puerta1; // DECLARAMOS AL SERVO
Stepper Motor (80, 9, 10, 11, 12); //seteamos los pines para el paso a paso


/////////COMIENZA ALGORITMO DE LA PUERTA////////


bool Cierra_Puerta ( )
{
  if (digitalRead (PULSADOR_PUERTA) != HIGH) // PRESIONANDO EL PIN 26 EL SERVO SE POCICIONA EN 90º (SE ABRE LA PUERTA)
    {
     Puerta1.write(100);
     flag = 1;
     puerta_abierta = 1;
     Serial.println ("la puerta se abre");
   }

  
   if (flag_5_seg == 1 && puerta_abierta == 1)
  {
    Puerta1.write (40); // SI NADA OBSTACULIZA EL SENSOR, LA PUERTA SE CIERRA LUEGO DE 5 SEG
    Serial.println ("la puerta se cierra luego de 5 segundos");
    flag_5_seg = 0;
    puerta_abierta = 0;
  }

  
  if ( (digitalRead (SENSOR_PUERTA) != HIGH) && flag == 1 )
  {
    Puerta1.write (40); // SI ALGO OBSTACILIZA EL SENSOR, LA PUERTA SE CIERRA
    Serial.println ("el sensor cierra la puerta");
    flag = 0 ;
  }
  return true;
}
///////////TERMINA ALGORITMO DE LA PUERTA/////////////



//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

bool ALARMA = true
{
  
/*-------------------INTENTO DE FUNCION PARA LA ALARMA------------------*/


  if(ALARMA == true)
  {
  ////INDICADOR LED/////
  digitalWrite (LED_VERDE_INDICADOR_ALARMA, LOW);
  digitalWrite (LED_ROJO_INDICADOR_ALARMA, HIGH);
  /////////////////////


  if (digitalRead(SENSOR_PIR) == HIGH || digitalRead (REDSWITCH) == LOW || digitalRead (SENSOR_FUEGO) == HIGH || digitalRead (SENSOR_SONIDO) == HIGH )
  {
    // SI ENTRE ACA QUIERE DECIR QUE DETECTE A ALGUIEN!
    if (estado_buzzer)
       digitalWrite(BUZZER, HIGH);
      else
      {
        digitalWrite (BUZZER, LOW);
      }
    }
  }

  if(ALARMA == false)
  {
  ////INDICADOR LED/////
  digitalWrite (LED_VERDE_INDICADOR_ALARMA, HIGH);
  digitalWrite (LED_ROJO_INDICADOR_ALARMA, LOW);
  digitalWrite (BUZZER, LOW);
  ///
  }

/*-------------------FIN DE INTENTO DE FUNCION PARA LA ALARMA------------------*/




  
/*-------------------INTENTO DE FUNCION PARA LA ALARMA------------------*/


  if(ALARMA == true)
  {
  ////INDICADOR LED/////
  digitalWrite (LED_VERDE_INDICADOR_ALARMA, LOW);
  digitalWrite (LED_ROJO_INDICADOR_ALARMA, HIGH);
  /////////////////////


  if (digitalRead(SENSOR_PIR) == HIGH || digitalRead (REDSWITCH) == LOW || digitalRead (SENSOR_FUEGO) == HIGH || digitalRead (SENSOR_SONIDO) == HIGH )
  {
    // SI ENTRE ACA QUIERE DECIR QUE DETECTE A ALGUIEN!
    if (estado_buzzer)
       digitalWrite(BUZZER, HIGH);
      else
      {
        digitalWrite (BUZZER, LOW);
      }
    }
  }

  if(ALARMA == false)
  {
  ////INDICADOR LED/////
  digitalWrite (LED_VERDE_INDICADOR_ALARMA, HIGH);
  digitalWrite (LED_ROJO_INDICADOR_ALARMA, LOW);
  digitalWrite (BUZZER, LOW);
  ///
  }
}




///////////COMIENZA ALGORITMO DE LAS CORTINAS///////////
bool pos_cort()
{
  if (LuzSensor >= 10) // el maximo ahora es 10
    LuzSensor =  10;
  if (LuzSensor <= 0) // el minimo ahora es 0
    LuzSensor = 0;

  if (Poscicion < LuzSensor)
  {
    if (estado == false)
    {
      PosAux = -10;
      estado = true;
    }

    Motor.step (10);
    PosAux++;

    if (PosAux == 50)
    {
      PosAux = 0;
      Poscicion++;
    }
  }

  if (Poscicion > LuzSensor)
  {
    if (estado == true)
    {
      PosAux = 10 - PosAux;
      estado = false;
    }
    Motor.step (-10);
    PosAux++;
    if (PosAux == 50)
    {
      PosAux = 0;
      Poscicion--;
    }

  }

}
///////////////TERMINA EL ALGORITMO DE LAS CORTINAS////////////////

//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

////////////// COMIENZA EL ALGORITMO DEL SENSADO DEL LDR Y DTH ///////////////////
bool ldr (void *)
{
  
  Serial.print("Tomando_DATOS!");
  Serial.print("luz ");
  Serial.println (LuzSensor); // SE MUESTRA LA CANTIDAD DE LUZ QUE RECIVE EL SENSOR
  Serial.print("POS ");
  Serial.println (Poscicion);

  Led = analogRead (LDR_SENSOR); // lectura de luz para las luces
  Luzled = map ( Led , 0, 1023, 0, 255);
  LuzSensor = map ( Led , 0, 1023, 0, 10);

  humedad = sensor.readHumidity();
  temperatura = sensor.readTemperature();


  Serial.print("Sample OK: ");
  Serial.print((int)temperatura); Serial.print(" *C, ");
  Serial.print((int)humedad); Serial.println(" H");


  ///////
  flag_5_seg = 1;
  ///////

  return true;
}
//////////////////// TERMINA EL ALGORITMO DEL SENSADO DEL LDR Y DHT///////////////////



//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\



////////////////////////////COMIENZA EL ALGORITMO DE LA ALARMA////////////////////////////
bool buzzer (void *)
{
  if (estado_buzzer == 1)
  {
    estado_buzzer = 0 ;
    digitalWrite(BUZZER, LOW);
  }
  else
  {
    estado_buzzer = 1;
    digitalWrite (BUZZER, HIGH);
  }
}
////////////////////////////TERMINA EL ALGORITMO DE LA ALARMA////////////////////////////

void setup()
{
  Serial.begin (9600);
  Motor.setSpeed (80);

  ////SETEOS DEL TIMER///
  timer.every(5000, ldr); ///PARA CERRAR LA PUERTA
  timer.every (2000, buzzer); ///PARA QUE EL BUZZER SUENE CADA DOS SEGUNDOS
  ///// FIN SETEOS DEL TIMER////

  Puerta1.attach (SERVO_PUERTA_1); //ES LA SALIDA QUE VA A IR AL DATO DEL SERVO
  Puerta1.write (20); // EL SERVO SE VA A POCICIONAR EN 0º CUANDO COMIENCE EL PROGRAMA (SE CIERRA LA PUERTA)
  //Serial.println ("la puerta se setea en cerrado");

  
  //////SETEOS DE PINES PARA LA ILUMINACION//////////
  pinMode (PULSADOR_1, INPUT);
  pinMode (PULSADOR_2, INPUT);
  pinMode (PULSADOR_3, INPUT);
  pinMode (PULSADOR_4, INPUT);
  pinMode (PULSADOR_5, INPUT);
  pinMode (PULSADOR_6, INPUT);
  pinMode (PULSADOR_7, INPUT);

  pinMode (HABITACION_1, OUTPUT);
  pinMode (HABITACION_2, OUTPUT);
  pinMode (HABITACION_3, OUTPUT);
  pinMode (HABITACION_4, OUTPUT);
  pinMode (HABITACION_5, OUTPUT);
  pinMode (HABITACION_6, OUTPUT);
  pinMode (HABITACION_7, OUTPUT);
  /////////FIN DE SETEOS DE PINES PARA LA ILUMINACION//////////


  
  pinMode (SENSOR_CORTINA, INPUT);
  pinMode (SENSOR_PUERTA, INPUT);
  pinMode (PULSADOR_PUERTA, INPUT);




  ///////////PINES PARA ALARMA////////
  pinMode (BUZZER , OUTPUT) ; //para el BUZZER
  pinMode (SENSOR_PIR , INPUT); //SENSOR PIR
  pinMode (LED_ROJO_INDICADOR_ALARMA, OUTPUT);
  pinMode (LED_VERDE_INDICADOR_ALARMA, OUTPUT);
  pinMode (PULSADOR_ALARMA, INPUT_PULLUP); //PULSADOR QUE ACTIVA Y DESACTIVA ALARMA
  pinMode (REDSWITCH, INPUT);
  pinMode (SENSOR_FUEGO, INPUT);
  pinMode (SENSOR_SONIDO, INPUT);
  //////////FIN PINES PARA ALARMA/////////

  //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

  //////////////////////SETEO DE LAS CORTINAS PARA QUE COMIENCEN ABIERTAS///////////////////

  while (digitalRead (SENSOR_CORTINA) == HIGH ) // SE USA PARA EL SENSOR DE LAS CORTINAS. CUANDO ESTEN ARRIBA, SE VAN A DETENER, Y ESE SERA EL PUNTO DE INICIO
  {
    digitalWrite (LED_ROJO_INDICADOR_ALARMA, HIGH);
    Serial.println ("cerrando");
    Motor.step (-1); // ESTO HARA QUE EL PASO A PASO GIRE CONTINUAMENTE HASTA QUE LO INDIQUE EL SENSOR
  }
  Serial.println ("cerrado");
  
  //////////////////FIN DEL SETEO DE LAS CORTINAS////////////////
}





void loop()
{

  //////// LLAMADO DE LAS FUNCIONES//////
  pos_cort();
  Cierra_Puerta();
  timer.tick();
  //////// FIN DEL LLAMADO DE LAS FUNCIONES/////////


  ////////////LOGARITMO PARA REFRIGERACION//////////////
  if (temperatura > 25)
  {
    digitalWrite (COOLER, HIGH);
    digitalWrite (ROJO, HIGH);
  }
  else
  {
    digitalWrite (COOLER, LOW);
    digitalWrite (ROJO, LOW);
    digitalWrite (VERDE, HIGH);
  }

  if (temperatura < 25)
    digitalWrite (VERDE, HIGH);

  else
    digitalWrite (VERDE, LOW);
  ///////////// FIN DE ALGORITMO PARA REFRIGERACION////////////////


  ////////////// LED RGB PARA ALARMA ///////////////
  if (digitalRead (BOTON_ALARMA) == HIGH)
  {
    if (Alarma_Activada == 1)
      Activo_Alarma ();
    else
      Desactivo_Alarma ();
  }

  ///////////////FIN DE RGB PARA ALARMA/////////////////////







  //////////////ILUMINACION////////////////// 

  if (digitalRead (PULSADOR_1) == HIGH)
   {
    while (digitalRead (PULSADOR_1) == HIGH)
      {
      delay (5);
      }
      
      letra = 'b';
      CONT_H1 = 1;
   }

   if (digitalRead (PULSADOR_2) == HIGH)
   {
    while (digitalRead (PULSADOR_2) == HIGH)
      {
      delay (5);
      }
      letra = 'c';
      CONT_H2 = 1;
   }
  
   if (digitalRead (PULSADOR_3) == HIGH)
   {
    while (digitalRead (PULSADOR_3) == HIGH)
      {
      delay (5);
      }
      letra = 'd';
      CONT_H3 = 1;
   }
   
   if (digitalRead (PULSADOR_4) == HIGH)
   {
    while (digitalRead (PULSADOR_4) == HIGH)
      {
      delay (5);
      }
      letra = 'e';
      CONT_H4 = 1;
   }
  
   if (digitalRead (PULSADOR_5) == HIGH)
   {
    while (digitalRead (PULSADOR_5) == HIGH)
      {
      delay (5);
      }
      letra = 'f';
      CONT_H5 = 1;
   }
  
   if (digitalRead (PULSADOR_6) == HIGH)
   {
    while (digitalRead (PULSADOR_6) == HIGH)
      {
      delay (5);
      }
      letra = 'g';
      CONT_H6 = 1;
   }
  
   if (digitalRead (PULSADOR_7) == HIGH)
   {
    while (digitalRead (PULSADOR_7) == HIGH)
      {
      delay (5);
      }
      letra = 'h';
      CONT_H7 = 1;
   }



  switch (letra)
    {
      case 'a':
      digitalWrite (HABITACION_1, LOW);
      digitalWrite (HABITACION_2, LOW);
      digitalWrite (HABITACION_3, LOW);
      digitalWrite (HABITACION_4, LOW);
      digitalWrite (HABITACION_5, LOW);
      digitalWrite (HABITACION_6, LOW);
      digitalWrite (HABITACION_7, LOW);
      break;

      case 'b': //SI PRESIONAMOS EL PULSADOR 1, ENVIAMOS UNA LETRA AL SWITCH, Y AL RECIVIRLA EJECUTA LA SENTENCIA. SI VUELVE A RECIVIR LA MISMA LETRA Y HABITACION == HIGH, HABITACION = LOW 
      digitalWrite (HABITACION_1, HIGH);

      if ((CONT_H1 == 1) && (HABITACION_1 == HIGH))
        {
           while (digitalRead (PULSADOR_1) == HIGH)
            {
             delay (5);
            }
                    
          digitalWrite (HABITACION_1, LOW);
          CONT_H1 = 0;
        }

        
      case 'c':
       digitalWrite (HABITACION_2, HIGH);

      if ((CONT_H2 == 1) && (HABITACION_2 == HIGH))
        {
          while (digitalRead (PULSADOR_2) == HIGH)
            {
             delay (5);
            }
          digitalWrite (HABITACION_2, LOW);
          CONT_H2 = 0;
        }


      case  'd':
        digitalWrite (HABITACION_3, HIGH);

        if ((CONT_H3 == 1) && (HABITACION_3 == HIGH))
         {   
            while (digitalRead (PULSADOR_3) == HIGH)
            {
            delay (5);
            }
          digitalWrite (HABITACION_3, LOW);
          CONT_H3 = 0;
         }
        

      case 'e':
        digitalWrite (HABITACION_4, HIGH);

        if ((CONT_H4 == 1) && (HABITACION_4 == HIGH))
         {
          
            while (digitalRead (PULSADOR_4) == HIGH)
              {
              delay (5);
              }
           digitalWrite (HABITACION_4, LOW);
           CONT_H4 = 0;
          }
  
    
       case 'f':
        digitalWrite (HABITACION_5, HIGH);

        if ((CONT_H5 == 1) && (HABITACION_5 == HIGH))
         {
            while (digitalRead (PULSADOR_5) == HIGH)
              {
              delay (5);
              }
            digitalWrite (HABITACION_5, LOW);
            CONT_H5 = 0;
          }


        case 'g':
        digitalWrite (HABITACION_6, HIGH);

        if ((CONT_H6 == 1) && (HABITACION_6 == HIGH))
         {
            while (digitalRead (PULSADOR_6) == HIGH)
              {
              delay (5);
              }
            digitalWrite (HABITACION_6, LOW);
            CONT_H6 = 0;
          }


        case 'h':
        digitalWrite (HABITACION_7, HIGH);

        if ((CONT_H7 == 1) && (HABITACION_7 == HIGH))
         {
            while (digitalRead (PULSADOR_7) == HIGH)
              {
              delay (5);
              }
            digitalWrite (HABITACION_7, LOW);
            CONT_H7 = 0;
          }

    }


  if (digitalRead (PULSADOR_ALARMA)== HIGH
  {
    ALARMA = true;
  }
  
}
