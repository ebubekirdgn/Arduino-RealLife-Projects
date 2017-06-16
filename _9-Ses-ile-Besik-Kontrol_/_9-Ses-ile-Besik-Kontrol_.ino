int motor_Pin = 9; // Motorun bagli oldugu PWM pini
int esik_degeri = 500; // Bebek sesi icin sectigimiz esik degeri
int deger; // Okunan analog verinin aktarılacagı degisken

void setup() 
{
  Serial.begin(9600); // Seri iletim basliyor...
  pinMode(motor_Pin ,OUTPUT);  // Motor Pini cikis olarak kullanilacak...
}

void loop()
{
   deger = analogRead(A0); //Bebegin sesi alinip degiskene aktariliyor.
   if(deger >= esik_degeri)  // Eger ses esige esit veya buyukse
   {
    for(int i=0;i<256;i++) // Motor hizi artsın.
    {
      analogWrite(motor_Pin, i);  //calismaya baslasin.
      delay(10); // Cakisma olmamasi icin gecikme veriyoruz.
    }
    delay(3000); // Motor 3 sn. calisiyor.
     for(int i=255;i>=0;i--)
    {
      analogWrite(motor_Pin, i);  //duruyor
      delay(10); // Cakisma olmamasi icin gecikme veriyoruz.
    }
     delay(3000); // Motor 3 sn. calisiyor.
   }
   else
   {
     analogWrite(motor_Pin, LOW); //bebegin sesi az ise motor duruyor.  
   }

}








