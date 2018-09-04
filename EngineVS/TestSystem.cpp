#include "TestSystem.h"

TestEventSystem::TestEventSystem()
{

}

TestEventSystem::~TestEventSystem()
{
	EventListenerDelegate delegateFunc = fastdelegate::MakeDelegate(this, &TestEventSystem::DestroyActorDelegate);
	ServiceLocator::GetEventService()->VRemoveListener(delegateFunc, Event_DestroyActor::sk_EventId);
}

//the call back method
void TestEventSystem::DestroyActorDelegate(IEventPtr pEvent)
{
	std::shared_ptr<Event_DestroyActor> pDestroyActorEvent = std::static_pointer_cast<Event_DestroyActor>(pEvent);
	MyTypes::ActorId id = pDestroyActorEvent->GetId();
	std::cout << "Destroy actor event received. Actor ID: " << id << std::endl;
}

//create a delegate for the call back and register the delegate with the event manager
void TestEventSystem::Init(void)
{
	EventListenerDelegate delegateListener = fastdelegate::MakeDelegate(this, &TestEventSystem::DestroyActorDelegate);
	ServiceLocator::GetEventService()->VRegisterListener(delegateListener, Event_DestroyActor::sk_EventId);
}