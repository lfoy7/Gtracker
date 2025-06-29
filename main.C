#include <iostream>
#include <string>

// Sample Clock class definition for demonstration
class Clock {
private:
    int hour, minute, second;

public:
    Clock() : hour(0), minute(0), second(0) {}

    void addSecond() {
        second++;
        if (second >= 60) {
            second = 0;
            addMinute();
        }
    }

    void addMinute() {
        minute++;
        if (minute >= 60) {
            minute = 0;
            addHour();
        }
    }

    void addHour() {
        hour = (hour + 1) % 24;
    }

    std::string getTime24Hour() const {
        char buffer[9];
        snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", hour, minute, second);
        return std::string(buffer);
    }

    std::string getTime12Hour() const {
        char buffer[11];
        int displayHour = hour % 12 == 0 ? 12 : hour % 12;
        const char* ampm = hour >= 12 ? "PM" : "AM";
        snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d %s", displayHour, minute, second, ampm);
        return std::string(buffer);
    }
};

// Print the user menu
void printMenu() {
    std::cout << "\n--- Clock Menu ---\n";
    std::cout << "1. Add One Second\n";
    std::cout << "2. Add One Minute\n";
    std::cout << "3. Add One Hour\n";
    std::cout << "4. Display Time\n";
    std::cout << "5. Exit\n";
}

// Function to process user input
void processInput(Clock& clock) {
    int choice;

    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                clock.addSecond();
                break;
            case 2:
                clock.addMinute();
                break;
            case 3:
                clock.addHour();
                break;
            case 4:
                std::cout << "Time (24-Hour): " << clock.getTime24Hour() << std::endl;
                std::cout << "Time (12-Hour): " << clock.getTime12Hour() << std::endl;
                break;
            case 5:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 5);
}

int main() {
    Clock clock;
    processInput(clock);
    return 0;
}

