#include <Rumia.h>
#include <memory>

class Sandbox : public Rumia::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};


std::unique_ptr<Rumia::Application> Rumia::CreateApplication()
{
	return std::make_unique<Rumia::Application>();
}

