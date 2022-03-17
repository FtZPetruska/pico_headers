#define PICO_LOG_IMPLEMENTATION
#include "../pico_log.h"

#include <stdio.h>

static void appender1(const char* p_msg, void* p_user_data)
{
    (void)p_user_data;
    printf("Appender 1: %s", p_msg);
    fflush(stdout);
}

static void appender2(const char* p_msg, void* p_user_data)
{
    (void)p_user_data;
    printf("Appender 2: %s", p_msg);
    fflush(stdout);
}

static void log_all()
{
    plog_trace ("Test message: %d", 0);
    plog_debug ("Test message: %d", 1);
    plog_info  ("Test message: %d", 2);
    plog_warn  ("Test message: %d", 3);
    plog_error ("Test message: %d", 4);
    plog_fatal ("Test message: %d", 5);
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    plog_id_t id1 = plog_add_appender(appender1, PLOG_LEVEL_TRACE, NULL);
    plog_id_t id2 = plog_add_appender(appender2, PLOG_LEVEL_INFO, NULL);

    plog_set_level(id1, PLOG_LEVEL_TRACE);
    plog_set_level(id2, PLOG_LEVEL_TRACE);

    printf("================== Both appenders ==================\n");

    log_all();

    printf("================== One appender ==================\n");

    plog_disable_appender(id1);
    log_all();

    printf("================== Level Off ==================\n");

    plog_display_level(id1, false);
    plog_display_level(id2, false);

    log_all();

    printf("================== Level On/Set Level (INFO) ==================\n");

    plog_enable_appender(id1);

    plog_display_level(id1, true);
    plog_display_level(id2, true);

    plog_set_level(id1, PLOG_LEVEL_INFO);
    plog_set_level(id2, PLOG_LEVEL_INFO);

    log_all();

    plog_remove_appender(id2);

    printf("================== Timestamp ==================\n");

    id2 = plog_add_appender(appender2, PLOG_LEVEL_INFO, NULL);

    plog_display_timestamp(id1, true);
    plog_display_timestamp(id2, true);

    log_all();

    printf("================== File ==================\n");

    plog_display_file(id1, true);
    plog_display_file(id2, true);

    log_all();

    printf("================== Function ==================\n");

    plog_display_function(id1, true);
    plog_display_function(id2, true);

    log_all();

    return 0;
}

