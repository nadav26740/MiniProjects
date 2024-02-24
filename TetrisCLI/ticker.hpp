#pragma once
#ifndef TICKER_HPP
#define TICKER_HPP
#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <cmath>
#include <memory>
#include <vector>
#include <queue>
#include <mutex>
#include <chrono>


#define DEFAULT_TIME_TYPE_TICKER std::chrono::milliseconds

class Ticker
{
protected:
    /// @brief For timeline control so we will be able to stop and start the methood
    bool m_Running = false;
    bool m_Force_Stop_Flag = false;

    /// @brief the minimum time between ticks
    DEFAULT_TIME_TYPE_TICKER interval = std::chrono::milliseconds(2);

    /// @brief The time past since the last tick started
    DEFAULT_TIME_TYPE_TICKER m_delta_time = std::chrono::milliseconds(0);
    
    // TODO: move to high resolution clock Using chrono
    
    /// @brief That's the main clock thread!
    virtual void Clock();

private:
    
    
    
    /// @brief Clock is the main thread here it will run on the queue of items
    std::unique_ptr<std::thread> m_clock;

    // List of function to run in every tick
    std::vector<void(*)(DEFAULT_TIME_TYPE_TICKER)> m_functions_list;
    std::mutex m_function_list_mutex;


public:
    /// @brief default construtctor that will create a clock without a minimal time per tick 
    Ticker();

    /// @brief Constructor that will create the object with minimal time per tick 
    /// @param t_minimal_time_per_tick paramater that will hold the time minimal times between ticks
    Ticker(DEFAULT_TIME_TYPE_TICKER t_minimal_time_per_tick);

    // destructor will crush the clock thread
    ~Ticker();

    // ======== Timeline Methoods ========

    /// @brief will make the current ticker rotation his last
    virtual void Stop();

    /// @brief Will start the ticker thread
    virtual void Start();

    /// @brief Will make the ticker to stop immidetily buy crashing the thread (Not recommanded!)
    virtual void ForceStop();

    // ===================================

    // ==== control list methoods ====

    /// @brief Adding new function to the function queue
    /// @param func Function pointer to the new function
    /// @attention function need to be in this standart: void <function name>(DEFAULT_TIME_TYPE_TICKER deltatime)
    ///  Where "deltatime" is the time gap from last running
    void AddFunction(void (*t_func)(DEFAULT_TIME_TYPE_TICKER));
    
    /// @brief Will search for function with the same ptr in the list and try to remove it
    /// @param t_func Function to search
    /// @warning If function hasn't found throw exception
    /// @version Unstable
    void RemoveFunction(void (*t_func)(DEFAULT_TIME_TYPE_TICKER));
    
    /// @brief Removing function using his index the list
    /// @param index index of element to remove
    void RemoveFunction(const int index);

    /// @brief Returning the minimal time between ticks
    /// @return std::time_t type that represent the minimal time between ticks 
    virtual DEFAULT_TIME_TYPE_TICKER GetInterval() const noexcept;
    
    /// @brief Returning if Clock Still running
    /// @return Bool type that represent the status of the clock
    virtual bool GetTickerStatus() const noexcept;

    void SetInterval(DEFAULT_TIME_TYPE_TICKER time_per_tick) noexcept;
};
#endif