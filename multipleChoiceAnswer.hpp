#pragma once

#include <iostream>
#include <string>
#include "answer.hpp"


class multipleChoiceAnswer : public answer
{
    public:
        multipleChoiceAnswer(); //default constructer
        multipleChoiceAnswer(const std::string answerText); //constructer accepts a string, the answerText
        const std::string getHTML(const std::string &questionText) const;
        
        
};