
//Bu projede Ldr üzerine gelen isik acisimi matematiksel sinüs(sin()) fonksiyonu ile hesaplayarak 3 adet led'den cesitli
//zaman aralıklarında cesitli cikislari alacagiz.
//kirmizi = sin(x)
//yesil = sin(x + PI/3)
//mavi = sin(x + 2PI/3)

float RGB[3];

int ldrPin=0 , ldr_deger,led_kirmizi,led_yesil,led_mavi;

led_kirmizi=11;
led_yesil=10;
led_mavi =9;


void setup() 
{
  // put your setup code here, to run once:
  //Ledler cikislara baglandi.
pinMode(led_kirmizi,OUTPUT);
pinMode(led_yesil,OUTPUT);
pinMode(led_mavi,OUTPUT);

// en basta hicbir led yanmayacak.

digitalWrite(led_kirmizi,LOW);
digitalWrite(led_yesil,LOW);
digitalWrite(led_mavi,LOW);
}

void loop()
{
  // x ile tanimlanan aci yarim daire (PI)'ye kadar cok kucuk oranda artacak sekilde ayarlıyoruz.

   for (float i =0;i< PI;i+=0.00001)
   {
    //abs mutlak deger alma fonksiyonudur.
    RGB[0]=255*abs(sin(x*(180/PI))); // artma islemi sirasinde kirmizi ledin parlakligi hesaplaniyor...
    RGB[1]=255*abs(sin((x+ PI/3)*(180/PI)));// artma islemi sirasinde yesil ledin parlakligi hesaplaniyor...
    RGB[2]=255*abs(sin(x*(X+(2*PI)/3)*(180/PI)));// artma islemi sirasinde mavi ledin parlakligi hesaplaniyor...

    ldr_deger = analogRead(ldrPin);
    //ldr'ye dusen isik kaydediliyor.
    if(ldrPin>600)
    {
      //ldr ye dusen isik miktari bizim belirledigimiz 600 degerinden buyukse iste o zaman yapilan hesaplamaya göre led'leri yak
      analogWrite(led_kirmizi,RGB[0]);
      analogWrite(led_yesil,RGB[1]);
      analogWrite(led_mavi,RGB[2]);
    }
    else
    {
      //parlaklik dusukse hepsini sondur
        digitalWrite(led_kirmizi,LOW);
        digitalWrite(led_yesil,LOW);
        digitalWrite(led_mavi,LOW);
    }
    //ledler arasında cok kucuk bir zaman gecikmesi yaparak
    //renklerin daha net gozukmesini saglayan
    //rastgele degerlerin esik olarak belirlendigi for dongusu --->

    for(int k=0; k<3;k++)
    {
      if(RGB[k]<1)delay(100);
      if(RGB[k]<5)delay(50);
      if(RGB[k]<10)delay(10);
      if(RGB[k]<100)delay(5);
      delay(1);
    }
    
   }

}
