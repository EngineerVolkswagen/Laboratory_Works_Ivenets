#include <iostream>


void CreatArray(int32_t**& mtr, int32_t line, int32_t column)
{
    mtr = new int32_t*[line];
    for(int32_t i{0}; i < line; ++i)
    {
        mtr[i] = new int32_t[column]; 
    }
}


void swap(int32_t& a, int32_t& b)
{
    int32_t tmp = a; 
    a  = b;
    b = tmp;
}


void OutputElementArray(int32_t** mtr, int32_t line , int32_t column)
{
    for(int32_t i{0}; i < line; ++i)
    {
        for(int32_t j{0}; j < column; ++j)
        {
            std::cout << mtr[i][j] << " ";
        }
        std::cout  << '\n';
    }
}


void InputElementArray(int32_t** mtr, int32_t line , int32_t column)
{
    for(int32_t i{0}; i < line; ++i)
    {
        for(int32_t j{0}; j < column; ++j)
        {
            std::cin >> mtr[i][j];
        }
    }
}


// задание 1 варианта номер 5
bool CheckIfStringElementPositive(int32_t** mtr, int32_t NumberLine , int32_t column)
{
    for(int32_t j{0}; j < column; ++j)
    {
        if(mtr[NumberLine][j] < 0)
        {
            return false;
        }
    }
    return true;
}


int32_t MultiplicationStringElementsWithPositiveElement(int32_t** mtr, int32_t line , int32_t column)
{
    int32_t result{1};
    for(int32_t i{0}; i < line; ++i)
    {
        if(CheckIfStringElementPositive(mtr,i,column))
        {
            for(int32_t j{0}; j < column; ++j)
            {
                result *= mtr[i][j];
            }
        }
    }
    return result;
}


// задание 2 варианта номер 5
int32_t MaxElementInArray(int32_t** mtr, int32_t line , int32_t column)
{
    int32_t a = mtr[0][0];
    for(int32_t i{0}; i < line; ++i)
    {   
        for(int32_t j{0}; j < column; ++j )
        {
            if(mtr[i][j] > a)
            {
                a = mtr[i][j];
            }
        }
    }
    return a;
}


int32_t Index_I(int32_t** mtr, int32_t line , int32_t column , int32_t a)
{
    int32_t index_i{0};
    for(int32_t i{0}; i < line; ++i)
    {   
        for(int32_t j{0}; j < column; ++j )
        {
            if(mtr[i][j] == a)
            {
                index_i = i;
            }
        }
    }
    return index_i;
}


int32_t Index_J(int32_t** mtr, int32_t line , int32_t column, int32_t a)
{
    int32_t index_j{0};
    for(int32_t j{0}; j < column; ++j )
    {   
        for(int32_t i{0}; i < line; ++i)
        {
            if(mtr[i][j] == a)
            {
                index_j = j;
            }
        }
    }
    return index_j;
}

void SwapLines(int32_t**& mtr, int32_t column,int32_t numberline1, int32_t numberline2)
{
    for(int32_t i{0}; i < column; ++i)
    {   
        int32_t tmp{0};
        tmp = mtr[numberline1][i];
        mtr[numberline1][i] = mtr[numberline2][i];
        mtr[numberline2][i] = tmp; 
    }
}


void SwapColumns(int32_t**& mtr, int32_t line ,int32_t numberline1, int32_t numberline2)
{
    for(int32_t j{0}; j < line; ++j)
    {   
        int32_t tmp{0};
        tmp = mtr[j][numberline1];
        mtr[j][numberline1] = mtr[j][numberline2];
        mtr[j][numberline2] = tmp; 
    }
}


void SwapArrayElementsBySwapLineColumns(int32_t**& mtr, int32_t line , int32_t column)
{
    SwapLines(mtr, column, Index_I(mtr,line ,column, MaxElementInArray(mtr,line ,column)),0);
    SwapColumns(mtr, line, column-1 , Index_J(mtr,line ,column,MaxElementInArray(mtr,line ,column)));
}


/*
//попытка задания 1 вариант 15
int32_t elementmencshzadanogo(int32_t** mtr, int32_t line , int32_t column, int32_t b )
{
    int32_t a = mtr[0][0];
    a = 0;
    for(int32_t i{0}; i < line; ++i)
    {   
        for(int32_t j{0}; j < column; ++j )
        {
            if( mtr[i][j] < b )
            {
                if(mtr[i][j] > a)
                {
                    a = mtr[i][j];
                }
            }
        }
    }
    return a;
}


void SMENA(int32_t**& mtr, int32_t line , int32_t column)
{
    SwapLines(mtr, column, 0, Index_I(mtr,line ,column, MaxElementInArray(mtr,line ,column)));
    SwapColumns(mtr, line, 0 , Index_J(mtr,line ,column,MaxElementInArray(mtr,line ,column)));
    int32_t a{MaxElementInArray(mtr, line, column)};
    for(int32_t i {1}; i < ALessB(line, column); ++i )
    {
        if(Index_I(mtr,line ,column, elementmencshzadanogo(mtr,line,column,a) ==  || Index_J(mtr,line ,column, elementmencshzadanogo(mtr,line,column,a)) == )
        {

        }
        else 
        {
        SwapLines(mtr, column, i, Index_I(mtr,line ,column, elementmencshzadanogo(mtr,line,column,a)));
        if(mtr[i][i] != elementmencshzadanogo(mtr,line,column,a))
        {
            SwapColumns(mtr, line, i , Index_J(mtr,line ,column, elementmencshzadanogo(mtr,line,column,a)));
        }
        }
        a = mtr[Index_I(mtr,line,column,elementmencshzadanogo(mtr,line,column,a))][Index_J(mtr,line,column,elementmencshzadanogo(mtr,line,column,a))];
    }
}
*/



// задание 2 вариант 15
int32_t CheckIfStringNegative(int32_t** mtr, int32_t column, int32_t line)
{
    for(int32_t i{0}; i < line; ++i)
    {
        if(!CheckIfStringElementPositive(mtr, i , column))
        {
            return i+1;
        }
    }
    return -1;
}
