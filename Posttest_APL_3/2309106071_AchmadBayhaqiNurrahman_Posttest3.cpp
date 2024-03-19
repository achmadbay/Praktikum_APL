#include <iostream>
#include <string>

using namespace std;

struct Driver {
    string name;
};

struct Team {
    string name;
    Driver driver1;
    Driver driver2;
};

struct User {
    string username;
    string nim;
};

const User validUser = {"byhaqi", "071"};
const int MAX_LOGIN_ATTEMPTS = 3;
const int MAX_TEAMS = 10;  

int login() {
    int attempts = 0;
    while (attempts < MAX_LOGIN_ATTEMPTS) {
        string username, nim;
        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (username == validUser.username && nim == validUser.nim) {
            cout << "Login berhasil!\n";
            return 1; // Berhasil
        } else {
            cout << "Login gagal.\n";
            attempts++;
        }
    }

    cout << "Anda telah melebihi batas percobaan login. Program berhenti.\n";
    return 0; // Gagal
}

void displayTeams(const Team teams[], int teamCount) {
    cout << "\nData Tim Formula 1:\n";
    for (int i = 0; i < teamCount; ++i) {
        cout << i + 1 << ". " << teams[i].name << "\n";
        cout << "   Driver 1: " << teams[i].driver1.name << "\n";
        cout << "   Driver 2: " << teams[i].driver2.name << "\n\n";
    }
}

int addTeam(Team teams[], int& teamCount) {
    if (teamCount < MAX_TEAMS) {
        cout << "Nama Tim: ";
        cin >> teams[teamCount].name;

        cout << "Nama Driver 1: ";
        cin >> teams[teamCount].driver1.name;

        cout << "Nama Driver 2: ";
        cin >> teams[teamCount].driver2.name;

        cout << "Tim berhasil ditambahkan!\n";
        teamCount++;
        return 1; // Berhasil
    } else {
        cout << "Batas maksimal tim telah tercapai.\n";
        return 0; // Gagal
    }
}

int updateTeam(Team teams[], int teamCount) {
    if (teamCount > 0) {
        int index;
        cout << "Pilih tim yang ingin di ubah (1-" << teamCount << "): ";
        cin >> index;

        if (index >= 1 && index <= teamCount) {
            cout << "Nama Tim: ";
            cin >> teams[index - 1].name;

            cout << "Nama Driver 1: ";
            cin >> teams[index - 1].driver1.name;

            cout << "Nama Driver 2: ";
            cin >> teams[index - 1].driver2.name;

            cout << "Data tim berhasil diubah!\n";
            return 1; // Berhasil
        } else {
            cout << "Indeks tidak valid.\n";
            return 0; // Gagal
        }
    } else {
        cout << "Belum ada data tim untuk diubah.\n";
        return 0; // Gagal
    }
}

int deleteTeam(Team teams[], int& teamCount) {
    if (teamCount > 0) {
        int index;
        cout << "Masukkan indeks tim yang ingin dihapus (1-" << teamCount << "): ";
        cin >> index;

        if (index >= 1 && index <= teamCount) {
            for (int i = index - 1; i < teamCount - 1; ++i) {
                teams[i] = teams[i + 1];
            }
            teamCount--;
            cout << "Data tim berhasil dihapus!\n";
            return 1; // Berhasil
        } else {
            cout << "Indeks tidak valid.\n";
            return 0; // Gagal
        }
    } else {
        cout << "Belum ada data tim untuk dihapus.\n";
        return 0; // Gagal
    }
}

// Fungsi untuk mencari tim berdasarkan nama
int searchTeamByName(const Team teams[], const string& name, int index, int teamCount) {
    if (index == teamCount) {
        return 0; // Gagal: tim tidak ditemukan
    }
    if (teams[index].name == name) {
        return 1; // Berhasil: tim ditemukan
    }
    // Panggil rekursif untuk mencari tim di indeks berikutnya
    return searchTeamByName(teams, name, index + 1, teamCount);
}

// Fungsi rekursif untuk menampilkan menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Lihat Data Tim\n";
    cout << "2. Tambah Tim\n";
    cout << "3. Ubah Data Tim\n";
    cout << "4. Hapus Tim\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu (1-5): ";
}

int main() {
    if (!login()) {
        return 1; // Program berhenti jika login gagal
    }

    Team teams[MAX_TEAMS] = {
        {"Red Bull", {"Perez"}, {"Verstappen"}},
        {"Ferrari", {"Sainz"}, {"Leclerc"}},
        {"McLaren", {"Piastri"}, {"Norris"}}
    };
    int teamCount = 3;

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Lihat Data Tim
                displayTeams(teams, teamCount);
                break;

            case 2: // Tambah Tim
                addTeam(teams, teamCount);
                break;

            case 3: // Ubah Data Tim
                updateTeam(teams, teamCount);
                break;

            case 4: // Hapus Tim
                deleteTeam(teams, teamCount);
                break;

            case 5: // Out
                cout << "Program berhenti.\n";
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 5);

    return 0;
}
