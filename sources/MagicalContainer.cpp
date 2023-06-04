#include "MagicalContainer.hpp"
using namespace ariel;

/**
 * @brief Constructs an empty MagicalContainer object.
 */
MagicalContainer::MagicalContainer() {}

/**
 * @brief Adds an element to the container.
 * @param element The element to be added.
 */
void MagicalContainer::addElement(int element)
{
    auto iter = std::lower_bound(mystical_elements.begin(), mystical_elements.end(), element);
    mystical_elements.insert(iter, element);
}

/**
 * @brief Removes an element from the container.
 * @param element The element to be removed.
 *
 * If the element exists in the container, it will be removed. If there are multiple
 * occurrences of the element, only the first occurrence will be removed.
 * @throws std::runtime_error If the element is not found in the container.
 */
void MagicalContainer::removeElement(int element)
{
    // Find the element in the vector and remove it
    auto iter = std::find(mystical_elements.begin(), mystical_elements.end(), element);

    if (iter != mystical_elements.end())
    {
        mystical_elements.erase(iter);
    }
    else
    {
        throw std::runtime_error("The number is not in the container");
    }
}

/**
 * @brief Returns the number of elements in the container.
 * @return The size of the container.
 */
size_t MagicalContainer::size()
{
    return this->mystical_elements.size();
}

/**
 * @brief Constructs an AscendingIterator object.
 * @param magic_ctr The MagicalContainer to iterate over.
 */
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &magic_ctr) : magic_ctr(&magic_ctr), index(0) {}

/**
 * @brief Copy constructor for AscendingIterator.
 * @param other The AscendingIterator to copy from.
 */
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : magic_ctr(other.magic_ctr), index(other.index) {}

/**
 * @brief Move constructor for AscendingIterator.
 * @param other The other AscendingIterator to move from.
 */
MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &&other) noexcept : magic_ctr(other.magic_ctr), index(other.index) {}

/**
 * @brief Move assignment operator for AscendingIterator.
 * @param other The other AscendingIterator to move from.
 * @return Reference to the assigned AscendingIterator.
 */
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept {
    if (this != &other)
    {
        magic_ctr = other.magic_ctr;
        index = other.index;
    }

    return *this;
}

/**
 * @brief Equality comparison operator.
 * @param other The other Mystical_Iterator to compare with.
 * @return True if the iterators are equal, false otherwise.
 * @throws std::runtime_error if the iterators are of different types or point to different containers.
 */
bool MagicalContainer::AscendingIterator::operator==(const Mystical_Iterator &other) const {
    const AscendingIterator *other_ptr = dynamic_cast<const AscendingIterator *>(&other);

    if (other_ptr == nullptr)
        throw std::runtime_error("Cannot compare iterators of different types");

    else if (&magic_ctr != &other_ptr->magic_ctr)
        throw std::runtime_error("Iterators are pointing at different containers");

    return index == other_ptr->index;
}

/**
 * @brief Inequality comparison operator.
 * @param other The other Mystical_Iterator to compare with.
 * @return True if the iterators are not equal, false otherwise.
 * @throws std::runtime_error if the iterators are of different types or point to different containers.
 */
bool MagicalContainer::AscendingIterator::operator!=(const Mystical_Iterator &other) const {
    const AscendingIterator *other_ptr = dynamic_cast<const AscendingIterator *>(&other);

    if (other_ptr == nullptr)
        throw std::runtime_error("Cannot compare iterators of different types");

    if (magic_ctr != other_ptr->magic_ctr)
        throw std::runtime_error("Iterators are pointing at different containers");

    return index != other_ptr->index;
}

/**
 * @brief Less than comparison operator.
 * @param other The other Mystical_Iterator to compare with.
 * @return True if this iterator is less than the other iterator, false otherwise.
 * @throws std::runtime_error if the iterators are of different types or point to different containers.
 */
bool MagicalContainer::AscendingIterator::operator<(const Mystical_Iterator &other) const {
    const AscendingIterator *other_ptr = dynamic_cast<const AscendingIterator *>(&other);

    if (other_ptr == nullptr)
        throw std::runtime_error("Cannot compare iterators of different types");

    if (magic_ctr != other_ptr->magic_ctr)
        throw std::runtime_error("Iterators are pointing at different containers");

    return index < other_ptr->index;
}

