# C++11 Comparison Functions #

Sometime a need arises to implement equal-to operator (`operator==`) or less-than operator (`operator<`) for a struct or class. This is especially the case when we want to insert instances of the class to a sorted container (like `std::set` or `std::map`), or to search for them using standard algorithms (like `std::find`).

Rolling the implementation by hand is fine if the class has only few members, but quickly gets tedious and error-prone as the number of members to compare grows. Consider this example:

```
struct Employee
{
    std::string first_name;
    std::string last_name;
    std::string position;
};

bool operator==(Employee const & l, Employee const & r)
{
    return (
        (l.first_name == r.first_name) &&
        (l.last_name == r.last_name) &&
        (l.position == r.position));
}

bool operator<(Employee const & l, Employee const & r)
{
    if (l.first_name < r.first_name)
    {
        return true;
    }
    else if (l.first_name > r.first_name)
    {
        return false;
    }

    if (l.last_name < r.last_name)
    {
        return true;
    }
    else if (l.last_name > r.last_name)
    {
        return false;
    }

    if (l.position < r.position)
    {
        return true;
    }

    return false;
}
```

This is a lot of typing just to compare three members.

## tuples ##

C++11 makes implementing the comparisons much easier by introducing `std::tuple`, which is a generalisation of `std::pair` to arbitrary number of elements, with relational operators built in, and `std::tie` function, which allows creating tuples on the spot.

Using the above-mentioned facilities, the comparisons can be made shorter:

```
bool operator==(Employee const & l, Employee const & r)
{
    return (std::tie(l.first_name, l.last_name, l.position) == std::tie(r.first_name, r.last_name, r.position));
}

bool operator<(Employee const & l, Employee const & r)
{
    return (std::tie(l.first_name, l.last_name, l.position) < std::tie(r.first_name, r.last_name, r.position));
}
```

The pro is that these versions are much shorter, but the con is that the compared members are not close to each other and it still may be easy to make a mistake and reorder the members.

## `sequentialEqual` and `sequentialLess` ##

This module delivers two generalised comparison functions: `sequentialEqual` and `sequentialLess`, which do pair-by-pair comparisons with short-circuit evaluation. The advantage over the tuple based version is that compared structures are decomposed into compared pairs, which makes mistakes much easier to catch:

```
bool operator==(Employee const & l, Employee const & r)
{
    return sequentialEqual(
        l.first_name, r.first_name,
        l.last_name, r.last_name,
        l.position, r.position);
}

bool operator<(Employee const & l, Employee const & r)
{
    return sequentialLess(
        l.first_name, r.first_name,
        l.last_name, r.last_name,
        l.position, r.position);
}
```

Both functions support arbitrary number of elements.

## License ##

This project is released under **MIT/X11** license, so feel free to do anything you like with it.


