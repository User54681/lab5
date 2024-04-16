#include <iostream>
#include "Source.h"
#include <algorithm>
#include <fstream>
#include <string>

void Edit_Func(unsigned choice);
void Read_Func(unsigned choice);

int main()
{
    setlocale(LC_ALL, "rus");
    std::string word, line;
    unsigned cnt {};
    std::cout << "Введите слово, кол-во которого вы хотите посчитать: " << "\n";
    std::cin >> word;
    std::ifstream file("file1.txt");

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

    std::ofstream f("file2.txt");

    if (f.is_open()) {
        f << mat;
        std::cout << "Запись матрицы в файл завершена" << "\n";
    }

    f.close();

    unsigned choice;
    while (choice != 6) {
        std::cout << "Выберите для дальнейшего действия: " << "\n";
        std::cout << "1 - Добавить новую запись в файл" << "\n";
        std::cout << "2 - Просмотр всех существующих записей в файле" << "\n";
        std::cout << "3 - Удаление записи из файла" << "\n";
        std::cout << "4 - Поиск записи в файле" << "\n";
        std::cout << "5 - Редактирование записи в файле" << "\n";
        std::cout << "6 - Выход из меню" << "\n";
        std::cin >> choice;
        
        if (choice == 1 || choice == 3 || choice == 5) {
            Edit_Func(choice);
        }
    }
}

void Edit_Func(unsigned choice) {
    std::ofstream ff("file3.txt", std::ios_base::app);
    std::string line, id_in, id;

    if (ff.is_open()){
        switch (choice)
        {
        case 1:
            std::cout << "Введите строку для записи в файл" << "\n";
            std::cin >> line;
            std::replace(line.begin(), line.end(), ' ', '\t');
            ff << line << "\n";
            break;
        case 3:
            std::cout << "" << "\n";
            std::cin >> id;
            
        default:
            break;
        }
    }
    ff.close();
}

void Read_Func(unsigned choice) {
    std::ifstream fff("file3.txt");

    switch (choice)
    {
    case 2:

    case 4:

    default:
        break;
    }
}