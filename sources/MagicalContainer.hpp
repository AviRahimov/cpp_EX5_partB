//
// Created by avi on 24/05/2023.
//

/**
 * @file MagicalContainer.h
 * @brief Defines the MagicalContainer class and its iterators.
 */

#ifndef CPP_EX4_PARTA_MAGICALCONTAINER_HPP
#define CPP_EX4_PARTA_MAGICALCONTAINER_HPP

#include <iostream>
#include <vector>
#include <math.h>
#include "Mystical_Iterator.hpp"

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
        MagicalContainer();
        void addElement(int element);
        void removeElement(int element);
        size_t size();

        /**
         * @class AscendingIterator
         * @brief An iterator that iterates over the elements in ascending order.
         *
         * The AscendingIterator class provides an iterator that allows traversing the elements
         * in ascending order in the MagicalContainer.
         */
        class AscendingIterator : public Mystical_Iterator
        {
        private:
            MagicalContainer *magic_ctr; /**< Pointer to the MagicalContainer object. */
            std::size_t index;           /**< Index indicating the current position in the container. */

        public:
            AscendingIterator(MagicalContainer &magic_ctr);
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator(AscendingIterator &&other) noexcept;
            /**
             * @brief Default Destructor for AscendingIterator.
             */
            ~AscendingIterator() override = default;
            AscendingIterator &operator=(const AscendingIterator &other);
            AscendingIterator &operator=(AscendingIterator &&other) noexcept;
            bool operator==(const Mystical_Iterator &other) const override;
            bool operator!=(const Mystical_Iterator &other) const override;
            bool operator<(const Mystical_Iterator &other) const override;
            bool operator>(const Mystical_Iterator &other) const override;
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            int operator*() const;
            AscendingIterator &operator++();
            AscendingIterator begin();
            AscendingIterator end();
        };

        /**
         * @class SideCrossIterator
         * @brief An iterator that iterates over the elements in a side-cross pattern.
         *
         * The SideCrossIterator class provides an iterator that allows traversing the elements
         * in a side-cross pattern in the MagicalContainer.
         */
        class SideCrossIterator : public Mystical_Iterator
        {
        private:
            MagicalContainer *magic_ctr; /**< Pointer to the MagicalContainer object. */
            std::size_t head_index;
            std::size_t tail_index; /**< Index indicating the current position in the container. */
            bool is_head;

        public:
            SideCrossIterator(MagicalContainer &magic_ctr);
            SideCrossIterator(const SideCrossIterator &other);
            SideCrossIterator(SideCrossIterator &&other) noexcept;
            /**
             * @brief Default Destructor for SideCrossIterator.
             */
            ~SideCrossIterator() override = default;
            SideCrossIterator &operator=(const SideCrossIterator &other);
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;
            bool operator==(const Mystical_Iterator &other) const override;
            bool operator!=(const Mystical_Iterator &other) const override;
            bool operator<(const Mystical_Iterator &other) const override;
            bool operator>(const Mystical_Iterator &other) const override;
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            int operator*() const;
            SideCrossIterator &operator++();
            SideCrossIterator begin();
            SideCrossIterator end();
        };

        /**
         * @class PrimeIterator
         * @brief An iterator that iterates over the prime elements in the container.
         *
         * The PrimeIterator class provides an iterator that allows traversing the prime
         * elements in the MagicalContainer.
         */
        class PrimeIterator : public Mystical_Iterator
        {
        private:
            MagicalContainer *magic_ctr; /**< Pointer to the MagicalContainer object. */
            std::size_t index;           /**< Index indicating the current position in the container. */
            static bool isPrime(int value);

        public:
            PrimeIterator(MagicalContainer &magic_ctr);
            PrimeIterator(const PrimeIterator &other);
            PrimeIterator(PrimeIterator &&other) noexcept;
            /**
             * @brief Default Destructor for PrimeIterator.
             */
            ~PrimeIterator() override = default;
            PrimeIterator &operator=(const PrimeIterator &other);
            PrimeIterator &operator=(PrimeIterator &&other) noexcept;
            bool operator==(const Mystical_Iterator &other) const override;
            bool operator!=(const Mystical_Iterator &other) const override;
            bool operator<(const Mystical_Iterator &other) const override;
            bool operator>(const Mystical_Iterator &other) const override;
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            int operator*() const;
            PrimeIterator &operator++();
            PrimeIterator begin();
            PrimeIterator end();
        };
    };
} // namespace ariel

#endif // CPP_EX4_PARTA_MAGICALCONTAINER_HPP
