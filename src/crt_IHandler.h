// by Marius Versteegen, 2022

#ifndef CRT_IHANDLER
#define CRT_IHANDLER

#include "crt_IHandlerListener.h"

namespace crt
{
	class IHandler
	{
	public:
		virtual void start() = 0;
		virtual void addHandlerListener(IHandlerListener* pHandlerListener) = 0;
	};
};

#endif