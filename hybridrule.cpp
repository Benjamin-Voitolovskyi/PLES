#include "hybridrule.h"
#include "Probability.h"

HybridRule::HybridRule()
{

}

void HybridRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, prob] : answers)
    {
        if (progLang == "JavaScript" || progLang == "C#")
            prob = Probability::CERTAIN;
        else if (progLang == "C/C++")
            prob = Probability::POSSIBLE;
        else
            prob = Probability::UNLIKELY;
    }
}