/**
 * @brief Greater than comparison operator.
 * @param other The other Mystical_Iterator to compare with.
 * @return True if this iterator is greater than the other iterator, false otherwise.
 * @throws std::runtime_error if the iterators are of different types or point to different containers.
 */
bool MagicalContainer::AscendingIterator::operator>(const Mystical_Iterator &other) const {
    const AscendingIterator *other_ptr = dynamic_cast<const AscendingIterator *>(&other);

    if (other_ptr == nullptr)
        throw std::runtime_error("Cannot compare iterators of different types");

    if (magic_ctr != other_ptr->magic_ctr)
        throw std::runtime_error("Iterators are pointing at different containers");

    return index > other_ptr->index;
}

/**
 * @brief Assignment operator for AscendingIterator.
 * @param other The AscendingIterator to assign from.
 * @return Reference to the assigned AscendingIterator.
 * @throws std::runtime_error If the iterators are pointing at different containers.
 */
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this->magic_ctr != other.magic_ctr)
    {
        throw std::runtime_error("Iterators are pointing at different containers");
    }

    if (this != &other)
    {
        magic_ctr = other.magic_ctr;
        index = other.index;
    }
    return *this;
}

/**
 * @brief Equality comparison operator.
 * @param other The AscendingIterator to compare with.
 * @return True if the iterators are equal, false otherwise.
 */
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return index == other.index;
}

/**
 * @brief Inequality comparison operator.
 * @param other The AscendingIterator to compare with.
 * @return True if the iterators are not equal, false otherwise.
 */
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return !(*this == other);
}

/**
 * @brief Greater than comparison operator.
 * @param other The AscendingIterator to compare with.
 * @return True if this iterator is greater than the other iterator, false otherwise.
 */
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return index > other.index;
}

/**
 * @brief Less than comparison operator.
 * @param other The AscendingIterator to compare with.
 * @return True if this iterator is less than the other iterator, false otherwise.
 */
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return !(*this > other) && (other != other);
}

/**
 * @brief Dereference operator.
 * @return The element at the current position of the iterator.
 */
int MagicalContainer::AscendingIterator::operator*() const
{
    return magic_ctr->mystical_elements[index];
}

/**
 * @brief Pre-increment operator.
 * @return Reference to the incremented iterator.
 * @throws std::runtime_error If the index is invalid.
 */
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (this->index == this->magic_ctr->size())
    {
        throw std::runtime_error("Invalid index");
    }
    ++index;
    return *this;
}

/**
 * @brief Returns the beginning iterator of the container.
 * @return The beginning iterator.
 */
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(*magic_ctr);
}

/**
 * @brief Returns the ending iterator of the container.
 * @return The ending iterator.
 */
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator iter(*magic_ctr);
    iter.index = magic_ctr->mystical_elements.size();
    return iter;
}

/**
 * @brief Constructs a SideCrossIterator object.
 * @param magic_ctr The MagicalContainer to iterate over.
 */
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &magic_ctr) : magic_ctr(&magic_ctr), head_index(0), tail_index(magic_ctr.size() - 1), is_head(true)
{
    if (magic_ctr.size() == 0)
    {
        tail_index = 0;
    }
}

/**
 * @brief Copy constructor for SideCrossIterator.
 * @param other The SideCrossIterator to copy from.
 */
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : magic_ctr(other.magic_ctr), head_index(other.head_index), tail_index(other.tail_index), is_head(other.is_head) {}

/**
 * @brief Move constructor for SideCrossIterator.
 * @param other The other SideCrossIterator to move from.
 */
MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &&other) noexcept : magic_ctr(other.magic_ctr), head_index(other.head_index), tail_index(other.tail_index) {}

/**
 * @brief Move assignment operator for SideCrossIterator.
 * @param other The other SideCrossIterator to move from.
 * @return Reference to the assigned SideCrossIterator.
 */
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept {
    if (this != &other)
    {
        magic_ctr = other.magic_ctr;
        head_index = other.head_index;
        tail_index = other.tail_index;
    }

    return *this;
}

