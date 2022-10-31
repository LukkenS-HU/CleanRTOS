// by Marius Versteegen, 2022

#ifndef CRT_IHANDLER_LISTENER
#define CRT_IHANDLER_LISTENER

namespace crt
{
	class IHandlerListener
	{
	public:
		virtual void update()=0;
	};
};

#endif