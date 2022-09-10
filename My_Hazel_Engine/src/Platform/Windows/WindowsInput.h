#pragma once

#include "MyHazel/Core/Input.h"

#include <GLFW/glfw3.h>
namespace MyHazel {

	class WindowsInput : public Input
	{

	protected:
		virtual bool IsKeyPressedImpl(KeyCode  keycode) override;
		virtual bool IsMouseButtonPressedImpl(MouseCode  button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}