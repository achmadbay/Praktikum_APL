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

void displayTeams(const vector<Team>& teams) {
    cout << "\nData Tim Formula 1:\n";
    for (size_t i = 0; i < teams.size(); ++i) {
        cout << i + 1 << ". " << teams[i].name << "\n";
        for (size_t j = 0; j < teams[i].drivers.size(); ++j) {
            cout << "   Driver " << j + 1 << ": " << teams[i].drivers[j].name << "\n";
        }
        cout << endl;
    }
}

void merge(vector<Team>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<Team> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i].name <= R[j].name) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Team>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void bubbleSortDescending(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSortAscending(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int binarySearchAscending(const vector<Team>& teams, const string& key) {
    int low = 0;
    int high = teams.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (teams[mid].name == key) {
            return mid;
        } else if (teams[mid].name < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int linearSearchDescending(const vector<int>& arr, int key) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int linearSearchDescending(const vector<Team>& teams, int key) {
    for (size_t i = 0; i < teams.size(); ++i) {
        if (teams[i].drivers.size() == key) {
            return i;
        }
    }
    return -1;
}


int addTeam(vector<Team>& teams) {
    if (teams.size() < MAX_TEAMS) {
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

        teams.push_back(newTeam);
        cout << "Tim berhasil ditambahkan!\n";
        return 1;
    } else {
        cout << "Batas maksimal tim telah tercapai.\n";
        return 0;
    }

    
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Lihat Data Tim\n";
    cout << "2. Tambah Tim\n";
    cout << "3. Sorting Tim (Huruf Ascending)\n";
    cout << "4. Sorting Jumlah Driver (Angka Descending)\n";
    cout << "5. Sorting Jumlah Driver (Angka Ascending)\n";
    cout << "6. Searching Tim (Nama Ascending)\n";
    cout << "7. Searching Jumlah Driver (Jumlah Descending)\n";
    cout << "8. Keluar\n";
    cout << "Pilih menu (1-8): ";
}

int main() {
    if (!login()) {
        return 1;
    }

    vector<Team> teams = {
        {"Red Bull", {{"Perez"}, {"Verstappen"}}},
        {"Ferrari", {{"Sainz"}, {"Leclerc"}}},
        {"McLare", {{"Piastri"}}}
    };

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                displayTeams(teams);
                break;

            case 2:
                addTeam(teams);
                break;

            case 3:
                mergeSort(teams, 0, teams.size() - 1);
                cout << "\nData Tim Formula 1 (Sorted Ascending by Name):\n";
                displayTeams(teams);
                break;

            case 4:
                {
                    vector<int> driverCounts;
                    for (const auto& team : teams) {
                        driverCounts.push_back(team.drivers.size());
                    }
                    bubbleSortDescending(driverCounts);
                    cout << "\nData Tim Formula 1 (Sorted Descending by Driver Count):\n";
                    for (const auto& count : driverCounts) {
                        cout << count << endl;
                    }
                    break;
                }

            case 5:
                {
                    vector<int> driverCounts;
                    for (const auto& team : teams) {
                        driverCounts.push_back(team.drivers.size());
                    }
                    selectionSortAscending(driverCounts);
                    cout << "\nData Tim Formula 1 (Sorted Ascending by Driver Count):\n";
                    for (const auto& count : driverCounts) {
                        cout << count << endl;
                    }
                    break;
                }

            case 6:
                {
                    string searchKey;
                    cout << "Masukkan nama tim yang ingin dicari: ";
                    cin >> searchKey;
                    int index = binarySearchAscending(teams, searchKey);
                    if (index != -1) {
                        cout << "Tim ditemukan pada indeks: " << index + 1 << endl;
                    } else {
                        cout << "Tim tidak ditemukan.\n";
                    }
                    break;
                }

            case 7:
                {
                    int searchKey;
                    cout << "Masukkan jumlah driver yang ingin dicari: ";
                    cin >> searchKey;
                    int index = linearSearchDescending(teams, searchKey);
                    if (index != -1) {
                        cout << "Tim ditemukan pada indeks: " << index + 1 << endl;
                    } else {
                        cout << "Tim tidak ditemukan.\n";
                    }
                    break;
                }

            case 8:
                cout << "Program berhenti.\n";
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice != 8);

    return 0;
}
