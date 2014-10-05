#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <float.h>
#include "../profiling.h"

TEST_GROUP(ProfilingTestGroup)
{
    void teardown()
    {
        mock().clear();
    }
};

TEST(ProfilingTestGroup, DurationTest)
{
    profiling_duration_t p;
    profiling_duration_reset(&p);
    mock().expectOneCall("os_timestamp_get").andReturnValue(0);
    profiling_duration_start(&p);
    mock().expectOneCall("os_timestamp_get").andReturnValue(100);
    profiling_duration_stop(&p);
    DOUBLES_EQUAL(100, statistics_get_mean(&p.stat), FLT_EPSILON);
}
