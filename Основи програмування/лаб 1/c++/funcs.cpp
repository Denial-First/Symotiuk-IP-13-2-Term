#include "Header.h"

void write_file(string path)
{
    ofstream fout;
    fout.open(path);
    if (fout.is_open())
    {
        string line;
        cout << "Enter your strings. To finish entering enter '+' in the new line.\n";
        getline(cin, line);
        while (line[0] != 43)
        {
            fout << line;
            getline(cin, line);
            if (line[0] != 43) {
                fout << '\n';
            }
        }
        fout.close();
    }
    else
    {
        cout << "File wasn`t opened!";
    }
}

void read_file(string path) {

    ifstream fin;
    fin.open(path);
    if (fin.is_open()) {
        while (!fin.eof()) {
            string line;
            getline(fin, line);
            cout << line << '\n';
        }
        fin.close();
    }
    else
    {
        cout << "File wasn`t opened!";
    }
}

vector<string> sort(vector <string> vec) {
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j].length() < vec[j + 1].length()) {
                string tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
            }
        }
    }
    return vec;
}

void format_file(string first_path, string second_path) {
    ifstream fin;
    ofstream fout;
    fin.open(first_path);
    fout.open(second_path);
    if (fin.is_open() and fout.is_open()) {
        vector<string> lines;
        while (!fin.eof()) {
            string line;
            getline(fin, line);
            lines.push_back(line);
        }
        lines = sort(lines);
        for (int i = 0; i < lines.size(); i++)
        {
            string len = to_string(lines[i].length());
            string str = len + " " + lines[i];
            fout << str << '\n';
        }
        fout.close();
        fin.close();
    }
    else
    {
        cout << "Files weren`t opened!";
    }
}