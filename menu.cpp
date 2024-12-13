#pragma once
#include "Menu.h"

// Desenho genérico para menus
void draw_menu(const char* title, const char* options[], int num_options, int highlight) {
    clear();
    mvprintw(0, (COLS - (int)strlen(title)) / 2, title); // Título centralizado
    for (int i = 0; i < num_options; ++i) {
        if (i == highlight) {
            attron(A_REVERSE);
            mvprintw(2 + i, (COLS - (int)strlen(options[i])) / 2, options[i]);
            attroff(A_REVERSE);
        }
        else {
            mvprintw(2 + i, (COLS - (int)strlen(options[i])) / 2, options[i]);
        }
    }
    refresh();
}

void menu() {
    int highlight = 0;
    int choice;
    const char* options[] = { "Play", "Settings", "Exit" };
    const int num_options = 3;

    while (true) {
        draw_menu("PAC-MAN", options, num_options, highlight);
        choice = getch();
        switch (choice) {
        case KEY_UP:
            highlight = (highlight == 0) ? num_options - 1 : highlight - 1;
            break;
        case KEY_DOWN:
            highlight = (highlight == num_options - 1) ? 0 : highlight + 1;
            break;
        case '\n': // Enter
            if (highlight == 0) {
                clear();

                refresh();
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
            else if (highlight == 1) {
                Settings();
            }
            else if (highlight == 2) {
                endwin(); // Encerra a janela curses
                exit(0);
            }
            break;
        default:
            break;
        }
    }
}

void Settings() {
    int highlight = 0;
    int choice;
    const char* options[] = { "Controls", "Difficulty", "Back" };
    const int num_options = 3;
    int d;

    while (true) {
        draw_menu("Settings", options, num_options, highlight);
        choice = getch();
        switch (choice) {
        case KEY_UP:
            highlight = (highlight == 0) ? num_options - 1 : highlight - 1;
            break;
        case KEY_DOWN:
            highlight = (highlight == num_options - 1) ? 0 : highlight + 1;
            break;
        case '\n': // Enter
            if (highlight == 0) {
                clear();
                mvprintw(5, (COLS - 17) / 2, "Controls:");
                mvprintw(7, (COLS - 25) / 2, "Move Up:    Arrow Up");
                mvprintw(8, (COLS - 25) / 2, "Move Down:  Arrow Down");
                mvprintw(9, (COLS - 25) / 2, "Move Left:  Arrow Left");
                mvprintw(10, (COLS - 25) / 2, "Move Right: Arrow Right");
                mvprintw(12, (COLS - 10) / 2, "Press any key to go back");
                refresh();
                getch();
            }
            else if (highlight == 1) {
                clear();
                mvprintw(5, (COLS - 20) / 2, "Choose Difficulty:");
                mvprintw(7, (COLS - 20) / 2, "1. Easy");
                mvprintw(8, (COLS - 20) / 2, "2. Medium");
                mvprintw(9, (COLS - 20) / 2, "3. Hard");
                refresh();
                int difficulty = getch() - '0';
                if (difficulty >= 1 && difficulty <= 3) {
                    d = difficulty;
                }
            }
            else if (highlight == 2) {
                return;
            }
            break;
        default:
            break;
        }
    }
}