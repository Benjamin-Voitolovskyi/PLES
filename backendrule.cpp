#include "backendrule.h"
#include "Probability.h"

BackendRule::BackendRule()
{

}

void BackendRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, probability] : answers)
    {
        if (progLang == "Java" || progLang == "C#" || progLang == "Python")
            probability = Probability::CERTAIN;
        else if (progLang == "C/C++" || progLang == "JavaScript")
            probability = Probability::POSSIBLE;
        else
            probability = Probability::UNLIKELY;
    }
}
