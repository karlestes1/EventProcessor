/*
*
* Event.hpp
* Created by: Karl Estes
* Date: 07/04/2023
*
*/

#pragma once

#include <functional>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

enum class Priority {
    LOW,
    MEDIUM,
    HIGH,
    CRITICAL,
    IMEDDIATE
};


/**
 * The Event class represents an event that can be scheduled to be executed at a later time.
 * It contains a callback function, a priority level, an execution time step, and a unique ID.
 */
class Event {

    private:
        std::function<void()> m_callback; // The callback function to be executed when the event is triggered
        Priority m_priority; // The priority level of the event
        int m_execTimeStep; // The time step at which the event should be executed
        boost::uuids::uuid m_id; // The unique ID of the event
        boost::uuids::uuid callingObjectID; // The unique ID of the object that created the event (optional)

    public:
        /**
         * Constructor for the Event class.
         * @param callback The callback function to be executed when the event is triggered.
         * @param priority The priority level of the event.
         * @param execTimeStep The time step at which the event should be executed.
         * @param callingObjectID The unique ID of the object that created the event (optional).
         */
        Event(std::function<void()> callback, Priority priority, int execTimeStep, boost::uuids::uuid callingObjectID=boost::uuids::nil_uuid());
        
        // Deleted copy constructor and assignment operator
        Event(const Event&) = delete;
        Event& operator=(const Event&) = delete;

        /**
         * Destructor for the Event class.
         */
        ~Event();

        // Move constructor and assignment operator
        Event(Event&&) noexcept;
        Event& operator=(Event&&) noexcept;

        /**
         * Overloaded comparison operator for the Event class.
         * @param rhs The event to compare to.
         * @return True if this event has a higher priority than the rhs event, false otherwise.
         */
        bool operator<(const Event& rhs) const;

        /**
         * Overloaded comparison operator for the Event class.
         * @param rhs The event to compare to.
         * @return True if this event has a lower priority than the rhs event, false otherwise.
         */
        bool operator>(const Event& rhs) const;

        /**
         * Invokes the callback function associated with this event.
         */
        void invoke() const;

        /**
         * Overloaded function call operator for the Event class.
         * Invokes the callback function associated with this event.
         */
        void operator()() const;

        /**
         * Returns the priority level of this event.
         * @return The priority level of this event.
         */
        Priority getPriority() const;

        /**
         * Returns the time step at which this event should be executed.
         * @return The time step at which this event should be executed.
         */
        int getExecTimeStep() const;

        /**
         * Returns the unique ID of this event.
         * @return The unique ID of this event.
         */
        boost::uuids::uuid getID() const;
};

