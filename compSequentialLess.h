#ifndef COMP_SEQUENTIAL_LESS_H
#define COMP_SEQUENTIAL_LESS_H

namespace comp
{
    template<typename T>
    bool sequentialLess(T const & lhs, T const & rhs);
}

namespace comp
{
////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline bool sequentialLess(T const & lhs, T const & rhs)
{
    return (lhs < rhs);
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* COMP_SEQUENTIAL_LESS_H */

