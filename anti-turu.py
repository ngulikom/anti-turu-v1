import serial
import time
import pygame
import os

PORT = "/dev/ttyUSB3"   # ganti kalau ESPnya beda port
BAUD = 115200
ALARM_FILE = "alarm.mp3"

alarm_playing = False

def init_audio():
    if not os.path.exists(ALARM_FILE):
        raise FileNotFoundError(f"File alarm tidak ditemukan: {ALARM_FILE}")

    pygame.mixer.init()
    pygame.mixer.music.load(ALARM_FILE)

def play_alarm():
    global alarm_playing
    if not alarm_playing:
        print("ALARM NYALA! Pencet switch buat matiin.")
        pygame.mixer.music.play(-1)
        alarm_playing = True

def stop_alarm():
    global alarm_playing
    if alarm_playing:
        pygame.mixer.music.stop()
        print("Alarm mati.")
        alarm_playing = False

def main():
    print("ANTI TURU PYTHON START")
    init_audio()

    print(f"Membuka serial port: {PORT}")
    ser = serial.Serial(PORT, BAUD, timeout=0.1)

    time.sleep(2)
    print("Python siap baca ESP...")
    print("Tekan Ctrl+C untuk stop.\n")

    while True:
        line = ser.readline().decode(errors="ignore").strip()

        if not line:
            continue

        print("ESP:", line)

        if line == "FAILED":
            play_alarm()

        elif line == "RESET_AFTER_FAILED":
            stop_alarm()

        elif line == "SUCCESS":
            stop_alarm()

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        stop_alarm()
        print("\nProgram dihentikan.")