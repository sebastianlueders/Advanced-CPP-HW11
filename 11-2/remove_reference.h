#pragma once


// Base Case: T is non-reference type
template <typename T>
struct remove_reference 
{
    using type = T;
};

// lvalue specialization
template <typename T>
struct remove_reference<T&>
{
    using type = T;
};

// rvalue specialization
template <typename T>
struct remove_reference<T&&>
{
    using type = T;
};

// Alias
template <typename T>
using remove_reference_t = typename remove_reference<T>::type;