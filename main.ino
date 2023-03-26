int a; 
int counter; 
int metrisi;
int max=-1000;
int min=1000;

void setup()
{
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
Serial.begin(9600);
Serial.println("START");
delay(5000);
}  

void loop() 
{   
 a=analogRead(A0);                    //photoresistor value
 float sensorValue = analogRead(A1);  //anemometer    value
 
 
 float voltage = (sensorValue / 1023) * 5;
 if(voltage < .02){
    voltage = 0;
  }
 float wind_speed = mapfloat(voltage, 0.0, 2, 0, 32.4);
 float speed_mph = ((wind_speed *3600)/1609.344);

 if (a>max){
   max = a;   
 }
 if (a<min){
   min = a;   
 }

 //if(wind_speed) 
 if(a<40){              
   digitalWrite(6,HIGH);
   digitalWrite(7,LOW);
    if(counter==1){
     digitalWrite(8,HIGH);             // sun
     delay(10000);                     //delay for motor //xrono gia na anebei h tenta 
     digitalWrite(8,LOW);
     counter=counter-1;
     }
 }else{
   digitalWrite(7,HIGH);
   digitalWrite(6,LOW);
    if(counter==0){
     digitalWrite(5,HIGH);            //there is no sun
     delay(10000);                   //delay for motor //xrono gia na katebei h tenta
     digitalWrite(5,LOW);
     counter=counter+1;
    } 
 } 
 metrisi=metrisi+1;                 // mono gia ta apotelesmata

 delay(1000);
 Serial.print(metrisi); 
 Serial.print(")H metrish ana 1 lepto einai: ");
 Serial.println(a);
 Serial.print("megaliterh timh: "); 
 Serial.println(max); 
 Serial.print("mikroterh timh: "); 
 Serial.println(min); 
 Serial.print("Wind Speed =");
 Serial.print(wind_speed);
 Serial.println("m/s");
 Serial.println();
 
 delay(60000); // diakoph enos leptoy
} 
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}