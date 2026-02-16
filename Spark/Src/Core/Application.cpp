#include "Application.h"


#include <iostream>



namespace Spark{
	Application* Application::s_Instance = nullptr;
	
	Application::Application(const ApplicationSpec& specs)
	:m_Specifications(specs){

		SPARK_ASSERT(s_Instance==nullptr,"Appplication already initialized")

		s_Instance = this;
	}

	Application::~Application(){
	}

	void Application::Run(){
	}
	
	void Application::stop(){
		m_Running = false;
	}
	
}


