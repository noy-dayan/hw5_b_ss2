#include "MagicalContainer.hpp"

namespace ariel {
    MagicalContainer::~MagicalContainer(){
        // free all pointers in primeElements
        for (int* pPrimeNumber : primeElements) 
            delete pPrimeNumber;
    }

    void MagicalContainer::addElement(int number) {
        // finds the first position in which number could be inserted without changing the ordering
        auto it = std::lower_bound(container.begin(), container.end(), number);
        container.insert(it, number);

        // if number is prime, create a pointer to the number and add it to primeElements
        if(isPrime(number)){
            int* pNumber = new int(number);
            
            // finds the first position in which pNumber could be inserted without changing the ordering (by using the formula: x < y)
            auto pIt = std::lower_bound(this->primeElements.begin(), this->primeElements.end(), pNumber, 
                [](const int* x, const int* y) { 
                    return *x < *y; 
                });

            primeElements.insert(pIt, pNumber);
        }
    }

    void MagicalContainer::removeElement(int number) {
        // erase number from container
        for (auto it = container.begin(); it != container.end() ; ++it) 
            if(*it == number) {
                this->container.erase(it);
                if(isPrime(number))
                    continue;
                else
                    return;
            }

        // erase and free pointer to the number from primeElements
        for (auto pIt = primeElements.begin(); pIt != primeElements.end() ; ++pIt) 
            if(**pIt == number) {
                delete *pIt;
                this->primeElements.erase(pIt);
                return;
            }

        // if did not return, throw an exception
        throw std::runtime_error("Number does not exist in the container");
    }

    size_t MagicalContainer::size() const {
        return this->container.size();
    }

    // IsPrime
    bool MagicalContainer::isPrime(int number) const {
        if (number <= 1)
            return false;

        for (int i = 2; i <= sqrt(number); i++)
            if (number % i == 0)
                return false;
        

        return true;
    }
}

