#define DEBUG_ENABLE

#define FORMAT(STR,ARG1) format[STR,ARG1]
#define FORMAT_1(STR,ARG1,ARG2) format[STR,ARG1,ARG2]
#define FULL_NAME_ARRAY (__FILE__ splitString "\")
#define NAME_FILE FULL_NAME_ARRAY select ((count FULL_NAME_ARRAY) - 1)

#ifdef DEBUG_ENABLE
#define LOG(MESSAGE) diag_log text FORMAT(MESSAGE,NAME_FILE);
#define LOG_1(MESSAGE,ARG1) diag_log text FORMAT_1(MESSAGE,NAME_FILE,ARG1);
#else
#define LOG(MESSAGE) /* disabled */
#define LOG_1(MESSAGE,ARG1) /* disabled */
#endif
