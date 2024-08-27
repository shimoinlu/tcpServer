#include <windows.h>

class Semaphore {
public:
    // Constructor
    Semaphore(int initialCount = 0, int maxCount = 1) {
        hSemaphore = CreateSemaphore(nullptr, initialCount, maxCount, nullptr);
    }

    // Destructor
    ~Semaphore() {
        CloseHandle(hSemaphore);
    }

    // Wait (P operation)
    void wait() {
        WaitForSingleObject(hSemaphore, INFINITE);
    }

    // Signal (V operation)
    void signal() {
        ReleaseSemaphore(hSemaphore, 1, nullptr);
    }

private:
    HANDLE hSemaphore;
};
