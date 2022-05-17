#include "Question.hpp"

 std::string Question::getHTML() const noexcept
{
    std::string html = "<div class = \"q1\">" "<li>\n<h3>" + promptText + "</h3>\n";

    for (int i = 0; i < answers.size(); i++)
    { 
        html += answers[i]->getHTML(promptText); //here the answers get their html tag i
        html+="\n";
    }

    
    html += "</div>\n</li>\n";

    return html;
}

const std::string& Question::getPrompt() const noexcept { return promptText; }