#include "multipleChoiceAnswer.hpp"

multipleChoiceAnswer::multipleChoiceAnswer() : answer() {}; //default constructer

multipleChoiceAnswer::multipleChoiceAnswer(const std::string answerText) : answer(answerText) {}; //constructer accepts a string, the answerText

//here we construct a virtual function
const std::string multipleChoiceAnswer::getHTML(const std::string &questionText) const
{
    std::string html = "<input type=\"radio\" id=\"" + std::to_string(getAnswerTextHash()) + "\" name=\"" + std::to_string(getQuestionTextHash(questionText)) + "\" value=\"" + std::to_string(getAnswerTextHash()) + "\">"
    "<label for=\"" +  std::to_string(getAnswerTextHash()) + "\">" + answerText + "</label><br>";
    return html;
}