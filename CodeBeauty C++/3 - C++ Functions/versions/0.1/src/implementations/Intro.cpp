#include "../headers/Intro.h"


void Intro() 
{
    try {
        window_size();
        print_ascii();
        continue_message();
    }
    catch (int ex) {
        Error("Intro.cpp", "Intro()", ex);
    }
}

void window_size() {
    try {
        HWND console = GetConsoleWindow();
        RECT r;
        GetWindowRect(console, &r); //stores the console's current dimensions

        MoveWindow(console, r.left, r.top, console_width, console_height, TRUE);

    }
    catch (int ex) {
        Error("Intro.cpp", "window_size()", ex);
    }
}
void ascii_space(int size) {
    try {
        for (int i = 0; i < size; i++) {
            cout << endl;
        }
    }
    catch (int ex) {
        Error("Intro.cpp", "ascii_space(int)", ex);
    }
}
void ascii_color(int i) {
    try {
        int color = 0;
        do {
            srand(time(NULL) + i + color);
            color = rand() % 15 + 1;
        } while (color == 7 || color == 15);

        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, color);
    }
    catch (int ex) {
        Error("Intro.cpp", "ascii_color(int)", ex);
    }
}
void ascii_white() {
    try {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 15);
    }
    catch (int ex) {
        Error("Intro.cpp", "ascii_white()", ex);
    }
}

void check_char(char c, int seed) {
    try {
        if (c == '1') {
            ascii_color(seed);
            seed++;
        }
        else {
            ascii_white();
        }
        cout << c;
    }
    catch (int ex) {
        Error("Intro.cpp", "check_char(char, int)", ex);
    }
}
void generate_char(int seed, int i) {
    try {
        for (char c : ascii[i]) {
            check_char(c, seed);
        }
    }
    catch (int ex) {
        Error("Intro.cpp", "generate_char(int, int)", ex);
    }
}
void print_ascii() {
    try {
        ascii_space(3);
        int seed = -69420;
        for (int i = 0; i < ascii_lenght; i++)
        {
            generate_char(seed++, i);
            cout << endl;
        }
        ascii_space(3);
    }
    catch (int ex) {
        Error("Intro.cpp", "print_ascii()", ex);
    }
}
void continue_message() {
    try {
        Console_Color(6);
        Space(intro_outro_space);
        cout << "Press ";
        Console_Color(15);
        cout << "[";
        Console_Color(4);
        cout << "Enter";
        Console_Color(15);
        cout << "] ";
        Console_Color(6);
        cout << "to continue..." << endl;
        Space(intro_outro_space);

        cin.get();
    }
    catch (int ex) {
        Error("Intro.cpp", "continue_message()", ex);
    }
}