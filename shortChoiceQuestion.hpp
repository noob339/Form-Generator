#pragma once

#include <iostream>
#include <string>
#include <deque>
#include "Question.hpp"
#include "shortChoiceAnswer.hpp"


class shortChoiceQuestion : public Question
{
    protected: 
        std::deque <shortChoiceAnswer> scAnswers; 

    public:
        shortChoiceQuestion(const std::string &file, size_t &index);
        void push(shortChoiceAnswer answer);
      


        
};