#define Trig_pin 7
#define Echo_pin 6
#define buzzer 3
#define red_led 11
#define yellow_led 10
#define green_led 9
int sound = 500;
long distance_in_cm,duration;
void setup() {
  // put your setup code here, to run once:
pinMode(Trig_pin,OUTPUT);
pinMode(Echo_pin,INPUT);
pinMode(buzzer,OUTPUT);
pinMode(red_led,OUTPUT);
pinMode(yellow_led,OUTPUT);
pinMode(green_led,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Trig_pin,LOW);
delayMicroseconds(2);
digitalWrite(Trig_pin,HIGH);
delayMicroseconds(10);
digitalWrite(Trig_pin,LOW);
duration = pulseIn(Echo_pin,HIGH);
distance_in_cm = (duration*.034)/(2);
if(distance_in_cm < 20){
  Serial.print("Distance = ");
  Serial.println(distance_in_cm);
  digitalWrite(green_led,HIGH);
}
else{
  Serial.print("Distance = ");
  Serial.println(distance_in_cm);
  digitalWrite(green_led,LOW);
}
if(distance_in_cm<10){
  Serial.print("Distance = ");
  Serial.println(distance_in_cm);
  digitalWrite(yellow_led,HIGH);
  tone(buzzer,sound);
}
else{
   Serial.print("Distance = ");
  Serial.println(distance_in_cm);
  digitalWrite(yellow_led,LOW);
  noTone(buzzer);
}
if(distance_in_cm<5){
  sound = 1000;
  Serial.print("Distance = ");
  Serial.println(distance_in_cm);
  digitalWrite(red_led,HIGH);
  tone(buzzer,sound);
}
else{
  Serial.print("Distance = ");
  Serial.println(distance_in_cm);
  digitalWrite(red_led,LOW);
  noTone(buzzer);
}
}
