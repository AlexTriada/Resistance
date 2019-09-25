#define DEBUG_ENABLE

#define FORMAT(STR,ARG1) format[STR,ARG1]
#define FULL_NAME_ARRAY (__FILE__ splitString "\")
#define NAME_FILE FULL_NAME_ARRAY select ((count FULL_NAME_ARRAY) - 1)

#ifdef DEBUG_ENABLE
#define LOG(MESSAGE) diag_log text FORMAT(MESSAGE,NAME_FILE);
#else
#define LOG(MESSAGE) /* disabled */
#endif
