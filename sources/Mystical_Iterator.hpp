#ifndef CPP_EX4_PARTA_MYSTICAL_ITERATOR_HPP
#define CPP_EX4_PARTA_MYSTICAL_ITERATOR_HPP

namespace ariel
{
    /**
     * @class Mystical_Iterator
     * @brief Abstract base class for mystical iterators.
     *
     * The Mystical_Iterator class is an abstract base class that defines the interface for mystical iterators.
     * It provides pure virtual functions for comparison operators and default implementations for the special member functions.
     * Derived classes must implement the comparison operators.
     *
     * @note This class is meant to be inherited and extended by concrete iterator classes.
     */
    class Mystical_Iterator
    {
    public:
        /**
         * @brief Equality comparison operator.
         * @param other The other Mystical_Iterator to compare with.
         * @return True if the iterators are equal, false otherwise.
         */
        virtual bool operator==(const Mystical_Iterator &other) const = 0;

        /**
         * @brief Inequality comparison operator.
         * @param other The other Mystical_Iterator to compare with.
         * @return True if the iterators are not equal, false otherwise.
         */
        virtual bool operator!=(const Mystical_Iterator &other) const = 0;

        /**
         * @brief Less than comparison operator.
         * @param other The other Mystical_Iterator to compare with.
         * @return True if this iterator is less than the other iterator, false otherwise.
         */
        virtual bool operator<(const Mystical_Iterator &other) const = 0;

        /**
         * @brief Greater than comparison operator.
         * @param other The other Mystical_Iterator to compare with.
         * @return True if this iterator is greater than the other iterator, false otherwise.
         */
        virtual bool operator>(const Mystical_Iterator &other) const = 0;

        /**
         * @brief Default constructor.
         */
        Mystical_Iterator() = default;

        /**
         * @brief Destructor.
         */
        virtual ~Mystical_Iterator() = default;

        /**
         * @brief Copy constructor.
         * @param other The other Mystical_Iterator to copy from.
         */
        Mystical_Iterator(const Mystical_Iterator &other) = default;

        /**
         * @brief Move constructor.
         * @param other The other Mystical_Iterator to move from.
         */
        Mystical_Iterator(Mystical_Iterator &&other) = default;

        /**
         * @brief Copy assignment operator.
         * @param other The other Mystical_Iterator to assign from.
         * @return Reference to the assigned Mystical_Iterator.
         */
        Mystical_Iterator &operator=(const Mystical_Iterator &other) = default;

        /**
         * @brief Move assignment operator.
         * @param other The other Mystical_Iterator to move from.
         * @return Reference to the assigned Mystical_Iterator.
         */
        Mystical_Iterator &operator=(Mystical_Iterator &&other) = default;
    };
}

#endif // CPP_EX4_PARTA_MYSTICAL_ITERATOR_HPP
