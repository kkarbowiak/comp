#ifndef COMP_SEQUENTIAL_LESS_H
#define COMP_SEQUENTIAL_LESS_H

namespace comp
{
    template<typename T>
    bool sequentialLess(T const & lhs, T const & rhs);

    template<typename H, typename ... Ts>
    bool sequentialLess(H const & lhs, H const & rhs, Ts const & ... ts);
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
template<typename H, typename ... Ts>
inline bool sequentialLess(H const & lhs, H const & rhs, Ts const & ... ts)
{
    if (lhs < rhs)
    {
        return true;
    }
    else if (rhs < lhs)
    {
        return false;
    }
    else
    {
        return sequentialLess(ts ...);
    }
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* COMP_SEQUENTIAL_LESS_H */

