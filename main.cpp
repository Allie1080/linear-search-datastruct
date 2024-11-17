#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <forward_list>
#include <thread>


//
//
// func doLinearSearch (container, target):
//    for index := 0 to container.end do:  
//        if container[index] == targetIndex:
//            return index
//
//    else: error
//
//
//

constexpr std::chrono::duration<double> SLEEP_AMOUNT = std::chrono::duration<double>(0.5);

int doLinearSearch (std::vector<int> numberVector, int target) {
    for (int index{0}; index < numberVector.size(); index++) {
        if (numberVector[index] == target) {
            return index;

        }

    } 

    return -1;

}

int doLinearSearch (std::forward_list<int> numberLinkedList, int target) {
    int index{0};

    while (!numberLinkedList.empty()) {
        if (numberLinkedList.front() == target) {
            return index;

        }

        numberLinkedList.pop_front();
        index++;

    }

    return -1;

}

void displayList (std::vector<int> numberVector) {
    for (int index{0}; index < numberVector.size(); index++) {
        std::cout << numberVector[index] << ((index == numberVector.size() - 1) ? "\n" : ", ");

    }

}

void displayList (std::forward_list<int> numberLinkedList) {
    for (std::forward_list<int>::iterator iterator{numberLinkedList.begin()}; iterator != numberLinkedList.end(); ++iterator ) {
        std::cout << "[" << *iterator << "]" << ((std::next(iterator) == numberLinkedList.end()) ? "\n" : "  ->  ");

    }

}

void displayLinearSearch (std::forward_list<int> numberLinkedList, int target, bool targetIndexMode=false) {
    int iterationCounter{0};
    bool foundMatch{false};

    for (std::forward_list<int>::iterator iterator{numberLinkedList.begin()}; iterator != numberLinkedList.end(); ++iterator ) {
        if ((*iterator == target & targetIndexMode == false) | (iterationCounter == target & targetIndexMode == true & !foundMatch)) {
            foundMatch = true;
            std::cout << "[" << *iterator << "]" << ((std::next(iterator) == numberLinkedList.end()) ? "\n" : "  ->  ");

        } else {
            std::cout << "[ ]" << ((std::next(iterator) == numberLinkedList.end()) ? "\n" : "  ->  ");
            
        }
        
        if (!foundMatch) {
            iterationCounter++;
        
        }

    }

    if (foundMatch) {
        for (int spaceCounter{0}; spaceCounter < iterationCounter + 1; spaceCounter++) {
            if (spaceCounter == iterationCounter) {
                std::cout << " ^ ";

            } else {
                std::cout << "   ";

            }

            std::cout << "      ";

        }

        std::cout << '\n';
    
    } else {
        std::cout << "NO MATCH FOUND" << '\n';

    }

}

void displayAnimatedLinearSearch (std::forward_list<int> numberLinkedList, int target) {
    int targetIndex = doLinearSearch(numberLinkedList, target);

    if (targetIndex == -1) {
        int counter{0};
        for (std::forward_list<int>::iterator iterator{numberLinkedList.begin()}; iterator != numberLinkedList.end(); ++iterator ) {
            system("cls");
            if (std::next(iterator) == numberLinkedList.end()) {
                std::cout << "Index of " << target << " cannot be found... " << '\n';

            } else {
                std::cout << "Index of " << target << " is " << counter << '\n';

            }
            displayLinearSearch(numberLinkedList, counter, true);
            std::this_thread::sleep_for(std::chrono::duration<double>(SLEEP_AMOUNT));
            counter++;
        
        }

    } else {
        for (int index{0}; index <= targetIndex; index++) {
            system("cls");
            std::cout << "Index of " << target << " is " << index << '\n';
            displayLinearSearch(numberLinkedList, index, true);
            std::this_thread::sleep_for(std::chrono::duration<double>(SLEEP_AMOUNT));

        }

    }



}

int main () {
    std::string dummy;
    int findIndex{0};
    std::vector<int> numberVector = {1, 2, 3, 5, 8, 13, 21, 34, 55};
    std::forward_list<int> numberLinkedList;
    
    for (int counter{0}; counter < 10; counter++) {
        numberLinkedList.push_front(counter);

    }
    std::cout << "Vector//Array: ";
    displayList(numberVector);

    std::cout << "Index of 1 = " << doLinearSearch(numberVector, 1) << '\n';
    std::cout << "Index of 5 = " << doLinearSearch(numberVector, 5) << '\n';
    std::cout << "Index of 9 = " << doLinearSearch(numberVector, 2) << '\n';
    std::cout << "Index of 10 = " << doLinearSearch(numberVector, 77) << '\n';
    getline(std::cin, dummy);
    std::cin.ignore();
    
    system("cls");
    std::cout << "Linked List:" << '\n';
    displayList(numberLinkedList);

    while (findIndex != -2) {
        std::cout << '\n';
        std::cout << "Enter number to find: ";
        std::cin >> findIndex;
        system("cls");
        displayAnimatedLinearSearch(numberLinkedList, findIndex);

    }



    // std::getline(std::cin, dummy);
    // system("cls");
    // displayAnimatedLinearSearch(numberLinkedList, 5);
    // std::getline(std::cin, dummy);
    // system("cls");
    // displayAnimatedLinearSearch(numberLinkedList, 6);
    // std::getline(std::cin, dummy);
    // system("cls");
    // displayAnimatedLinearSearch(numberLinkedList, 10);
    // std::getline(std::cin, dummy);

}