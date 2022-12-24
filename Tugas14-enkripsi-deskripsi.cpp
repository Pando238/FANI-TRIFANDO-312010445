#include <iostream>
#include <string>

using namespace std;

int main() {
  while (true) {
    cout << "Pilih menu:" << endl;
    cout << "1. Enkripsi" << endl;
    cout << "2. Deskripsi" << endl;
    cout << "3. Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
      // Enkripsi teks
      string plaintext;
      cout << "Masukkan teks yang akan dienkripsi: ";
      cin.ignore();
      getline(cin, plaintext);

      string key;
      cout << "Masukkan kunci enkripsi: ";
      getline(cin, key);

      // Pastikan panjang kunci sama dengan panjang teks
      int keyLength = key.length();
      if (keyLength < plaintext.length()) {
        int difference = plaintext.length() - keyLength;
        for (int i = 0; i < difference; i++) {
          key += key[i % keyLength];
        }
      }

      // Enkripsi teks menggunakan XOR
      string encrypted;
      for (int i = 0; i < plaintext.length(); i++) {
        encrypted += plaintext[i] ^ key[i];
      }

      cout << "Teks terenkripsi: " << encrypted << endl;
    } else if (choice == 2) {
      // Deskripsi teks
      string encrypted;
      cout << "Masukkan teks yang akan didekripsi: ";
      cin.ignore();
      getline(cin, encrypted);

      string key;
      cout << "Masukkan kunci deskripsi: ";
      getline(cin, key);

      // Pastikan panjang kunci sama dengan panjang teks terenkripsi
      int keyLength = key.length();
      if (keyLength < encrypted.length()) {
        int difference = encrypted.length() - keyLength;
        for (int i = 0; i < difference; i++) {
          key += key[i % keyLength];
        }
      }

      // Deskripsi teks menggunakan XOR
      string decrypted;
      for (int i = 0; i < encrypted.length(); i++) {
        decrypted += encrypted[i] ^ key[i];
      }

      cout << "Teks tersedia: " << decrypted << endl;
    } else if (choice == 3) {
      break;
    } else {
      cout << "Pilihan tidak valid" << endl;
    }
  }

  return 0;
}
