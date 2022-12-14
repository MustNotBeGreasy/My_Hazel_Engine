#pragma once
#include "MyHazel/Core/Base.h"
#include "Window.h"
#include "LayerStack.h"

#include "MyHazel/Events/Event.h"
#include "MyHazel/Events/ApplicationEvent.h"
#include "MyHazel/Core/Timestep.h"

#include "MyHazel/ImGui/ImGuiLayer.h"

#include "MyHazel/Renderer/VertexArray.h"
#include "MyHazel/Renderer/Shader.h"
#include "MyHazel/Renderer/Buffer.h"
#include "MyHazel/Renderer/OrthographicCamera.h"

int main(int argc, char** argv);

namespace MyHazel {

	class Application
	{
	public:
		Application(const std::string& name = "Hazel App");
		virtual ~Application();

		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void Close();
		
		Window& GetWindow() { return *m_Window; }


		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }

	private:
		void Run();
		bool OnWindiwClosed(WindowClosedEvent & e);
		bool OnWindiwResized(WindowResizedEvent& e);

		ImGuiLayer* m_ImGuiLayer;
		std::unique_ptr<Window> m_Window;
		bool m_Running = true, m_Minimized = false;
		LayerStack m_LayerStack;

		Timestep m_Timestep;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;

		friend int ::main(int argc, char** argv);
	};

	//To be defined in client
	Application* CreateApplication();

}

