#include "computergraphicsrule.h"
#include "Probability.h"

ComputerGraphicsRule::ComputerGraphicsRule()
{

}

void ComputerGraphicsRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, prob] : answers)
    {
        if (progLang == "C/C++" || progLang == "C#" || progLang == "JavaScript")
            prob = Probability::CERTAIN;
        else if (progLang == "Java" || progLang == "Python")
            prob = Probability::POSSIBLE;
        else
            prob = Probability::UNLIKELY;
    }
}
