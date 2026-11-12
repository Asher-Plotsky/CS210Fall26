#include "Adventure.h"
#include <iostream>

// ===================== GIVEN HELPERS (do not change) =====================

// Reads the next line that is not blank.
// Spaces at the start of the line are removed.
// Returns false when the file has no more lines.
bool Adventure::nextLine(std::ifstream& in, std::string& line) {
    std::string raw;
    while (std::getline(in, raw)) {
        int start = 0;
        while (start < (int)raw.size() && (raw[start] == ' ' || raw[start] == '\t')) {
            start++;
        }
        line = raw.substr(start);
        // Files saved on Windows can end each line with an extra '\r'.
        if (!line.empty() && line[line.size() - 1] == '\r') {
            line = line.substr(0, line.size() - 1);
        }
        if (!line.empty()) {
            return true;
        }
    }
    return false;
}

// Reads the next line and checks that it starts with keyword.
// Example: for the line "HP -2" and keyword "HP", value becomes "-2".
// Prints an error and returns false if the line is missing or wrong.
bool Adventure::readField(std::ifstream& in, const std::string& keyword, std::string& value) {
    std::string line;
    if (!nextLine(in, line)) {
        std::cout << "Error: expected a " << keyword << " line but the file ended." << std::endl;
        return false;
    }
    std::string prefix = keyword + " ";
    if (line.substr(0, prefix.size()) != prefix) {
        std::cout << "Error: expected a " << keyword << " line but found: " << line << std::endl;
        return false;
    }
    value = line.substr(prefix.size());
    return true;
}

// Adds one choice number to a path.
// extendPath("", 2) gives "2". extendPath("2-1", 3) gives "2-1-3".
std::string Adventure::extendPath(const std::string& path, int choiceNumber) const {
    if (path.empty()) {
        return std::to_string(choiceNumber);
    }
    return path + "-" + std::to_string(choiceNumber);
}

// ===================== LOADING =====================

// TODO 10: open the story file and build the tree.
//   - If the file will not open, print exactly:
//       Error: could not open file <fileName>
//     and return false.
//   - Read the START_HP line and save the number in startHp_.
//     (std::stoi turns "10" into 10.)
//   - Build the whole story with readScene. The first scene's label is "START".
//   - If anything failed, return false. Otherwise give the story to tree_.
bool Adventure::load(const std::string& fileName) {
    std::ifstream in(fileName);
    if (!in.is_open()) {
        std::cout << "Error: could not open file <" << fileName << ">" << std::endl;
        return false;
    }
    try
    {
        std::string line;
        if (!std::getline(in, line)) {
            return false;
        }
        if (line.find("START_HP") != std::string::npos) {
            line = line.substr(8);
            startHp_ = std::stoi(line);
            tree_.setRoot(readScene(in, "START"));
            in.close();
            return true;
        }
        in.close();
        return false;
    }
    catch (std::exception& e) {
        in.close();
        return false;
    }
}

// TODO 11: read ONE scene and everything below it. Return it.
//   - Read SCENE, HP, LOOT, ITEM, and CHOICES with readField, in that order.
//   - If CHOICES is below 0 or above Scene<Moment>::MAX_CHOICES, print exactly:
//       Error: scene "<scene text>" has <n> choices. The limit is 3.
//     and return nullptr.
//   - Each choice is a LABEL line followed by a whole scene.
//   - If anything goes wrong at any depth, return nullptr
//     and make sure nothing you already built is leaked.
Scene<Moment>* Adventure::readScene(std::ifstream& in, const std::string& label) {
    std::string line;
    int hp;
    std::string text;
    int level;
    int choice;
    for (int i = 0; i < 5; i++) {
        if (!std::getline(in, line)) {
            return nullptr;
        }
        level = line.substr(0, line.find_first_not_of(" ")).length() / 2;
        line.erase(0,line.find_first_not_of(" "));
        if (line.find("HP") != std::string::npos) {
            hp = std::stoi(line.substr(2));
        }
        if (line.find("LOOT") != std::string::npos) {

        }
        if (line.find("ITEM") != std::string::npos) {

        }
        if (line.find("CHOICES") != std::string::npos) {
            if (std::stoi(line.substr(5)) > Scene<Moment>::MAX_CHOICES || std::stoi(line.substr(5)) < 0) {
                std::cout << "Error: scene " << text <<" has " << line.substr(5) << " choices. The limit is 3." << std::endl;
                return nullptr;
            }
            choice = std::stoi(line.substr(5));
        }
        if (line.find("SCENE") != std::string::npos) {
            text = line.substr(5);
            text = text.erase(0,text.find_first_not_of(" "));
        }
    }
    for (int i = 0; i < choice; i++) {
        while (true) {
            if (!std::getline(in, line)) {
                return nullptr;
            }
            if (line.find("Label") != std::string::npos){
                text = line.substr(5);
                text = text.erase(0,text.find_first_not_of(" "));
                if (readScene(in, text) == nullptr) {
                    return nullptr;
                }
                break;
            }
        }
    }
    return nullptr;
}

