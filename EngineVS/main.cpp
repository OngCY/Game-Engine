#include "Events.h"
#include "EventManager.h"
#include "ServiceLocator.h"
#include "TestSystem.h"
#include "ThirdParty\json.hpp"
#include "Actors.h"
#include <fstream>

using json = nlohmann::json;

int main()
{
	/*********EVENT TEST********/
	/*
	std::shared_ptr<IEventManager> pEventManager(new EventManager());

	//Service Locator pattern. Call the Initialise method early
	ServiceLocator::Initialise();
	ServiceLocator::SetEventService(pEventManager);

	//Test system for event handling
	TestSystem* tEventSystem = new TestSystem();
	tEventSystem->Init();

	//Create the event and fire it immediately. The alternative is to queue the event
	std::shared_ptr<Event_DestroyActor> pDestroyEvent(new Event_DestroyActor(01));
	ServiceLocator::GetEventService()->VTriggerEvent(pDestroyEvent);

	delete tEventSystem;
	*/

	/********NLOHMAN JSON LIBRARY TEST******/
	/*
	json j;
	j = {
		{"pi", 3.142 },
		{"name", "ong"},
		{"object",
			{
				{"currency", "usd"},
				{"value", 42}
			}
		}
	};
	std::cout << j << std::endl;

	//nlohmann json library: json file parsing
	std::ifstream ifs("C:\\engine\\Engine\\EngineVS\\configuration\\components.json");
	json jstream = json::parse(ifs);
	std::cout << jstream.at("NumComponents") << std::endl;
	std::cout << jstream["PhysicsComponent"]["material"] << std::endl;
	std::cout << jstream["PhysicsComponent"]["mass"] << std::endl;

	//nlohmann json library: array iteration
	std::vector<std::string> componentVector = jstream["Components"];
	for (auto comp : componentVector)
		std::cout << comp << std::endl;

	//nlohmann json library: sub object access
	json jsubstream = jstream["PhysicsComponent"];
	std::cout << jsubstream["material"] << std::endl;
	*/

	/********GAME ACTORS TEST******/
	ActorFactory* actorFactory = new ActorFactory();
	StrongActorPtr greenHerbActor(actorFactory->CreateActor("C:\\engine\\Engine\\EngineVS\\configuration\\components.json"));
	std::weak_ptr<HealthPickUp> wHealthPickUp(greenHerbActor->GetComponent<HealthPickUp>(COMPONENTS::PICKUP_HEALTH));
	std::shared_ptr<HealthPickUp> sHealthPickUp = wHealthPickUp.lock(); //lock returns a shard_ptr
	
	std::getchar();

	return 0;
}