#include <iostream>
#include <string>
#include <vector> 
#include <limits> 

using namespace std;

struct Driver {
    string name;
};

struct Team {
    string name;
    vector<Driver> drivers; 
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
            return 1; 
        } else {
            cout << "Login gagal.\n";
            attempts++;
        }
    }

    cout << "Anda telah melebihi batas percobaan login. Program berhenti.\n";
    return 0; 
}

void displayTeams(const vector<Team>* teams) {
    cout << "\nData Tim Formula 1:\n";
    for (size_t i = 0; i < teams->size(); ++i) {
        cout << i + 1 << ". " << (*teams)[i].name << "\n";
        for (size_t j = 0; j < (*teams)[i].drivers.size(); ++j) {
            cout << "   Driver " << j + 1 << ": " << (*teams)[i].drivers[j].name << "\n";
        }
        cout << endl;
    }
}

int addTeam(vector<Team>* teams) {
    if (teams->size() < MAX_TEAMS) {
        Team newTeam;
        cout << "Nama Tim: ";
        cin >> newTeam.name;

        int numDrivers;
        cout << "Masukkan jumlah driver: ";
        cin >> numDrivers;

        for (int i = 0; i < numDrivers; ++i) {
            Driver driver;
            cout << "Nama Driver " << i + 1 << ": ";
            cin >> driver.name;
            newTeam.drivers.push_back(driver);
        }

        teams->push_back(newTeam);
        cout << "Tim berhasil ditambahkan!\n";
        return 1; 
    } else {
        cout << "Batas maksimal tim telah tercapai.\n";
        return 0; 
    }
}

int updateTeam(vector<Team>* teams) {
    if (!teams->empty()) {
        size_t index;
        cout << "Pilih tim yang ingin diubah (1-" << teams->size() << "): ";
        cin >> index;

        if (index >= 1 && index <= teams->size()) {
            cout << "Nama Tim: ";
            cin >> (*teams)[index - 1].name;

            cout << "Masukkan jumlah driver baru: ";
            size_t numDrivers;
            cin >> numDrivers;

            (*teams)[index - 1].drivers.clear(); 

            for (size_t i = 0; i < numDrivers; ++i) {
                Driver driver;
                cout << "Nama Driver " << i + 1 << ": ";
                cin >> driver.name;
                (*teams)[index - 1].drivers.push_back(driver);
            }

            cout << "Data tim berhasil diubah!\n";
            return 1; 
        } else {
            cout << "Indeks tidak valid.\n";
            return 0; 
        }
    } else {
        cout << "Belum ada data tim untuk diubah.\n";
        return 0; 
    }
}

int deleteTeam(vector<Team>* teams) {
    if (!teams->empty()) {
        size_t index;
        cout << "Masukkan indeks tim yang ingin dihapus (1-" << teams->size() << "): ";
        cin >> index;

        if (index >= 1 && index <= teams->size()) {
            teams->erase(teams->begin() + index - 1);
            cout << "Data tim berhasil dihapus!\n";
            return 1; 
        } else {
            cout << "Indeks tidak valid.\n";
            return 0; 
        }
    } else {
        cout << "Belum ada data tim untuk dihapus.\n";
        return 0; 
    }
}

int searchTeamByName(const vector<Team>* teams, const string& name) {
    for (size_t i = 0; i < teams->size(); ++i) {
        if ((*teams)[i].name == name) {
            return i; 
        }
    }
    return -1; 
}

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
        return 1; 
    }

    vector<Team> teams = {
        {"Red Bull", {{"Perez"}, {"Verstappen"}}},
        {"Ferrari", {{"Sainz"}, {"Leclerc"}}},
        {"McLaren", {{"Piastri"}, {"Norris"}}}
    };

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: 
                displayTeams(&teams);
                break;

            case 2: 
                addTeam(&teams);
                break;

            case 3: 
                updateTeam(&teams);
                break;

            case 4: 
                deleteTeam(&teams);
                break;

            case 5: 
                cout << "Program berhenti.\n";
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    } while (choice != 5);

    return 0;
}
