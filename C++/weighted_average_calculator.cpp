#include <iostream>
#include <string>
#include <vector>

int StrToInt(std::string string);
std::string ToLower(std::string string);
bool StringIsNumber(std::string string);

int main()
{
    int numberGrades;
    int currentGrade;
    int currentWeight;
    int totalGrade = 0;
    int totalWeight = 0;
    std::string buffer;

    // Beginning
    std::cout << "Average Calculator (Optional Weight)\n";
    std::cout << "Enter number of grades: ";
    std::cin >> buffer;
    numberGrades = StrToInt(buffer);

    // Getting all grades
    for (int i = 1; i <= numberGrades; i++)
    {
        std::cout << "Enter grade (" << i << "/" << numberGrades << "): ";
        std::cin >> buffer;
        currentGrade = StrToInt(buffer);

        std::cout << "Enter weight of grade: ";
        std::cin >> buffer;
        currentWeight = StrToInt(buffer);

        system("cls");

        totalGrade += currentGrade * currentWeight;
        totalWeight += currentWeight;
    }

    std::cout << "Weighted Average: " << totalGrade / totalWeight;

    return 0;
}

int StrToInt(std::string string)
{
    while (!StringIsNumber(string))
    {
        std::cout << "Input must be a number, try again: ";
        std::cin >> string;
    }

    return stoi(string);
}

std::string ToLower(std::string string)
{    
    for (int i = 0; i < string.length(); i++)
    {
        string[i] = tolower(string[i]);
    }

    return string;
}

bool StringIsNumber(std::string string)
{
    for (int i = 0; i < string.length(); i++)
    {
        if (!isdigit(string[i]))
        {
            return false;
        }
    }

    return true;
}