/**
 * @brief Equality comparison operator.
 * @param other The other Mystical_Iterator to compare with.
 * @return True if the iterators are equal, false otherwise.
 * @throws std::runtime_error if the iterators are of different types or point to different containers.
 */
bool MagicalContainer::SideCrossIterator::operator==(const Mystical_Iterator &other) const {
    const SideCrossIterator *other_ptr = dynamic_cast<const SideCrossIterator *>(&other);

    if (other_ptr == nullptr)
        throw std::runtime_error("Cannot compare iterators of different types");

    else if (&magic_ctr != &other_ptr->magic_ctr)
        throw std::runtime_error("Iterators are pointing at different containers");

    return (head_index == other_ptr->head_index) && (tail_index == other_ptr->tail_index);
}

/**
 * @brief Inequality comparison operator.
 * @param other The other Mystical_Iterator to compare with.
 * @return True if the iterators are not equal, false otherwise.
 * @throws std::runtime_error if the iterators are of different types or point to different containers.
 */
bool MagicalContainer::SideCrossIterator::operator!=(const Mystical_Iterator &other) const {
    const SideCrossIterator *other_ptr = dynamic_cast<const SideCrossIterator *>(&other);

    if (other_ptr == nullptr)
        throw std::runtime_error("Cannot compare iterators of different types");

    if (magic_ctr != other_ptr->magic_ctr)
        throw std::runtime_error("Iterators are pointing at different containers");

    return (head_index != other_ptr->head_index) && (tail_index != other_ptr->tail_index);
}

/**
 * @brief Less than comparison operator.
 * @param other The other Mystical_Iterator to compare with.
 * @return True if this iterator is less than the other iterator, false otherwise.
 * @throws std::runtime_error if the iterators are of different types or point to different containers.
 */
bool MagicalContainer::SideCrossIterator::operator<(const Mystical_Iterator &other) const {
    const SideCrossIterator *other_ptr = dynamic_cast<const SideCrossIterator *>(&other);

    if (other_ptr == nullptr)
        throw std::runtime_error("Cannot compare iterators of different types");

    if (magic_ctr != other_ptr->magic_ctr)
        throw std::runtime_error("Iterators are pointing at different containers");

    return !(*this > other) && (other != other);
}

/**
 * @brief Greater than comparison operator.
 * @param other The other Mystical_Iterator to compare with.
 * @return True if this iterator is greater than the other iterator, false otherwise.
 * @throws std::runtime_error if the iterators are of different types or point to different containers.
 */
bool MagicalContainer::SideCrossIterator::operator>(const Mystical_Iterator &other) const {
    const SideCrossIterator *other_ptr = dynamic_cast<const SideCrossIterator *>(&other);

    if (other_ptr == nullptr)
        throw std::runtime_error("Cannot compare iterators of different types");

    if (magic_ctr != other_ptr->magic_ctr)
        throw std::runtime_error("Iterators are pointing at different containers");

    return (tail_index > other_ptr->tail_index) || (head_index > other_ptr->head_index);
}
/**
 * @brief Assignment operator for SideCrossIterator.
 * @param other The SideCrossIterator to assign from.
 * @return Reference to the assigned SideCrossIterator.
 * @throws std::runtime_error If the iterators are pointing at different containers.
 */
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (other.magic_ctr != this->magic_ctr)
    {
        throw std::runtime_error("Iterators are pointing at different containers");
    }
    if (this != &other)
    {
        magic_ctr = other.magic_ctr;
        head_index = other.head_index;
        tail_index = other.tail_index;
        is_head = other.is_head;
    }
    return *this;
}

/**
 * @brief Equality comparison operator.
 * @param other The SideCrossIterator to compare with.
 * @return True if the iterators are equal, false otherwise.
 */
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return (head_index == other.head_index) && (tail_index == other.tail_index);
}

/**
 * @brief Inequality comparison operator.
 * @param other The SideCrossIterator to compare with.
 * @return True if the iterators are not equal, false otherwise.
 */
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return !(*this == other);
}

