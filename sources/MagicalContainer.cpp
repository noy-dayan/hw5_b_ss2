#include "MagicalContainer.hpp"

namespace ariel {
    MagicalContainer::~MagicalContainer(){
        for (int* pPrimeNumber : primeElements) 
            delete pPrimeNumber;
    }

    void MagicalContainer::addElement(int number) {
        auto it = std::lower_bound(container.begin(), container.end(), number);
        container.insert(it, number);
        if(isPrime(number)){
            int* pNumber = new int(number);
            auto pIt = std::lower_bound(this->primeElements.begin(), this->primeElements.end(), pNumber, 
                [](const int* x, const int* y) { 
                    return *x < *y; 
                });

            primeElements.insert(pIt, pNumber);
        }
    }

    void MagicalContainer::removeElement(int number) {
        for (auto it = container.begin(); it != container.end() ;++it) 
            if(*it == number) {
                this->container.erase(it);
                if(isPrime(number))
                    continue;
                else
                    return;
            }

        for (auto pIt = primeElements.begin(); pIt != primeElements.end() ;++pIt) 
            if(**pIt == number) {
                delete *pIt;
                this->primeElements.erase(pIt);
                return;
            }
            
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

