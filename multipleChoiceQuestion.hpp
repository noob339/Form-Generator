#pragma once

#include <iostream>
#include <string>
#include <deque>
#include "Question.hpp"
#include "multipleChoiceAnswer.hpp"

//derived class from Question, this essentially constructs the mpQuestions
class multipleChoiceQuestion : public Question
{
    protected: 
        //when you inherit a vector from Question, is it the exact same vector?
        std::deque <multipleChoiceAnswer> mpAnswers; //a container for answers
        int position = -1;

    public:
        void push(multipleChoiceAnswer answer);

        //constructer of mpQuestions
        multipleChoiceQuestion(const std::string &file, size_t &index);
       
        const multipleChoiceAnswer& correctAnswer() const;
       

        
};