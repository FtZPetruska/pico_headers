#define PICO_LOG_IMPLEMENTATION
#include "../pico_log.h"

#include <stdio.h>

static void appender(const char* p_msg, void* p_user_data)
{
    (void)p_user_data;
    printf("%s", p_msg);
    fflush(stdout);
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    plog_id_t id = plog_add_appender(appender, PLOG_LEVEL_INFO, NULL);

    plog_display_timestamp(id, true);
    plog_display_file(id, true);
    plog_display_function(id, true);

    // Default log level is INFO

    plog_trace ("Test message: %d", 0);
    plog_debug ("Test message: %d", 1);
    plog_info  ("Test message: %d", 2);
    plog_warn  ("Test message: %d", 3);
    plog_error ("Test message: %d", 4);
    plog_fatal ("Test message: %d", 5);

    return 0;
}
