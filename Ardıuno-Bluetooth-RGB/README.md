# Arduino Uno ile Bluetooth Kontroll?? RGB LED Projesi

Bu projede, Arduino Uno, HC-06 Bluetooth modulu ve bir RGB LED kullanilarak LED'in renkleri Android telefon uzerinden kontrol edilebilmektedir. Kullanici, Android cihazdan gonderdigi harflerle LED'in rengini degistirebilir.

##  Kullanilan Malzemeler

- Arduino Uno
- HC-06 Bluetooth Modulu
- RGB LED (Ortak Anot - HIGH = kapali, LOW = acik)
- 3 x 220?? direnc
- Jumper kablolar
- Breadboard
- Android telefon (Bluetooth Serial Controller gibi bir uygulama onerilir)

##  Devre Baglantilari

| Bile??en      | Arduino Pin |
|--------------|-------------|
| RGB - Kirmizi| 9           |
| RGB - Yesil  | 10          |
| RGB - Mavi   | 11          |
| HC-06 TX     | Arduino RX (Pin 0) |
| HC-06 RX     | Arduino TX (Pin 1) |
| HC-06 VCC    | 5V          |
| HC-06 GND    | GND         |

>  Not: Ortak anot LED kullanildiginda LED'i yakmak icin pin LOW yapilir.

##  Bluetooth Komutlari

Android uygulamasindan asagidadaki harfler gonderilerek LED kontrol edilir:

| Komut | Renk     | A????klama             |
|-------|----------|----------------------|
| `k`   | Kirmizi | Yesil ve mavi kapali|
| `y`   | Yesil    | Kirmizi ve mavi kapali |
| `m`   | Mavi     | Kirmizi ve yesil kapali|
| `a`   | Beyaz    | Tum renkler acik      |
| `o`   | Kapali  | Tum renkler kapali    |

## Arduino Kod Ozeti

Kodda `SoftwareSerial` ile HC-06 uzerinden veri alinir. Gelen komutlar, `k`, `y`, `m`, `a`, `o` gibi karakterlerle RGB LED'in renklerini degistirir. Ortak anot LED oldugu icin `LOW = acik`, `HIGH = kapali` olarak calisir.

