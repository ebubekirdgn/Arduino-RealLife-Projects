
int led = 11; //Dijital 11 çıkışına Led'i bağladik.
String readString; // Mobil cihazimizdan gelen on/off bilgisini tutacak olan String türündeki degiskenimiz.


void setup()
{
Serial.begin(9600); //9600 Baund veri hizinda mobil cihaz ile etkilesime gecilecek ve ledi cikis elemani
//olarak görecek.
pinMode(led,OUTPUT); 

}

void loop() 
{
  while(Serial.available()) // seri iletisimde oldugu sürece demektir bu.1
  {
    delay(3); //3 mikro sn gecikme veriyoruz.
    char c = Serial.read(); // Mobil cihazdan gelen verileri karakter bazli olarak okuyor.
    readString += c; // on off bilgisi geliyor.
  }
  if(readString.length()>0) // on off bilgisi geldimi demek aslinda
  {
    Serial.println(readString);
    if(readString=="on")
      {
        digitalWrite(led,HIGH);
      }
    if(readString ==  "off")
      {
        digitalWrite(led,LOW);
      }
  readString ="";
  }

  

}
