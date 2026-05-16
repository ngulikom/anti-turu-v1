# Anti-Turu-PC V1

Halo sobat digital!!
jadi di repository kali ini mamang bikin alat anti ketiduran berbasis ESP8266 + Python ☠️

jadi ceritanya alat ini bakal nyuruh kalian pencet tombol tiap beberapa detik sekali, kalo kalian gagal pencet tombolnya... alarm laptop bakal bunyi brutal sampe kalian bangun 😭

cocok buat :

* ngoding malem
* editing
* belajar
* nugas
* ato buat nyiksa diri sendiri biar ga rebahan terus

<img width="541" height="525" alt="Screenshot_2026-05-16_09-58-44" src="https://github.com/user-attachments/assets/8288371c-fd8f-4409-ac57-84c0a4b773d4" />

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

```bash id="4fq9uy"
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

```bash id="ttlb4f"
esp_antituru.ino
```

pake Arduino IDE kaya biasa

---

# Jalankan Program Python

jalanin :

```bash id="x4n1ic"
python anti_turu.py
```

---

# Setting Serial Port

nah sebelum dijalanin jangan lupa cek dulu serial portnya

bagian ini :

```python id="aq3myf"
PORT = "COM4"
```

---

## Kalo Pake Windows

biasanya portnya :

* COM3
* COM4
* COM5
* dst

buat cek port :

1. colok ESP8266
2. buka Device Manager
3. buka :

```text id="nrbjlwm"
Ports (COM & LPT)
```

nanti bakal muncul misal :

```text id="ut2sbr"
USB-SERIAL CH340 (COM4)
```

berarti tinggal ubah jadi :

```python id="2i3yrn"
PORT = "COM4"
```

---

## Kalo Pake Linux

cek port pake :

```bash id="1fj5sy"
ls /dev/ttyUSB*
```

biasanya muncul :

```text id="a1l5t0"
/dev/ttyUSB0
```

atau :

```text id="wb6zyx"
/dev/ttyUSB1
```

lalu ubah jadi :

```python id="y5dz4m"
PORT = "/dev/ttyUSB0"
```



---


# Built With

* ESP8266
* Python
* PySerial
* Pygame
* Arduino IDE

---

oke sob semoga eksperimen kalian lancar jaya
sampai jumpa di project absurd lainnya

Salam Ngulik!!

Project absurd by [Ngulikom](https://youtube.com/@ngulikom)
