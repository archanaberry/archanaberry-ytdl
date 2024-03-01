# archanaberry-ytdl-exec++

![icon](archanaberry/icon.png)

archanaberry-ytdl-exec++ adalah sebuah proyek yang memungkinkan Anda untuk mendownload video dari YouTube menggunakan C++. Proyek ini merupakan hasil garapan dari [Archana Berry](https://github.com/archanaberry) yang merupakan adaptasi dari proyek [youtube-dl-exec](https://github.com/microlinkhq/youtube-dl-exec) menggunakan bahasa pemrograman C++.

## Fitur-fitur
- **Download Video dari YouTube**: Anda dapat dengan mudah mendownload video dari YouTube hanya dengan menggunakan perintah sederhana.
- **Pilihan Resolusi**: Anda dapat memilih resolusi video yang ingin Anda unduh dari daftar resolusi yang tersedia.
- **Output Kustom**: Anda dapat menentukan nama file keluaran sesuai keinginan Anda.
- **Python tidak diperlukan**: Tidak seperti versi JavaScript, proyek ini tidak memerlukan Python untuk dijalankan.

## Cara Penggunaan
### Mengunduh dan Mengompilasi
1. Clone repositori: `git clone https://github.com/archanaberry/youtube-dl-exec-cpp.git`
2. Masuk ke direktori proyek: `cd youtube-dl-exec-cpp`
3. Kompilasi program: `make`

### Menjalankan Program
```sh
./ytdl -d <URL> -r=<RESOLUSI> -o "<NAMA_FILE_KELUARAN>"
