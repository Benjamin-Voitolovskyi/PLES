#include "airule.h"
#include "Probability.h"

AIRule::AIRule()
{

}

void AIRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, prob] : answers)
    {
        if (progLang == "R" || progLang == "Python")
            prob = Probability::CERTAIN;
        else if (progLang == "Java" || progLang == "C#" || progLang == "C/C++" || progLang == "JavaScript")
            prob = Probability::POSSIBLE;
        else
            prob = Probability::UNLIKELY;
    }
}
