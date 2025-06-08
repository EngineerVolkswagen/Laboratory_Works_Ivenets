#include <iostream>
#include <cstring>


int32_t CounterZeroInLiteral(char* ptr)
{
    int32_t counterZero{0};
    for(size_t i{0}; i < strlen(ptr); ++i)
        {
            if(ptr[i] == '0')
            {
                ++counterZero;
            }
        }
    return counterZero;
}


bool AlphabetCheck(char* str)
{
    for(int32_t i{0}; i < strlen(str)-1; ++i)
    {
        if(!isalnum(str[i]) && str[i] != ' ') 
        {
            return false;
        }
    }
    return true;
}
 

char* LiteralhMaxNumberZeros(char* str)
{
    char delim[25]= " ,;.!?/-+:@#$%&^()*{}[]}";
        char *ptr = strtok(str, delim);
        char *lastLiteral = new char[strlen(ptr)+1];
        lastLiteral = ptr;
        char *penultimateLiteral = new char[strlen(lastLiteral)+1];
        penultimateLiteral = lastLiteral;
        while(ptr != NULL)
        {
            if(CounterZeroInLiteral(lastLiteral) < CounterZeroInLiteral(ptr))
            {
                lastLiteral = ptr;
                penultimateLiteral = lastLiteral;
            }
            else if(CounterZeroInLiteral(penultimateLiteral) == CounterZeroInLiteral(ptr))
            {
                penultimateLiteral = lastLiteral;
                lastLiteral = ptr;
            }
            ptr = strtok(NULL, delim);
        }
    return penultimateLiteral;
}


int main()
{
    char str[300];
    std::cout << "Enter string: ";
    std::cin.getline(str,300);
    if(!AlphabetCheck(str))
    {
        std::cout << "the string does not consist of words of this alphabet :( \n";
    }
    else if(CounterZeroInLiteral(str) == 0)
    {
        std::cout << "there are no zeros in the string :(  \n";
    }
    else
    {
        std::cout << "result: " << LiteralhMaxNumberZeros(str) << " :) " << '\n';   
    }
    return 0;
}
