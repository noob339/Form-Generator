#pragma once

#include <iostream>
#include <string>

long getQuestionTextHash(const std::string &answerQuestion);


class answer
{
    protected: 
        std::string answerText; 

    public:
        answer(); 
        answer(std::string answerText);  
        void setAnswerText(std::string answerText);
        std::string getAnswerText();
        virtual const std::string getHTML(const std::string &questionText) const = 0; 
        long getAnswerTextHash() const;
      
    

};

