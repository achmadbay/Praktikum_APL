#include <iostream>
#include <iomanip>

using namespace std;

void convertSpeed(int choice, double speed) {
    double hasil;

    switch (choice) {
        case 1: // Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)
            hasil = speed * 100000 / 3600;
            cout << fixed << setprecision(2);
            cout << speed << " Kilometer/jam sama dengan:\n";
            cout << hasil << " Centimeter/detik\n";
            cout << speed / 3.6 << " Meter/detik\n";
            cout << speed * 0.621371 << " Mil/jam\n";
            break;

        case 2: // Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)
            hasil = speed * 0.036 / 100;
            cout << fixed << setprecision(2);
            cout << speed << " Centimeter/detik sama dengan:\n";
            cout << hasil << " Kilometer/jam\n";
            cout << speed / 100 << " Meter/detik\n";
            cout << hasil * 27.7778 << " Mil/jam\n";
            break;

        case 3: // Meter/detik ke (Kilometer/jam, Centimeter/detik, Mil/jam)
            hasil = speed * 3.6;
            cout << fixed << setprecision(2);
            cout << speed << " Meter/detik sama dengan:\n";
            cout << hasil / 1000 << " Kilometer/jam\n";
            cout << speed * 100 << " Centimeter/detik\n";
            cout << hasil * 0.621371 << " Mil/jam\n";
            break;

        case 4: // Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)
            hasil = speed * 1.60934;
            cout << fixed << setprecision(2);
            cout << speed << " Mil/jam sama dengan:\n";
            cout << hasil << " Kilometer/jam\n";
            cout << speed * 447.04 << " Centimeter/detik\n";
            cout << hasil * 1000 / 3600 << " Meter/detik\n";
            break;

        default:
            cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai.\n";
    }
}

int main() {
    string nama, nim;
    int salah = 0;

    while (true) {
        do {
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;

            if (nama != "byhaqi" || nim != "071") {
                salah++;
                cout << "Login Gagal. Kesempatan tersisa: " << 3 - salah << " kali\n";
            }

        } while ((nama != "byhaqi" || nim != "071") && salah < 3);

        if (salah == 3) {
            cout << "Anda telah melebihi batas percobaan. Program berhenti.\n";
            break;
        }

        cout << "\nMenu Konversi Kecepatan:\n";
        cout << "1. Konversi Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)\n";
        cout << "2. Konversi Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)\n";
        cout << "3. Konversi Meter/detik ke (Kilometer/jam, Centimeter/detik, Mil/jam)\n";
        cout << "4. Konversi Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu (0-4): ";

        int menu;
        if (!(cin >> menu)) {
            cout << "Error dalam memasukkan pilihan menu. Program berhenti.\n";
            return 1;
        }

        if (menu == 0) {
            cout << "Program berhenti. Terima kasih!\n";
            break;
        }

        double kecepatan;
        cout << "Masukkan kecepatan: ";
        if (!(cin >> kecepatan)) {
            cout << "Error dalam memasukkan kecepatan. Program berhenti.\n";
            return 1;
        }

        convertSpeed(menu, kecepatan);
    }

    return 0;
}
