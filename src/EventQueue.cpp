/*
*
* EventQueue.cpp
* Created by: Karl Estes
* Date: 07/04/2023
*
*/

#include "EventQueue.hpp"

EventQueue::MoveableEventPtr::MoveableEventPtr(std::unique_ptr<Event> p) : ptr(std::move(p)) {}

EventQueue::MoveableEventPtr::MoveableEventPtr(MoveableEventPtr &&other) : ptr(std::move(other.ptr)) {}

EventQueue::MoveableEventPtr::MoveableEventPtr(const MoveableEventPtr &other) : ptr(std::move(other.ptr)) {}

EventQueue::MoveableEventPtr& EventQueue::MoveableEventPtr::operator=(MoveableEventPtr other) {
    ptr = std::move(other.ptr);
    return *this;
}

bool EventQueue::MoveableEventPtr::operator<(const EventQueue::MoveableEventPtr &other) const {
    return *ptr < *other.ptr;
}

EventQueue::EventQueue() {};

EventQueue::~EventQueue() {};

void EventQueue::enqueue(std::unique_ptr<Event> event) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_internalQueue.push(MoveableEventPtr(std::move(event)));
}

std::unique_ptr<Event> EventQueue::dequeue() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_internalQueue.empty()) {
        return nullptr;
    }
    std::unique_ptr<Event> event = std::move(m_internalQueue.top().ptr);
    m_internalQueue.pop();
    return event;
}

unsigned int EventQueue::getNextExecTimeStep() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_internalQueue.empty()) {
        return 0;
    }
    return m_internalQueue.top().ptr->getExecTimeStep();
}

int EventQueue::size() {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_internalQueue.size();
}

bool EventQueue::isEmpty() {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_internalQueue.empty();
}