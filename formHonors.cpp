#include <iostream>
#include "httplib.h"
#include <vector>
#include <deque>
#include <stdexcept>
#include <fstream>
#include <string>
#include "form.hpp"

//For honors project - website, video, UML, flowchart

int main()
{
    httplib::Server svr;
    
    try
    {
        form form1;
        std::string fileData = readFile("MisinfoSurvey.txt");
        form1.buildFromString(fileData); 

        bool staticServer = svr.set_mount_point("/", "./");

        svr.Get("/option", [](const auto &req, auto &res) {

            form form;
            std::string fileData = readFile("MisinfoSurvey.txt");
            form.buildFromString(fileData); 

            std::string responseHTML = form.htmlGradedResponse(req).htmlGradingOutput;
            res.set_content(responseHTML, "text/html");
         });

        std::cout << form1.getHTML("option", "GET") << std::endl; 
        svr.listen("0.0.0.0", 8080);
    }
    catch(...)
    {
        std::cout << "Default exception caught\n";
    }
    
    
    return 0;
}



