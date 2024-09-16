#include "pch.h"

#include "Log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stacktrace>
#include <iostream>
#include <windows.h>

using namespace Squawk;

void Log::SetColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void Log::ResetColor()
{
    SetColor(CONSOLE_COLOR_RESET);
}

void Log::PrintWithColor(const char* str, int color)
{
    SetColor(color);
    // This is the only print function call in this class
    std::cout << str << std::endl;
    ResetColor();
}

char* Log::AddStrInfo(char* str)
{
    char* result = ToString("Squawk Log: %s", str);
    free(str);
    return result;
}

char* Log::Evaluatef(const char* format, va_list args)
{
    // Create a buffer with initial size of 256
    size_t size = 256;
    char* buffer = (char*)malloc(size * sizeof(char));
    if (buffer == nullptr)
    {
        PrintWithColor("ERROR: Memory allocation failed!", CONSOLE_COLOR_RED);
        return nullptr;
    }

    size_t neededSize = vsnprintf(buffer, size, format, args);

    if (neededSize > size)
    {
        size = neededSize + 1;
        char* newBuffer = (char*)realloc(buffer, size);
        if (newBuffer == nullptr)
        {
            PrintWithColor("ERROR: Memory reallocation failed!", CONSOLE_COLOR_RED);
            free(buffer);
            return nullptr;
        }
        buffer = newBuffer;

        vsnprintf(buffer, size, format, args);
    }

    return buffer;
}

char* Log::ToString(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    char* result = Evaluatef(format, args);
    va_end(args);

    return result;
}

void Log::Print(const char* str)
{
    Printf(str);
}

void Log::Printf(const char* format, ...)
{
    // Read args in the ellipsis ... parameter
    va_list args;
    va_start(args, format);
    char* result = Evaluatef(format, args);
    va_end(args);

    result = AddStrInfo(result);
    PrintWithColor(result, CONSOLE_COLOR_WHITE);
    free(result);
}

void Log::Error(const char* err)
{
    Errorf(err);
}

void Log::Errorf(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    char* result = Evaluatef(format, args);
    va_end(args);

    result = AddStrInfo(result);
    PrintWithColor(result, CONSOLE_COLOR_RED);
    free(result);
}

void Log::Warn(const char* warn)
{
    Warnf(warn);
}

void Log::Warnf(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    char* result = Evaluatef(format, args);
    va_end(args);

    result = AddStrInfo(result);
    PrintWithColor(result, CONSOLE_COLOR_YELLOW);
    free(result);
}
