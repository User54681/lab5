#include <iostream>
#include "Source.h"
#include <fstream>
#include <string>

int main()
{
    setlocale(LC_ALL, "rus");
    std::string word, line;
    unsigned cnt {};
    std::cout << "Введите слово, кол-во которого вы хотите посчитать: " << "\n";
    std::cin >> word;
    std::ifstream file("file.txt");

    if (file.is_open()) {
        std::getline(file, line);
        for (unsigned i {}; i <= line.length() - word.length(); ++i) {
            size_t position = line.find(word, i);
            if (position == std::string::npos) break;
            ++cnt;
            i = position + word.length() - 1;
        }
    }

    std::cout << cnt << "\n";
    file.close();

    matrix<float> mat(3, 3);
    mat.random();

    std::ofstream f("file.txt", std::ios_base::app);

    if (f.is_open()) {
        f << mat;
    }
}