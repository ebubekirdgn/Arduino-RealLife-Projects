//pin tanimlamalari

int lm35_Pin=A1;
int yesil_led = 12;
int kirmizi_led=5;
int buzzer_alarm=2;


void setup()
{
 // giris cikis ayrimi

  pinMode(lm35_Pin,INPUT);
  pinMode(yesil_led,OUTPUT);
  pinMode(kirmizi_led,OUTPUT);
  pinMode(buzzer_alarm,OUTPUT);
  // ilk durumda normal olarak yesil ledimizi yakiyoruz.

  digitalWrite(yesil_led,HIGH);

}

void loop() 
{

// LM35 sensorunden bilgi okuma yapilir.
float lm35_okunan_deger = analogRead(lm35_Pin);
//okunan analog bilgi gerilim degerine donusturulur.
float analog_sicaklik = (lm35_okunan_deger / 1023)*5000;
//gerilim sicakliga donusturulur.
float dijital_sicaklik= analog_sicaklik/10.0;
  if(dijital_sicaklik>50)
  {
    //sicaklik fazla ise buzzer ve kirmizi led calisir.
    //yesil ledi sondurmemiz gerekiyor.
    tone(buzzer_alarm,300);
    digitalWrite(kirmizi_led,HIGH);
    digitalWrite(yesil_led,LOW);
  }
  else
  {
    //durum normal ise buzzer ve kirmizi led pasif durumda kalir.Yesil led yanmaya devam eder aksi olmadikca
  
    noTone(buzzer_alarm);
    digitalWrite(yesil_led,HIGH);
    digitalWrite(kirmizi_led,LOW); 
  }
}
