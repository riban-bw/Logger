/** A simple example of using the Logger class
*   Copyright riban (2016)
*   Author: Brian Walton (brian@riban.co.uk)
*   Licence: LGPL
*/
#include "logger.h" //provides logger class
#include <unistd.h> //provides sleep

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
