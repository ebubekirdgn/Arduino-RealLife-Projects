int durum , haber =11;



//Durum bilgisine göre hareket edecegiz. 1 ve 0 bilgisi gelecek bize. 0 da depo dolu , 1 de depo bostur.
void setup() 
{
  // put your setup code here, to run once:
  pinMode(haber , INPUT);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(Serial.available() >0)
  {
    durum = digitalRead(haber);
    if(durum == HIGH)
    {
      Serial.println("Sivi dengesinde azalma var , Motor calisiyor.");
    }
    else if(durum == LOW)
    {
      Serial.println("Sivi dengesinde azalma var , Motor calismiyor."); 
    }
  }
}