/**
 * @brief Greater than comparison operator.
 * @param other The SideCrossIterator to compare with.
 * @return True if this iterator is greater than the other iterator, false otherwise.
 */
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return tail_index > other.tail_index || head_index > other.head_index;
}

/**
 * @brief Less than comparison operator.
 * @param other The SideCrossIterator to compare with.
 * @return True if this iterator is less than the other iterator, false otherwise.
 */
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return !(*this > other) && (other != other);
}

/**
 * @brief Dereference operator.
 * @return The element at the current position of the iterator.
 */
int MagicalContainer::SideCrossIterator::operator*() const
{
    if (is_head)
    {
        return magic_ctr->mystical_elements[head_index];
    }
    return magic_ctr->mystical_elements[tail_index];
}

/**
 * @brief Pre-increment operator.
 * @return Reference to the incremented iterator.
 * @throws std::runtime_error If the iterator has reached the end.
 */
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    if (*this == end())
    {
        throw std::runtime_error("Reached to the end");
    }

    if (is_head)
    {
        head_index++;
    }
    else
    {
        tail_index--;
    }

    if (tail_index < head_index)
    {
        tail_index = magic_ctr->size();
        head_index = 0;
    }
    is_head = !is_head;
    return *this;
}

/**
 * @brief Returns the beginning iterator of the container.
 * @return The beginning iterator.
 */
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    return SideCrossIterator(*magic_ctr);
}

/**
 * @brief Returns the ending iterator of the container.
 * @return The ending iterator.
 */
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator iter(*magic_ctr);
    iter.head_index = 0;
    iter.tail_index = magic_ctr->size();
    iter.is_head = true;
    return iter;
}

/**
 * @brief Constructs a PrimeIterator object.
 * @param magic_ctr The MagicalContainer to iterate over.
 */

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &magic_ctr) : magic_ctr(&magic_ctr), index(0)
{
    if (magic_ctr.size() > 0)
    {
        while (!(isPrime(magic_ctr.mystical_elements[index])) && index < magic_ctr.size())
        {
            ++index;
        }
    }
}

/**
 * @brief Copy constructor for PrimeIterator.
 * @param other The PrimeIterator to copy from.
 */

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : magic_ctr(other.magic_ctr), index(other.index) {}
/**
 * @brief Move constructor for PrimeIterator.
 * @param other The other PrimeIterator to move from.
 */
MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &&other) noexcept : magic_ctr(other.magic_ctr), index(other.index) {}

/**
 * @brief Move assignment operator for PrimeIterator.
 * @param other The other PrimeIterator to move from.
 * @return Reference to the assigned PrimeIterator.
 */
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other) noexcept {
    if (this != &other)
    {
        magic_ctr = other.magic_ctr;
        index = other.index;
    }

    return *this;
}

/**
 * @brief Equality comparison operator.
 * @param other The other Mystical_Iterator to compare with.
 * @return True if the iterators are equal, false otherwise.
 * @throws std::runtime_error if the iterators are of different types or point to different containers.
 */
bool MagicalContainer::PrimeIterator::operator==(const Mystical_Iterator &other) const {
    const PrimeIterator *other_ptr = dynamic_cast<const PrimeIterator *>(&other);

    if (other_ptr == nullptr)
        throw std::runtime_error("Cannot compare iterators of different types");

    else if (&magic_ctr != &other_ptr->magic_ctr)
        throw std::runtime_error("Iterators are pointing at different containers");

    return index == other_ptr->index;
}

/**
 * @brief Inequality comparison operator.
 * @param other The other Mystical_Iterator to compare with.
 * @return True if the iterators are not equal, false otherwise.
 * @throws std::runtime_error if the iterators are of different types or point to different containers.
 */
bool MagicalContainer::PrimeIterator::operator!=(const Mystical_Iterator &other) const {
    const PrimeIterator *other_ptr = dynamic_cast<const PrimeIterator *>(&other);

    if (other_ptr == nullptr)
        throw std::runtime_error("Cannot compare iterators of different types");

    if (magic_ctr != other_ptr->magic_ctr)
        throw std::runtime_error("Iterators are pointing at different containers");

    return index != other_ptr->index;
}

