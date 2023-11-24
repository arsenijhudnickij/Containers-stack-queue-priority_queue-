#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Test.h"
#include "libraries.h"

int check() {
    int number;
    std::cin >> number;
    while (std::cin.fail() || std::cin.get() != '\n' || number < 0) {
        {
            std::cout << "\nOшибка ввода.\nПовторите попытку:";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> number;
        }
    }
    return number;
}
float check1() {
    float number;
    std::cin >> number;
    while (std::cin.fail() || std::cin.get() != '\n' || number < 0) {
        {
            std::cout << "\nOшибка ввода.\nПовторите попытку:";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> number;
        }
    }
    return number;
}


const std::string name_fil = "..//File1//Persons2.txt";
const std::string name_fik_test = "..//File1//Tests2.txt";


int main()
{
    system("chcp 1251");
    system("cls");
    Person* pers = NULL;
    std::stack<Test*> tests;
    std::priority_queue<Person*, std::vector<Person*>> teachers;
    std::queue<Person*, std::list<Person*>> students;


    Test* test = NULL;

    int choice{};
    do {
        std::cout << "1.Добавить ученика" << std::endl;
        std::cout << "2.Добавить учителя" << std::endl;
        std::cout << "3.Добавить тест" << std::endl;
        std::cout << "4.Просмотреть всех учеников" << std::endl;
        std::cout << "5.Просмотреть всех учителей" << std::endl;
        std::cout << "6.Посмотреть все тесты" << std::endl;
        std::cout << "7.Отсортировать все тесты по названию" << std::endl;
        std::cout << "8.Отсортировать учеников по возрасту" << std::endl;
        std::cout << "9.Поиск учителя по имени" << std::endl;
        std::cout << "10.Поиск ученика по имени" << std::endl;
        std::cout << "11.Поиск теста по названию" << std::endl;
        std::cout << "12.Удаление ученика" << std::endl;
        std::cout << "13.Удаление учителя" << std::endl;
        std::cout << "14.Удаление теста" << std::endl;
        std::cout << "15.Изменение имени ученика" << std::endl;
        std::cout << "16.Изменение имени преподавателя" << std::endl;
        std::cout << "17.Изменение названия теста" << std::endl;
        std::cout << "18.Выход" << std::endl;

        std::cout << "\n\n";
        std::cout << "Ваш выбор?" << std::endl;

        try {
            if (!(std::cin >> choice))
                throw std::runtime_error("Неверный ввод данных");
        }
        catch (std::runtime_error errr) {

            std::cout << errr.what() << std::endl;
            system("pause");
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            continue;
        }

        std::cin.clear();
        std::cin.ignore(1024, '\n');
        system("cls");
        switch (choice)
        {
        case 1:
        {
            std::string name_st;
            std::cout << "Введите имя ученика" << std::endl;
            std::getline(std::cin, name_st);
            int age_st;
            std::cout << "Введите возраст ученика" << std::endl;
            age_st = check();
            int year_of;
            std::cout << "Введите количество лет обучения ученика:" << std::endl;
            year_of = check();

            pers = new Student(name_st, age_st, year_of);
            students.emplace(pers);

            std::cout << "Успешно добавлен" << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            std::string name_tch;
            std::cout << "Введите имя преподавателя" << std::endl;
            std::getline(std::cin, name_tch);
            int age_tch;
            std::cout << "Введите возраст преподавателя" << std::endl;
            age_tch = check();
            int year_of;
            std::cout << "Введите стаж преподавателя:" << std::endl;
            year_of = check();

            pers = new Teacher(name_tch, age_tch, year_of);
            teachers.emplace(pers);
            std::cout << "Успешно добавлен" << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            std::string name_test;
            std::cout << "Введите название теста:" << std::endl;
            std::getline(std::cin, name_test);
            std::vector<std::string> quest;
            std::string pointer = "y";
            do {
                std::string question;
                std::cout << "Введите ваш вопрос?" << std::endl;
                std::getline(std::cin, question);
                quest.push_back(question);
                std::cout << "Хотите продолжить ввод?(если да - y)" << std::endl;
                std::getline(std::cin, pointer);
            } while (pointer == "y");
            test = new Test(name_test, quest);
            tests.emplace(test);
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            auto a = students._Get_container();
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                         УЧЕНИКИ                       |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(7) << "Лет обучения |" << "\n";
            std::cout << "---------------------------------------------------------\n";
            for (auto& item : a)
            {
                std::cout << '|' << std::setw(20) << std::left << item->getName() << '|' << std::setw(20)
                    << item->getAge() << '|' << std::setw(12) << item->getYear() << " |" << std::endl;
                std::cout << "---------------------------------------------------------\n";
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            std::priority_queue<Person*, std::vector<Person*>> teachers1;
            teachers1 = teachers;
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                       ПРЕПОДАВАТЕЛИ                   |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(9) << "Стаж работы  |\n";
            std::cout << "---------------------------------------------------------\n";
            while (!teachers1.empty())
            {
                std::cout << '|' << std::setw(20) << std::left << teachers1.top()->getName() << '|' << std::setw(20)
                    << teachers1.top()->getAge() << '|' << std::setw(4) << teachers1.top()->getWork() << "         |" << std::endl;
                std::cout << "---------------------------------------------------------\n";
                teachers1.pop();
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            std::stack<Test*> tests1;
            tests1 = tests;
            while (!tests1.empty())
            {
                tests1.top()->printQuestions();
                tests1.pop();
            }
            std::cout << "\n";
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 7:
        {
            std::string* temporary = new std::string[tests.size()];
            auto b = tests._Get_container();
            for (int i = 0; i < tests.size(); i++) {
                temporary[i] = b[i]->get_name();
            }
            for (int i = 0; i < tests.size(); i++) {
                for (int j = tests.size() - 1; j > i; j--) {
                    if (temporary[j - 1] > temporary[j]) {
                        swap(temporary[j - 1], temporary[j]);
                    }
                }
            }
            for (int i = 0; i < tests.size(); i++) {
                for (int j = 0; j < tests.size(); j++)
                {
                    if (temporary[i] == b[j]->get_name())
                    {
                        b[j]->printQuestions();
                    }
                }
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 8:
        {

            std::list<int> sort;
            auto c = students._Get_container();
            for (auto& item : c)
            {
                sort.push_back(item->getAge());
            }

            sort.sort();

            std::cout << "Отсортированный список:" << std::endl;
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                         УЧЕНИКИ                       |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(7) << "Лет обучения |" << "\n";
            std::cout << "---------------------------------------------------------\n";
            for (std::list<int>::iterator it = sort.begin(); it != sort.end(); it++)
            {
                for (auto& item : c)
                {
                    if (item->getAge() == *it)
                    {
                        std::cout << '|' << std::setw(20) << std::left << item->getName() << '|' << std::setw(20)
                            << item->getAge() << '|' << std::setw(12) << item->getYear() << " |" << std::endl;
                        std::cout << "---------------------------------------------------------\n";
                    }
                }
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 9:
        {
            std::priority_queue<Person*, std::vector<Person*>> teachers5;
            teachers5 = teachers;
            std::string name_poi;
            std::cout << "Введите имя учителя, которого хотите найти" << std::endl;
            std::getline(std::cin, name_poi);
            int flag = 0;
            
            while (!teachers5.empty())
            {
                if (teachers5.top()->getName() == name_poi)
                {
                    teachers5.top()->showData();
                    flag = 1;
                    break;
                }
                teachers5.pop();
            }
            if (flag == 1)
            {
                std::cout << "Успешно найден" << std::endl;
            }
            else
            {
                std::cout << "Отсутствует преподаватель с таким именем" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 10:
        {
            std::string name_poi;
            std::cout << "Введите имя ученика, которого хотите найти" << std::endl;
            std::getline(std::cin, name_poi);
            std::queue<Person*, std::list<Person*>> students1;
            students1 = students;
            int flag = 0;
            
            while (!students1.empty())
            {
                if (students1.front()->getName() == name_poi)
                {
                    students1.front()->showData();
                    flag = 1;
                }
                students1.pop();
            }
            if (flag == 1)
            {
                std::cout << "Успешно найден" << std::endl;
            }
            else
            {
                std::cout << "Отсутствует ученик с таким именем" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 11:
        {
            auto tes = tests._Get_container();
            std::string name_pois;
            std::cout << "Введите название теста, который хотите найти" << std::endl;
            std::getline(std::cin, name_pois);
            int flag = tests.size();
            int fl = 0;
            for (int i = 0; i < flag; i++)
            {
                if (tes[i]->get_name() == name_pois)
                {
                    tes[i]->printQuestions();
                    fl = 1;
                }
            }
            if (fl == 1)
            {
                std::cout << "Успешно найден" << std::endl;
            }
            else
            {
                std::cout << "Отсутствует тест с таким именем" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 12:
        {
            auto a = students._Get_container();
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                         УЧЕНИКИ                       |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(7) << "Лет обучения |" << "\n";
            std::cout << "---------------------------------------------------------\n";
            for (auto& item : a)
            {
                std::cout << '|' << std::setw(20) << std::left << item->getName() << '|' << std::setw(20)
                    << item->getAge() << '|' << std::setw(12) << item->getYear() << " |" << std::endl;
                std::cout << "---------------------------------------------------------\n";
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            std::string name_poi;
            std::cout << "Введите имя ученика, которого хотите удалить" << std::endl;
            std::getline(std::cin, name_poi);
            std::queue<Person*, std::list<Person*>> students1;
            students1 = students;
            int flag = students.size();
            while (!students.empty())
            {
                students.pop();
            }
            while (!students1.empty())
            {
                if (students1.front()->getName() != name_poi)
                {
                    students.emplace(students1.front());
                    flag--;
                }
                students1.pop();
            }
            if (flag != 0)
            {
                std::cout << "Успешно удален" << std::endl;
            }
            else
            {
                std::cout << "Отсутствует ученик с таким именем" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 13:
        {
            std::priority_queue<Person*, std::vector<Person*>> teachers1;
            teachers1 = teachers;
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                       ПРЕПОДАВАТЕЛИ                   |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(9) << "Стаж работы  |\n";
            std::cout << "---------------------------------------------------------\n";
            while (!teachers1.empty())
            {
                std::cout << '|' << std::setw(20) << std::left << teachers1.top()->getName() << '|' << std::setw(20)
                    << teachers1.top()->getAge() << '|' << std::setw(4) << teachers1.top()->getWork() << "         |" << std::endl;
                std::cout << "---------------------------------------------------------\n";
                teachers1.pop();
            }
            std::cout << "\n";
            system("pause");
            system("cls");

            std::priority_queue<Person*, std::vector<Person*>> teachers5;
            teachers5 = teachers;
            std::string name_poi;
            std::cout << "Введите имя учителя, которого хотите удалить" << std::endl;
            std::getline(std::cin, name_poi);
            int flag = teachers.size();
            while (!teachers.empty())
            {
                teachers.pop();
            }
            while (!teachers5.empty())
            {
                if (teachers5.top()->getName() != name_poi)
                {
                    teachers.emplace(teachers5.top());
                    flag--;
                }
                teachers5.pop();
            }
            if (flag != 0)
            {
                std::cout << "Успешно удален" << std::endl;
            }
            else
            {
                std::cout << "Отсутствует преподаватель с таким именем" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 14:
        {
            std::stack<Test*> tests1;
            tests1 = tests;
            while (!tests1.empty())
            {
                tests1.top()->printQuestions();
                tests1.pop();
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            auto tes = tests._Get_container();
            std::string name_pois;
            std::cout << "Введите название теста, который хотите удалить" << std::endl;
            std::getline(std::cin, name_pois);
            int flag = tests.size();
            int fl = tests.size();
            while (!tests.empty())
            {
                tests.pop();
            }
            for (int i = 0; i < flag; i++)
            {
                if (tes[i]->get_name() != name_pois)
                {
                    tests.emplace(tes[i]);
                    fl--;
                }
            }
            if (fl != 0)
            {
                std::cout << "Успешно удален" << std::endl;
            }
            else
            {
                std::cout << "Отсутствует тест с таким именем" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 15:
        {
            auto a = students._Get_container();
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                         УЧЕНИКИ                       |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(7) << "Лет обучения |" << "\n";
            std::cout << "---------------------------------------------------------\n";
            for (auto& item : a)
            {
                std::cout << '|' << std::setw(20) << std::left << item->getName() << '|' << std::setw(20)
                    << item->getAge() << '|' << std::setw(12) << item->getYear() << " |" << std::endl;
                std::cout << "---------------------------------------------------------\n";
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            std::string name_poi;
            std::cout << "Введите имя ученика, у которого хотите изменить имя" << std::endl;
            std::getline(std::cin, name_poi);
            std::queue<Person*, std::list<Person*>> students1;
            students1 = students;
            int flag = students.size();
            while (!students.empty())
            {
                students.pop();
            }
            while (!students1.empty())
            {
                if (students1.front()->getName() != name_poi)
                {
                    students.emplace(students1.front());
                    flag--;
                }
                else
                {
                    std::string nam;
                    std::cout << "Введите новое имя:" << std::endl;
                    std::getline(std::cin, nam);
                    students1.front()->setName(nam);
                    students.emplace(students1.front());
                }
                students1.pop();
            }
            if (flag != 0)
            {
                std::cout << "Успешно изменено" << std::endl;
            }
            else
            {
                std::cout << "Отсутствует ученик с таким именем" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 16:
        {
            std::priority_queue<Person*, std::vector<Person*>> teachers1;
            teachers1 = teachers;
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                       ПРЕПОДАВАТЕЛИ                   |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(9) << "Стаж работы  |\n";
            std::cout << "---------------------------------------------------------\n";
            while (!teachers1.empty())
            {
                std::cout << '|' << std::setw(20) << std::left << teachers1.top()->getName() << '|' << std::setw(20)
                    << teachers1.top()->getAge() << '|' << std::setw(4) << teachers1.top()->getWork() << "         |" << std::endl;
                std::cout << "---------------------------------------------------------\n";
                teachers1.pop();
            }
            std::cout << "\n";
            system("pause");
            system("cls");

            std::priority_queue<Person*, std::vector<Person*>> teachers5;
            teachers5 = teachers;
            std::string name_poi;
            std::cout << "Введите имя учителя,у которого хотите изменить имя" << std::endl;
            std::getline(std::cin, name_poi);
            int flag = teachers.size();
            while (!teachers.empty())
            {
                teachers.pop();
            }
            while (!teachers5.empty())
            {
                if (teachers5.top()->getName() != name_poi)
                {
                    teachers.emplace(teachers5.top());
                    flag--;
                }
                else
                {
                    std::string nam;
                    std::cout << "Введите новое имя:" << std::endl;
                    std::getline(std::cin, nam);
                    teachers5.top()->setName(nam);
                    teachers.emplace(teachers5.top());
                }
                teachers5.pop();
            }
            if (flag != 0)
            {
                std::cout << "Успешно изменено" << std::endl;
            }
            else
            {
                std::cout << "Отсутствует преподаватель с таким именем" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 17:
        {
            std::stack<Test*> tests1;
            tests1 = tests;
            while (!tests1.empty())
            {
                tests1.top()->printQuestions();
                tests1.pop();
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            auto tes = tests._Get_container();
            std::string name_pois;
            std::cout << "Введите название теста,у которого хотите изменить название" << std::endl;
            std::getline(std::cin, name_pois);
            int flag = tests.size();
            int fl = tests.size();
            while (!tests.empty())
            {
                tests.pop();
            }
            for (int i = 0; i < flag; i++)
            {
                if (tes[i]->get_name() != name_pois)
                {
                    tests.emplace(tes[i]);
                    fl--;
                }
                else
                {
                    std::string nam;
                    std::cout << "Введите новое имя:" << std::endl;
                    std::getline(std::cin, nam);
                    tes[i]->setName(nam);
                    tests.emplace(tes[i]);
                }
            }
            if (fl != 0)
            {
                std::cout << "Успешно удален" << std::endl;
            }
            else
            {
                std::cout << "Отсутствует тест с таким именем" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }

        case 18:
            break;
        default:
            std::cout << "Неверный ввод" << std::endl;
        }
    } while (choice != 18);

    std::ofstream File;
    File.open(name_fil, std::ios::binary);
    if (File.is_open())
    {
        std::priority_queue<Person*, std::vector<Person*>> teachers4;
        teachers4 = teachers;
        auto stu = students._Get_container();
        File << "---------------------------------------------------------\n";
        File << "|                         УЧЕНИКИ                       |\n";
        File << "---------------------------------------------------------\n";
        File << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(7) << "Лет обучения |" << "\n";
        File << "---------------------------------------------------------\n";
        for (auto& item : stu)
        {
            File << '|' << std::setw(20) << std::left << item->getName() << '|' << std::setw(20)
                << item->getAge() << '|' << std::setw(12) << item->getYear() << " |" << std::endl;
            File << "---------------------------------------------------------\n";
        }
        File << "---------------------------------------------------------\n";
        File << "|                       ПРЕПОДАВАТЕЛИ                   |\n";
        File << "---------------------------------------------------------\n";
        File << '|' << std::setw(20) << std::left << "Имя " << '|' << std::setw(20) << "Возраст " << '|' << std::setw(9) << "Стаж работы  |\n";
        File << "---------------------------------------------------------\n";
        while (!teachers4.empty())
        {
            File << '|' << std::setw(20) << std::left << teachers4.top()->getName() << '|' << std::setw(20)
                << teachers4.top()->getAge() << '|' << std::setw(4) << teachers4.top()->getWork() << "         |" << std::endl;
            File << "---------------------------------------------------------\n";
            teachers4.pop();
        }
        std::cout << "Данные успешно записаны в файл\n";
    }
    else std::cout << "Ошибка открытия файла\n";
    File.close();

    std::ofstream File1;
    auto tes = tests._Get_container();
    File1.open(name_fik_test, std::ios::binary);
    if (File1.is_open())
    {
        for (auto& item : tes)
        {
            File1 << "Название теста:  " << item->get_name();
            File1 << "\n";
            File1 << "Вопросы:\n";
            for (int j = 0; j < item->get_col_que(); j++)
            {
                File1 << item->get_quest(j);
                File1 << "\n";
            }
            File1 << "\n\n";
        }
    }
    else std::cout << "Ошибка открытия файла\n";
    File1.close();
    return 0;
}