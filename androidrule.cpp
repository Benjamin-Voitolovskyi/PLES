#include "androidrule.h"
#include "Probability.h"

AndroidRule::AndroidRule()
{

}

void AndroidRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, prob] : answers)
    {
        if (progLang == "Java" || progLang == "Kotlin")
            prob = Probability::CERTAIN;
        else if (progLang == "C/C++" || progLang == "Python" || progLang == "C#" || progLang == "JavaScript")
            prob = Probability::POSSIBLE;
        else
            prob = Probability::UNLIKELY;
    }
}
