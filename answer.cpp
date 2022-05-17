#include "answer.hpp"

answer::answer() : answerText("") {} //consturctor

answer::answer(std::string answerText) : answerText(answerText) {} //here we can construct an anwer by passing a string

//setter
void answer::setAnswerText(std::string answerText)
{
    this->answerText = answerText;
}

//getter
std::string answer::getAnswerText()
{
    return answerText;
}

//GETTER 
long answer::getAnswerTextHash() const
{
    return std::hash<std::string>()(answerText); //gives us a value for each input, a unique identifier of sorts
}

long getQuestionTextHash(const std::string &answerQuestion)
{
    return std::hash<std::string>()(answerQuestion); //gives us a value for each input, a unique identifier of sorts
}