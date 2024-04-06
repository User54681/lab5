#include <iostream>
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
        for (unsigned i {}; i <= line.length() - word.length();) {
            size_t position = line.find(word, i);
            if (position == std::string::npos) break;
            ++cnt;
            //i = position + i;
        }
    }

    std::cout << cnt << "\n";
    file.close();
}