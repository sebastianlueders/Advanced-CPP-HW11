
#pragma once

// Base Case (not an l or r value)
template <typename T>
struct is_reference 
{
    static constexpr bool val = false;
};

// lvalue specialization
template <typename T>
struct is_reference<T&> 
{
    static constexpr bool val = true;
};

// rvalue specialization
template <typename T>
struct is_reference<T&&> 
{
    static constexpr bool val = true;
};




template <typename T>
inline constexpr bool is_reference_v = is_reference<T>::val;