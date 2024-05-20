#include "webprogrammingrule.h"
#include "Probability.h"
#include "frontendrule.h"
#include "backendrule.h"
#include "fullstackrule.h"

WebProgrammingRule::WebProgrammingRule()
{
    m_prompt = "Which part of the web programs do you want to develop?";

    m_nextRules =
    {
        "Frontend",
        "Backend",
        "FullStack"
    };
}

std::unique_ptr<Rule> WebProgrammingRule::getChildRule(const std::string &input) const
{
    if (input == m_nextRules[0])
        return std::make_unique<FrontendRule>();
    if (input == m_nextRules[1])
        return std::make_unique<BackendRule>();
    if (input == m_nextRules[2])
        return std::make_unique<FullstackRule>();
    return Rule::getChildRule(input);
}

void WebProgrammingRule::run(std::map<std::string, Probability> &answers)
{
    for (auto& [progLang, probability] : answers)
    {
        if (progLang == "C/C++" || progLang == "R")
            probability = Probability::UNLIKELY;
        else
            probability = Probability::POSSIBLE;
    }
}
