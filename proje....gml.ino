
int led_m=5;
int buton=2;
int kapi=1;
const int motorPin1 = 8;
const int motorPin2 = 9;
const int motorPin3 = 10;
const int motorPin4 = 11;
int bekleme = 4;

void adim1() {
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(bekleme);
}

void adim2() {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(bekleme);
}

void adim3() {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);
delay(bekleme);
}

void adim4() {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
delay(bekleme);
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(led_m,OUTPUT);
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);

 pinMode(buton,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int s_degeri=analogRead(A0);
     

 
    if(s_degeri>300 && kapi==1)
    {
      digitalWrite(led_m,HIGH);
      
      for (int i = 0; i < 512; i++)
           {
              adim1();
              adim2();
             adim3();
             adim4();
           }
             
      for (int i = 0; i < 300; i++)
           {
              adim1();
              adim2();
             adim3();
             adim4();
           }
  Serial.print("sensör degeri= ");
    Serial.println(s_degeri);
        Serial.println("dongu 1 ");
        
     kapi=0;
        digitalWrite(led_m,LOW);
      }
      
        
        
       else if((digitalRead(buton)==HIGH) && (kapi==1)){
          for (int i = 0; i < 512; i++)
         { 
          adim1();
          adim2();
          adim3();
          adim4();
       
          }
           for (int i = 0; i < 300; i++)
         {  adim1();
          adim2();
          adim3();
          adim4();
       
          }
            Serial.print("sensör degeri= ");
    Serial.println(s_degeri);
    Serial.print("dongu 2 ");
         kapi=0;
        }                     
          else if((digitalRead(buton)==HIGH) && (kapi==0)){
          for (int i = 0; i <512; i++)
         {
        adim4();
          adim3();
          adim2();
          adim1();
         }
           for (int i = 0; i <300; i++)
         {
        adim4();
          adim3();
          adim2();
          adim1();
         }
           Serial.print("sensör degeri= ");
    Serial.println(s_degeri);
         Serial.print("dongu 3 ");
         kapi=1;
          }


        
}
