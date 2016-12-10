/** Logger - A class providing file log
*   Copyright riban (2016)
*   Author: Brian Walton (brian@riban.co.uk)
*   Licence: LGPL
*/
#pragma once
#include <string>

using namespace std;

/** The Logger class provides the function to print messages to a log file.
    Each call to print() function will print a new line in the log file. Messages may be formatted similar to printf.
    If the logfile is not open, it will be opened, assuming the filename is valid and the application has rights to create the file.
    Each line is prefixed with a timestamp which may be configured by the parent application. The default is HH:MM:SS YYYY-mm-dd followed by a horizontal tab.
    @par
    @example
    //This is a simple example of using the logger class to log messages to file
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
*/
class Logger
{
    public:
        /** @brief  Construct an instance of a logger
        *   @param  filename Full name including path of the file to log to
        *   @param  reopen True to to reopen log file after each print (Default: true)
        *   @note   Reopening file after print may be required to update the file during runtime otherwise the log file is only updated when the logger object is destroyed or a call to close() is made.
        */
        Logger(string filename, bool reopen = true);
        virtual ~Logger();

        /** @brief  Open the log file
        */
        bool open();

        /** @brief  Close the log file
        */
        void close();

        /** @brief  Check if log file is open
        *   @return True if log file is open
        */
        bool isOpen();

        /** @brief  Print a formatted message to the log file
        *   @param  message The formatted message to log
        *   @param  ... Comma separated list of arguments to the formatted message
        *   @note   Use printf style formatted, e.g. print("Index %d", nIndex);
        */
        void print(const char* message, ...);

        /** @brief  Print a string message to the log file
        *   @param  message The message to log
        */
        void print(const string message);

        /** @brief  Set the timestamp format
        *   @param  format The format of the timestamp in strftime format, e.g. "%H:%M:%S - "
        *   @note   Default is "%H:%M:%S %Y-%m-%d\t", i.e. HH:MM:SS YYYY-mm-dd followed by a horizontal tab
        */
        void setTimestamp(const string format = "%H:%M:%S %Y-%m-%d\t");

    protected:

    private:
    FILE* m_pFileLog; //Pointer to the file stream
    string m_sFilename; //Log file name
    string m_sTimestamp; //Format of the timestamp
    bool m_bReopen; //True to reopen file after each print
};

