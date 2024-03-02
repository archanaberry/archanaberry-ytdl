# archanaberry-ytdl-exec++

![icon](archanaberry/icon.png)

archanaberry-ytdl-exec++ adalah sebuah proyek yang memungkinkan Anda untuk mendownload video dari YouTube menggunakan C++. Proyek ini merupakan hasil garapan dari saya sendiri ya [Archana Berry](https://github.com/archanaberry) yang merupakan adaptasi dari proyek [youtube-dl-exec](https://github.com/microlinkhq/youtube-dl-exec) menggunakan bahasa pemrograman C++.

![archanaberry](archanaberry/archanaberryw.png)

## Fitur-fitur
- **Download Video dari YouTube**: Anda dapat dengan mudah mendownload video dari YouTube hanya dengan menggunakan perintah sederhana.
- **Pilihan Resolusi**: Anda dapat memilih resolusi video yang ingin Anda unduh dari daftar resolusi yang tersedia.
- **Output Kustom**: Anda dapat menentukan nama file keluaran sesuai keinginan Anda.
- **Python tidak diperlukan**: Tidak seperti versi JavaScript, proyek ini tidak memerlukan Python untuk dijalankan.

## Resolusi yang didukung
| Resolution | Description       |
|------------|-------------------|
| ultralow   | Ultra-Low Quality |
| 144p       | 144 pixels        |
| 240p       | 240 pixels        |
| 360p       | 360 pixels        |
| 480p       | 480 pixels        |
| 720p       | 720 pixels        |
| 1080p      | 1080 pixels       |

## Format video dari YouTube yang didukung 
| Format      | Description                     |
|-------------|---------------------------------|
| m4a         | MPEG-4 Audio                   |
| mhtml       | MHTML                           |
| mp4         | MPEG-4 Part 14                  |
| none        | No Audio                        |
| 3gp         | 3GPP Media File                 |
| webm        | WebM Media File                 |


## Cara Penggunaan
### Mengunduh dan Mengompilasi
1. Clone repositori:
2. ```git clone https://github.com/archanaberry/archanaberry-ytdl.git```
3. Masuk ke direktori proyek:
4. ```cd youtube-dl-exec-cpp```
5. Bikin konfigurasi pakai cmake
6. ```cmake .```
7. Kompilasi paket program:
8. ```make```

### Menjalankan Program
```sh
./ytdl -d <URL> -r=<RESOLUSI> -o "<NAMA_FILE_KELUARAN>"
