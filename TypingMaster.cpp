#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

string sentences[] = {
    "The quick brown fox jumps over the lazy dog.",
    "Programming is fun when you practice daily.",
    "C++ is a powerful language for system programming.",
    "A journey of a thousand miles begins with a single step.",
    "Typing speed is improved with continuous practice."
};

void startTypingTest() {
    srand(time(0));
    string givenText = sentences[rand() % 5];

    cout << "\n==== Typing Master (C++ Console Application) ====\n";
    cout << "\nType the following text as fast as you can:\n";
    cout << "------------------------------------------\n";
    cout << givenText << endl;
    cout << "------------------------------------------\n";

    cout << "\nPress ENTER to start typing...\n";
    cin.get();

    clock_t startTime = clock();  // Start time in milliseconds
    string userText;

    cout << "\nStart Typing: ";
    getline(cin, userText);

    clock_t endTime = clock();  // End time
    double timeTaken = double(endTime - startTime) / CLOCKS_PER_SEC; // Time in seconds

    // Calculate Words Per Minute (WPM)
    int wordsTyped = givenText.length() / 5;  // Avg word length = 5
    double wpm = (wordsTyped / timeTaken) * 60;

    // Accuracy Calculation
    int correctChars = 0;
    for (size_t i = 0; i < givenText.length() && i < userText.length(); i++) {
        if (givenText[i] == userText[i]) {
            correctChars++;
        }
    }
    double accuracy = ((double)correctChars / givenText.length()) * 100;

    // Show Results
    cout << "\n===== Typing Test Results =====\n";
    cout << "Time Taken: " << timeTaken << " seconds" << endl;
    cout << "Typing Speed: " << wpm << " WPM" << endl;
    cout << "Accuracy: " << accuracy << "%" << endl;
}

int main() {
    startTypingTest();
    return 0;
}
