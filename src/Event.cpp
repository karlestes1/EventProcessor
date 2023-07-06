/*
*
* Event.hpp
* Created by: Karl Estes
* Date: 07/05/2023
*
*/

#include "Event.hpp"

Event::Event(std::function<void()> callback, Priority priority, int execTimeStep, boost::uuids::uuid callingObjectID) :
    m_callback(callback),
    m_priority(priority),
    m_execTimeStep(execTimeStep),
    m_id(boost::uuids::random_generator()()),
    callingObjectID(callingObjectID){}

Event::~Event() {}

Event::Event(Event&& other) noexcept :
    m_callback(std::move(other.m_callback)),
    m_priority(std::move(other.m_priority)),
    m_execTimeStep(std::move(other.m_execTimeStep)),
    m_id(std::move(other.m_id)),
    callingObjectID(std::move(other.callingObjectID)) {}

Event::Event& operator=(Event&& other) noexcept {
    if (this != &other) {
        m_callback = std::move(other.m_callback);
        m_priority = std::move(other.m_priority);
        m_execTimeStep = std::move(other.m_execTimeStep);
        m_id = std::move(other.m_id);
        callingObjectID = std::move(other.callingObjectID);
    }
    return *this;
}

bool Event::operator<(const Event& other) const {
    // Use std::tie to compare time steps first, then priority levels
    return std::tie(m_execTimeStep, m_priority) < std::tie(other.m_execTimeStep, other.m_priority);
}

bool Event::operator>(const Event& other) const {
    // Use std::tie to compare time steps first, then priority levels
    return std::tie(m_execTimeStep, m_priority) > std::tie(other.m_execTimeStep, other.m_priority);
}

void Event::invoke() {
    m_callback();
}

void Event::operator()() {
    invoke();
}

void Event::getPriority() const {
    return m_priority;
}

int Event::getExecTimeStep() const {
    return m_execTimeStep;
}

boost::uuids::uuid Event::getID() const {
    return m_id;
}