// ===================== PLAYING =====================

// TODO 12: ask the player to pick a choice from 1 to numChoices.
//   - Print "Your choice: " (no newline) and read a whole line.
//   - If the line is not a valid number in range, print exactly:
//       Please type a number from 1 to <numChoices>.
//     and ask again.
//   - If the input ends (getline fails), return 0.
int Adventure::askChoice(int numChoices) {
    while (true) {
        std::cout << "Your choice: ";
        std::string line;
        if (!std::getline(std::cin, line)) {
            return 0;
        }
        bool isNumber = !line.empty();
        for (unsigned char c : line) {
            if (!std::isdigit(c)) isNumber = false;
        }
        if (isNumber && std::stoi(line) <= numChoices && std::stoi(line) > 0) {
            return std::stoi(line);
        }
        std::cout << "Please type a number from 1 to " << numChoices << "." << std::endl;
    }
}

// TODO 13: play the story once from the start.
// Every time the player ENTERS a scene, in this order:
//   1. Add its HP change to hp and its loot to loot.
//   2. Print a line of 40 dashes, then the scene text.
//   3. If the scene has an item:
//        if the bag already has it, print "You already have: <item>"
//        otherwise add it to the bag and print "You picked up: <item>"
//   4. Print "HP: <hp>  Loot: <loot>" (two spaces before Loot).
//   5. If hp is 0 or less, print "Your HP hit 0. GAME OVER." and stop.
//      If the scene is an ending, print "THE END." and stop.
//   6. Print each choice as "[1] <label>" and use askChoice.
//      If askChoice returns 0, leave play right away.
// When the game stops, print:
//   Final HP: <hp>  Final loot: <loot>
//   Inventory (<count> items):
// and then print the bag.
// The bag is a List<Item>. Start with HP = startHp_ and loot = 0.
void Adventure::play() {

}

// ===================== ANALYZING =====================

// TODO 14: print exactly three lines:
//   Scenes: <count>
//   Endings: <count>
//   Longest playthrough: <height> choices
void Adventure::printStats() const {
    std::cout << tree_.countScenes() << std::endl;
    std::cout << tree_.countEndings() << std::endl;
    std::cout << std::to_string(tree_.height()) << std::endl;
}

// TODO 15: print every ending in the story, one per line.
void Adventure::printSpoilers() const {
    if (tree_.getRoot() == nullptr) {
        return;
    }
    printSpoilers(tree_.getRoot());
}

//Could not figure out how to do it in the first method, so I made a new one.
void Adventure::printSpoilers(Scene<Moment>* scene) const {
    if (scene == nullptr) {
        return;
    }
    if (scene->getNumChoices() == 0) {
        std::cout <<scene->getData()->getText() << std::endl;
        return;
    }
    for (int i = 0; i < scene->getNumChoices(); i++) {
        printSpoilers(scene->getChoice(i));
    }
}

// TODO 16: print every ending below scene.
// path holds the choice numbers taken to reach scene, like "2-1".
// Each ending prints as:
//   Path <path>: <scene text>
// If the very first scene is an ending, print "Path (start): <scene text>".
// Endings print in order: choice 1 before choice 2 before choice 3.
void Adventure::printEndings(Scene<Moment>* scene, const std::string& path) const {
    if (scene == nullptr) {
        return;
    }
    if (scene -> getNumChoices() == 0) {
        if (tree_.getRoot() == scene) {
            std::cout << "Path (start): " << scene -> getData() -> getText() << std::endl;
            return;
        }
        std::cout <<"Path " << path << ": " << scene -> getData() -> getText() << std::endl;
        return;
    }
    for (int i = 0; i < scene -> getNumChoices(); i++) {
        if (path.empty()) {
            printEndings(scene -> getChoice(i), std::to_string(i + 1));
        }
        else {
            printEndings(scene -> getChoice(i), path + "-" + std::to_string(i + 1));
        }
    }
}

// TODO 17: the greedy advisor.
// Start at the first scene with startHp_ and 0 loot.
// Enter scenes the same way play does (add HP and loot).
// Stop when hp is 0 or less, or you reach an ending.
// Otherwise always move to the choice with the MOST loot right now.
// On a tie, pick the lower choice number.
// Print:
//   Greedy advisor
//     Path: <path>
//     Loot: <loot>
//     Result: died               (or "Result: reached an ending")
void Adventure::greedyRun() const {
}

// TODO 18: the best total loot you can collect from scene down to an ending,
// arriving at scene with hp health and having taken path to get here.
//   - Return -1 if every way down from here kills you.
//   - Put the path of the best run into bestPath.
//   - Must be recursive and look at every choice.
int Adventure::bestLoot(Scene<Moment>* scene, int hp, const std::string& path, std::string& bestPath) const {
    return -1;
}

// TODO 19: the optimal advisor. Use bestLoot from the first scene.
// Print:
//   Optimal advisor
//     Path: <path>
//     Loot: <loot>
//     Result: reached an ending
// If no path survives, print only:
//   Optimal advisor
//     Result: no path survives this story
void Adventure::optimalRun() const {

}
