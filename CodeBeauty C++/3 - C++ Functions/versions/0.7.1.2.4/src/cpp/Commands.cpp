#include "../h/Commands.h"



const int COLOR_DEFAULT = 15;
const int COLOR_SYSTEM = 223;
const int COLOR_INFORMATION = 175;
const int COLOR_COMMAND = 31;
const int COLOR_ERROR = 159;


const string commands[8] = {
	{"01"},

	{'/'},
	{"commands"},

	{"close"},
	{"info"},
	{"test"},

	{"coloroff"},
	{"coloron"},
};




bool Check_Command(string input) {
	bool _gate = false;
	
	if (input == "/") {
		command_message(input, false);
		command_list(SPACE_COMMANDS); return true;
	}

	if (input[0] != '/') return false;


	for (string _command : commands) {
		if (input == '/' + _command) {
			if(input == '/' + commands[0]) command_message(input, true);
			else command_message(input, false);
			_gate = true;
		}
	}
	if (!_gate) {
		cout << "command not found!" << endl; return false;
	}
	
	input.erase(0, 1);

	if (input == "01") c01();

	else if (input == "commands") command_list(SPACE_COMMANDS);

	else if (input == "close") Close();
	else if (input == "info") info();
	else if (input == "test") test();

	else if (input == "coloroff") colorOff();
	else if (input == "coloron") colorOn();

	else {
		cout << "Command: -" << input << "- NOT FOUND!";
		return false;
	}
	
	//Console_Color(0);
	//cin;
	return true;
}


void output_message(int color, string message) {
	Console_Color(color);
	Space(SPACE_MESSAGE);
	cout << message << ' ';
	Console_Color(15);
	cout << endl;
}
void system_message(string message) {
	output_message(COLOR_SYSTEM, message);
}
void information_message(string message) {
	output_message(COLOR_INFORMATION, message);
}
void command_message(string command, bool c) {
	Console_Color(COLOR_INFORMATION);
	Space(SPACE_MESSAGE);

	cout << "Command: --";
	if (!c) {
		Console_Color(COLOR_COMMAND); cout << command;
	}
	else {
		Console_Color(COLOR_SYSTEM); cout << command;
	}
	Console_Color(COLOR_INFORMATION); cout << "-- used! ";

	Console_Color(COLOR_DEFAULT);
	cout << endl;
}
void error_message(string message) {
	output_message(COLOR_ERROR, message);
}


void command_list(int SPACE) {
	int _index = 0;

	window_size(270, 480);

	for (string _command : commands) {
		if (_command != "01") {
			if (_command == "/") {
				Space(SPACE); cout << '#' << _index << ".  " + _command << endl;
			}
			else {
				Space(SPACE); cout << '#' << _index << ".  /" + _command << endl;
			}
			
			if (_index == 1 || _index == 4) cout << endl;
		}
		_index++;
	}cout << endl;
}
void c01() {//                    Default: window_size(270, 320);
	window_size(270, 320);

	system_message("01");
	cout << endl;
}
void Close() {
	window_size(700, 460);

	system_message("Program clossing!");
	Console_Color(COLOR_DEFAULT);


	exit(0);
}
void info() {
	window_size(320, 380); //window_size(270, 380);

	cout << "by LemurWater" << endl;
	cout << "2023" << endl;
	cout << endl;
}
void test() {
	window_size(650, 380);

	Error("THIS IS A TEST ERROR", "THIS IS A TEST ERROR", 0);
	frame("TEST FRAME");
}

void colorOff() {
	window_size(270, 320);

	system_message("Not implemented!");
	cout << endl;
}
void colorOn() {
	system_message("Not implemented!");
	cout << endl;
}