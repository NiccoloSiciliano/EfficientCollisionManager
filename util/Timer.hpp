#pragma once
 #include <time.h>
class Timer
{
	public:
		static unsigned int frame_from_start;
		static const unsigned char frame_rate_limit = 60;
		static unsigned int current_time_seconds ;
		static unsigned int last_frame_per_second;
		static unsigned int obj_count;
		static void update()
		{
			Timer::frame_from_start++;
			if (time(NULL)-current_time_seconds> 1)
			{
				printf("FPS: %d, objects count: %d\n", frame_from_start -last_frame_per_second, obj_count);
				last_frame_per_second= frame_from_start;
			current_time_seconds = time(NULL);

			}
			
		}

		static float get_seconds()
		{
			return (float)Timer::frame_from_start/Timer::frame_rate_limit;
		}
};