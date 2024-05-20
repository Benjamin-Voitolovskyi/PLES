#include "fullstackrule.h"
#include "Probability.h"

FullstackRule::FullstackRule()
{

}

void FullstackRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, probability] : answers)
    {
        if (progLang == "Java" || progLang == "C#" || progLang == "Python" || progLang == "HTML/CSS" || progLang == "JavaScript")
            probability = Probability::CERTAIN;
        else
            probability = Probability::UNLIKELY;
    }
}
