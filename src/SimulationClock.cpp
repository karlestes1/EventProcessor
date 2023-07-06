/*
*
* SimulationClock.cpp
* Created by: Karl Estes
* Date: 07/05/2023
*
*/

#include "SimulationClock.hpp"

SimulationClock::SimulationClock() : m_time(0) {}

void SimulationClock::setTime(unsigned int time) {
    m_time = time;
}

void SimulationClock::advance(unsigned int numSteps) {
    m_time += numSteps;
}

unsigned int SimulationClock::getTime() const {
    return m_time;
}