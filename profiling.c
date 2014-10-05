
#include <stdint.h>
#include <stdio.h>
#include <platform-abstraction/timestamp.h>
#include <statistics/statistics.h>
#include "profiling.h"

void profiling_duration_reset(profiling_duration_t *d)
{
    statistics_reset(&d->stat);
    d->start_timestamp = 0;
}

void profiling_duration_start(profiling_duration_t *d)
{
    d->start_timestamp = os_timestamp_get();
}

void profiling_duration_stop(profiling_duration_t *d)
{
    float duration = (float)(os_timestamp_get() - d->start_timestamp);
    statistics_add_sample(&d->stat, duration);
}

void profiling_duration_print_statistics(profiling_duration_t *d, char *buf)
{
    snprintf(buf, PROFILING_DURATION_PRINT_BUFFER_SIZE,
        "[mean: %fus, stddev: %fus, min: %fus, max %fus, %d samples]",
        statistics_get_mean(&d->stat), statistics_get_stddev(&d->stat),
        statistics_get_min(&d->stat), statistics_get_max(&d->stat),
        statistics_get_nb_samples(&d->stat));
}
