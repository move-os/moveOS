#include "inc/base/MLoggerFileDump.h"

#include "src/_internal_inc/macros.h"

#include <stdarg.h>


moveOS::base::MLoggerFileDump::MLoggerFileDump(const char* filename)
  : MLogger()
{
  this->filename = filename;

#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


  if (filename != nullptr)
  {
    outFileStream.open(filename, std::ios_base::app);
  }

  
#endif
}

moveOS::base::MLoggerFileDump::MLoggerFileDump(const char* filename, log_level minimumLogLevel)
  : MLogger(minimumLogLevel)
{
  this->filename = filename;

#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


  if (filename != nullptr)
  {
    outFileStream.open(filename, std::ios_base::app);
  }


#endif
}

void moveOS::base::MLoggerFileDump::log(log_level logLevel, const char* message)
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

void moveOS::base::MLoggerFileDump::logInfo(const char* format_str, ...)
{
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


  if (minimumLogLevel == LOG_INFO && outFileStream.is_open())
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


    outFileStream << message << std::endl;
    outFileStream.flush();
  }


#endif
}

void moveOS::base::MLoggerFileDump::logWarning(const char* format_str, ...)
{
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


  if (minimumLogLevel != LOG_ERROR && outFileStream.is_open())
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


    outFileStream << "Warning: " << message << std::endl;
    outFileStream.flush();
  }


#endif
}

void moveOS::base::MLoggerFileDump::logError(const char* format_str, ...)
{
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


  if (outFileStream.is_open())
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


    outFileStream << "Error: " << message << std::endl;
    outFileStream.flush();
  }


#endif
}


void moveOS::base::MLoggerFileDump::logNoEndline(log_level logLevel, const char* message)
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

void moveOS::base::MLoggerFileDump::logInfoNoEndline(const char* format_str, ...)
{
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


	if (minimumLogLevel == LOG_INFO && outFileStream.is_open())
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


		outFileStream << message;
		outFileStream.flush();
	}


#endif
}

void moveOS::base::MLoggerFileDump::logWarningNoEndline(const char* format_str, ...)
{
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


	if (minimumLogLevel != LOG_ERROR && outFileStream.is_open())
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


		outFileStream << "Warning: " << message;
		outFileStream.flush();
	}


#endif
}

void moveOS::base::MLoggerFileDump::logErrorNoEndline(const char* format_str, ...)
{
#if   TARGET_PLATFORM == PLATFORM_GNU_LINUX || TARGET_PLATFORM == PLATFORM_WINDOWS


	if (outFileStream.is_open())
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


		outFileStream << "Error: " << message;
		outFileStream.flush();
	}


#endif
}