//
// Created by avi on 24/05/2023.
//

/**
 * @file MagicalContainer.h
 * @brief Defines the MagicalContainer class and its iterators.
 */

#ifndef CPP_EX4_PARTA_MAGICALCONTAINER_H
#define CPP_EX4_PARTA_MAGICALCONTAINER_H

#include <iostream>
#include <vector>
#include <math.h>

namespace ariel
{
    /**
     * @class MagicalContainer
     * @brief A container class that holds mystical elements.
     *
     * The MagicalContainer class stores a collection of mystical elements. It provides
     * methods to add and remove elements from the container, as well as access the size
     * of the container.
     */
    class MagicalContainer
    {
    private:
        std::vector<int> mystical_elements; /**< The underlying vector to store the elements. */

    public:
        /**
         * @brief Constructs an empty MagicalContainer object.
         */
        MagicalContainer() {}

        /**
         * @brief Adds an element to the container.
         * @param element The element to be added.
         */
        void addElement(int element)
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
        void removeElement(int element)
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
        size_t size()
        {
            return this->mystical_elements.size();
        }

        /**
         * @class AscendingIterator
         * @brief An iterator that iterates over the elements in ascending order.
         *
         * The AscendingIterator class provides an iterator that allows traversing the elements
         * in ascending order in the MagicalContainer.
         */
        class AscendingIterator
        {
        private:
            MagicalContainer *magic_ctr; /**< Pointer to the MagicalContainer object. */
            std::size_t index;           /**< Index indicating the current position in the container. */

        public:
            /**
             * @brief Constructs an AscendingIterator object.
             * @param magic_ctr The MagicalContainer to iterate over.
             */
            AscendingIterator(MagicalContainer &magic_ctr) : magic_ctr(&magic_ctr), index(0) {}

            /**
             * @brief Copy constructor for AscendingIterator.
             * @param other The AscendingIterator to copy from.
             */
            AscendingIterator(const AscendingIterator &other) : magic_ctr(other.magic_ctr), index(other.index) {}

            /**
             * @brief Default Destructor for AscendingIterator.
             */
            ~AscendingIterator() = default;

            /**
             * @brief Assignment operator for AscendingIterator.
             * @param other The AscendingIterator to assign from.
             * @return Reference to the assigned AscendingIterator.
             * @throws std::runtime_error If the iterators are pointing at different containers.
             */
            AscendingIterator &operator=(const AscendingIterator &other)
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
            bool operator==(const AscendingIterator &other) const
            {
                return index == other.index;
            }

            /**
             * @brief Inequality comparison operator.
             * @param other The AscendingIterator to compare with.
             * @return True if the iterators are not equal, false otherwise.
             */
            bool operator!=(const AscendingIterator &other) const
            {
                return !(*this == other);
            }

            /**
             * @brief Greater than comparison operator.
             * @param other The AscendingIterator to compare with.
             * @return True if this iterator is greater than the other iterator, false otherwise.
             */
            bool operator>(const AscendingIterator &other) const
            {
                return index > other.index;
            }

            /**
             * @brief Less than comparison operator.
             * @param other The AscendingIterator to compare with.
             * @return True if this iterator is less than the other iterator, false otherwise.
             */
            bool operator<(const AscendingIterator &other) const
            {
                return !(*this > other) && (other != other);
            }

            /**
             * @brief Dereference operator.
             * @return The element at the current position of the iterator.
             */
            int operator*() const
            {
                return magic_ctr->mystical_elements[index];
            }

            /**
             * @brief Pre-increment operator.
             * @return Reference to the incremented iterator.
             * @throws std::runtime_error If the index is invalid.
             */
            AscendingIterator &operator++()
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
            AscendingIterator begin()
            {
                return AscendingIterator(*magic_ctr);
            }

            /**
             * @brief Returns the ending iterator of the container.
             * @return The ending iterator.
             */
            AscendingIterator end()
            {
                AscendingIterator iter(*magic_ctr);
                iter.index = magic_ctr->mystical_elements.size();
                return iter;
            }
        };

        /**
         * @class SideCrossIterator
         * @brief An iterator that iterates over the elements in a side-cross pattern.
         *
         * The SideCrossIterator class provides an iterator that allows traversing the elements
         * in a side-cross pattern in the MagicalContainer.
         */
        class SideCrossIterator
        {
        private:
            MagicalContainer *magic_ctr; /**< Pointer to the MagicalContainer object. */
            std::size_t head_index;
            std::size_t tail_index; /**< Index indicating the current position in the container. */
            bool is_head;

        public:
            /**
             * @brief Constructs a SideCrossIterator object.
             * @param magic_ctr The MagicalContainer to iterate over.
             */
            SideCrossIterator(MagicalContainer &magic_ctr) : magic_ctr(&magic_ctr), head_index(0), tail_index(magic_ctr.size() - 1), is_head(true)
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
            SideCrossIterator(const SideCrossIterator &other) : magic_ctr(other.magic_ctr), head_index(other.head_index), tail_index(other.tail_index), is_head(other.is_head) {}

