#include "Header.h"

int main() 
{
	setlocale(LC_ALL, "rus");
	string first_path = "FirstFile.txt";
	string second_path = "SecondFile.txt";
	write_file(first_path);
	format_file(first_path, second_path);
	read_file(second_path);
}