#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>
#include <string>
#include <vector>

namespace Constants
{
const std::vector<std::string> PROGRAMMING_LANGUAGES
{
    "C/C++",
    "JavaScript",
    "Java",
    "C#",
    "Python",
    "R",
    "Swift",
    "Kotlin",
    "HTML/CSS"
};

const std::map<std::string, std::string> PROG_LANG_TO_IMAGE
{
    { "C/C++", ":/images/images/c++.png"},
    { "JavaScript", ":/images/images/js.png"},
    { "Java", ":/images/images/java.png"},
    { "C#", ":/images/images/c-sharp.png"},
    { "Python", ":/images/images/python.png"},
    { "R", ":/images/images/r.png"},
    { "Swift", ":/images/images/swift.png"},
    { "Kotlin", ":/images/images/kotlin-programming-language-icon.png"},
    { "HTML/CSS", ":/images/images/html+css.png"}
};

constexpr int IMAGE_SIZE = 256;
}

#endif // CONSTANTS_H
