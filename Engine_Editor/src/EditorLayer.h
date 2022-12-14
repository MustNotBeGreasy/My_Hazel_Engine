#pragma once

#include "MyHazel.h"

namespace MyHazel
{

	class EditorLayer : public Layer
	{

	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;

	private:
		MyHazel::OrthographicCameraController m_CameraController;

		//Temp
		Ref<VertexArray> m_SquareVA;
		Ref<Shader> m_FlatColorShader;
		Ref<Framebuffer> m_FrameBuffer;

		Ref<Texture2D> m_Texture;

		bool m_ViewportFocused = false, m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };

		glm::vec4 m_ImGuiColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	};

}