#ifndef ARRAY_HPP
#define ARRAY_HPP

class ArrayInvalidIndex : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Array: Invalid index access";
        }
};

template <typename T>
class Array
{
    private:
    T*              array;
    unsigned int    n;

    public:
        Array(): array(NULL), n(0) {};

        Array(unsigned int n): n(n)
        {
            if (n == 0)
                array = NULL;
            else
                array = new T[n]();
        }

        Array(const Array& other): n(other.n)
        {
            if (n == 0)
                array = NULL;
            else
            {
                array = new T[n];
                for (unsigned int i = 0; i < n; i++)
                    array[i] = other.array[i];
            }
        }

        const T& operator[](unsigned int index) const
        {
            if (index >= n)
                throw ArrayInvalidIndex();
            return array[index];
        }

        T& operator[](unsigned int index)
        {
            if (index >= n)
                throw ArrayInvalidIndex();
            return array[index];
        }

        T& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] array;
                n = other.n;
                if (n == 0)
                    array = NULL;
                else
                {
                    array = new T[n];
                    for (unsigned int i = 0; i < n; i++)
                        array[i] = other.array[i];
                }
            }
            return *this;
        }

        unsigned int size() const
        {
            return n;
        }


};

#endif