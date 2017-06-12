//Buzzer nedir? Elektronik cihazlarda,gelen voltajın büyüklüğü ile orantılı "bip" sesi
//cikaran minik hoparlöre denir.

int buzzer_Pin=12;
int ldr_Pin = A0; 
void setup() 
{
  // put your setup code here, to run once:
pinMode(ldr_Pin,INPUT);
pinMode(buzzer_Pin,OUTPUT);

}

void loop()
{
  // put your main code here, to run repeatedly:
 int ldr_degeri = analogRead(ldr_Pin);  
 if(ldr_degeri >=250)
 {
  tone(buzzer_Pin,100); //zil sesi cıkarması için 
 }
 else
 {
  noTone(buzzer_Pin); //sesi kapatacak olan fonksiyon
 }
}
