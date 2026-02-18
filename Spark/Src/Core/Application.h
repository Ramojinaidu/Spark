#ifndef APPLICATION_H
#define APPLICATION_H

#include "../pch.h"
#include "Window.h"


namespace Spark{

	struct ApplicationSpec{

		ApplicationSpec(std::string_view title = "Spark"):Title(title){}
		std::string Title;
	};

	class Application{
	public:
		Application(const ApplicationSpec& spec = ApplicationSpec());
		~Application();

		void Run();
		void stop();

		static Application& Get(){ return *s_Instance; }

	private:

		bool m_Running = true;
		static std::unique_ptr<Window> m_Window;

	private:
		const ApplicationSpec& m_Specifications;
		static Application* s_Instance;

	};
}

#endif
