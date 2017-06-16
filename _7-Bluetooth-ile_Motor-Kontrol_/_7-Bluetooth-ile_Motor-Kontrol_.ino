int motor_Pin1 = 3; //L293D 2.PİN
int motor_Pin2 = 4; //L293D 7.PİN
int enable_Pin = 5; //L293D 1.PİN
int durum , bayrak =0;


void setup()
{
 //Giris cikis pinlerinin ayarlanmasi
   pinMode(motor_Pin1,OUTPUT);
   pinMode(motor_Pin2,OUTPUT);
   pinMode(enable_Pin,OUTPUT); //Motorun calisabilmesi icin yetki pinini(enablePin) yapiyoruz.
   digitalWrite(enable_Pin ,HIGH);
   //Bluetooth ile seri iletisim baslatildi.
   Serial.begin(9600);
}
void loop() 
{
  if(Serial.available()>0) 
  {
    durum = Serial.read();
    bayrak = 0;
  }
  //Eger mobilden "0" bilgisi gelirse motor dursun.
  
  if(durum == '0')
  {
    digitalWrite(motor_Pin1 ,LOW);    
    digitalWrite(motor_Pin2 ,LOW);
    if(bayrak == '0')
    {
      Serial.println("Motor : Kapalı" );
      bayrak = 1; 
    }
  }
  //Eger mobilden "1" bilgisi gelirse motor saga donsun.
  else if(durum == '1')
  {
    digitalWrite(motor_Pin1 ,LOW);    
    digitalWrite(motor_Pin2 ,HIGH);
    if(bayrak == '1')
    {
      Serial.println("Motor : Sağa Dönüyor" );
      bayrak = 1; 
    }
  }
  //Eger mobilden "2" bilgisi gelirse motor sola donsun.
  else if(durum == '2')
  {
    digitalWrite(motor_Pin1 ,HIGH);    
    digitalWrite(motor_Pin2 ,LOW);
    if(bayrak == '0')
    {
      Serial.println("Motor : Sola Dönüyor" );
      bayrak = 1; 
    }
  }
}








