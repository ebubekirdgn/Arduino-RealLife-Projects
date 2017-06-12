#include "pitches.h" //notaları bünyesinde bulunduran dosyamızı cagiriyoruz.
//pitches.h dosyasi indirilmeli ve Sketch menusunden Add File... menüsü seçimi ile projemize kütüphaneyi import etmeliyiz.


int melody[] = {NOTE_C4,NOTE_G3,NOTE_G3,NOTE_A3,0,NOTE_B3,NOTE_C4}; //kapi zilindeki notalar dizisi
int btn_Pin=12; //Butonun bagli oldugu pin numarasi
//note ritirmleri ranımlardik 
//4'lük nota 2 vurus ,8 lik nota yarım vurus
int nota_ritimleri_dizisi[] ={4,8,4,4,8,8,8,4};

void setup()
{
  // put your setup code here, to run once:
pinMode(btn_Pin,INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
int btn_durum = digitalRead(btn_Pin); // Butonun basili olup olmadigi kart tarafından okunuyor.
//butonun basili olup olmadigi kart tarafından okunuyor.
  if(btn_durum == 1) //eğer basili ise butona
  {
     //sekiz notamizi bastan calmak icin diziyi donguye veriyoruz.
     for(int i=0;i<8;i++)
     {
      //bir saniyelik(1000ms) nota süresi hesaplanip nota türlerine göre ayarlanacak.
      //ornegin 1000/4 bir vurus olarak , 1000/8 yarim vurus olarak kabul etmekteyiz.
      int nota_suresi = 100/nota_ritimlerş_dizisi[i];
      tone(8,melody[i],nota_suresi);
      //iki nota arasında belli bir süre ayrımı yapılmalı.
      //en uygun süre +30% bir zaman dilimidir.
      int iki_nota_arasi = nota_suresi*1.30;
      delay(iki_nota_arasi);
      tone(8); //müziği sonlandır.
     }
  }
}
