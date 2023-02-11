#include "inc/base/MLoggerConsole.h"

#include "src/_internal_inc/macros.h"

#include <stdarg.h>
#include <string.h>
#include <stdio.h>




#if     TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


  #include <iostream>

  using namespace std;

  #define __COLOR_FG_BLACK             "\033[0;30m"
  #define __COLOR_FG_RED               "\033[0;31m"
  #define __COLOR_FG_GREEN             "\033[0;32m"
  #define __COLOR_FG_YELLOW            "\033[0;33m"
  #define __COLOR_FG_BLUE              "\033[0;34m"
  #define __COLOR_FG_MAGENTA           "\033[0;35m"
  #define __COLOR_FG_CYAN              "\033[0;36m"
  #define __COLOR_FG_WHITE             "\033[0;37m"

  #define __COLOR_FG_BLACK_BOLD        "\033[1;30m"
  #define __COLOR_FG_RED_BOLD          "\033[1;31m"
  #define __COLOR_FG_GREEN_BOLD        "\033[1;32m"
  #define __COLOR_FG_YELLOW_BOLD       "\033[1;33m"
  #define __COLOR_FG_BLUE_BOLD         "\033[1;34m"
  #define __COLOR_FG_MAGENTA_BOLD      "\033[1;35m"
  #define __COLOR_FG_CYAN_BOLD         "\033[1;36m"
  #define __COLOR_FG_WHITE_BOLD        "\033[1;37m"

  #define __COLOR_FG_BLACK_BLINK       "\033[5;30m"
  #define __COLOR_FG_RED_BLINK         "\033[5;31m"
  #define __COLOR_FG_GREEN_BLINK       "\033[5;32m"
  #define __COLOR_FG_YELLOW_BLINK      "\033[5;33m"
  #define __COLOR_FG_BLUE_BLINK        "\033[5;34m"
  #define __COLOR_FG_MAGENTA_BLINK     "\033[5;35m"
  #define __COLOR_FG_CYAN_BLINK        "\033[5;36m"
  #define __COLOR_FG_WHITE_BLINK       "\033[5;37m"

  #define __COLOR_BG_BLACK             "\033[40m"
  #define __COLOR_BG_RED               "\033[41m"
  #define __COLOR_BG_GREEN             "\033[42m"
  #define __COLOR_BG_YELLOW            "\033[43m"
  #define __COLOR_BG_BLUE              "\033[44m"
  #define __COLOR_BG_MAGENTA           "\033[45m"
  #define __COLOR_BG_CYAN              "\033[46m"
  #define __COLOR_BG_WHITE             "\033[47m"

  #define __PRINT_ERROR(msg)                cout << __COLOR_FG_RED_BOLD       \
                                                 << "Error: "                 \
                                                 << __COLOR_FG_CYAN           \
                                                 << msg                       \
                                                 << __COLOR_FG_WHITE          \
                                                 << endl;

  #define __PRINT_WARNING(msg)              cout << __COLOR_FG_YELLOW_BOLD    \
                                                 << "Warning: "               \
                                                 << __COLOR_FG_CYAN           \
                                                 << msg                       \
                                                 << __COLOR_FG_WHITE          \
                                                 << endl;

  #define __PRINT_INFO(msg)                 cout << __COLOR_FG_WHITE          \
                                                 << msg                       \
                                                 << endl;

  #define __PRINT_ERROR_NO_ENDLINE(msg)     cout << __COLOR_FG_RED_BOLD       \
                                                 << "Error: "                 \
                                                 << __COLOR_FG_CYAN           \
                                                 << msg                       \
                                                 << __COLOR_FG_WHITE;

  #define __PRINT_WARNING_NO_ENDLINE(msg)   cout << __COLOR_FG_YELLOW_BOLD    \
                                                 << "Warning: "               \
                                                 << __COLOR_FG_CYAN           \
                                                 << msg                       \
                                                 << __COLOR_FG_WHITE;

  #define __PRINT_INFO_NO_ENDLINE(msg)      cout << __COLOR_FG_WHITE          \
                                                 << msg;

#else


  #define __PRINT_ERROR(msg)
  #define __PRINT_WARNING(msg)
  #define __PRINT_INFO(msg)


