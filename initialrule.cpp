#include "initialrule.h"
#include "webprogrammingrule.h"
#include "airule.h"
#include "desktoprule.h"
#include "osrule.h"
#include "mobilerule.h"
#include "iotrule.h"
#include "computergraphicsrule.h"

#include <string>

InitialRule::InitialRule()
{
    m_prompt = "Specify domain of programming";

    m_nextRules =
    {
        "Web Programming",
        "Artificial Intelligence",
        "Desktop Apps",
        "Operating Systems",
        "Mobile Apps",
        "Internet of Things",
        "Computer Graphics"
    };
}

std::unique_ptr<Rule> InitialRule::getChildRule(const std::string &input) const
{
    if (input == m_nextRules[0])
        return std::make_unique<WebProgrammingRule>();
    if (input == m_nextRules[1])
        return std::make_unique<AIRule>();
    if (input == m_nextRules[2])
        return std::make_unique<DesktopRule>();
    if (input == m_nextRules[3])
        return std::make_unique<OSRule>();
    if (input == m_nextRules[4])
        return std::make_unique<MobileRule>();
    if (input == m_nextRules[5])
        return std::make_unique<IoTRule>();
    if (input == m_nextRules[6])
        return std::make_unique<ComputerGraphicsRule>();
    return Rule::getChildRule(input);
}
