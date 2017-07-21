#ifndef COMP_SEQUENTIAL_EQUAL_H
#define COMP_SEQUENTIAL_EQUAL_H

namespace comp
{
    template<typename T>
    bool sequentialEqual(T const & lhs, T const & rhs);

    template<typename H, typename ... Ts>
    bool sequentialEqual(H const & lhs, H const & rhs, Ts const & ... ts);
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
template<typename H, typename ... Ts>
inline bool sequentialEqual(H const & lhs, H const & rhs, Ts const & ... ts)
{
    return (sequentialEqual(lhs, rhs) && sequentialEqual(ts ...));
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* COMP_SEQUENTIAL_EQUAL_H */

