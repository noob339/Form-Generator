#include "shortChoiceQuestion.hpp"

shortChoiceQuestion::shortChoiceQuestion(const std::string &file, size_t &index)
{
    /*
    question: SA
    prompt: How is your day today?
    answer: Enter your answer
    */

    int questionStart = file.find("question:", index); //assigns to the position of the first character (q)
    
    int promptStart = file.find("\n", questionStart) + 1; //assigns the promptStart (p)
    
    //check if we actually got prompt, guess we could do this for the question as well
    if(file.substr(promptStart, std::string("prompt:").length()) != "prompt:")
    {
        throw std::invalid_argument("Error, invalid question, no prompt supplied");
    }
    
    int promptTextStart = promptStart + std::string("prompt:").length(); 

    int promptEnd = file.find("\n", promptTextStart); 

    promptText = file.substr(promptTextStart, promptEnd - promptTextStart); 

    push(shortChoiceAnswer());
    
    index = file.find("question:", promptEnd);
}

void shortChoiceQuestion::push(shortChoiceAnswer answer)
{
    scAnswers.push_back(answer); //push the answer into the deque
    answers.push_back(&scAnswers.back()); //the push the last element of the mpAnswers into the vector that is inherited from the base class
}