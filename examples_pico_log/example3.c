#define PICO_LOG_IMPLEMENTATION
#include "../pico_log.h"

#include <stdio.h>

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    plog_id_t id = plog_add_stream(stdout, PLOG_LEVEL_TRACE);

    plog_set_level(id, PLOG_LEVEL_TRACE);

    plog_set_time_fmt(id, "%H:%M:%S");
    plog_display_colors(id, true);
    plog_display_timestamp(id, true);
    plog_display_file(id, true);

    // Default log level is INFO

    plog_trace ("Test message: %d", 0);
    plog_debug ("Test message: %d", 1);
    plog_info  ("Test message: %d", 2);
    plog_warn  ("Test message: %d", 3);
    plog_error ("Test message: %d", 4);
    plog_fatal ("Test message: %d", 5);

    return 0;
}

