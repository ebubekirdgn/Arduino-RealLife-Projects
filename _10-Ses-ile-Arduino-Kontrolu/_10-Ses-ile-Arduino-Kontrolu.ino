int led = 13; //Led'in bagli oldugu pin
int esik_degeri = 500; // Ses icin bizim sectigimiz esik degeri
int deger; // Okunan verinin aktarılacagi degisken

void setup() 
{
Serial.begin(9600); //Seri iletim basliyor.
pinMode(led, OUTPUT);
}

void loop()
{
    deger = analogRead(A0); // Analog-0'dan gelen veriyi oku ve deger'e aktar.
    if(deger >= esik_degeri)
    {
      //deger disaridan gelen ses sinyali kart degerinden buyukse 
      digitalWrite(led, HIGH);//Led'i yak
    }
    else
    {
      digitalWrite(led,LOW); //degilse ledi sondur.
    }
}
