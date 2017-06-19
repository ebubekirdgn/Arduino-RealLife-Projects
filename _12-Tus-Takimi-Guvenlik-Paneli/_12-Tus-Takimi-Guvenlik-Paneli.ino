#include <Keypad.h>  

char* guvenlik_kodu ="1234"; //bizim keyfi belirledigimiz sifremiz
int position = 0; //hangi tusa basildigini bilmemiz icin gerekli olan tus takimi

const byte satir = 4;  //tus takimi satir sayisi
const byte sutun = 3; //tus takimi sutun sayisi
// tus takimi tanimlandi.
char tus[satir][sutun] ={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
  } ;
//tus takimi satırlarının bagli oldugu pinler
byte satir_pinleri[satir] = {2,7,6,4};

//tus takimi sutunlarının bagli oldugu pinler
byte sutun_pinleri[satir] = {3,1,5};

Keypad kp = Keypad (makeKeypad(tus),satir_pinleri,satir,sutun_pinleri,satir,sutun);
int kirmizi_led = 9;
int yesil_led = 8;
  
void setup() 
{
  pinMode(kirmizi_led , OUTPUT); //Ledler cikis elemani
  pinMode(yesil_led , OUTPUT);
  setLocked(true);
  //setLocked fonksiyonu asagida tanimlanmistir.
  //deger olarak true veya false dondurur.
  //true degeri locked'dir ki bu tus takiminin kilitli oldugunu , false degeri tus takiminin acik oldugunu belirtir.
  
}
void loop()
{
//getKey() özelligi ile hangi tusa basildigina bakiyoruz.
char hangi_tus = keypad.getKey();
//eger * ve # tuslarina basilirsa sistem kilitli
  if(hangi tus == '*' || hangi tus == '#')
  {
    position = 0;
    setLocked(true);
  }
 // eger basilan tuslar guvenlik kodu ile aynıysa 
 //4 hane girilmesine izin ver
 //4 sayısı bizim tanımladigimiz kod rakamlarıdır.
  if(hangi tus == guvenlik_kodu[position]) 
      position ++;
  if(position == 4)
      setLocked(false);

 delay(100); //tus sıcramasından dolayı guvenlik gecıkmesi standarttır.
}

void setLocked(int locked)
{
  if(locked)
  {
    digitalWrite(kirmizi_led , HIGH);
    digitalWrite(yesil_led , LOW);
  }
  else
  {
    digitalWrite(kirmizi_led , LOW);
    digitalWrite(yesil_led , HIGH); 
  }
}

