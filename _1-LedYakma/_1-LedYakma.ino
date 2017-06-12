
const int led_Pin =13; // Ledin bagli oldugu pin
const int ldr_Pin=A0;//ldr nin bagli oldugu Arduino pini


void setup() 
{
  // put your setup code here, to run once:
   pinMode(led_Pin,OUTPUT);
   //13 numaralı pin cıkıs olarak atandı.
}

void loop() {
  // put your main code here, to run repeatedly:
   int durum = analogRead(ldr_Pin);
   //ldr pininden ışıgın yogunlugu okunuyor.
   if(durum <=300)
   {
    digitalWrite(led_Pin,HIGH);
   }
   //eger isik yogunlugu kendi oluşturdugumuz 300 degerimizden esit veya düsükse led yanacak.
   else
   {
    digitalWrite(led_Pin,LOW);
    //eger isik yogunlugu kendi olusturdugumuz 300 degerimizden büyükse led sönecektir.
   }
}
