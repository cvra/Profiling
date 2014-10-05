#ifndef PROFILING_H
#define PROFILING_H

#include <stdint.h>
#include <statistics/statistics.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    statistics_t stat;
    uint32_t start_timestamp;
} profiling_duration_t;

#define PROFILING_DURATION_PRINT_BUFFER_SIZE 150

void profiling_duration_reset(profiling_duration_t *d);
void profiling_duration_start(profiling_duration_t *d);
void profiling_duration_stop(profiling_duration_t *d);
void profiling_duration_print_statistics(profiling_duration_t *d, char *buf);

#ifdef __cplusplus
}
#endif

#endif // PROFILING_H
