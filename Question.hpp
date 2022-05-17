#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "answer.hpp"


class Question
{
    protected:
        std::vector<answer*> answers; //a vector of pointers to answer
        std::string promptText; //inherited by mpChoiceQuestions
        friend class form;

    public:
        //build an html tag for the promptText from the vector
        std::string getHTML() const noexcept;
        const std::string& getPrompt() const noexcept;
};