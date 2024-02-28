#include <iostream>

using namespace std;

    //Mendeklarasikan fungsi compress yang menerima array karakter (chars) dan panjang array (length) sebagai argumen
    int compress(char* chars, int length) {
    //Inisialisasi variabel lokal menggunakan index dan count
    int index = 0;
    int count = 1;
    //Menggunakan looping for melalui array karakter dimulai dari index 1
    for (int i = 1; i <= length; i++) {
        //Mengecek apakah karakter ini sama dengan karakter sebelumnya. Jika sama increment 'count'
        if (chars[i] == chars[i-1]) {
            count++;
        } else {
            //Menyimpan karakter yang berbeda dan increment index
            chars[index++] = chars[i-1];
        {
                //Mengonversi 'count' ke dalam string dan menyimpan setiap digit sebagai karakter dalam array
                string count_str = to_string(count);
                for (int j = 0; j < count_str.length(); j++) {
                    chars[index++] = count_str[j];
                }
            }
            count = 1;
        }
    }
    //Mengembalikan panjang array
    return index;
}

int main() {

    int length;
    cout << "Masukan Panjang array : ";
    cin >> length;
    char chars[length];
    cout << "Masukan karakter array : ";
    for (int i = 0; i < length; i++) {
        cin >> chars[i];
    }
    int compressed_length = compress(chars, length);
    for (int i = 0; i < compressed_length; i++) {
        cout << chars[i];
    }
    cout << "\n\n----------------------------------------" << endl;
    cout << "Program ini dibuat oleh:" << endl;
    cout << "Nama   : Indira Ayu Anggraeni" << endl;
    cout << "NPM    : 2310631170021" << endl;

    return 0;
}
