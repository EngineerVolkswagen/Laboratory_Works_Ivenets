#include <iostream>
#include <string>


int32_t NumberDifferentElementWord(std::string& str) {
    int32_t counter = 0;
    for (size_t i = 0; i < str.length(); ++i) 
    {
        if (str.find(str[i]) == i) 
        {
            ++counter;       
        }
    }
    return counter;
}


std::string FindWordLargestNumberDifferentElements(std::string str)
{
    std::cout << "Находим слово(а) с наибольшим колличеством разных символов в строке: " << str << '\n';
    std::string delim(" !,.:;");
    std::string result;
    std::string str_save;
    std::string str_peremen;
    int size = str.size();    
    int i{0};
        std::string::size_type begIdx, endIdx;
        begIdx = str.find_first_not_of(delim);
        while(begIdx != std::string::npos)
        {
            endIdx = str.find_first_of(delim, begIdx);
            if(endIdx == std::string::npos)
            {
                endIdx = str.length();
            }
            str_peremen = str.substr(begIdx, endIdx-begIdx);
            if(NumberDifferentElementWord(str_save) < NumberDifferentElementWord(str_peremen))
            {
                str_save = str_peremen;
                result = str_peremen;
            }
            else if(NumberDifferentElementWord(str_save) == NumberDifferentElementWord(str_peremen))
            {
                result.append(" ");
                result.append(str_peremen);
            }
            begIdx = str.find_first_not_of(delim, endIdx);
        }
        std::cout << "Результат: ";
        return result;
}


int main()
{
    std::string str;
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);
    std::cout << FindWordLargestNumberDifferentElements(str) << '\n';
    return 0;
}
