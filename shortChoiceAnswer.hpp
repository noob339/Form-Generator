#pragma once

#include <iostream>
#include <string>
#include "answer.hpp"

class shortChoiceAnswer : public answer
{
    public:
        shortChoiceAnswer(); 
        shortChoiceAnswer(const std::string answerText); //constructer accepts a string, the answerText
        const std::string getHTML(const std::string &questionText) const;
        
};