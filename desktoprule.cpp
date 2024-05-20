#include "desktoprule.h"
#include "Probability.h"

DesktopRule::DesktopRule()
{

}

void DesktopRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, probability] : answers)
    {
        if (progLang == "Python" || progLang == "Java" || progLang == "C/C++" || progLang == "C#")
            probability = Probability::CERTAIN;
        else
            probability = Probability::UNLIKELY;
    }
}
