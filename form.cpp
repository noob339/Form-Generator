#include "form.hpp"

form::form() {} //default constructor

void form::buildFromString(std::string &file)
{
    questions.clear(); //clear the vector
    mpQuestions.clear(); //clear the deque ("deck")
    saQuestions.clear();

    size_t index = file.find("question:");  //file.find("question:", 0); what is index set to exactly?
    //std::cout << "\n\n\n\n" << index << std::endl << std::endl << std::endl; //its set to 68 but why? that is the letter D

    //here we check, if the file has ended
    if(index == std::string::npos)
    {
        throw std::invalid_argument("Error, no questions in form");
    }

    size_t n = std::string("question:").length(); //we get the length of question
    

    while(index != std::string::npos) //while not at the end of the string
    {
        if(file.substr(n + index, 2) == "MP") //if it has MP, then push the MP answers
        {
            pushMPChoice(file, index);
        }
        else if (file.substr(n +index, 2) == "SA")
        {
            pushSAChoice(file, index);
        }
        else
        {
            index = std::string::npos;
        }
    }
}
//this function pushes the questions into the deque, and then pushes it into the vector
void form::pushMPChoice(std::string file, size_t &index) 
{
    mpQuestions.push_back(multipleChoiceQuestion(file, index)); //push the question into the deque
    questions.push_back(&mpQuestions.back()); //push the last element from the deque into the vector
    
}

void form::pushSAChoice(std::string file, size_t &index)
{
    saQuestions.push_back(shortChoiceQuestion(file, index));
    questions.push_back(&saQuestions.back());

}

//this function actually builds the html
std::string form::getHTML(std::string action, std::string method)
{
    std::string titleText = getTitle();

    std::string html = "<!DOCTYPE html> \n<html> \n<head> \n \t <link href=\"idk.css\" rel=\"stylesheet\" type=\"text/css\"> \n</head>\n";
    html += "<center> \n<div class = \"header\"> \n<h2>" + titleText + "</h2> \n</div> \n<form action=\"/" + action + "\" method=\"" + method + "\"> \n<ul class= \"no-bullets\">\n";

    for(int i = 0; i < questions.size(); i++)
    {
        //this adds the questions from the vector we pushed it into
        html += questions[i]->getHTML(); //when you want to access a method/member of a pointer to an object use the ->
    }

    html += "</ul>\n<input type=\"submit\" value=\"Enter\"> </form> \n </center> \n <html> \n"; //appends the final html syntax needed for the html code

    return html;
}


std::string readFile(std::string filePath)
{
  std::fstream file(filePath); 
  std::string val((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()); 
  //
  return val; //return what it stored from the file
}

std::string getTitle()
{
    std::string file = readFile("MisinfoSurvey.txt");

    int cursor = 0;
    int titleStart = file.find("title: ", cursor);

    if(file.substr(titleStart, std::string("title:").length()) != "title:")
    {
        throw std::invalid_argument("Error, invalid, no title supplied");
    }

    int titleTextStart = titleStart + std::string("title:").length();
    int titleEnd = file.find("\n", titleTextStart);
    std::string titleText = file.substr(titleTextStart, titleEnd - titleTextStart);

    return titleText;
}

