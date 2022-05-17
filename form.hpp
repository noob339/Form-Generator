#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include "shortChoiceQuestion.hpp"
#include "multipleChoiceQuestion.hpp"
#include "shortChoiceAnswer.hpp"
#include "multipleChoiceAnswer.hpp"

//initialize any local variable in the 

std::string getTitle();

std::string readFile(std::string filePath);

class form
{
    private:
        std::vector<Question*> questions; //objects on a vector, stores questions
        std::deque<multipleChoiceQuestion> mpQuestions; //objects on a deque stores MP questons
        std::deque<shortChoiceQuestion> saQuestions;
        std::string titleText;

    public:
        form(); 
        void buildFromString(std::string &file);
        void pushMPChoice(std::string file, size_t &index);
        void pushSAChoice(std::string file, size_t &index);
        std::string getHTML(std::string action, std::string method);

        struct gradingRecord
        {
            std::string htmlGradingOutput = " ";
            int countCorrect = 0;
            int totQ_Count = 0;

            gradingRecord(std::string htmlGradingOutput, int countCorrect, int totQ_Count)
            {
                this->htmlGradingOutput = htmlGradingOutput;
                this->countCorrect = countCorrect;
                this->totQ_Count = totQ_Count;
            }
        };

        gradingRecord htmlGradedResponse(const auto &req)
        {
            std::string html;
            int countCorrect = 0;
            int totQ_count = mpQuestions.size();

            for(int i = 0; i < mpQuestions.size(); i++)
            {
                multipleChoiceQuestion& currentQuestion = mpQuestions[i];
                html += "<li><h3>" + currentQuestion.promptText + "</h3>";

                const long questionHash = getQuestionTextHash(mpQuestions[i].getPrompt());
                std::string strQ_Hash = std::to_string(questionHash);

                if(req.has_param(strQ_Hash.c_str()))
                {
                    std::string hashedAnswer = req.get_param_value(strQ_Hash.c_str());

                    if(stol(hashedAnswer) == currentQuestion.correctAnswer().getAnswerTextHash())
                    {
                        countCorrect++;
                    }

                    for (int j = 0; j < currentQuestion.answers.size(); j++)
                    {
                        multipleChoiceAnswer& currentAnswer = *(multipleChoiceAnswer*)currentQuestion.answers[j];
                        
                        if(currentAnswer.getAnswerTextHash() == currentQuestion.correctAnswer().getAnswerTextHash())
                        {
                            html+= "<span style='color: green'>" + currentAnswer.getHTML(currentQuestion.promptText) + "</span>";
                            
                        } 
                        else if (stol(hashedAnswer) == currentAnswer.getAnswerTextHash())
                        {
                            html+= "<span style='color: red'>" + currentAnswer.getHTML(currentQuestion.promptText) + "</span>";
                        }
                        else
                        {
                            html+= "<span style='color: gray'>" + currentAnswer.getHTML(currentQuestion.promptText) + "</span> \n";
                        }
                    }
                }

                // if(countCorrect == totQ_count)
                // {
                //     html = 
                // }
            }

            html += "<p>You scored: " + std::to_string(countCorrect) + " out of " + std::to_string(mpQuestions.size()) + "!\n </p>";

            return form::gradingRecord(html, countCorrect, mpQuestions.size());
        }

        

};

