  int btn= 11;         
int led1 = 12;        

int state = HIGH;       
int reading;            
int previous = LOW;     

 
long time = 0;         
long debounce = 200;    
int led2= 13;
int ldr2=A1;
int value1= 0;
int value2= 0;
int ldr1= A0;
int count=0;
int buzzer=9;
int buttonPushCounter=0;
int buttonState=0;
int lastButtonState=0;
int sys_state=0;
int i=0;
int y=0;

void setup()
{
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(btn,INPUT);
  Serial.begin (9600);
}

void loop()
{
  reading = digitalRead(btn);

  
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;

    time = millis();    
  

   i = analogRead(ldr1);
value1= map(i, 0, 1023, 0, 255);
Serial.println(value1);
delay(200);
y = analogRead(ldr2);
value2= map(y, 0, 1023, 0, 255);
Serial.println(value2);
delay(200);
  
  if(value1<25)
  {
    count++;
     Serial.println("the counter is" );
     Serial.println(count);
    digitalWrite(led1, HIGH);
    delay(5);
     digitalWrite(led1, LOW);
  }
   if (value2<25){
    count--;
    Serial.println("the counter is" );
     Serial.println(count);
     digitalWrite(led2, HIGH);
     delay(5);
     digitalWrite(led2, LOW);
   }
    if (count>5){
     
       Serial.println("the room is full" );
     digitalWrite(12, HIGH);
     delay(5);
     digitalWrite(12, LOW);
      digitalWrite(led2, HIGH);
     delay(5);
     digitalWrite(led2,LOW);
     digitalWrite(9, HIGH);
    
    }
     
  if (digitalRead(buzzer)==HIGH)
  {
    delay(1000);
    digitalWrite(9, LOW);
  }  }  }

 
  
   
         
