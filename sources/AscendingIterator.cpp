#include "MagicalContainer.hpp"

namespace ariel {
    // AscendingIterator
    // Constructors & Destructors
    MagicalContainer::AscendingIterator::AscendingIterator() : container(*new MagicalContainer()), index(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : container(container), index(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container, size_t index) : container(container), index(index){}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) : container(other.container), index(other.index) {}

    // Operators
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        if(&this->container != &other.container)
            throw std::runtime_error("Iterators are pointing at different containers");

        this->container = other.container;
        this->index = other.index;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return this->index == other.index;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return this->index > other.index;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return this->index < other.index;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return this->container.container[index];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        if(this->index >= this->container.size())
            throw std::runtime_error("Iterator Increment Beyond End");
        this->index++;
        return *this;
    }

    // Begin & End
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
        return AscendingIterator(this->container);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
        return AscendingIterator(this->container, this->container.size());
    }
}