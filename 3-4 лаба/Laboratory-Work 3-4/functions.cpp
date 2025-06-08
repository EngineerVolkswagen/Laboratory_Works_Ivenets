#include <iostream>
#include <cmath>


bool IsNatural(int32_t namber)
{
if(namber < 0)
{
    return false;
}
return true;
}


void InputSize(int32_t& size)
{
    std::cin >> size;
    std::cout << '\n';
}


void CreateArray (int32_t size , double*& arr)
{ 
    arr = new double[size];
}


void Delete(double*& arr)
{
    delete []arr;
}

template<class Type>
void FillArray(int32_t size, Type arr)
{
    srand(time(NULL));
    for(size_t i{0}; i < size; ++i)
    {
        std::cin >> arr[i];
       //arr[i] = rand() % 10 * pow(-1 , rand());
    }
}


void OutputArray(int32_t size, double* arr)
{
    std::cout << "Элементы массива: ";
    for(size_t i{0}; i < size; ++i)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << '\n';
}

template<class Type>
int32_t  LastNumberModulMinELementArray(int32_t size , Type arr)
{
    int32_t index{0};
    for(size_t counter{0}; counter < size; ++counter)
    {
         if(abs(arr[index]) >= abs(arr[counter]))
         {
            index = counter;
         }
    }
    return index;
}

template<class Type>
int32_t  FirstMinusElementArray(int32_t size, Type arr)
{
    int32_t index {0};
    for(size_t counter{0}; counter < size; ++counter)
    {
         if(arr[counter] < 0)
         {
            index = counter;
            return index;
         }
    }
    std::cout << "В массиве отсутствуют отрицательные елементы!";
    return 0;
}


template<class Type>
double SumElementsAfterFirstMinusElementArray (int32_t size, Type arr)
{
    double sum{0};
    for(size_t counter = FirstMinusElementArray(size, arr) + 1; counter < size; counter++ )
    {
        sum += arr[counter];
    }
    return sum;
}


template<class Type>
void ShiftElementArray(int32_t& size , Type arr, int32_t index , int32_t ediniz)
{
    for(int32_t counter{index}; counter < size; ++counter)
    {
        arr[counter] = arr[counter + ediniz];
    }
    size -=1;
}
 

template<class Type>
void DeleteElenment(int32_t& size , Type arr, int32_t index)
{
    if(index < 0 || index >= size)
    {
        std::cout << "такого элемента нет: ";
        return;
    }
    double* newArr  = new double [size-1];
    for (size_t i = 0, j = 0; i < size; ++i) 
    {
        if (i == index)
        {
            ++i;
        }
        newArr[j++] = arr[i];
    }
    delete []arr;
    arr = newArr;
    --size;
 }


/*
 template<class Type>
    void AddElementInArray(int32_t &size , Type arr, int32_t index, double NewElement)
    {
        double *newArr  = new double [size+1];
            size++;
        if(index < 0 || index >= size+1)
        {
            std::cout << "такого элемента нет: ";
            return;
        }
        for (size_t i = 0, j = 0; i < size; ++i) 
        {
            if (i == index)
            {
                newArr[j] = NewElement;
                j++;
            }
            newArr[j++] = arr[i];
        }
        delete []arr;
        arr = newArr;
    }
*/


template<class Type>
void AddElementInArray(int32_t &size , Type arr, int32_t index, double NewElement)
{ 
    size++;
    if(index < 0 || index >= size+1)
    {
        std::cout << "такого элемента нет: ";
        return;
    }

    for (size_t i = 0, j = 0; i < size; ++i) 
    {
        if (i == index)
        {
            arr[j++] = NewElement;
            //i++;
        }
        arr[j++] = arr[i];
    }
}



template<class Type>
void DeleteNumberFromArray(int32_t& size , Type arr)
{
    double NumberDeleteFromArray{};
    std::cout << "Enter number delete from array: ";
    std::cin >> NumberDeleteFromArray;
    for(size_t counter{0}; counter < size; ++counter)
    {
         if(arr[counter] == NumberDeleteFromArray )
        {
            ShiftElementArray(size , arr, counter, 1);
             size++;
             arr[size-1] = 0;
            --counter;
        }
    }
}

template<class Type>
void SortAscending(int32_t& size, Type arr)
{
    for(int32_t i{0}; i < size-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            ShiftElementArray(size,arr,i+1,1);
            --i;
        }
    }
}


template<class Type>
int32_t LastMinELementArray(int32_t size , Type arr)
{
    int32_t index{0};
    for(size_t counter{0}; counter < size; ++counter)
    {
         if(arr[index] >= arr[counter])
         {
            index = counter;
         }
    }
    return index;
}


template<class Type>
int32_t LastMaxElementArray(int32_t size , Type arr)
{
    int32_t index{0};
    for(size_t counter{0}; counter < size; ++counter)
    {
         if(arr[index] <= arr[counter])
         {
            index = counter;
         }
    }
    return index;
}


void Recursion(int32_t& first_number, int32_t& second_number)
{
    int32_t temp = first_number;
    first_number = second_number;
    second_number = temp;
}


template<class Type>
double ProductArrayElements(int32_t size , Type arr, int32_t first_index, int32_t second_index)
{
    first_index++;
    double res{1};
    if(first_index == second_index)
    {
        res = 0;
    }
    if(first_index > second_index)
    {
        Recursion(first_index, second_index);
    }
    while(first_index < second_index)
    {
        res = res *  arr[first_index];
        first_index++;
    }
    return res;
}


void swap(double& number1 , double& number2)
{
double tmp = number1;
number1 = number2;
number2 = tmp;
}


template<class Type>
void BubleSort(int32_t& size , Type arr)
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


template<class Type>
void SortEvenElementArray(int32_t& size , Type arr)
{
    for(size_t i{1}; i < size; ++i)
    {
        ShiftElementArray(size, arr , i, 1);
    }
    BubleSort(size , arr);
}