# #Sets in Python can be defined as mutable dynamic collections of immutable unique elements. \
# #The elements contained in a set must be immutable.

# Core Characteristics

#     Unordered: The items have no defined order. You cannot refer to items by index or key.

#     Unique: Duplicate elements are not allowed. If you try to add a duplicate, it is simply ignored.

#     Mutable: You can add or remove items from a set.

#     Hashable Elements: While the set itself is mutable, the elements contained in the set must be immutable (e.g., numbers, strings, tuples). You cannot put a list inside a set.

# Creation and Syntax

#     Curly Braces: Sets are created using curly braces {}.

#         Example: my_set = {1, 2, 3}

#     set() Constructor: Used to create a set from another iterable (great for removing duplicates from a list).

#         Example: set([1, 2, 2, 3]) becomes {1, 2, 3}.

#     The Empty Set Trap: To create an empty set, you must use set(). Using empty curly braces {} creates an empty Dictionary, not a set.

# Mathematical Operations

# Sets in Python support standard mathematical operations, often represented by operators or methods.

#     Union (|): Combines items from both sets (removes duplicates).

#         set_a | set_b or set_a.union(set_b)

#     Intersection (&): Keeps only items found in both sets.

#         set_a & set_b or set_a.intersection(set_b)

#     Difference (-): Keeps items in the first set that are not in the second.

#         set_a - set_b or set_a.difference(set_b)

#     Symmetric Difference (^): Keeps items in either set, but not in both.

#         set_a ^ set_b or set_a.symmetric_difference(set_b)

# Modifying Sets

#     Adding Items:

#         add(x): Adds a single element x.

#         update(iterable): Adds multiple elements from a list, tuple, or another set.

#     Removing Items:

#         remove(x): Removes x. Raises a KeyError if x does not exist.

#         discard(x): Removes x. Does not raise an error if x is missing.

#         pop(): Removes and returns a random item (since sets are unordered).

#         clear(): Empties the set.

# Accessing Elements

#     No Indexing: Since sets are unordered, you cannot use my_set[0].

#     Iteration: You can loop through a set using a for loop.

#     Membership Testing: Use the in keyword to check if a value exists (sets are highly optimized for this).

#         Example: if "apple" in my_set:

# Frozen Sets

#     frozenset(): An immutable version of a set. Once created, items cannot be added or removed. Frozensets can be used as keys in dictionaries (regular sets cannot).