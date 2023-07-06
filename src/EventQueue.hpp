/*
*
* EventQueue.hpp
* Created by: Karl Estes
* Date: 07/04/2023
*
*/

#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include "Event.hpp"

/**
 * @class EventQueue
 * @brief A priority queue of events.
 */
class EventQueue {
    
    private:

        std::priority_queue<Event> m_internalQueue; /**< The internal priority queue. */
        std::mutex m_mutex; /**< The mutex used to synchronize access to the queue. */

    public:

        /**
         * @brief Constructs an empty EventQueue.
         */
        EventQueue();

        /**
         * @brief Destroys the EventQueue.
         */
        ~EventQueue();

        /**
         * @brief Copy constructor is deleted.
         */
        EventQueue(const EventQueue&) = delete;

        /**
         * @brief Assignment operator is deleted.
         */
        EventQueue& operator=(const EventQueue&) = delete;

        /**
         * @brief Adds an event to the queue.
         * @param event The event to add.
         */
        void enqueue(const Event& event);

        /**
         * @brief Removes and returns the next event in the queue.
         * @return The next event in the queue.
         */
        Event dequeue();

        /**
         * @brief Gets the next execution time step.
         * @return The next execution time step.
         */
        unsigned int getNextExecTimeStep() const;

        /**
         * @brief Gets the size of the queue.
         * @return The size of the queue.
         */
        int size() const;

        /**
         * @brief Checks if the queue is empty.
         * @return True if the queue is empty, false otherwise.
         */
        bool isEmpty() const;

};