            /**
             * @brief Default Destructor for SideCrossIterator.
             */
            ~SideCrossIterator() = default;

            /**
             * @brief Assignment operator for SideCrossIterator.
             * @param other The SideCrossIterator to assign from.
             * @return Reference to the assigned SideCrossIterator.
             * @throws std::runtime_error If the iterators are pointing at different containers.
             */
            SideCrossIterator &operator=(const SideCrossIterator &other)
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
            bool operator==(const SideCrossIterator &other) const
            {
                return (head_index == other.head_index) && (tail_index == other.tail_index);
            }

            /**
             * @brief Inequality comparison operator.
             * @param other The SideCrossIterator to compare with.
             * @return True if the iterators are not equal, false otherwise.
             */
            bool operator!=(const SideCrossIterator &other) const
            {
                return !(*this == other);
            }

            /**
             * @brief Greater than comparison operator.
             * @param other The SideCrossIterator to compare with.
             * @return True if this iterator is greater than the other iterator, false otherwise.
             */
            bool operator>(const SideCrossIterator &other) const
            {
                return tail_index > other.tail_index || head_index > other.head_index;
            }

            /**
             * @brief Less than comparison operator.
             * @param other The SideCrossIterator to compare with.
             * @return True if this iterator is less than the other iterator, false otherwise.
             */
            bool operator<(const SideCrossIterator &other) const
            {
                return !(*this > other) && (other != other);
            }

            /**
             * @brief Dereference operator.
             * @return The element at the current position of the iterator.
             */
            int operator*() const
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
            SideCrossIterator &operator++()
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
            SideCrossIterator begin()
            {
                return SideCrossIterator(*magic_ctr);
            }

            /**
             * @brief Returns the ending iterator of the container.
             * @return The ending iterator.
             */
            SideCrossIterator end()
            {
                SideCrossIterator iter(*magic_ctr);
                iter.head_index = 0;
                iter.tail_index = magic_ctr->size();
                iter.is_head = true;
                return iter;
            }
        };

        /**
         * @class PrimeIterator
         * @brief An iterator that iterates over the prime elements in the container.
         *
         * The PrimeIterator class provides an iterator that allows traversing the prime
         * elements in the MagicalContainer.
         */
        class PrimeIterator
        {
        private:
            MagicalContainer *magic_ctr; /**< Pointer to the MagicalContainer object. */
            std::size_t index;           /**< Index indicating the current position in the container. */

        public:
            /**
             * @brief Constructs a PrimeIterator object.
             * @param magic_ctr The MagicalContainer to iterate over.
             */
            PrimeIterator(MagicalContainer &magic_ctr) : magic_ctr(&magic_ctr), index(0)
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
            PrimeIterator(const PrimeIterator &other) : magic_ctr(other.magic_ctr), index(other.index) {}

            /**
             * @brief Default Destructor for PrimeIterator.
             */
            ~PrimeIterator() = default;

            /**
             * @brief Assignment operator for PrimeIterator.
             * @param other The PrimeIterator to assign from.
             * @return Reference to the assigned PrimeIterator.
             * @throws std::runtime_error If the iterators are pointing at different containers.
             */
            PrimeIterator &operator=(const PrimeIterator &other)
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
            bool operator==(const PrimeIterator &other) const
            {
                return index == other.index;
            }

            /**
             * @brief Inequality comparison operator.
             * @param other The PrimeIterator to compare with.
             * @return True if the iterators are not equal, false otherwise.
             */
            bool operator!=(const PrimeIterator &other) const
            {
                return !(*this == other);
            }

            /**
             * @brief Greater than comparison operator.
             * @param other The PrimeIterator to compare with.
             * @return True if this iterator is greater than the other iterator, false otherwise.
             */
            bool operator>(const PrimeIterator &other) const
            {
                return index > other.index;
            }

            /**
             * @brief Less than comparison operator.
             * @param other The PrimeIterator to compare with.
             * @return True if this iterator is less than the other iterator, false otherwise.
             */
            bool operator<(const PrimeIterator &other) const
            {
                return !(*this > other) && (other != other);
            }

            /**
             * @brief Dereference operator.
             * @return The element at the current position of the iterator.
             */
            int operator*() const
            {
                return magic_ctr->mystical_elements[index];
            }

            /**
             * @brief Pre-increment operator.
             * @return Reference to the incremented iterator.
             * @throws std::runtime_error If the iterator has reached the end.
             */
            PrimeIterator &operator++()
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
            PrimeIterator begin()
            {
                return PrimeIterator(*magic_ctr);
            }

            /**
             * @brief Returns the ending iterator of the container.
             * @return The ending iterator.
             */
            PrimeIterator end()
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
            bool static isPrime(int value)
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
        };
    };
} // namespace ariel

#endif // CPP_EX4_PARTA_MAGICALCONTAINER_H
