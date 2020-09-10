﻿#include "StateMachine.h"
#include <iostream>
#include "Monster.h"
#pragma region STATE MACHINE CLASS
StateMachine::StateMachineBase::StateMachineBase()
{
	
}

void StateMachine::StateMachineBase::CreateStateMachine()
{
	
}

StateMachine::State* StateMachine::StateMachineBase::getCurrentState() const
{
	return this->currentState;
}

void StateMachine::StateMachineBase::ChangeState(State* targetState)
{
	State* prevState = this->currentState;

	this->currentState = nullptr;
	this->currentState = targetState;

	this->currentState->OnStateEnter();
	
	delete prevState;
}

void StateMachine::StateMachineBase::ProcessState()
{
	for (int i = 0; i < this->currentState->Transitions.size(); ++i)
	{
		if (currentState->Transitions[i])
			ChangeState(currentState->Transitions[i]->end);
	}
}
#pragma endregion 


#pragma region STATE CLASS
StateMachine::State::State()
{
	this->Transitions.reserve(5);
}

void StateMachine::State::AddTransition(const BaseTransition* t)
{
	this->Transitions.push_back(t);
}


StateMachine::State::~State()
{
	for (auto& transition : Transitions)
	{
		delete transition;
	}
}

#pragma endregion

#pragma region Life Condition

StateMachine::LifeConditionTransition::LifeConditionTransition(State* endState, bool greater, bool isTargetMine, char life) 
{
	this->end = endState;
	this->greater = greater;
	this->life = life;
	this->isTargetMine = isTargetMine;
}

bool StateMachine::LifeConditionTransition::Process(const Monster& mine, Monster& oth)
{
	Monster target;
	if (this->isTargetMine == true)
		target = mine;
	else
		target = oth;
	
	if (this->greater)
		if (target.getLife() >= this->life)
			return true;
		else
			return false;
	else
		if (target.getLife() <= this->life)
			return true;
		else
			return false;
}

#pragma endregion

#pragma region Use Elemental transition
StateMachine::UseElementalTransition::UseElementalTransition(State* endState) {
	this->end = endState;
}

bool StateMachine::UseElementalTransition::Process(const Monster& mine, Monster& oth) {
	if (oth.getWeakness() == mine.getElement())
		return true;
	return false;
}
#pragma endregion

#pragma region Use Elemental transition
StateMachine::UseNeutralTransition::UseNeutralTransition(State* endState) {
	this->end = endState;
}

bool StateMachine::UseNeutralTransition::Process(const Monster& mine, Monster& oth) {
	if (oth.getWeakness() != mine.getElement())
		return true;
	return false;
}
#pragma endregion


