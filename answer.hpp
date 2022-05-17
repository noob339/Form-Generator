#pragma once

#include <iostream>
#include <string>

long getQuestionTextHash(const std::string &answerQuestion);


class answer
{
    protected: 
        std::string answerText; 

    public:
        answer(); //consturctor
        answer(std::string answerText);  //here we can construct an anwer by passing a string

        //setter
        void setAnswerText(std::string answerText);
    

        //getter
        std::string getAnswerText();
   

        //virtual function that gets deined in the derived class
        virtual const std::string getHTML(const std::string &questionText) const = 0; 

        //GETTER 
        long getAnswerTextHash() const;
      
        //maybe answers could have a bolean variable that tells us if its the correct answer

};

