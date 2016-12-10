# Logger
C++ class that logs messages to file

#Overview
This simple C++ class provides the ability to add logging to file to an application.

#Usage
Include the header logger.h in the main application.
Add logger.h and logger.cpp to the project (or you may compile it as a library and link to it).

The Logger class provides the function to print messages to a log file.
Each call to print() function will print a new line in the log file. Messages may be formatted similar to printf.
If the logfile is not open, it will be opened, assuming the filename is valid and the application has rights to create the file.
Each line is prefixed with a timestamp which may be configured by the parent application. The default is HH:MM:SS YYYY-mm-dd followed by a horizontal tab.

#Example
This is a simple example of using the logger class to log messages to file.
`
#include "logger.h" //provides logger class
using namespace std;
int main()
{
    Logger logger("test.log");
    logger.print("This is a test.");
    for(int i=1;i<6;++i)
    {
        logger.print("Message #%d", i);
        sleep(1);
    }
    logger.setTimestamp("");
    string sMessage = "Hello world!";
    logger.print(sMessage);
    return 0;
}
`