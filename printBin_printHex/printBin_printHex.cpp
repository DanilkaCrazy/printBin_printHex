
using namespace std;

#include <iostream>

// Функция printBin, принимающая на вход нетипизированный указатель на данные и размер данных в байтах.
void printBin(void* data, size_t size) {
    unsigned char* ptr = static_cast<unsigned char*>(data);
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            cout << (((ptr[i] >> j) & 1) ? "1" : "0");
        }
        cout << " ";
    }
}

// Аналогичное написание функции printHex
void printHex(void* data, size_t size) {
    unsigned char* ptr = static_cast<unsigned char*>(data);
    ios_base::fmtflags f(cout.flags());
    for (int i = size - 1; i >= 0; i--) {
        cout << std::hex << static_cast<int>(ptr[i]) << " ";
    }
    cout.flags(f);
}

    int main() {
        int num = 1000;
        string str = "Hello, world!";

        // Функция должна выводить на экран входные данные в двоичном представлении, начиная со старшего разряда.
        printBin(&num, sizeof(num));
        cout << endl;
        // Функция printHex, выводит данные в 16ричном представлении.
        printHex(&num, sizeof(num));
        cout << endl;

        printBin(&str, sizeof(str));
        cout << endl;
        printHex(&str, sizeof(str));
        cout << endl;

        return 0;
    }


