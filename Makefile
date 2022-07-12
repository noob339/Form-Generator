CC = g++ 
CXX = g++
INCLUDES = 
LDFLAGS = -pthread
CFLAGS = -g -fpermissive -std=c++2a -pthread 
CXXFLAGS = -g -fpermissive -std=c++2a -pthread
APP_CPPFLAGS += 
default: formHonors
formHonors: form.o Question.o answer.o multipleChoiceAnswer.o multipleChoiceQuestion.o shortChoiceAnswer.o shortChoiceQuestion.o formHonors.o
formHonors.o: formHonors.cpp form.hpp Question.hpp answer.hpp multipleChoiceAnswer.hpp multipleChoiceQuestion.hpp shortChoiceQuestion.hpp shortChoiceAnswer.hpp
form.o: form.cpp form.hpp Question.hpp answer.hpp multipleChoiceQuestion.hpp multipleChoiceAnswer.hpp shortChoiceQuestion.hpp shortChoiceAnswer.hpp
Question.o: Question.cpp Question.hpp answer.hpp
answer.o: answer.cpp answer.hpp
multipleChoiceAnswer.o: multipleChoiceAnswer.cpp multipleChoiceAnswer.hpp answer.hpp
multipleChoiceQuestion.o: multipleChoiceQuestion.cpp multipleChoiceQuestion.hpp Question.hpp answer.hpp 
shortChoiceAnswer.o: shortChoiceAnswer.cpp shortChoiceAnswer.hpp answer.hpp
shortChoiceQuestion.o: shortChoiceQuestion.cpp shortChoiceQuestion.hpp Question.hpp answer.hpp 
.PHONY: clean 
  
clean:
	rm *.o formHonors 
