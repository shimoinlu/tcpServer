#include <windows.h>

class CustomMutex {
public:
    CustomMutex() {
        // Initialize the internal state to indicate that the mutex is unlocked
        locked = 0;
    }

    // Lock the mutex (wait until it becomes available)
    void lock() {
        // Spin until we can set the `locked` variable to 1 (indicating it's locked)
        while (InterlockedExchange(&locked, 1) == 1) {
            // Optionally yield to other threads to avoid busy-waiting
            Sleep(0);
        }
    }

    // Unlock the mutex
    void unlock() {
        // Set the `locked` variable back to 0, indicating the mutex is unlocked
        InterlockedExchange(&locked, 0);
    }

private:
    LONG locked; // Using LONG because InterlockedExchange works with LONG
};
