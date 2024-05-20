#ifndef RULE_H
#define RULE_H

#include <map>
#include <memory>
#include <string>
#include <vector>

enum class Probability;

class Rule
{
public:
    Rule();

    virtual void run(std::map<std::string, Probability>&) {}
    virtual std::unique_ptr<Rule> getChildRule(const std::string&) const;

    const std::vector<std::string>& getNextRules() const;
    const std::string& getPrompt() const;
    bool hasNextRules() const;

protected:
    std::string m_prompt;
    std::vector<std::string> m_nextRules;
};

#endif // RULE_H
