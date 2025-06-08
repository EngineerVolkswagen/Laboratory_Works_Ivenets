#include <iostream>
#include <fstream>
#include <istream>


struct Student {
    char name[30];
    char surname[30];
    int32_t course;
    char group[15];
    int32_t marks[5];
    double average;
};


void InsertionSort(double arr[], int32_t size) 
{
    for(int32_t i{1}; i < size; ++i) 
    {
        double ptr = arr[i];
        int32_t j{i-1};
        while(j >= 0 && arr[j] > ptr) 
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = ptr;
    }
}


void SelectionSort(double array[], int32_t size) 
{
    for(int32_t i{0}; i < size - 1; ++i)
    {
        for(int32_t j{i + 1}; j < size; ++j)
        { 
            if(array[i] > array[j])
            {
            std::swap(array[i], array[j]);
            }
        }
    }
}


void BubbleSort(double arr[], int32_t size) 
{
    for(int32_t i{0}; i < size - 1; ++i) 
    {
        for(int32_t j{0}; j < size - 1 - i; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


int Compare(const void* el1, const void* el2) {
	return *((double*)el2) - *((double*)el1);
}


void ReverseArray(double arr[], int32_t size) 
{
    for(int32_t i{0}; i < size / 2; ++i) 
    {
        std::swap(arr[i], arr[size-1-i]);
    }
}


void SortArray(double array[],int32_t size, int32_t metod, int32_t monotony) 
{
    switch(metod) {
        //case 1: quickSort(arr, 0, n - 1); break;
        case 2: InsertionSort(array, size); break;
        case 3: SelectionSort(array, size); break;
        //case 4: mergeSort(arr, 0, n -  ); break;
        case 5: BubbleSort(array, size); break;
        //case 6: qsort(arr, n, sizeof(double), Compare); break;
    }
    if(monotony == 0)
    {
        ReverseArray(array, size);
    }
}


void SortStudents(Student array[], int32_t size) 
{
    for(int32_t i{0}; i < size; ++i) 
    {
        double sum{0};
        for(int32_t j{0}; j < 5; ++j)
        {
            sum += array[i].marks[j];
        }
        array[i].average = sum / 5;
    }
    for(int32_t i{0}; i < size - 1; ++i)
    {
        for(int32_t j = {i+1}; j < size; ++j)
        { 
            if(array[i].average < array[j].average)
            {
                std::swap(array[i], array[j]);
            }
        }
    }
}


void CheckInputFile(std::ifstream& fin) {
	if (!fin.good()) {
		throw "file isnt exist\n";
	}
	if (!fin) {
		throw "input file error\n";
	}
	if (fin.peek() == EOF) {
		throw "file is empty\n";
	}
}


void CheckOutputFile(std::ofstream& fout) {
	if (!fout.good()) {
		throw "file isnt exist\n";
	}
	if (!fout) {
		throw "output file error\n";
	}
}


int main()
{
    try
    { 
        // ЗАДАНИЕ 1
        std::cout << "Выберите режим:\n1 - Ввод с консоли \n2 - Ввод из файла и вывод \n3 - Ввод из файла и запись в файл\nНус...: ";
        int32_t mode{};  
        std::cin >> mode;
        int32_t n{};
        double array[300];
        if(mode != 1 && mode != 2 && mode != 3 )
        {
            throw "Нет такого режима! :(\n";     
        }
        if(mode == 1)
        {
            std::cout << "введите кол-во элементов массива: ";
            std::cin >> n;
            if( n < 1) 
            {
                throw "Недопустимое колличество элементов :( \n";
            }
            for(int32_t i{0}; i < n; ++i)
            {
                std::cin >> array[i];
            }
        }
        else if(mode == 2 || mode == 3)
        {
            std::ifstream fin("input.txt");
            CheckInputFile(fin);
            double x;
            while(fin >> x)
            {
                array[n++] = x;
            }
            fin.close();
        }
        int32_t metod{};
        int32_t monotony{};
        std::cout << "Выберите метод сортировки (1-6): ";
        std::cin >> metod;
        if(0 < metod > 7)
        {
            throw "Нет такого метода! :(\n";
        }
        std::cout << "Сортировать по возрастанию? (1 - да, 0 - нет): \n";
        std::cin >> monotony;
        if(monotony != 1 && monotony != 0)
        {
            throw "Нет такого выюора ответа! :(\n";
        }
        SortArray(array, n, metod, monotony);
        if(mode == 2) 
        {
            for(int32_t i = 0; i < n; ++i)
            {
                std::cout << array[i] << " ";
            }   
        }   
        else 
        {
            std::ofstream fout("output.txt");
            CheckOutputFile(fout);
            for(int32_t i = 0; i < n; ++i)
            {
                fout << array[i] << " ";
            }
            fout.close();
        }
        /*
        // ЗАДАНИЕ 2
        int32_t studentCount;
        std::cout << "\nВведите количество студентов: ";
        std::cin >> studentCount;
        if( studentCount < 1) 
        {
            throw "Недопустимое колличество студентов :( \n";
        }
        Student students[100];
        for(int32_t i = 0; i < studentCount; ++i) 
        {
            std::cout << "Введите фамилию, имя, курс, группу:\n";
            std::cin >>  students[i].surname >> students[i].name >> students[i].course >> students[i].group;
            std::cout << "Введите 5 оценок:\n";
            for(int32_t j = 0; j < 5; ++j)
            {
                std::cin >> students[i].marks[j];
                if(students[i].marks[j] < 0)
                {
                    throw "оценка должна быть положительной\n";
                }
            }
        }
        SortStudents(students, studentCount);
        std::cout << "Список студентов по убыванию среднего балла:\n";
        for(int32_t i = 0; i < studentCount; ++i) 
        {
            std::cout << i+1 << ". " << students[i].surname << " " << students[i].name << " Курс: " << students[i].course << " Группа: " << students[i].group << " Средний балл: " << students[i].average << std::endl;
        }   */
    }
    catch(const char* m)
    {
        std::cout << m << '\n';
    }
    return 0;
}