#include "frontendrule.h"
#include "Probability.h"

FrontendRule::FrontendRule()
{

}

void FrontendRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, probability] : answers)
    {
        if (progLang == "HTML/CSS" || progLang == "JavaScript")
            probability = Probability::CERTAIN;
        else if (progLang == "Python")
            probability = Probability::POSSIBLE;
        else
            probability = Probability::UNLIKELY;
    }
}
