#pragma once

#ifdef PERCHENGINECPP_EXPORTS
#define PERCH_API __declspec(dllexport)
#else
#define PERCH_API __declspec(dllimport)
#endif


#include <stdarg.h>

namespace Squawk
{
	// Windows terminal color keys. WINDOWS ONLY
	constexpr auto CONSOLE_COLOR_RESET = 7;
	constexpr auto CONSOLE_COLOR_YELLOW = 14;
	constexpr auto CONSOLE_COLOR_WHITE = 15;
	constexpr auto CONSOLE_COLOR_RED = 12;

	static class Log
	{

	private:

		static void SetColor(int color);
		static void ResetColor();
		static void PrintWithColor(const char* str, int color);
		static char* AddStrInfo(char* str);
		static char* Evaluatef(const char* format, va_list args);

	public:

		PERCH_API static char* ToString(const char* format, ...);

		PERCH_API static void Print(const char* str);
		PERCH_API static void Printf(const char* format, ...);
		PERCH_API static void Error(const char* err);
		PERCH_API static void Errorf(const char* format, ...);
		PERCH_API static void Warn(const char* warn);
		PERCH_API static void Warnf(const char* format, ...);

	};

}
