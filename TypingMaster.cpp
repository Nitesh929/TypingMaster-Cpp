#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <limits>

using namespace std;

vector<string> easySentences = {
    "The sun is shining brightly.",
    "I love coding in C++.",
    "Typing fast is a useful skill.",
    "Practice makes perfect.",
    "Keep learning new things."
};

vector<string> hardSentences = {
    "Synchronization is an essential part of multithreading.",
    "Memory allocation in C++ requires careful handling.",
    "Efficiency of sorting algorithms depends on input data.",
    "Optimization problems require strong problem-solving skills.",
    "Artificial Intelligence is transforming the future."
};

struct Score {
    string name;
    double wpm;
    double accuracy;
};

vector<Score> leaderboard;

void displayLeaderboard() {
    cout << "\n===== Leaderboard =====\n";
    if (leaderboard.empty()) {
        cout << "No scores yet! Be the first to set a record.\n";
        return;
    }
    for (size_t i = 0; i < leaderboard.size(); i++) {
        cout << i + 1 << ". " << leaderboard[i].name << " - "
             << leaderboard[i].wpm << " WPM, "
             << leaderboard[i].accuracy << "% Accuracy" << endl;
    }
}

void startTypingTest() {
    srand(time(0));
    cout << "\nChoose Difficulty Level: 1. Easy  2. Hard\n";
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string givenText;
    if (choice == 1) {
        givenText = easySentences[rand() % easySentences.size()];
    } else {
        givenText = hardSentences[rand() % hardSentences.size()];
    }

    cout << "\n==== Typing Master (Advanced) ====";
    cout << "\nType the following text as fast as you can:\n";
    cout << "------------------------------------------\n";
    cout << givenText << endl;
    cout << "------------------------------------------\n";

    cout << "\nPress ENTER to start typing...";
    cin.get();

    clock_t startTime = clock();
    string userText;

    cout << "\nStart Typing: ";
    getline(cin, userText);

    clock_t endTime = clock();
    double timeTaken = double(endTime - startTime) / CLOCKS_PER_SEC;
    int wordsTyped = givenText.length() / 5;
    double wpm = (wordsTyped / timeTaken) * 60;

    int correctChars = 0;
    for (size_t i = 0; i < givenText.length() && i < userText.length(); i++) {
        if (givenText[i] == userText[i]) {
            correctChars++;
        }
    }
    double accuracy = ((double)correctChars / givenText.length()) * 100;

    cout << "\n===== Typing Test Results =====\n";
    cout << "Time Taken: " << timeTaken << " seconds" << endl;
    cout << "Typing Speed: " << wpm << " WPM" << endl;
    cout << "Accuracy: " << accuracy << "%" << endl;

    cout << "\nEnter your name for leaderboard: ";
    string name;
    getline(cin, name);
    leaderboard.push_back({name, wpm, accuracy});
}

int main() {
    while (true) {
        cout << "\n1. Start Typing Test";
        cout << "\n2. View Leaderboard";
        cout << "\n3. Exit";
        cout << "\nChoose an option: ";
        int option;
        cin >> option;
        cin.ignore();

        if (option == 1) {
            startTypingTest();
        } else if (option == 2) {
            displayLeaderboard();
        } else {
            cout << "\nThank you for using Typing Master!\n";
            break;
        }
    }
    return 0;
}
