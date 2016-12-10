/** Logger - A class providing file log
*   Copyright riban (2016)
*   Author: Brian Walton (brian@riban.co.uk)
*   Licence: LGPL
*/
#include "logger.h"
#include <stdarg.h> //provides va_* functions
#include <fstream> //provides fopen, etc.
#include <ctime> //provides time functions

Logger::Logger(string filename, bool reopen) :
    m_pFileLog(NULL),
    m_sFilename(filename),
    m_bReopen(reopen)
{
    setTimestamp();
}

Logger::~Logger()
{
    close();
}

bool Logger::open()
{
    if(m_pFileLog)
        return true;
    m_pFileLog = fopen(m_sFilename.c_str(), "a");
    return(m_pFileLog != NULL);
}

void Logger::close()
{
    if(m_pFileLog)
        fclose(m_pFileLog);
    m_pFileLog = NULL;
}

bool Logger::isOpen()
{
    return(m_pFileLog == NULL);
}

void Logger::print(const char* message, ...)
{
    if(!open())
        return;
    //Time stamp
    time_t now = time(NULL);
    tm * ptm = localtime(&now);
    char timestamp[32];
    strftime(timestamp, 32, m_sTimestamp.c_str(), ptm);
    fprintf(m_pFileLog, timestamp);

    va_list va;
    va_start(va, message);
    vfprintf(m_pFileLog, message, va);
    va_end(va);
    fprintf(m_pFileLog, "\n");
    if(m_bReopen)
        m_pFileLog = freopen(m_sFilename.c_str(), "a", m_pFileLog);
}

void Logger::print(string message)
{
        print(message.c_str());
}

void Logger::setTimestamp(const string format)
{
    m_sTimestamp = format;
}
