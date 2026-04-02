#pragma once 
// Only include this once compiler directive

template <typename T>
struct remove_all_pointers {
    using type = T; // Store the type of T as remove_all_pointers::type
};

// Recursive Case: If the type is a pointer, recursively remove_all_pointers until the pointers are completely dereferenced
template <typename T>
struct remove_all_pointers<T*> {
    using type = typename remove_all_pointers<T>::type; // Store the type of T as remove_all_pointers::type [typename is required since the type is a dependent nested type]
};

// Handle constant pointers
template <typename T>
struct remove_all_pointers<T* const> {
    using type = typename remove_all_pointers<T>::type;
};

// Handle volatile pointers
template <typename T>
struct remove_all_pointers<T* volatile> {
    using type = typename remove_all_pointers<T>::type;
};

// Handle constant volatile pointers
template <typename T>
struct remove_all_pointers<T* const volatile> {
    using type = typename remove_all_pointers<T>::type;
};

// Alias Template so that we can write:
// remove_all_pointers_t<T>;
// instead of
// typename remove_all_pointers<T>::type;
template <typename T>
using remove_all_pointers_t = typename remove_all_pointers<T>::type;