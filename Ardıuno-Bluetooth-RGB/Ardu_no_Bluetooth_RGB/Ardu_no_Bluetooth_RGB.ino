#include <SoftwareSerial.h>

SoftwareSerial BTserial(0, 1); // RX, TX

const int kirmiziPin = 9;
const int yesilPin = 10;
const int maviPin = 11;

String gelenKomut = "";  // Gelen veriyi tutar
bool komutHazir = false;

void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);
  pinMode(kirmiziPin, OUTPUT);
  pinMode(yesilPin, OUTPUT);
  pinMode(maviPin, OUTPUT);
  kapat();
  Serial.println("Bluetooth RGB LED kontrol hazır");
}

void loop() {
  while (BTserial.available()) {
    char c = BTserial.read();

    if (c == '\n' || c == '\r') { // Komut sonu işareti
      komutHazir = true;
    } else {
      gelenKomut += c;  // Karakteri komuta ekle
    }
  }

  if (komutHazir) {
    Serial.print("Gelen komut: ");
    Serial.println(gelenKomut);

    // Komutları karşılaştır
    if (gelenKomut == "k") {
      setColor(LOW, HIGH, HIGH); // Kırmızı
    } else if (gelenKomut == "y") {
      setColor(HIGH, LOW, HIGH); // Yeşil
    } else if (gelenKomut == "m") {
      setColor(HIGH, HIGH, LOW); // Mavi
    } else if (gelenKomut == "a") {
      setColor(LOW, LOW, LOW); // Beyaz (hepsi açık)
    } else if (gelenKomut == "o") {
      kapat();
    } else {
      Serial.println("Geçersiz komut");
    }

    // Komut temizle
    gelenKomut = "";
    komutHazir = false;
  }
}

void setColor(int r, int g, int b) {
  digitalWrite(kirmiziPin, r);
  digitalWrite(yesilPin, g);
  digitalWrite(maviPin, b);
}

void kapat() {
  digitalWrite(kirmiziPin, HIGH);
  digitalWrite(yesilPin, HIGH);
  digitalWrite(maviPin, HIGH);
}
