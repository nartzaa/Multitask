#define LED1 13
#define LED2 12

unsigned long last1, last2;

void setup(){
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
}

void loop(){
    if (millis() - last1 >= 500){
        last1 = millis();
        digitalWrite(LED1, !digitalRead(LED1));
    }
    if (millis() - last2 >= 300){
        last2 = millis();
        digitalWrite(LED2, !digitalRead(LED2));
    }
}