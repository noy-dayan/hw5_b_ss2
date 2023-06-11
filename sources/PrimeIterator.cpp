#include "MagicalContainer.hpp"

namespace ariel {
    // PrimeIterator
    // Constructors & Destructors
    MagicalContainer::PrimeIterator::PrimeIterator() : container(*new MagicalContainer()), index(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : container(container), index(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container, size_t index) : container(container), index(index){}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) : container(other.container) {}

    // Operators
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        if(&this->container != &other.container)
            throw std::runtime_error("Iterators are pointing at different containers");
        this->container = other.container;
        this->index = other.index;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return this->index == other.index;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return this->index > other.index;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return this->index < other.index;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        return *(this->container.primeElements[index]);
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        if(this->index >= this->container.primeElements.size())
            throw std::runtime_error("Iterator Increment Beyond End");
        ++this->index;
        return *this;
    }

    // Begin & End
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
        return PrimeIterator(this->container);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
        return PrimeIterator(this->container, this->container.primeElements.size());
    }

}