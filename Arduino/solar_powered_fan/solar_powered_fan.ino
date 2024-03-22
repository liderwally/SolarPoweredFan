
boolean isFanOn = false, isOverideOn = false, lastfanvalue = false, currFanvalue = false;

int lastvalue = 0;
int buttonCounter = 0;
int tempCoeficient =  2;
int zeroTempValue = 102;


void setup () {

// TODO: put your setup code here, to run once:
Serial.begin(9600);
pinMode(3, INPUT);
pinMode(4, OUTPUT);

}

void loop() {
// TODO: put your main code here, to run repeatedly:
int value = analogRead(A0);

int tempvalue = (value - zeroTempValue)/ tempCoeficient; //map(value, 0 , 1023, -20 , 70);

if(lastvalue != tempvalue){
 Serial.print(tempvalue);
 Serial.println("celcius");
 Serial.println(lastfanvalue);
 lastvalue = tempvalue;
 if(tempvalue > 30){
 isFanOn = true;
 }else{
 isFanOn = false;
 }
 
}

if(digitalRead(3) > 0 && (millis() - buttonCounter ) > 300 ){
  isOverideOn = true;
  buttonCounter = millis();
}




currFanvalue = (!isOverideOn && lastfanvalue) || (!lastfanvalue && isOverideOn && !isFanOn) || (!isOverideOn && isFanOn);
digitalWrite(4, currFanvalue);

isOverideOn = false;
lastfanvalue = currFanvalue;

}
