#pragma once

// Classe totalmente traduzida do Ogre3D, com poucas adições
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef WIN32_EXTRA_LEAN
#define WIN32_EXTRA_LEAN
#endif
#define NOMINMAX
#include <windows.h>
#include <time.h>

class TimerWin32{
	private:
		unsigned long timeStepMs;

		clock_t mZeroClock;
		DWORD mStartTick;
		mutable LONGLONG mLastTime;
		mutable LARGE_INTEGER mStartTime;
		LARGE_INTEGER mFrequency;
		DWORD mTimerMask;

		DWORD procMask;
		DWORD sysMask;

	public:
		explicit TimerWin32(const unsigned long timeStepMs = 1000);				
		~TimerWin32();

		bool timeHasPassed();				
		unsigned long getTimeStepMs() const;	

		void setTimeStepMs(const unsigned long timeStepMs);	

		void reset();

		/** Returns milliseconds since initialisation or last reset */
		unsigned long getMilliseconds() const;

		/** Returns microseconds since initialisation or last reset */
		unsigned long getMicroseconds() const;

		/** Returns nanoseconds since initialisation or last reset */
		unsigned long long getNanoseconds() const;	

		template<typename T> __forceinline static T minimum(const T& a, const T& b){                                                 
			return a < b ? a : b;                               
		}

		template<typename T> __forceinline static T maximum(const T& a, const T& b){                                                 
			return a > b ? a : b;                               
		}

};
