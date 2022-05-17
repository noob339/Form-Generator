# Form Generator

This project allows us to automatically generate a form from a file, and in this case I am using a txt file.

The file is then converted into a string and then parsed into an html file.

Based on the template from the txt file, the user is able to create a multiple choice form, a written answer form, a mixed form, and hopefully other varieties of forms moving forward. 

# The following is the template used and can be used with most common text files:

      title:
      question:SA/MP
      prompt: 
      answer:
      @answer:


The template above represents just one question but with a title.

title: - This tag is used for the title alone, and the progrem expects just one title.

question:MP - There can be an unlimited amount of questions and the "MP" tag and "SA" tags are used to denote the format of the question.
MP is multiple choice and SA is short answer.

prompt: - Each question has a prompt and the prompt could be an acutal question or it could be some form of instruction to the user.

answer: - There could be multiple answers depending on the format of the quiz, for example true or false has 2 possible answers, a written response typically has one and a proper multiple choice question has four.

@ - This symbol is used to denote the correct answer for the multiple choice question


# Example of the program

      title: Climate Change Quiz

      question:MP
      prompt: Greenhouse gases trap heat, acting a blanket for the earth and causing its general temperature to rise
      @answer: True
      answer: False 


      question:MP
      prompt: The following gases are not GHGs: nitrous oxide (N2O), methane (CH4), water vapor (H20) and chlorofluorocarbons (CFCs) such as carbon dioxide.
      answer: True
      @answer: False


      question:MP
      prompt: Human activities are responsible for climate change 
      @answer: True
      answer: False


      question:MP
      prompt: Climate change has an adverse effect of the environment and the species living in it?
      @answer: True
      answer: False


      question:MP
      prompt: Climate change is not harmful and is a natural process of earth itself 
      answer: True
      @answer: False


      question:MP
      prompt: Humans themselves created greenhouse gases
      @answer: True
      answer: False


      question:MP
      prompt: If we continue emitting green house gases without any stop then irreversible damage to earth’s atmosphere and environment across several regions
      @answer: True
      answer: False


      question:MP
      prompt: The United States has contributed more GHG emissions than any other country.
      @answer: True
      answer: False


      question:MP
      prompt: The term global warming was changed to climate change in an effort to account for the varying extreme weathers as a result from the overall global warming
      @answer: True
      answer: False


      question:MP
      prompt: Only leaders, politicians and head of states can impact climate change in positive or negative ways
      answer: True
      @answer: False
      
      
# Results when running


![Screen Shot 2022-05-16 at 10 09 53 PM](https://user-images.githubusercontent.com/88294617/168714010-80910532-9128-4cd7-8faa-033281635ec9.png)

# Challenges
Learning to use the httplib server library and effectively implement a server to serve and handle requests

Learning to use a step through debugger to be able to pinpoint the bugs in my program

Learning to use Google Sites to showcase my site

Designing a UML and flowchart for my program

Parsing the text inside the string in order to get the right data in its corresponding fields to generate the form

Learning CSS and HTML

# Future Direction
Generating the CSS page and abstracting the template for users to builder their forms online.

Add more functuonality to the form site by adding features such as a name, email, and date field. 

Store the scores on a database to collect and analyze data such as the average score, etc

Abstracting the template for clients to run directly from a browser

# How to locally build and run
1. clone the repository into a directory
2. cd into the directory
3. modify a txt file using the template above to make your own quiz
4. Open up formHonors.cpp and read in the txt file
5. from the terminal, run make to compile
6. then run ./formHonors > index.html 
7. then go to http://127.0.0.1:8080/ on any browser




