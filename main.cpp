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
            std::cout << "\nO����� �����.\n��������� �������:";
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
            std::cout << "\nO����� �����.\n��������� �������:";
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
        std::cout << "1.�������� �������" << std::endl;
        std::cout << "2.�������� �������" << std::endl;
        std::cout << "3.�������� ����" << std::endl;
        std::cout << "4.����������� ���� ��������" << std::endl;
        std::cout << "5.����������� ���� ��������" << std::endl;
        std::cout << "6.���������� ��� �����" << std::endl;
        std::cout << "7.������������� ��� ����� �� ��������" << std::endl;
        std::cout << "8.������������� �������� �� ��������" << std::endl;
        std::cout << "9.����� ������� �� �����" << std::endl;
        std::cout << "10.����� ������� �� �����" << std::endl;
        std::cout << "11.����� ����� �� ��������" << std::endl;
        std::cout << "12.�������� �������" << std::endl;
        std::cout << "13.�������� �������" << std::endl;
        std::cout << "14.�������� �����" << std::endl;
        std::cout << "15.��������� ����� �������" << std::endl;
        std::cout << "16.��������� ����� �������������" << std::endl;
        std::cout << "17.��������� �������� �����" << std::endl;
        std::cout << "18.�����" << std::endl;

        std::cout << "\n\n";
        std::cout << "��� �����?" << std::endl;

        try {
            if (!(std::cin >> choice))
                throw std::runtime_error("�������� ���� ������");
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
            std::cout << "������� ��� �������" << std::endl;
            std::getline(std::cin, name_st);
            int age_st;
            std::cout << "������� ������� �������" << std::endl;
            age_st = check();
            int year_of;
            std::cout << "������� ���������� ��� �������� �������:" << std::endl;
            year_of = check();

            pers = new Student(name_st, age_st, year_of);
            students.emplace(pers);

            std::cout << "������� ��������" << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            std::string name_tch;
            std::cout << "������� ��� �������������" << std::endl;
            std::getline(std::cin, name_tch);
            int age_tch;
            std::cout << "������� ������� �������������" << std::endl;
            age_tch = check();
            int year_of;
            std::cout << "������� ���� �������������:" << std::endl;
            year_of = check();

            pers = new Teacher(name_tch, age_tch, year_of);
            teachers.emplace(pers);
            std::cout << "������� ��������" << std::endl;
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            std::string name_test;
            std::cout << "������� �������� �����:" << std::endl;
            std::getline(std::cin, name_test);
            std::vector<std::string> quest;
            std::string pointer = "y";
            do {
                std::string question;
                std::cout << "������� ��� ������?" << std::endl;
                std::getline(std::cin, question);
                quest.push_back(question);
                std::cout << "������ ���������� ����?(���� �� - y)" << std::endl;
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
            std::cout << "|                         �������                       |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(7) << "��� �������� |" << "\n";
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
            std::cout << "|                       �������������                   |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(9) << "���� ������  |\n";
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

            std::cout << "��������������� ������:" << std::endl;
            std::cout << "---------------------------------------------------------\n";
            std::cout << "|                         �������                       |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(7) << "��� �������� |" << "\n";
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
            std::cout << "������� ��� �������, �������� ������ �����" << std::endl;
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
                std::cout << "������� ������" << std::endl;
            }
            else
            {
                std::cout << "����������� ������������� � ����� ������" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }
        case 10:
        {
            std::string name_poi;
            std::cout << "������� ��� �������, �������� ������ �����" << std::endl;
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
                std::cout << "������� ������" << std::endl;
            }
            else
            {
                std::cout << "����������� ������ � ����� ������" << std::endl;
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
            std::cout << "������� �������� �����, ������� ������ �����" << std::endl;
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
                std::cout << "������� ������" << std::endl;
            }
            else
            {
                std::cout << "����������� ���� � ����� ������" << std::endl;
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
            std::cout << "|                         �������                       |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(7) << "��� �������� |" << "\n";
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
            std::cout << "������� ��� �������, �������� ������ �������" << std::endl;
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
                std::cout << "������� ������" << std::endl;
            }
            else
            {
                std::cout << "����������� ������ � ����� ������" << std::endl;
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
            std::cout << "|                       �������������                   |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(9) << "���� ������  |\n";
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
            std::cout << "������� ��� �������, �������� ������ �������" << std::endl;
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
                std::cout << "������� ������" << std::endl;
            }
            else
            {
                std::cout << "����������� ������������� � ����� ������" << std::endl;
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
            std::cout << "������� �������� �����, ������� ������ �������" << std::endl;
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
                std::cout << "������� ������" << std::endl;
            }
            else
            {
                std::cout << "����������� ���� � ����� ������" << std::endl;
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
            std::cout << "|                         �������                       |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(7) << "��� �������� |" << "\n";
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
            std::cout << "������� ��� �������, � �������� ������ �������� ���" << std::endl;
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
                    std::cout << "������� ����� ���:" << std::endl;
                    std::getline(std::cin, nam);
                    students1.front()->setName(nam);
                    students.emplace(students1.front());
                }
                students1.pop();
            }
            if (flag != 0)
            {
                std::cout << "������� ��������" << std::endl;
            }
            else
            {
                std::cout << "����������� ������ � ����� ������" << std::endl;
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
            std::cout << "|                       �������������                   |\n";
            std::cout << "---------------------------------------------------------\n";
            std::cout << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(9) << "���� ������  |\n";
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
            std::cout << "������� ��� �������,� �������� ������ �������� ���" << std::endl;
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
                    std::cout << "������� ����� ���:" << std::endl;
                    std::getline(std::cin, nam);
                    teachers5.top()->setName(nam);
                    teachers.emplace(teachers5.top());
                }
                teachers5.pop();
            }
            if (flag != 0)
            {
                std::cout << "������� ��������" << std::endl;
            }
            else
            {
                std::cout << "����������� ������������� � ����� ������" << std::endl;
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
            std::cout << "������� �������� �����,� �������� ������ �������� ��������" << std::endl;
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
                    std::cout << "������� ����� ���:" << std::endl;
                    std::getline(std::cin, nam);
                    tes[i]->setName(nam);
                    tests.emplace(tes[i]);
                }
            }
            if (fl != 0)
            {
                std::cout << "������� ������" << std::endl;
            }
            else
            {
                std::cout << "����������� ���� � ����� ������" << std::endl;
            }
            std::cout << "\n";
            system("pause");
            system("cls");
            break;
        }

        case 18:
            break;
        default:
            std::cout << "�������� ����" << std::endl;
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
        File << "|                         �������                       |\n";
        File << "---------------------------------------------------------\n";
        File << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(7) << "��� �������� |" << "\n";
        File << "---------------------------------------------------------\n";
        for (auto& item : stu)
        {
            File << '|' << std::setw(20) << std::left << item->getName() << '|' << std::setw(20)
                << item->getAge() << '|' << std::setw(12) << item->getYear() << " |" << std::endl;
            File << "---------------------------------------------------------\n";
        }
        File << "---------------------------------------------------------\n";
        File << "|                       �������������                   |\n";
        File << "---------------------------------------------------------\n";
        File << '|' << std::setw(20) << std::left << "��� " << '|' << std::setw(20) << "������� " << '|' << std::setw(9) << "���� ������  |\n";
        File << "---------------------------------------------------------\n";
        while (!teachers4.empty())
        {
            File << '|' << std::setw(20) << std::left << teachers4.top()->getName() << '|' << std::setw(20)
                << teachers4.top()->getAge() << '|' << std::setw(4) << teachers4.top()->getWork() << "         |" << std::endl;
            File << "---------------------------------------------------------\n";
            teachers4.pop();
        }
        std::cout << "������ ������� �������� � ����\n";
    }
    else std::cout << "������ �������� �����\n";
    File.close();

    std::ofstream File1;
    auto tes = tests._Get_container();
    File1.open(name_fik_test, std::ios::binary);
    if (File1.is_open())
    {
        for (auto& item : tes)
        {
            File1 << "�������� �����:  " << item->get_name();
            File1 << "\n";
            File1 << "�������:\n";
            for (int j = 0; j < item->get_col_que(); j++)
            {
                File1 << item->get_quest(j);
                File1 << "\n";
            }
            File1 << "\n\n";
        }
    }
    else std::cout << "������ �������� �����\n";
    File1.close();
    return 0;
}