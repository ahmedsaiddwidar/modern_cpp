# Tuples are almost identical to lists, so they contain an ordered collection of elements,\
# except for one property: they are immutable.

# Core Characteristics

#     Immutable: Once a tuple is created, you cannot add, remove, or change elements. This is their defining feature.

#     Ordered: Items have a defined order (like lists).

#     Heterogeneous: Can contain mixed data types (integers, strings, lists, etc.).

#     Allow Duplicates: Can contain items with the same value.

#     Faster/Lighter: Tuples generally require less memory and are slightly faster to iterate over than lists.

# Creation and Syntax

#     Parentheses: Tuples are typically defined using parentheses ().

#         Example: my_tuple = (1, 2, "apple")

#     The Comma Rule (Crucial): It is actually the comma that creates the tuple, not the parentheses. Parentheses are just for grouping.

#         t = 1, 2 creates a tuple.

#     Single Item Trap: To create a tuple with only one item, you must include a trailing comma.

#         Correct: single = (5,) (Type is tuple)

#         Incorrect: not_tuple = (5) (Type is integer)

# Accessing Elements

#     Indexing & Slicing: Identical to lists.

#         my_tuple[0] gets the first item.

#         my_tuple[-1] gets the last item.

#         my_tuple[1:3] slices the tuple.

# The "Immutability" Nuance

#     Strict Structure: You cannot change the structure of the tuple (no append, extend, or assignment like t[0] = 5).

#     Mutable Contents: If a tuple contains a mutable object (like a list), that specific object can be modified.

#         Example:
#         Python

#         t = (1, 2, ["a", "b"])
#         t[2][0] = "c"  # This IS allowed because you are modifying the list inside.
#         # Result: (1, 2, ["c", "b"])

# Packing and Unpacking

# This is a very common and "Pythonic" way to use tuples.

#     Packing: Assigning multiple values to a single variable automatically creates a tuple.

#         coordinates = 4, 5

#     Unpacking: Assigning a tuple to multiple variables extracts the values.

#         x, y = coordinates (x becomes 4, y becomes 5).

#     Usage: This is often used to return multiple values from a function.

# Methods

# Because tuples are immutable, they only have two built-in methods:

#     count(x): Returns the number of times x appears.

#     index(x): Returns the index of the first occurrence of x.

# When to use Tuples?

#     Data Integrity: When you want to ensure data isn't accidentally changed throughout your program.

#     Dictionary Keys: Since tuples are immutable (and hashable), they can be used as keys in a dictionary (lists cannot).

#         Example: location_dict = {(35.6, 139.6): "Tokyo"}