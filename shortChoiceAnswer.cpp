#include "shortChoiceAnswer.hpp"

shortChoiceAnswer::shortChoiceAnswer() : answer() {};

shortChoiceAnswer::shortChoiceAnswer(const std::string answerText) : answer(answerText) {}; //constructer accepts a string, the answerText

const std::string shortChoiceAnswer::getHTML(const std::string &questionText) const
{
    std::string html = "<textarea id=" + std::to_string(getAnswerTextHash()) + " name=" + std::to_string(getQuestionTextHash(questionText)) + "rows=" + std::to_string(4) + " cols=" + std::to_string(50) + ">Enter text here</textarea>";

    return html;
}