#endif


moveOS::base::MLoggerConsole::MLoggerConsole() : MLogger()
{
}

moveOS::base::MLoggerConsole::MLoggerConsole(log_level minimumLogLevel) : MLogger(minimumLogLevel)
{
}

void moveOS::base::MLoggerConsole::log(log_level logLevel, const char* message)
{
  switch (logLevel)
  {
  case LOG_INFO:
    logInfo(message);
    break;

  case LOG_WARNING:
    logWarning(message);
    break;

  case LOG_ERROR:
    logError(message);
    break;
  }
}

void moveOS::base::MLoggerConsole::logInfo(const char* format_str, ...)
{
  if (minimumLogLevel == LOG_INFO)
  {
    char message[LOGGER_MESSAGE_STRING_BUFFER_SIZE];

		for (int _i = 0; _i < LOGGER_MESSAGE_STRING_BUFFER_SIZE; _i++) { message[_i] = 0; }

		va_list va_args;
		va_start(va_args, format_str);

		int message_index = 0;
		char identifier_char;
		char identifier_modifier;

		int __temp_index;
		int __temp_count;
		char __temp_char;
		unsigned int __temp_uint;

		for (int format_str_index = 0; format_str_index < strlen(format_str); format_str_index++) {

			identifier_char = format_str[format_str_index + 1];
			identifier_modifier = -1;

			if ((identifier_char == '0' ||
				   identifier_char == '1' ||
				   identifier_char == '2' ||
				   identifier_char == '3' ||
				   identifier_char == '4') && (format_str_index + 1 < strlen(format_str))) {

				identifier_modifier = format_str[format_str_index + 2];

				if (identifier_modifier == 'b' || identifier_modifier == 'B') {
					__temp_char = identifier_modifier;
					identifier_modifier = identifier_char - 48;
					identifier_char = __temp_char;
				}
				else {
					identifier_modifier = -1;
				}
			}

			if (format_str[format_str_index] != '%') {

				message[message_index++] = format_str[format_str_index];

			}
			else {

				switch (identifier_char) {

				case 'b':
				case 'B':
					__temp_uint = va_arg(va_args, unsigned int);
					__temp_index = message_index;
					__temp_count = 0;

					while (__temp_uint) {
						message[__temp_index++] = 48 + (__temp_uint % 2);
						message[__temp_index] = 0;

						__temp_uint /= 2;
						__temp_count++;
					}

					if (__temp_index == message_index) {

						// Value is zero
						switch (identifier_modifier) {
						case 0:
						case 1:  sprintf(&message[message_index], "00000000");                         break;
						case 2:  sprintf(&message[message_index], "0000000000000000");                 break;
						case 3:	 sprintf(&message[message_index], "000000000000000000000000");         break;
						case 4:  sprintf(&message[message_index], "00000000000000000000000000000000"); break;
						default: sprintf(&message[message_index], "0"); break;
						}

					}
					else {

						// Fill zeros if required
						if (identifier_modifier >= 0 && identifier_modifier <= 4) {
							if (identifier_modifier == 0) {
								while (identifier_modifier * 8 < __temp_count) identifier_modifier++;
							}

							while (__temp_count < identifier_modifier * 8) {
								message[__temp_index++] = 48;
								message[__temp_index] = 0;

								__temp_count++;
							}
						}

						// Reverse the order
						__temp_index--;
						while (__temp_index > message_index) {
							__temp_char = message[message_index];
							message[message_index] = message[__temp_index];
							message[__temp_index] = __temp_char;

							message_index++;
							__temp_index--;
						}
					}

					if (identifier_modifier >= 0 && identifier_modifier <= 4) {
						format_str_index++; // Extra addition
					}

					message_index = strlen(message);
					format_str_index++;
					break;

				case 'c':
				case 'C':
					sprintf(&message[message_index], "%c", va_arg(va_args, int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'd':
				case 'D':
					sprintf(&message[message_index], "%d", va_arg(va_args, int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'u':
				case 'U':
					sprintf(&message[message_index], "%u", va_arg(va_args, unsigned int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'x':
					sprintf(&message[message_index], "%x", va_arg(va_args, unsigned int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'X':
					sprintf(&message[message_index], "%X", va_arg(va_args, unsigned int));
					message_index = strlen(message);
					format_str_index++;
					break;

				default:
					message[message_index++] = format_str[format_str_index];
					break;
				}
			}
		}

		va_end(va_args);


    __PRINT_INFO(message);
  }
}

void moveOS::base::MLoggerConsole::logWarning(const char* format_str, ...)
{
  if (minimumLogLevel != LOG_ERROR)
  {
		char message[LOGGER_MESSAGE_STRING_BUFFER_SIZE];

		for (int _i = 0; _i < LOGGER_MESSAGE_STRING_BUFFER_SIZE; _i++) { message[_i] = 0; }

		va_list va_args;
		va_start(va_args, format_str);

		int message_index = 0;
		char identifier_char;
		char identifier_modifier;

		int __temp_index;
		int __temp_count;
		char __temp_char;
		unsigned int __temp_uint;

		for (int format_str_index = 0; format_str_index < strlen(format_str); format_str_index++) {

			identifier_char = format_str[format_str_index + 1];
			identifier_modifier = -1;

			if ((identifier_char == '0' ||
				identifier_char == '1' ||
				identifier_char == '2' ||
				identifier_char == '3' ||
				identifier_char == '4') && (format_str_index + 1 < strlen(format_str))) {

				identifier_modifier = format_str[format_str_index + 2];

				if (identifier_modifier == 'b' || identifier_modifier == 'B') {
					__temp_char = identifier_modifier;
					identifier_modifier = identifier_char - 48;
					identifier_char = __temp_char;
				}
				else {
					identifier_modifier = -1;
				}
			}

			if (format_str[format_str_index] != '%') {

				message[message_index++] = format_str[format_str_index];

			}
			else {

				switch (identifier_char) {

				case 'b':
				case 'B':
					__temp_uint = va_arg(va_args, unsigned int);
					__temp_index = message_index;
					__temp_count = 0;

					while (__temp_uint) {
						message[__temp_index++] = 48 + (__temp_uint % 2);
						message[__temp_index] = 0;

						__temp_uint /= 2;
						__temp_count++;
					}

					if (__temp_index == message_index) {

						// Value is zero
						switch (identifier_modifier) {
						case 0:
						case 1:  sprintf(&message[message_index], "00000000");                         break;
						case 2:  sprintf(&message[message_index], "0000000000000000");                 break;
						case 3:	 sprintf(&message[message_index], "000000000000000000000000");         break;
						case 4:  sprintf(&message[message_index], "00000000000000000000000000000000"); break;
						default: sprintf(&message[message_index], "0"); break;
						}

					}
					else {

						// Fill zeros if required
						if (identifier_modifier >= 0 && identifier_modifier <= 4) {
							if (identifier_modifier == 0) {
								while (identifier_modifier * 8 < __temp_count) identifier_modifier++;
							}

							while (__temp_count < identifier_modifier * 8) {
								message[__temp_index++] = 48;
								message[__temp_index] = 0;

								__temp_count++;
							}
						}

						// Reverse the order
						__temp_index--;
						while (__temp_index > message_index) {
							__temp_char = message[message_index];
							message[message_index] = message[__temp_index];
							message[__temp_index] = __temp_char;

							message_index++;
							__temp_index--;
						}
					}

					if (identifier_modifier >= 0 && identifier_modifier <= 4) {
						format_str_index++; // Extra addition
					}

					message_index = strlen(message);
					format_str_index++;
					break;

				case 'c':
				case 'C':
					sprintf(&message[message_index], "%c", va_arg(va_args, int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'd':
				case 'D':
					sprintf(&message[message_index], "%d", va_arg(va_args, int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'u':
				case 'U':
					sprintf(&message[message_index], "%u", va_arg(va_args, unsigned int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'x':
					sprintf(&message[message_index], "%x", va_arg(va_args, unsigned int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'X':
					sprintf(&message[message_index], "%X", va_arg(va_args, unsigned int));
					message_index = strlen(message);
					format_str_index++;
					break;

				default:
					message[message_index++] = format_str[format_str_index];
					break;
				}
			}
		}

		va_end(va_args);


    __PRINT_WARNING(message);
  }
}

void moveOS::base::MLoggerConsole::logError(const char* format_str, ...)
{
	char message[LOGGER_MESSAGE_STRING_BUFFER_SIZE];

	for (int _i = 0; _i < LOGGER_MESSAGE_STRING_BUFFER_SIZE; _i++) { message[_i] = 0; }

	va_list va_args;
	va_start(va_args, format_str);

	int message_index = 0;
	char identifier_char;
	char identifier_modifier;

	int __temp_index;
	int __temp_count;
	char __temp_char;
	unsigned int __temp_uint;

	for (int format_str_index = 0; format_str_index < strlen(format_str); format_str_index++) {

		identifier_char = format_str[format_str_index + 1];
		identifier_modifier = -1;

		if ((identifier_char == '0' ||
			identifier_char == '1' ||
			identifier_char == '2' ||
			identifier_char == '3' ||
			identifier_char == '4') && (format_str_index + 1 < strlen(format_str))) {

			identifier_modifier = format_str[format_str_index + 2];

			if (identifier_modifier == 'b' || identifier_modifier == 'B') {
				__temp_char = identifier_modifier;
				identifier_modifier = identifier_char - 48;
				identifier_char = __temp_char;
			}
			else {
				identifier_modifier = -1;
			}
		}

		if (format_str[format_str_index] != '%') {

			message[message_index++] = format_str[format_str_index];

		}
		else {

			switch (identifier_char) {

			case 'b':
			case 'B':
				__temp_uint = va_arg(va_args, unsigned int);
				__temp_index = message_index;
				__temp_count = 0;

				while (__temp_uint) {
					message[__temp_index++] = 48 + (__temp_uint % 2);
					message[__temp_index] = 0;

					__temp_uint /= 2;
					__temp_count++;
				}

				if (__temp_index == message_index) {

					// Value is zero
					switch (identifier_modifier) {
					case 0:
					case 1:  sprintf(&message[message_index], "00000000");                         break;
					case 2:  sprintf(&message[message_index], "0000000000000000");                 break;
					case 3:	 sprintf(&message[message_index], "000000000000000000000000");         break;
					case 4:  sprintf(&message[message_index], "00000000000000000000000000000000"); break;
					default: sprintf(&message[message_index], "0"); break;
					}

				}
				else {

					// Fill zeros if required
					if (identifier_modifier >= 0 && identifier_modifier <= 4) {
						if (identifier_modifier == 0) {
							while (identifier_modifier * 8 < __temp_count) identifier_modifier++;
						}

						while (__temp_count < identifier_modifier * 8) {
							message[__temp_index++] = 48;
							message[__temp_index] = 0;

							__temp_count++;
						}
					}

					// Reverse the order
					__temp_index--;
					while (__temp_index > message_index) {
						__temp_char = message[message_index];
						message[message_index] = message[__temp_index];
						message[__temp_index] = __temp_char;

						message_index++;
						__temp_index--;
					}
				}

				if (identifier_modifier >= 0 && identifier_modifier <= 4) {
					format_str_index++; // Extra addition
				}

				message_index = strlen(message);
				format_str_index++;
				break;

			case 'c':
			case 'C':
				sprintf(&message[message_index], "%c", va_arg(va_args, int));
				message_index = strlen(message);
				format_str_index++;
				break;

			case 'd':
			case 'D':
				sprintf(&message[message_index], "%d", va_arg(va_args, int));
				message_index = strlen(message);
				format_str_index++;
				break;

			case 'u':
			case 'U':
				sprintf(&message[message_index], "%u", va_arg(va_args, unsigned int));
				message_index = strlen(message);
				format_str_index++;
				break;

			case 'x':
				sprintf(&message[message_index], "%x", va_arg(va_args, unsigned int));
				message_index = strlen(message);
				format_str_index++;
				break;

			case 'X':
				sprintf(&message[message_index], "%X", va_arg(va_args, unsigned int));
				message_index = strlen(message);
				format_str_index++;
				break;

			default:
				message[message_index++] = format_str[format_str_index];
				break;
			}
		}
	}

	va_end(va_args);


  __PRINT_ERROR(message);
}

void moveOS::base::MLoggerConsole::logNoEndline(log_level logLevel, const char* message)
{
	switch (logLevel)
	{
	case LOG_INFO:
		logInfoNoEndline(message);
		break;

	case LOG_WARNING:
		logWarningNoEndline(message);
		break;

	case LOG_ERROR:
		logErrorNoEndline(message);
		break;
	}
}

void moveOS::base::MLoggerConsole::logInfoNoEndline(const char* format_str, ...)
{
	if (minimumLogLevel == LOG_INFO)
	{
		char message[LOGGER_MESSAGE_STRING_BUFFER_SIZE];

		for (int _i = 0; _i < LOGGER_MESSAGE_STRING_BUFFER_SIZE; _i++) { message[_i] = 0; }

		va_list va_args;
		va_start(va_args, format_str);

		int message_index = 0;
		char identifier_char;
		char identifier_modifier;

		int __temp_index;
		int __temp_count;
		char __temp_char;
		unsigned int __temp_uint;

		for (int format_str_index = 0; format_str_index < strlen(format_str); format_str_index++) {

			identifier_char = format_str[format_str_index + 1];
			identifier_modifier = -1;

			if ((identifier_char == '0' ||
				identifier_char == '1' ||
				identifier_char == '2' ||
				identifier_char == '3' ||
				identifier_char == '4') && (format_str_index + 1 < strlen(format_str))) {

				identifier_modifier = format_str[format_str_index + 2];

				if (identifier_modifier == 'b' || identifier_modifier == 'B') {
					__temp_char = identifier_modifier;
					identifier_modifier = identifier_char - 48;
					identifier_char = __temp_char;
				}
				else {
					identifier_modifier = -1;
				}
			}

			if (format_str[format_str_index] != '%') {

				message[message_index++] = format_str[format_str_index];

			}
			else {

				switch (identifier_char) {

				case 'b':
				case 'B':
					__temp_uint = va_arg(va_args, unsigned int);
					__temp_index = message_index;
					__temp_count = 0;

					while (__temp_uint) {
						message[__temp_index++] = 48 + (__temp_uint % 2);
						message[__temp_index] = 0;

						__temp_uint /= 2;
						__temp_count++;
					}

					if (__temp_index == message_index) {

						// Value is zero
						switch (identifier_modifier) {
						case 0:
						case 1:  sprintf(&message[message_index], "00000000");                         break;
						case 2:  sprintf(&message[message_index], "0000000000000000");                 break;
						case 3:	 sprintf(&message[message_index], "000000000000000000000000");         break;
						case 4:  sprintf(&message[message_index], "00000000000000000000000000000000"); break;
						default: sprintf(&message[message_index], "0"); break;
						}

					}
					else {

						// Fill zeros if required
						if (identifier_modifier >= 0 && identifier_modifier <= 4) {
							if (identifier_modifier == 0) {
								while (identifier_modifier * 8 < __temp_count) identifier_modifier++;
							}

							while (__temp_count < identifier_modifier * 8) {
								message[__temp_index++] = 48;
								message[__temp_index] = 0;

								__temp_count++;
							}
						}

						// Reverse the order
						__temp_index--;
						while (__temp_index > message_index) {
							__temp_char = message[message_index];
							message[message_index] = message[__temp_index];
							message[__temp_index] = __temp_char;

							message_index++;
							__temp_index--;
						}
					}

					if (identifier_modifier >= 0 && identifier_modifier <= 4) {
						format_str_index++; // Extra addition
					}

					message_index = strlen(message);
					format_str_index++;
					break;

				case 'c':
				case 'C':
					sprintf(&message[message_index], "%c", va_arg(va_args, int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'd':
				case 'D':
					sprintf(&message[message_index], "%d", va_arg(va_args, int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'u':
				case 'U':
					sprintf(&message[message_index], "%u", va_arg(va_args, unsigned int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'x':
					sprintf(&message[message_index], "%x", va_arg(va_args, unsigned int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'X':
					sprintf(&message[message_index], "%X", va_arg(va_args, unsigned int));
					message_index = strlen(message);
					format_str_index++;
					break;

				default:
					message[message_index++] = format_str[format_str_index];
					break;
				}
			}
		}

		va_end(va_args);


		__PRINT_INFO_NO_ENDLINE(message);
	}
}

void moveOS::base::MLoggerConsole::logWarningNoEndline(const char* format_str, ...)
{
	if (minimumLogLevel != LOG_ERROR)
	{
		char message[LOGGER_MESSAGE_STRING_BUFFER_SIZE];

		for (int _i = 0; _i < LOGGER_MESSAGE_STRING_BUFFER_SIZE; _i++) { message[_i] = 0; }

		va_list va_args;
		va_start(va_args, format_str);

		int message_index = 0;
		char identifier_char;
		char identifier_modifier;

		int __temp_index;
		int __temp_count;
		char __temp_char;
		unsigned int __temp_uint;

		for (int format_str_index = 0; format_str_index < strlen(format_str); format_str_index++) {

			identifier_char = format_str[format_str_index + 1];
			identifier_modifier = -1;

			if ((identifier_char == '0' ||
				identifier_char == '1' ||
				identifier_char == '2' ||
				identifier_char == '3' ||
				identifier_char == '4') && (format_str_index + 1 < strlen(format_str))) {

				identifier_modifier = format_str[format_str_index + 2];

				if (identifier_modifier == 'b' || identifier_modifier == 'B') {
					__temp_char = identifier_modifier;
					identifier_modifier = identifier_char - 48;
					identifier_char = __temp_char;
				}
				else {
					identifier_modifier = -1;
				}
			}

			if (format_str[format_str_index] != '%') {

				message[message_index++] = format_str[format_str_index];

			}
			else {

				switch (identifier_char) {

				case 'b':
				case 'B':
					__temp_uint = va_arg(va_args, unsigned int);
					__temp_index = message_index;
					__temp_count = 0;

					while (__temp_uint) {
						message[__temp_index++] = 48 + (__temp_uint % 2);
						message[__temp_index] = 0;

						__temp_uint /= 2;
						__temp_count++;
					}

					if (__temp_index == message_index) {

						// Value is zero
						switch (identifier_modifier) {
						case 0:
						case 1:  sprintf(&message[message_index], "00000000");                         break;
						case 2:  sprintf(&message[message_index], "0000000000000000");                 break;
						case 3:	 sprintf(&message[message_index], "000000000000000000000000");         break;
						case 4:  sprintf(&message[message_index], "00000000000000000000000000000000"); break;
						default: sprintf(&message[message_index], "0"); break;
						}

					}
					else {

						// Fill zeros if required
						if (identifier_modifier >= 0 && identifier_modifier <= 4) {
							if (identifier_modifier == 0) {
								while (identifier_modifier * 8 < __temp_count) identifier_modifier++;
							}

							while (__temp_count < identifier_modifier * 8) {
								message[__temp_index++] = 48;
								message[__temp_index] = 0;

								__temp_count++;
							}
						}

						// Reverse the order
						__temp_index--;
						while (__temp_index > message_index) {
							__temp_char = message[message_index];
							message[message_index] = message[__temp_index];
							message[__temp_index] = __temp_char;

							message_index++;
							__temp_index--;
						}
					}

					if (identifier_modifier >= 0 && identifier_modifier <= 4) {
						format_str_index++; // Extra addition
					}

					message_index = strlen(message);
					format_str_index++;
					break;

				case 'c':
				case 'C':
					sprintf(&message[message_index], "%c", va_arg(va_args, int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'd':
				case 'D':
					sprintf(&message[message_index], "%d", va_arg(va_args, int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'u':
				case 'U':
					sprintf(&message[message_index], "%u", va_arg(va_args, unsigned int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'x':
					sprintf(&message[message_index], "%x", va_arg(va_args, unsigned int));
					message_index = strlen(message);
					format_str_index++;
					break;

				case 'X':
					sprintf(&message[message_index], "%X", va_arg(va_args, unsigned int));
					message_index = strlen(message);
					format_str_index++;
					break;

				default:
					message[message_index++] = format_str[format_str_index];
					break;
				}
			}
		}

		va_end(va_args);


		__PRINT_WARNING_NO_ENDLINE(message);
	}
}

void moveOS::base::MLoggerConsole::logErrorNoEndline(const char* format_str, ...)
{
	char message[LOGGER_MESSAGE_STRING_BUFFER_SIZE];

	for (int _i = 0; _i < LOGGER_MESSAGE_STRING_BUFFER_SIZE; _i++) { message[_i] = 0; }

	va_list va_args;
	va_start(va_args, format_str);

	int message_index = 0;
	char identifier_char;
	char identifier_modifier;

	int __temp_index;
	int __temp_count;
	char __temp_char;
	unsigned int __temp_uint;

	for (int format_str_index = 0; format_str_index < strlen(format_str); format_str_index++) {

		identifier_char = format_str[format_str_index + 1];
		identifier_modifier = -1;

		if ((identifier_char == '0' ||
			identifier_char == '1' ||
			identifier_char == '2' ||
			identifier_char == '3' ||
			identifier_char == '4') && (format_str_index + 1 < strlen(format_str))) {

			identifier_modifier = format_str[format_str_index + 2];

			if (identifier_modifier == 'b' || identifier_modifier == 'B') {
				__temp_char = identifier_modifier;
				identifier_modifier = identifier_char - 48;
				identifier_char = __temp_char;
			}
			else {
				identifier_modifier = -1;
			}
		}

		if (format_str[format_str_index] != '%') {

			message[message_index++] = format_str[format_str_index];

		}
		else {

			switch (identifier_char) {

			case 'b':
			case 'B':
				__temp_uint = va_arg(va_args, unsigned int);
				__temp_index = message_index;
				__temp_count = 0;

				while (__temp_uint) {
					message[__temp_index++] = 48 + (__temp_uint % 2);
					message[__temp_index] = 0;

					__temp_uint /= 2;
					__temp_count++;
				}

				if (__temp_index == message_index) {

					// Value is zero
					switch (identifier_modifier) {
					case 0:
					case 1:  sprintf(&message[message_index], "00000000");                         break;
					case 2:  sprintf(&message[message_index], "0000000000000000");                 break;
					case 3:	 sprintf(&message[message_index], "000000000000000000000000");         break;
					case 4:  sprintf(&message[message_index], "00000000000000000000000000000000"); break;
					default: sprintf(&message[message_index], "0"); break;
					}

				}
				else {

					// Fill zeros if required
					if (identifier_modifier >= 0 && identifier_modifier <= 4) {
						if (identifier_modifier == 0) {
							while (identifier_modifier * 8 < __temp_count) identifier_modifier++;
						}

						while (__temp_count < identifier_modifier * 8) {
							message[__temp_index++] = 48;
							message[__temp_index] = 0;

							__temp_count++;
						}
					}

					// Reverse the order
					__temp_index--;
					while (__temp_index > message_index) {
						__temp_char = message[message_index];
						message[message_index] = message[__temp_index];
						message[__temp_index] = __temp_char;

						message_index++;
						__temp_index--;
					}
				}

				if (identifier_modifier >= 0 && identifier_modifier <= 4) {
					format_str_index++; // Extra addition
				}

				message_index = strlen(message);
				format_str_index++;
				break;

			case 'c':
			case 'C':
				sprintf(&message[message_index], "%c", va_arg(va_args, int));
				message_index = strlen(message);
				format_str_index++;
				break;

			case 'd':
			case 'D':
				sprintf(&message[message_index], "%d", va_arg(va_args, int));
				message_index = strlen(message);
				format_str_index++;
				break;

			case 'u':
			case 'U':
				sprintf(&message[message_index], "%u", va_arg(va_args, unsigned int));
				message_index = strlen(message);
				format_str_index++;
				break;

			case 'x':
				sprintf(&message[message_index], "%x", va_arg(va_args, unsigned int));
				message_index = strlen(message);
				format_str_index++;
				break;

			case 'X':
				sprintf(&message[message_index], "%X", va_arg(va_args, unsigned int));
				message_index = strlen(message);
				format_str_index++;
				break;

			default:
				message[message_index++] = format_str[format_str_index];
				break;
			}
		}
	}

	va_end(va_args);


	__PRINT_ERROR_NO_ENDLINE(message);
}
