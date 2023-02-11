#include "inc/base/MLoggerSplit.h"

#include "src/_internal_inc/macros.h"

#include <stdarg.h>


moveOS::base::MLoggerSplit::MLoggerSplit(
                   MLogger* firstLogger,
                   MLogger* secondLogger)
{
  logger_01 = firstLogger;
  logger_02 = secondLogger;
  logger_03 = nullptr;
  logger_04 = nullptr;
}

moveOS::base::MLoggerSplit::MLoggerSplit(
                   MLogger* firstLogger,
                   MLogger* secondLogger,
                   MLogger* thirdLogger)
{
  logger_01 = firstLogger;
  logger_02 = secondLogger;
  logger_03 = thirdLogger;
  logger_04 = nullptr;
}

moveOS::base::MLoggerSplit::MLoggerSplit(
                   MLogger* firstLogger,
                   MLogger* secondLogger,
                   MLogger* thirdLogger,
                   MLogger* fourthLogger)
{
  logger_01 = firstLogger;
  logger_02 = secondLogger;
  logger_03 = thirdLogger;
  logger_04 = fourthLogger;
}

void moveOS::base::MLoggerSplit::log(log_level logLevel, const char* message)
{
  if (logger_01 != nullptr) logger_01->log(logLevel, message);
  if (logger_02 != nullptr) logger_02->log(logLevel, message);
  if (logger_03 != nullptr) logger_03->log(logLevel, message);
  if (logger_04 != nullptr) logger_04->log(logLevel, message);
}

void moveOS::base::MLoggerSplit::logInfo(const char* format_str, ...)
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


  if (logger_01 != nullptr) logger_01->logInfo(message);
  if (logger_02 != nullptr) logger_02->logInfo(message);
  if (logger_03 != nullptr) logger_03->logInfo(message);
  if (logger_04 != nullptr) logger_04->logInfo(message);
}

void moveOS::base::MLoggerSplit::logWarning(const char* format_str, ...)
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


  if (logger_01 != nullptr) logger_01->logWarning(message);
  if (logger_02 != nullptr) logger_02->logWarning(message);
  if (logger_03 != nullptr) logger_03->logWarning(message);
  if (logger_04 != nullptr) logger_04->logWarning(message);
}

void moveOS::base::MLoggerSplit::logError(const char* format_str, ...)
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


  if (logger_01 != nullptr) logger_01->logError(message);
  if (logger_02 != nullptr) logger_02->logError(message);
  if (logger_03 != nullptr) logger_03->logError(message);
  if (logger_04 != nullptr) logger_04->logError(message);
}

void moveOS::base::MLoggerSplit::logNoEndline(log_level logLevel, const char* message)
{
	if (logger_01 != nullptr) logger_01->logNoEndline(logLevel, message);
	if (logger_02 != nullptr) logger_02->logNoEndline(logLevel, message);
	if (logger_03 != nullptr) logger_03->logNoEndline(logLevel, message);
	if (logger_04 != nullptr) logger_04->logNoEndline(logLevel, message);
}

void moveOS::base::MLoggerSplit::logInfoNoEndline(const char* format_str, ...)
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


	if (logger_01 != nullptr) logger_01->logInfoNoEndline(message);
	if (logger_02 != nullptr) logger_02->logInfoNoEndline(message);
	if (logger_03 != nullptr) logger_03->logInfoNoEndline(message);
	if (logger_04 != nullptr) logger_04->logInfoNoEndline(message);
}

void moveOS::base::MLoggerSplit::logWarningNoEndline(const char* format_str, ...)
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


	if (logger_01 != nullptr) logger_01->logWarningNoEndline(message);
	if (logger_02 != nullptr) logger_02->logWarningNoEndline(message);
	if (logger_03 != nullptr) logger_03->logWarningNoEndline(message);
	if (logger_04 != nullptr) logger_04->logWarningNoEndline(message);
}

void moveOS::base::MLoggerSplit::logErrorNoEndline(const char* format_str, ...)
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


	if (logger_01 != nullptr) logger_01->logErrorNoEndline(message);
	if (logger_02 != nullptr) logger_02->logErrorNoEndline(message);
	if (logger_03 != nullptr) logger_03->logErrorNoEndline(message);
	if (logger_04 != nullptr) logger_04->logErrorNoEndline(message);
}