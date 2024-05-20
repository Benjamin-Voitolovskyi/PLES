#include "iotrule.h"
#include "Probability.h"

IoTRule::IoTRule()
{

}

void IoTRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, prob] : answers)
    {
        if (progLang == "C/C++" || progLang == "Python")
            prob = Probability::CERTAIN;
        else if (progLang == "Java" || progLang == "JavaScript")
            prob = Probability::POSSIBLE;
        else
            prob = Probability::UNLIKELY;
    }
}
