#pragma once
#include "MyTypes.h"
#include "ThirdParty\json.hpp"
#include <memory>

class BaseActor;

class BaseActorComponent
{
	//friend class ActorFactory;
	typedef std::shared_ptr<BaseActor> StrongActorPtr;

public:
	BaseActorComponent();
	virtual ~BaseActorComponent(void) {}
	virtual bool VInit(nlohmann::json jComponent, unsigned int id) { return true; };
	virtual void VPostInit(void) {}
	virtual void VUpdate(int deltaMS) {}
	virtual MyTypes::ComponentId VGetComponentId(void) const;

protected:
	unsigned int m_componentId;
	StrongActorPtr m_pOwner;
	void SetOwner(StrongActorPtr pOwner) { m_pOwner = pOwner; }
};

class HealthComponent : public BaseActorComponent
{

public:
	HealthComponent();
	virtual ~HealthComponent(void) {}
	virtual bool VInit(nlohmann::json jComponent, unsigned int id);
	virtual void VPostInit(void) {}
	virtual void VUpdate(int deltaMS) {}

private:
	short int m_boost;
	std::string m_type;
};

class BaseActor
{
	//friend class ActorFactory;
	typedef std::shared_ptr<BaseActorComponent> StrongActorComponentPtr;
	typedef std::map<MyTypes::ComponentId, StrongActorComponentPtr> ActorComponentMap;

public:
	explicit BaseActor(MyTypes::ActorId id);
	~BaseActor(void);

	bool Init(nlohmann::json jComponent);
	void PostInit(void);
	void Destroy(void);
	void Update(int deltaMs);
	MyTypes::ActorId GetActorID(void) const;

private:
	MyTypes::ActorId m_id;
	ActorComponentMap m_componentMap;
	void AddComponent(StrongActorComponentPtr pComponent);
};