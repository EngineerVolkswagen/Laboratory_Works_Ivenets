#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>


const int32_t MAX_STUDENTS = 100;

struct Student 
{
    char name[30];
    int32_t group;
    double grade;
};


int32_t readFile(const char* filename, Student students[]) 
{
    std::ifstream file(filename);
    int32_t count = 0;
    char line[100];
    while(file.getline(line, sizeof(line)) && count < MAX_STUDENTS) 
    {
        char* ptr = strtok(line, ";");
        if(ptr)
        {
            strcpy(students[count].name, ptr);
        }
        ptr = strtok(NULL, ";");
        if(ptr)
        {
            students[count].group = atoi(ptr);
        }
        ptr = strtok(NULL, ";");
        if(ptr) 
        {
            students[count].grade = atof(ptr);
        }    
        count++;
    }
    file.close();
    return count;
}


void writeFile(const char* filename, Student students[], int32_t count) 
{
    std::ofstream file(filename);
    for(int32_t i = 0; i < count; ++i) 
    {
        file << students[i].name << ";" << students[i].group << ";" << students[i].grade <<  '\n';
    }
    file.close();
}


void sortName(Student students[], int32_t count) 
{
    for(int32_t i = 0; i < count - 1; ++i) 
    {
        for(int32_t j = i + 1; j < count; ++j) 
        {
            if(strcmp(students[i].name, students[j].name) > 0) 
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}


void searchName(Student students[], int32_t count, const char* name) 
{
    bool found = false;
    for(int32_t i = 0; i < count; ++i) 
    {
        if(strcmp(students[i].name, name) == 0) 
        {
            std::cout << students[i].name << ", группа: " << students[i].group << ", балл: " << students[i].grade << '\n';
            found = true;
        }
    }
    if(!found) 
    {
        std::cout << "Студент с такой фамилией не найден.\n";
    }
}


void sortGroupAndName(Student students[], int32_t count) 
{
    for(int32_t i = 0; i < count - 1; ++i) 
    {
        for(int32_t j = i + 1; j < count; ++j) 
        {
            if(students[i].group > students[j].group || (students[i].group == students[j].group && strcmp(students[i].name, students[j].name) > 0)) 
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}


void averageGroup(Student students[], int32_t count)
{
    int32_t groups[MAX_STUDENTS];
    int32_t groupCount = 0;
    for(int32_t i = 0; i < count; ++i) 
    {
        bool exists = false;
        for(int32_t j = 0; j < groupCount; ++j) 
        {
            if(groups[j] == students[i].group) 
            {
                exists = true;
                break;
            }
        }
        if(!exists) 
        {
            groups[groupCount++] = students[i].group;
        }
    }
    for(int32_t i = 0; i < groupCount; ++i) 
    {
        int32_t group = groups[i];
        double total = 0;
        int32_t num = 0;
        for(int32_t j = 0; j < count; ++j) {
            if(students[j].group == group) 
            {
                total += students[j].grade;
                num++;
            }
        }
        if(num > 0) 
        {
            std::cout << "Группа " << group << ": средний балл = " << total / num << '\n';
        }
    }
}

int main() 
{
    Student students[MAX_STUDENTS];
    int32_t count = readFile("students.txt", students);

    int32_t mode;
    while(mode != 5)
    {
        std::cout << "\nМеню:\n"<< "1. Отсортировать по фамилии\n" << "2. Найти по фамилии\n" << "3. Отсортировать по группам и фамилиям\n" << "4. Средний балл по группам\n" << "5. Выход\n" << "Выберите действие: ";
        std::cin >> mode;
        switch(mode) 
        {
            case 1:
            {
                sortName(students, count);
                writeFile("students.txt", students, count);
                std::cout << "Отсортировано по фамилии.\n";
                break;
            }
            case 2: 
            {
                char surname[30];
                std::cout << "Введите фамилию и инициалы для поиска: ";
                std::cin.ignore();
                std::cin.getline(surname, 30);
                searchName(students, count, surname);
                break;
            }
            case 3:
            {
                sortGroupAndName(students, count);
                for (int i = 0; i < count; ++i) 
                {
                    std::cout << students[i].name << ", группа: " << students[i].group << ", балл: " << students[i].grade << '\n';
                }
                break;
            }
            case 4:
                averageGroup(students, count);
                break;
            case 5:
                std::cout << "работа завершена \n";
                break;
            default:
                std::cout << "Неверный выбор.\n";
        }
    }
    return 0;
}