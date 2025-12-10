

    - Can you explain move semantics?

    - Can you describe what unique_ptr and shared_ptr are and when you would use them?

    - Can you name some of the standard library containers (vector, array, map etc.) and explain what uses each one has?

    - Have you heard of the rule of 5 and can you explain what it is?

    - Do you know what RAII is and can you explain it?

    - Are you aware of undefined behaviour, implementation defined behaviour and unspecified behaviour, and do you know the differences?

    - Do you actively try to keep up with developments in the language?

But my favorite questions are more open ended. For example:

    - What are one or two things that you really like about the C++ language and why?

    - Similarly, what are two things you really dislike about the language and would change if you could?

    - Is there anything fundamental you think is still missing from the language or the standard library?

    - What other languages do you like and why?
    -----------------------------------------------------------------------------------------------------------

I've already showed my "interview guide" here two or three times, probably need to suggest it as a pinned post.

My point is, modern C++ is a conglomerate of barely intersecting subsets. \
Candidate must show non-zero knowledge on any of them. Depth of the knowledge varies from Junior to Senior Dev.

C-legacy subset of C++. Work with the basic types, memory, pointers, alignment. However, \
we also can put here references, rvalue references, new/delete, why not to use it in 99% of the code, \
memory managers, and other C++ specific, but low-level things, which could be considered belonging to this subset

    OOP subset. Classes, inheritance, virtual functions, design patterns, and anti-patterns. \
    Don’t forget the multiple and virtual inheritance. Patterns related to new C++14/17 features.

    Template programming and metaprogramming subset. To claim “knowledge” \
    you both should know how to apply metaprogramming template magic, \
    and not to have a temptation to apply it in the human-readable code.\
    C++20 concepts are optional.

    The subset of Standard Library of C++. All these beautiful algorithms, \
    containers, and iterators. Don’t forget new features like ranges and filesystem

    Multithreading subset. Includes both lock-based and lock-free approach, atomics, async, future/promise etc. \
    Common multithreading traps, from data race to ABA’ problem. Having a “multithreaded” type of mindset is necessary, \
    if you work with modern architectures. Average CPU offers 4-12 cores on desktop, and 128-256 on server, \
    know how to take advantage of these resources. GPU is optional.

