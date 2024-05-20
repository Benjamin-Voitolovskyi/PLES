#include "rule.h"

#include <stdexcept>

Rule::Rule()
{

}

std::unique_ptr<Rule> Rule::getChildRule(const std::string&) const
{
    throw std::invalid_argument("Uknown domain");
}

const std::vector<std::string> &Rule::getNextRules() const
{
    return m_nextRules;
}

const std::string &Rule::getPrompt() const
{
    return m_prompt;
}

bool Rule::hasNextRules() const
{
    return !getNextRules().empty();
}
