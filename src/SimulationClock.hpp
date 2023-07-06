/*
*
* SimulationClock.hpp
* Created by: Karl Estes
* Date: 07/05/2023
*
*/

#pragma once


/**
 * @brief A class that represents a simulation clock.
 * 
 */
class SimulationClock {

    private:
        unsigned int m_time; /**< The current time of the clock. */
    public:

        /**
         * Construct a new Simulation Clock object.
         */
        SimulationClock();

        /**
         * Set the current time of the clock.
         * @param time The time to set the clock to.
         */
        void setTime(unsigned int time);

        /**
         * Advance the clock by a given number of time steps.
         * @param numSteps The number of time steps to advance the clock by.
         */
        void advance(unsigned int numSteps=1);

        /**
         * Get the current time of the clock.
         * @return unsigned int The current time of the clock.
         */
        unsigned int getTime() const;
};