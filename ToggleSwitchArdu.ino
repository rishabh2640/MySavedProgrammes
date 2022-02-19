

int butPin = 12;
int ledPin = 13;
bool newStat;
bool oldStat=1;
int ledStat=0;


void setup() {
 pinMode(butPin, INPUT);
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  newStat=digitalRead(butPin);
  
  if (oldStat==0 && newStat==1){
   if ( ledStat==0 ){
    digitalWrite(ledPin, HIGH);
    ledStat=1;
   delay(100);
   }
  else{
  digitalWrite(ledPin, LOW);
  ledStat=0;
  delay(100);
}
  }
  Serial.print(newStat);
  Serial.println(oldStat);
  
  oldStat=newStat;


   }
