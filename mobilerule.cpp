#include "mobilerule.h"
#include "Probability.h"
#include "androidrule.h"
#include "iosrule.h"
#include "hybridrule.h"

MobileRule::MobileRule()
{
    m_prompt = "Specify the platform for which you want to develop mobile applications";

    m_nextRules =
    {
        "Android",
        "iOS",
        "Hybrid Development"
    };
}

void MobileRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, prob] : answers)
    {
        if (progLang == "JavaScript" || progLang == "C/C++" || progLang == "C#")
            prob = Probability::POSSIBLE;
        else
            prob = Probability::UNLIKELY;
    }
}

std::unique_ptr<Rule> MobileRule::getChildRule(const std::string &input) const
{
    if (input == m_nextRules[0])
        return std::make_unique<AndroidRule>();
    if (input == m_nextRules[1])
        return std::make_unique<IOSRule>();
    if (input == m_nextRules[2])
        return std::make_unique<HybridRule>();
    return Rule::getChildRule(input);
}
