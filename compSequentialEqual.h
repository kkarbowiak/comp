#ifndef COMP_SEQUENTIAL_EQUAL_H
#define COMP_SEQUENTIAL_EQUAL_H

namespace comp
{
    template<typename T>
    bool sequentialEqual(T const & lhs, T const & rhs);
}

namespace comp
{
////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline bool sequentialEqual(T const & lhs, T const & rhs)
{
    return (lhs == rhs);
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* COMP_SEQUENTIAL_EQUAL_H */

