#include "MagicalContainer.hpp"

namespace ariel {
    // SideCrossIterator
    // Constructors & Destructors
    MagicalContainer::SideCrossIterator::SideCrossIterator() : container(*new MagicalContainer()), index(0) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : container(container), index(0) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container, size_t index) : container(container), index(index){}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : container(other.container), index(other.index){}

    // Operators
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        if(&this->container != &other.container)
            throw std::runtime_error("Iterators are pointing at different containers");
        this->container = other.container;
        this->index = other.index;
        return *this;
    }
    
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return this->index == other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return this->index > other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return this->index < other.index;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        size_t crossIndex = (this->index % 2 == 0) ? this->index / 2 : this->container.size() - 1 - this->index / 2;
        return this->container.container[crossIndex];
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if(this->index >= this->container.size())
            throw std::runtime_error("Iterator Increment Beyond End");
        ++this->index;
        return *this;
    }

    // Begin & End
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
        return SideCrossIterator(this->container);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
        return SideCrossIterator(this->container, this->container.size());
    }
}