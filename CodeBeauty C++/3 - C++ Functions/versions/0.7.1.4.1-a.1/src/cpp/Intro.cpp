#include "../h/Intro.h"



int seed = -42069;


const int DELAY = 1;
const int CONSOLE_WIDTH = 1200, CONSOLE_HEIGHT = 550;
const int ASCII_LENGTH = 22;

const int COLOR_0 = 8;



const string ASCII[ASCII_LENGTH]
{
    {"      000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000001100000000000000011110000110000000000000011100000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000001100000000000000111100000110000000000000001000001100000000000000000000000000000000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000000000000000000000100000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000111100001011100000100000011110000101110001111000011111100110000100000000000111010001111000001100011100001111001111000000000000000000"},
    {"      000000000000000000101100001111110000100000011110000111111000111000011111100110001100000000001111110001111100011010111110010001001000000000000000000000"},
    {"      000000000000000000001100001100110111111100000110000100011000001000000100000010001100000000001100010000000100010001100010010001101000000000000000000000"},
    {"      000000000000000000001100001000110000100000000110000100011000001000000100000011001000000000001000010001111100110001000010111111100110000000000000000000"},
    {"      000000000000000000001100001000110000100000000110000100011000001000000100000001001000000000001000010011100100010001100010110000000011000000000000000000"},
    {"      000000000000000000001100001000110000100000000110000100011000001000000100000001011000000000001100110011000100011110011100010000000001100000000000000000"},
    {"      000000000000000000111111001000110000100000011111100100011001111110000111110001110000000000001111110011111110000100001000011001001001000000000000000000"},
    {"      000000000000000001111111001000110000100000111111100100011001111111000011100000110000000000000011010001110110000000000000001111001110000000000000000000"},
    {"      000000000000000000000000000000000000000000000000000000000000000000000000000000110000111111100000010000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000000000000000000000000000000000000000000000000000000000000011100000000000000001110000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000000000000000000000000000000000000000000000000000000000000111000000000000001111100000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},
    {"      000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},
};



void Intro() 
{
    try {
        window_size(CONSOLE_WIDTH, CONSOLE_HEIGHT);

        print_ascii();


        sleep_until(system_clock::now() + seconds(DELAY));

        system("cls");
    }
    catch (int ex) {
        Error("Intro.cpp", "Intro()", ex);
    }
}

void ascii_space(int size) {
    for (int i = 0; i < size; i++) {
        cout << endl;
    }
}
void ascii_color(int i) {
    int color = 0;
    do {
        srand((unsigned int)time(NULL));
        color = (rand() + i + color) % 15 + 1;
    } while (color == 7 || color == 15);


    Console_Color(color);
}
void ascii_white() {
    Console_Color(COLOR_0);
}
void print_ascii() {
    ascii_space(3);
    for (int i = 0; i < ASCII_LENGTH; i++)
    {
        generate_char(i);
    }

    ascii_space(3);
}
void check_char(char c) {
    if (c == '1') {
        ascii_color(seed);
        seed++;
    }
    else {
        ascii_white();
    }
    cout << c;
}
void generate_char(int i) {
    for (char c : ASCII[i]) {
        check_char(c);
        seed++;
    }
    cout << endl;
}