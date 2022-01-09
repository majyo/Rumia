#include <Rumia.h>

class Sandbox : public Rumia::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};


Rumia::Application* Rumia::CreateApplication()
{
	return new Sandbox();
}

