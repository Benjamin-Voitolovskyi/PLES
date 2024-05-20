#include "osrule.h"
#include "Probability.h"

OSRule::OSRule()
{
}

void OSRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, prob] : answers)
    {
        prob = progLang == "C/C++" ? Probability::CERTAIN : Probability::UNLIKELY;
    }
}

std::unique_ptr<Rule> OSRule::getChildRule(const std::string &input) const
{

}
