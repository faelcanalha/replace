#include <iostream>
#include <regex>
#include <conio.h>
#include <Windows.h>

#include "Miscellaneous/clipboardxx.hpp"
#include "Miscellaneous/color.hpp"

using namespace std;

clipboardxx::clipboard clipboard;

int main() {
home:
	SetConsoleTitleA("Replace | by: fael#2081");
	system("cls");
	cout << endl << endl << "      [" << dye::grey("1") << "] " << "Add " << dye::aqua("00 ") << "to " << dye::aqua("AOB CODE") << endl;
	cout << "      [" << dye::grey("2") << "] " << "Remove " << dye::aqua("00 ") << "from " << dye::aqua("AOB CODE") << endl;
	cout << endl << "      [" << dye::grey("3") << "] " << "Convert " << dye::aqua("AOB CODE ") << "to " << dye::aqua("BYTE CODE") << endl;
	cout << "      [" << dye::grey("4") << "] " << "Convert " << dye::aqua("BYTE CODE ") << "from " << dye::aqua("AOB CODE") << endl;
	
	int opc;
	cin >> opc;
	if (opc == 1) {
		string get_aobcode;
		clipboard >> get_aobcode;

		system("cls");
		if (get_aobcode.empty()) {
			cout << endl << endl << "[" << dye::red("-") << "] " << "ERROR: " << dye::red("You need to copy the code to your clipboard") << endl;
		}
		else if (get_aobcode.length() <= 2) {
			cout << endl << endl << "[" << dye::red("-") << "] " << "ERROR: " << dye::red("Your code is too small") << endl;
			Sleep(1500);
			goto home;
		}
		else {
			system("cls");
			cout << endl << endl << "  [" << dye::yellow("?") << "] " << "Original Code" << endl;
			cout << "    " << dye::grey(get_aobcode) << endl;

			cout << endl << endl << "  [" << dye::yellow("?") << "] " << "Changed Code" << endl;
			cout << "    " << dye::grey(regex_replace(get_aobcode, regex("\\ "), " 00 ")) << endl;

			cout << endl << "Press any key to back..." << endl;
			_getch();
			goto home;
		}
	}
	else if (opc == 2) {
		string get_aobcode;
		clipboard >> get_aobcode;

		system("cls");
		if (get_aobcode.empty()) {
			cout << endl << endl << "[" << dye::red("-") << "] " << "ERROR: " << dye::red("You need to copy the code to your clipboard") << endl;
		}
		else {
			system("cls");
			cout << endl << endl << "  [" << dye::yellow("?") << "] " << "Original Code" << endl;
			cout << "    " << dye::grey(get_aobcode) << endl;

			cout << endl << endl << "  [" << dye::yellow("?") << "] " << "Changed Code" << endl;
			cout << "    " << dye::grey(regex_replace(get_aobcode, regex("\\ 00 "), " ")) << endl;

			cout << endl << "Press any key to back..." << endl;
			_getch();
			goto home;
		}
	}
	else if (opc == 3) {
		string get_aobcode;
		clipboard >> get_aobcode;

		system("cls");
		if (get_aobcode.empty()) {
			cout << endl << endl << "[" << dye::red("-") << "] " << "ERROR: " << dye::red("You need to copy the code to your clipboard") << endl;
		}
		else {
			system("cls");
			cout << endl << endl << "  [" << dye::yellow("?") << "] " << "Original Code" << endl;
			cout << "    " << dye::grey(get_aobcode) << endl;

			cout << endl << endl << "  [" << dye::yellow("?") << "] " << "Changed Code" << endl;

			string changed = regex_replace(get_aobcode, regex("\ "), ", 0x");
			string changed1 = regex_replace(changed, regex("\\dx\\?\\?"), "'?'");
			cout << "    " << dye::grey("0x" + changed1) << endl;

			cout << endl << "Press any key to back..." << endl;
			_getch();
			goto home;
		}
	}
	else if (opc == 4) {
		string get_aobcode;
		clipboard >> get_aobcode;

		system("cls");
		if (get_aobcode.empty()) {
			cout << endl << endl << "[" << dye::red("-") << "] " << "ERROR: " << dye::red("You need to copy the code to your clipboard") << endl;
		}
		else {
			system("cls");
			cout << endl << endl << "  [" << dye::yellow("?") << "] " << "Original Code" << endl;
			cout << "    " << dye::grey(get_aobcode) << endl;

			cout << endl << endl << "  [" << dye::yellow("?") << "] " << "Changed Code" << endl;
			cout << "    " << dye::grey(regex_replace(get_aobcode, regex("\\, 0x"), " ").replace(0, 2, "")) << endl;

			cout << endl << "Press any key to back..." << endl;
			_getch();
			goto home;
		}
	}
}
