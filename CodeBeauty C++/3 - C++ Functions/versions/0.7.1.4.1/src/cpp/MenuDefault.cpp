#include "../h/MenuDefault.h"



const int space_title = 3;
const int space_menu = 7;
const int space_input = 2;

const int color_title = 7;
const int color_tutorial = 7;


const int color_r_menu_main = 4;
const int color_r_menu_course = 6;
const int color_r_menu_functions = 14;


const int color_g_menu_main = 10;
const int color_g_menu_course = 2;
const int color_g_menu_functions = 11;


const int color_b_menu_main = 1;
const int color_b_menu_course = 3;
const int color_b_menu_functions = 11;


//color functions: red
//color pointers: gree
//color data structures: blue

const int color_information = 7;
const int color_error = 7;
const int color_system = 223;


int menu_iterations = 0;

int starter_color = 0;



const string input_symbol = "=>";

const int color_user_input = 31;
const int color_input_symbol = 25; // 27 30 25


const int options_menu_size = 3;
const string options_menu_a[options_menu_size] = {
	{"/."},
	{"-."},
	{"C."},
};
const string options_menu_b[options_menu_size] = {
	{"List of commands"},
	{"Main menu"},
	{"CLOSE"},
};

const string format_string = " - - - - - - - - - - - - - - - - ";
const string format_string_2 = "+++++++++++++++++++++++++++++++++++++++++++++++";



//int OPTIONS_MENU_SIZE() {
//	return options_menu_size;
//}
//const string* OPTIONS_MENU_A() {
//	return options_menu_a;
//}
//const string* OPTIONS_MENU_B() {
//	return options_menu_b;
//}

int Starter_Color() {
	return starter_color;
}


void Input_Error() {

}
const string message_error_input = "User input is NOT valid!";



void window_size(int width, int height) {
	try {
		HWND console_ = GetConsoleWindow();
		RECT r_;

		GetWindowRect(console_, &r_); //stores the console's current dimensions
		MoveWindow(console_, r_.left, r_.top, width, height, TRUE);
	}
	catch (int ex) {
		Error("Menu.cpp", "window_size(int, int)", ex);
	}
}

void random_color() {
	srand((unsigned int)time(NULL));
	starter_color = rand() % 3 + 1;
}



void Print_Menu(const string MENU[], const int SIZE) {
	
	first_menu();

	new_page();
	title(MENU[1]);
	print_lines(MENU, SIZE);


	custom_input();
}


void first_menu() {
	int i_ = 0;
	random_color();
	switch (starter_color) {
	case 1: i_ = color_r_menu_main; break;
	case 2: i_ = color_g_menu_main; break;
	case 3: i_ = color_b_menu_main; break;
	}
	Console_Color(i_);
}

void new_page() {
	system("cls");
	format();

	cout << endl;
	Space(space_title);
}
void format() {
	cout << format_string << endl;
	cout << endl;
}

void title(string text) {
	menu_iterations++;
	cout << endl;
	Space(space_title);
	cout << '[' << menu_iterations << "] - ";
	cout << text << endl;
	cout << endl;
}


void print_default_options(string MENU_SPACE) {
	for (int i = 0; i < options_menu_size; i++)
	{
		string s_ = options_menu_a[i] + MENU_SPACE + options_menu_b[i];

		Space(space_menu); cout << s_ << endl;
	}cout << endl;
}

void print_custom_options(const string MENU[], int SIZE) {
	for (int i = 1; i < SIZE; i++)
	{
		Space(space_menu); cout << *(MENU + i) << endl;
	}cout << endl;
}

void print_lines(const string MENU[], int SIZE) {

	print_default_options(MENU[0]);
	print_custom_options(MENU, SIZE);

	cout << endl;
}

void End_Menu() {
	cout << endl;
	cout << format_string_2 << endl;;
	cout << endl;
	Console_Color(color_tutorial);

	Pause();
}








void custom_input() {
	Console_Color(color_input_symbol);
	cout << input_symbol;
	Console_Color(color_user_input);

	Space(space_input);
}
string Get_User_Input() {
	string input_;
	cin >> input_;

	return input_;
}


bool Check_Default_Input(char input) {
	if (input == options_menu_a[0][0]) {//                 /. Commands
		//list of commands
		return true;
	}
	else if (toupper(input) == options_menu_a[1][0]) {//   C. CLOSE
		Close();
		return true;
	}
	else return false;
}


void Pause() {
	Console_Color(color_system);


#ifdef _WIN32
	system("pause");
	return;
#endif
	system("read");


	Console_Color();
}


string Format_String_2(){
	return format_string_2;
}