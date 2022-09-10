#include "hzpch.h"
#include "MyHazel/Core/Window.h"

#ifdef HZ_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace MyHazel
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef HZ_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		HZ_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}