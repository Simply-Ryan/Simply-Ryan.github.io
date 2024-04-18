#include <iostream>
#include <string>
#include <map>

bool CheckGenotypes(std::string genotypes[2]);

std::string ToLower(std::string s);

int main()
{
    // Variables
    std::string phenotypes[2];
    std::string genotypes[2];
    std::map<std::string, int> offsprings;
    const double totalPossibilities = 2;
    
    // Ask for possible phenotypes
    std::cout << "Enter dominant phenotype: ";
    std::getline(std::cin, phenotypes[0]);
    std::cout << "Enter recessive phenotype: ";
    std::getline(std::cin, phenotypes[1]);

    // Ask for genotypes
    std::cout << "Enter genotype (1/2): ";
    std::getline(std::cin, genotypes[0]);
    std::cout << "Enter genotype (2/2): ";
    std::getline(std::cin, genotypes[1]);

    // Genotype validity
    if (!CheckGenotypes(genotypes))
    {
        std::cout << "Genotypes must be the two same letters long. (Case insensitive)" << "\n";

        return 1;
    }

    // Count all probabilities
    for (int i = 0; i < 2; i++)
    {
        bool dominant = false;

        for (int j = 0; j < 2; j++)
        {
            if (isupper(genotypes[i][j]))
            {
                dominant = true;
                break;
            }
        }

        if (dominant)
        {
            offsprings[phenotypes[0]]++;
        }
        else
        {
            offsprings[phenotypes[1]]++;
        }
    }

    // Print probabilities
    for (const auto& pair : offsprings)
    {
        std::cout << "Probability of " << pair.first << ": " << pair.second / totalPossibilities * 100 << "%.\n";
    }

    return 0;
}

// Check whether all letter are same to lowercase
bool CheckGenotypes(std::string genotypes[2])
{
    return (genotypes[0].length() == 2 && genotypes[1].length() == 2 && ToLower(genotypes[0]) == ToLower(genotypes[1]));
}

std::string ToLower(std::string s)
{
    for (int i = 0, len = s.length(); i < len; i++)
    {
        s[i] = tolower(s[i]);
    }

    return s;
}