#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> container;
        std::vector<int*> primeElements;

    public:
        MagicalContainer(){}
        ~MagicalContainer();

        void addElement(int number);
        void removeElement(int number);
        size_t size() const;
        bool isPrime(int number) const;

        // Iterator classes
        class AscendingIterator {
        private:
            MagicalContainer& container;
            size_t index;
            AscendingIterator(MagicalContainer& container, size_t index);

        public:
            AscendingIterator();
            ~AscendingIterator(){};

            AscendingIterator(MagicalContainer& container);
            AscendingIterator(const AscendingIterator& other);

            AscendingIterator& operator=(const AscendingIterator& other);
            int operator*() const;
            AscendingIterator& operator++();

            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;

            AscendingIterator begin() const;
            AscendingIterator end() const;
        };

        class SideCrossIterator {
        private:
            MagicalContainer& container;
            size_t index;
            SideCrossIterator(MagicalContainer& container, size_t index);

        public:            
            SideCrossIterator();
            ~SideCrossIterator(){};

            SideCrossIterator(MagicalContainer& container);
            SideCrossIterator(const SideCrossIterator& other);

            SideCrossIterator& operator=(const SideCrossIterator& other);
            int operator*() const;
            SideCrossIterator& operator++();

            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;

            SideCrossIterator begin() const;
            SideCrossIterator end() const;
        };

        class PrimeIterator {
        private:
            MagicalContainer& container;
            size_t index;
            PrimeIterator(MagicalContainer& container, size_t index);

        public:
            PrimeIterator();
            ~PrimeIterator(){};

            PrimeIterator(MagicalContainer& container);
            PrimeIterator(const PrimeIterator& other);

            PrimeIterator& operator=(const PrimeIterator& other);
            int operator*() const;
            PrimeIterator& operator++();

            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;

            PrimeIterator begin() const;
            PrimeIterator end() const;

        };
    };
}

#endif // MAGICALCONTAINER_H
