# Tugas Kelas Week 9

Konfigurasi server sebagai sebagai MQTT broker dengan kriteria sebagai berikut:

## Server

```
IP          : 10.200.13.33 (private - jaringan @unram.ac.id)
OS          : Ubuntu 20.04
User        : *diinfo di kelas
Pass        : *diinfo di kelas
Pass (root) : *diinfo di kelas
```

## Software

Install `mosquito` pada server tersebut dan konfigurasi agar :
- Akses hanya dengan username password
- Buatkan akun masing-masing mahasiswa dengan username = NIM dan password random

## Skenario

Bagi kelas menjadi 3 kelompok  
1. Broker --> menginstall dan menyiapkan `mosquitto` kedalam server yang telah disediakan  
2. Publisher --> menjalankan command publish dengan topik `unram/if/iot/2023/tugas` dengan data berisi `NIM`  
3. Subscriber --> menjalankan command subscribe dengan topik yang sama dengan publisher  

Satu kelas dibagi menjadi 3 kelompok diatas dengan porsi yang seimbang, disepakati sendiri oleh mahasiswa.  

Masing-masing mahasiswa meng-capture hasil dari command yang dijalankan dan disimpan kedalam folder `week9/broker/{NIM}.jpg`, `week9/pub/{NIM}.jpg`, dan `week9/sub/{NIM}.jpg`.  

## Penilaian

Progress tugas dikirimkan melalui repo yang sama dengan melakukan `pull request` bagi masing-masing mahasiswa. Bagi yang sudah melakukan `pull request` dapat menginformasikan ke grup telegram.  

Nilai akan diberikan berdasarkan mahasiswa yang melakukan `pull request` dan NIM nya ada dalam salah satu kelompok yang telah ditentukan diatas.

## Referensi
- [Internet of Thinks: Messaging Protocols](https://drive.google.com/file/d/1BXPmxnkfyIM6dMNF-0JPiaTeRAjtroAT/view?usp=sharing)