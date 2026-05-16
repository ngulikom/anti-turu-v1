# Anti-Turu-PC

Halo sobat digital!!
jadi di repository kali ini mamang bikin alat anti ketiduran berbasis ESP8266 + Python ☠️

jadi ceritanya alat ini bakal nyuruh kalian pencet tombol tiap beberapa detik sekali, kalo kalian gagal pencet tombolnya... alarm laptop bakal bunyi brutal sampe kalian bangun 😭

cocok buat :

* ngoding malem
* editing
* belajar
* nugas
* ato buat nyiksa diri sendiri biar ga rebahan terus

---

# Komponen Yang Dibutuhkan

* ESP8266 / NodeMCU
* Passive buzzer module 3 pin
* Push button module 3 pin
* Kabel jumper
* Laptop / PC
* Mental kuat

---

# Software Yang Dibutuhkan

* Arduino IDE
* Python
* Library pyserial
* Library pygame

install library python dulu :

```bash id="d5a9l7"
pip install pyserial pygame
```

---

# Wiring

## Buzzer

| PIN Buzzer | PIN ESP8266 |
| ---------- | ----------- |
| S          | D2          |
| +          | 3.3V        |
| -          | GND         |

---

## Push Button

| PIN Button | PIN ESP8266 |
| ---------- | ----------- |
| S          | D7          |
| +          | 3.3V        |
| -          | GND         |

karena module buttonnya udah 3 pin biasanya udah ada resistor bawaan jadi tinggal colok aja

---

# Cara Kerja

jadi nanti sistemnya bakal kaya gini :

1. ESP nunggu beberapa detik
2. buzzer bunyi
3. kalian harus pencet tombol cepet cepet
4. kalo gagal...
5. alarm mp3 di laptop bakal nyala nonstop ☠️

dan alarmnya gabisa mati sampe tombol dipencet lagi 😭

---

# Upload Program ESP

upload file :

```bash id="phu7rx"
esp_antituru.ino
```

pake Arduino IDE kaya biasa

---

# Jalankan Program Python

jalanin :

```bash id="plp0n5"
python anti_turu.py
```

nah sebelum dijalanin jangan lupa cek dulu serial portnya

bagian ini :

```python id="v5e4r9"
PORT = "/dev/ttyUSB3"
```

soalnya tiap laptop kadang beda beda

buat cek port bisa pake :

```bash id="8r0jwk"
ls /dev/ttyUSB*
```

---

# Structure

```bash id="m63f3g"
.
├── esp_antituru.ino
├── anti_turu.py
├── alarm.mp3
└── README.md
```

---

# Future Plan

kedepannya mungkin mamang mau nambah :

* statistik reaction time
* mode random timing
* OLED display
* kamera deteksi mata
* mode anti rebahan
* integration ke smart lamp
* mode setrum ☠️

---

oke sob semoga eksperimen kalian lancar jaya
sampai jumpa di project absurd lainnya

Salam Ngulik!!
