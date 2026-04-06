// Only include this header file once during compilation
#pragma once

// Template for building a typelist container
template <typename ... Ts>
struct typelist {}; // Holds types at compile time

// Primary template
template <typename List, typename A, typename B>
struct Replace; // struct Replace declaration

// Helper to prepend a single type to a typelist
template <typename T, typename List>
struct Prepend;

// Replace Base case: empty list
template <typename A, typename B>
struct Replace<typelist<>, A, B> {  // If the typelist is empty, use this version of Replace
    using type = typelist<>; // empty typelist
};

// Replace Match Case: First type is A, so replace it with B and stop replacing
template <typename... Ts, typename A, typename B>
struct Replace<typelist<A, Ts...>, A, B> {  // matches a typelist that has A as the lead element
    using type = typelist<B, Ts...>;  // replace A at the front with B
};

// Replace Recursive Case: First type is B; Head is the first element in the typelist
template <typename Head, typename... Ts, typename A, typename B>
struct Replace<typelist<Head, Ts...>, A, B> {
    using type = typename Prepend<Head, typename Replace<typelist<Ts...>, A, B>::type>::type;
};

// Preprends T to the list of Ts
template<typename T, typename... Ts>
struct Prepend<T, typelist<Ts...>> {
    using type = typelist<T, Ts...>;
};

