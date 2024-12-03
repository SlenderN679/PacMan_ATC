#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <Windows.h>
#include <chrono>
#include <thread>
using namespace std;
void menu();
void Settings();
int x,y, opd, d;
void menu() {
    cout << "\033[37m" << setw(20) << "PAC-MAN" << endl << endl << endl;
    cout << "\033[37m" << setw(18) << "Play" << endl;
    cout << "\033[37m" << setw(20) << "Settings" << endl;
    cout << "\033[37m" << setw(18) << "Exit" << endl << endl;
    cout << "\033[37m" << setw(22) << "Press ENTER" << endl;
    if (d == 1) {
        cout << "Easy mode" << endl;
    }
    if (d == 2) {
        cout << "Medium mode" << endl;
    }
    if (d == 3) {
        cout << "Hard mode" << endl;
    }
    cin >> x;
    if (x == 1) {
        system("cls");
        cout << "\033[37m" << setw(20) << "PAC-MAN" << endl << endl << endl;
        cout << "\033[33m" << setw(18) << ">Play" << endl;
        cout <<"\033[37m" << setw(20) << "Settings" << endl;
        cout << "\033[37m" << setw(18) << "Exit" << endl << endl;
        this_thread::sleep_for(chrono::seconds(2));
        system("cls");
        cout << "jogo";
    }
    if (x == 2) {
        Settings();
        
    }
    if (x == 3) {
        system("cls");
        cout << "\033[37m" << setw(20) << "PAC-MAN" << endl << endl << endl;
        cout << "\033[37m" << setw(18) << "Play" << endl;
        cout << "\033[37m" << setw(20) << "Settings" << endl;
        cout << "\033[33m" << setw(18) << ">Exit" << endl << endl;
        this_thread::sleep_for(chrono::milliseconds(700));
        exit(0);

    }
}
void Settings() {
    system("cls");
    cout << "\033[37m" << setw(20) << "PAC-MAN" << endl << endl << endl;
    cout << "\033[37m" << setw(18) << "Play" << endl;
    cout << "\033[33m" << setw(20) << ">Settings" << endl;
    cout << "\033[37m" << setw(18) << "Exit" << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(700));
    system("cls");
    cout << "\033[37m" << setw(20) << "PAC-MAN" << endl << endl << endl;
    cout << setw(20) << "Controls" << endl;
    cout << setw(22) << "Difficulty" << endl;
    cout << setw(18) << "Back" << endl;
    cin >> y;
    if (y == 1) {
        system("cls");
        cout << "\033[37m" << setw(20) << "PAC-MAN" << endl << endl << endl;
        cout << "\033[33m" << setw(20) << ">Controls" << endl;
        cout << "\033[37m" << setw(22) << "Difficulty" << endl;
        cout << "\033[37m" << setw(18) << "Back" << endl;
        this_thread::sleep_for(chrono::milliseconds(700));
        system("cls");
        cout << "\033[36m" << "=======CONTROLS=======" << endl;
        cout << "Move Up" << setw(16) << u8"\u2191\n";
        cout << "Move Down" << setw(14) << u8"\u2193\n";
        cout << "Move Left" << setw(14) << u8"\u2190\n";
        cout << "Move Right" << setw(13) << u8"\u2192\n";
        cout << "Back" << setw(8) << endl;
        cin >> y;
        if (y == 4) {
            system("cls");
            cout << "\033[36m" << "=======CONTROLS=======" << endl;
            cout << "Move Up" << setw(16) << u8"\u2191\n";
            cout << "Move Down" << setw(14) << u8"\u2193\n";
            cout << "Move Left" << setw(14) << u8"\u2190\n";
            cout << "Move Right" << setw(13) << u8"\u2192\n";
            cout << "\033[33m" << ">Back" << setw(8) << endl;
            this_thread::sleep_for(chrono::milliseconds(700));
            system("cls");
            Settings();
        }
    }
    if (y == 2) {
        system("cls");
        cout << "\033[37m" << setw(20) << "PAC-MAN" << endl << endl << endl;
        cout << "\033[37m" << setw(20) << "Controls" << endl;
        cout << "\033[33m" << setw(22) << ">Difficulty" << endl;
        cout << "\033[37m" << "\033[37m" << setw(18) << "Back" << endl;
        this_thread::sleep_for(chrono::milliseconds(700));
        system("cls");
        cout << "\033[37m" << "========DIFFICULTY========" << endl;
        cout <<"\033[37m" << "Easy"  << "\033[37m" << setw(10) << "Medium"  <<"\033[37m" << setw(10) << "Hard" << endl;
        cout << "\033[37m" << setw(4) << u8"\u2191" << "\033[37m" << setw(12) << u8"\u2191" << "\033[37m" << setw(12) << u8"\u2191"<< endl;
        cin >> opd;//opção da dificuldade
        while (true) {
            if (opd == 1) {
                system("cls");
                cout << "\033[37m" << "========DIFFICULTY========" << endl;
                cout << "\033[33m" << "Easy" << "\033[37m" << setw(10) << "Medium" << "\033[37m" << setw(10) << "Hard" << endl;
                cout << "\033[33m" << setw(4) << u8"\u2191" << "\033[37m" << setw(12) << u8"\u2191" << "\033[37m" << setw(12) << u8"\u2191" << endl;
                cin >> opd;
                d = 1;
            }
            if (opd == 2) {
                system("cls");
                cout << "\033[37m" << "========DIFFICULTY========" << endl;
                cout << "\033[37m" << "Easy" << "\033[33m" << setw(10) << "Medium" << "\033[37m" << setw(10) << "Hard" << endl;
                cout << "\033[37m" << setw(4) << u8"\u2191" << "\033[33m" << setw(12) << u8"\u2191" << "\033[37m" << setw(12) << u8"\u2191" << endl;
                cin >> opd;
                d = 2;
            }
            if (opd == 3) {
                system("cls");
                cout << "\033[37m" << "========DIFFICULTY========" << endl;
                cout << "\033[37m" << "Easy" << "\033[37m" << setw(10) << "Medium" << "\033[33m" << setw(10) << "Hard" << endl;
                cout << "\033[37m" << setw(4) << u8"\u2191" << "\033[37m" << setw(12) << u8"\u2191" << "\033[33m" << setw(12) << u8"\u2191" << endl;
                cin >> opd;
                d = 3;
            }
            if (opd == 4) {
                Settings();
                return;
            }
        }
    }
    if (y == 3) {
        system("cls");
        cout << "\033[37m" << setw(20) << "PAC-MAN" << endl << endl << endl;
        cout << setw(20) << "Controls" << endl;
        cout << setw(22) << "Difficulty" << endl;
        cout << "\033[33m" << setw(18) << ">Back" << endl;
        this_thread::sleep_for(chrono::milliseconds(700));
        system("cls");
        menu();
    }

}
int main() {
    system("chcp 65001");
    system("cls");
    menu();
}