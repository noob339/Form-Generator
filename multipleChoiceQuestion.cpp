#include "multipleChoiceQuestion.hpp"

//constructer of mpQuestions
multipleChoiceQuestion::multipleChoiceQuestion(const std::string &file, size_t &index)
{

    int mIndex = -1;
    /*
    (q)uestion:MP 
    (p)rompt: (B)athing (\n1)
    (a)nswer: Bathes self completely or needs help in bathing only a single part of the body such as the back, genital area or disabled extremity. (\n2)
    answer: Need help with bathing more than one part of the body, getting in or out of the tub or shower. Requires total bathing
    */

    /*
    question:MP
    prompt: The United States has contributed more GHG emissions than any other country.
    @answer: True
    answer: False
    */

    //is this whole process called parsing?
    //the idea here is to start construction one multiple choice question at a time, we don't need to know exactly what index is to to, just that we can keep track of it by knowing what characters and strings we are dealing with. 

    int questionStart = file.find("question:", index); //assigns to the position of the first character (q)
    int promptStart = file.find("\n", questionStart) + 1; //assigns the promptStart (p)
    
    //check if we actually got prompt, guess we could do this for the question as well
    if(file.substr(promptStart, std::string("prompt:").length()) != "prompt:")
    {
        throw std::invalid_argument("Error, invalid question, no prompt supplied");
    }

    int promptTextStart = promptStart + std::string("prompt:").length(); // caculates the start of the text for the prompt (B)
    int promptEnd = file.find("\n", promptTextStart); //search for the breakline after prompTextStart (\n1)
    promptText = file.substr(promptTextStart, promptEnd - promptTextStart); //calculate the promptText using the start end to determine the amount of text to get

    int answerStart = promptEnd + 1 + (file[promptEnd + 1] == '@'); //calculate the answer start (a)
    int answerEnd = answerStart;//calculate the answer end  (a)

    //cout << "answerStart: " << file.substr(answerStart,20) << std::endl;

    //here we check to see if the answer start is indeed "answer:"
    if (file.substr(answerStart, std::string("answer:").length()) != "answer:")
    {
        throw std::invalid_argument("Error, invalid question, no answer supplied");
    }

    answerEnd = file.find("\n", answerStart); //search for the breakline after asnwer start (\n2)

    //this is where we get both answers
    while(file.substr(answerStart, std::string("answer:").length()) == "answer:")
    {
        const int mIndex = answerStart - 1; //this would set the index to @
        

        if(file[mIndex] == '@')
        {
            position = answers.size();
        }
        
        answerStart += std::string("answer:").length();
        multipleChoiceAnswer answer(file.substr(answerStart, answerEnd - answerStart));
        push(answer); //push the answer into the deque which pushes into the vector
        answerStart = answerEnd + 1 + (file[answerEnd + 1] == '@');
        answerEnd = file.find("\n", answerEnd + 1);

        //std::cout << "Start of answer row: " << file.substr(answerStart, 5) <<  std::endl;
    }
    index = file.find("question:", answerEnd); //set the index to the next question and start looking from the answer end, this is why reference index to save its location
}

void multipleChoiceQuestion::push(multipleChoiceAnswer answer)
{
    mpAnswers.push_back(answer); //push the answer into the deque
    answers.push_back(&mpAnswers.back()); //the push the last element of the mpAnswers into the vector that is inherited from the base class
    //why are we pushing into a deque first and then a vector? Why not just stick with the vector?
}

const multipleChoiceAnswer& multipleChoiceQuestion::correctAnswer() const
{
    return mpAnswers[position];
}