/**
 * @brief Less than comparison operator.
 * @param other The other Mystical_Iterator to compare with.
 * @return True if this iterator is less than the other iterator, false otherwise.
 * @throws std::runtime_error if the iterators are of different types or point to different containers.
 */
bool MagicalContainer::PrimeIterator::operator<(const Mystical_Iterator &other) const {
    const PrimeIterator *other_ptr = dynamic_cast<const PrimeIterator *>(&other);

    if (other_ptr == nullptr)
        throw std::runtime_error("Cannot compare iterators of different types");

    if (magic_ctr != other_ptr->magic_ctr)
        throw std::runtime_error("Iterators are pointing at different containers");

    return index < other_ptr->index;
}

/**
 * @brief Greater than comparison operator.
 * @param other The other Mystical_Iterator to compare with.
 * @return True if this iterator is greater than the other iterator, false otherwise.
 * @throws std::runtime_error if the iterators are of different types or point to different containers.
 */
bool MagicalContainer::PrimeIterator::operator>(const Mystical_Iterator &other) const {
    const PrimeIterator *other_ptr = dynamic_cast<const PrimeIterator *>(&other);

    if (other_ptr == nullptr)
        throw std::runtime_error("Cannot compare iterators of different types");

    if (magic_ctr != other_ptr->magic_ctr)
        throw std::runtime_error("Iterators are pointing at different containers");

    return index > other_ptr->index;
}
/**
 * @brief Assignment operator for PrimeIterator.
 * @param other The PrimeIterator to assign from.
 * @return Reference to the assigned PrimeIterator.
 * @throws std::runtime_error If the iterators are pointing at different containers.
 */
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (this->magic_ctr != other.magic_ctr)
    {
        throw std::runtime_error("Iterators are pointing at different containers");
    }

    if (this != &other)
    {
        magic_ctr = other.magic_ctr;
        index = other.index;
    }
    return *this;
}

/**
 * @brief Equality comparison operator.
 * @param other The PrimeIterator to compare with.
 * @return True if the iterators are equal, false otherwise.
 */
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return index == other.index;
}

/**
 * @brief Inequality comparison operator.
 * @param other The PrimeIterator to compare with.
 * @return True if the iterators are not equal, false otherwise.
 */
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return !(*this == other);
}

/**
 * @brief Greater than comparison operator.
 * @param other The PrimeIterator to compare with.
 * @return True if this iterator is greater than the other iterator, false otherwise.
 */
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return index > other.index;
}

/**
 * @brief Less than comparison operator.
 * @param other The PrimeIterator to compare with.
 * @return True if this iterator is less than the other iterator, false otherwise.
 */
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return !(*this > other) && (other != other);
}

/**
 * @brief Dereference operator.
 * @return The element at the current position of the iterator.
 */
int MagicalContainer::PrimeIterator::operator*() const
{
    return magic_ctr->mystical_elements[index];
}

/**
 * @brief Pre-increment operator.
 * @return Reference to the incremented iterator.
 * @throws std::runtime_error If the iterator has reached the end.
 */
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if (*this == end())
    {
        throw std::runtime_error("Cannot increment while pointing at the end of the vector");
    }
    ++index;
    while (!(isPrime(magic_ctr->mystical_elements[index])) && (index < magic_ctr->size()))
    {
        ++index;
    }
    return *this;
}
/**
 * @brief Returns the beginning iterator of the container.
 * @return The beginning iterator.
 */
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return PrimeIterator(*magic_ctr);
}

/**
 * @brief Returns the ending iterator of the container.
 * @return The ending iterator.
 */
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    PrimeIterator iter(*magic_ctr);
    iter.index = magic_ctr->mystical_elements.size();
    return iter;
}
/**
 * @brief Checks if a given value is prime.
 * @param value The value to check for primality.
 * @return True if the value is prime, false otherwise.
 */
bool MagicalContainer::PrimeIterator::isPrime(int value)
{
    if (value <= 1)
    {
        return false;
    }
    if (value == 2 || value == 3)
    {
        return true;
    }
    for (int i = 2; i <= sqrt(value); i++)
    {
        if (value % i == 0)
        {
            return false;
        }
    }
    return true;
}