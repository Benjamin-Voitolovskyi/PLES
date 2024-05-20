#include "iosrule.h"
#include "Probability.h"

IOSRule::IOSRule()
{

}

void IOSRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, prob] : answers)
    {
        if (progLang == "Swift")
            prob = Probability::CERTAIN;
        else if (progLang == "C/C++" || progLang == "C#" || progLang == "JavaScript")
            prob = Probability::POSSIBLE;
        else
            prob = Probability::UNLIKELY;
    }
}
