#ifndef APPLICATION_H
#define APPLICATION_H


#include "../defines.h"

#include <string>


namespace Spark{

	struct ApplicationSpec{

		ApplicationSpec(std::string title = "Spark"):Title(title){}
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

	private:
		const ApplicationSpec& m_Specifications;
		static Application* s_Instance;
	};
}

#endif