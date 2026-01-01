#Lists in Python are implemented as dynamic mutable arrays which hold an ordered collection of items.


# Core Characteristics

#     Ordered: Items have a defined order, and that order will not change unless you explicitly change it (e.g., by sorting).

#     Mutable: You can change, add, and remove items in a list after it has been created.

#     Heterogeneous: A single list can contain items of different data types (e.g., integers, strings, and even other lists).

#     Allow Duplicates: Lists can contain items with the same value.

# Creation and Syntax

#     Square Brackets: Lists are created using square brackets [].

#         Example: my_list = [1, 2, "apple", 4.5]

#     list() Constructor: You can convert other iterables (like tuples or strings) into a list.

#         Example: list((1, 2, 3)) creates [1, 2, 3].

# Accessing Elements

#     Zero-Based Indexing: The first item has index 0.

#         my_list[0] gets the first item.

#     Negative Indexing: -1 refers to the last item, -2 to the second to last, etc.

#     Slicing: You can access a range of items using a colon :.

#         my_list[1:3] gets items from index 1 up to (but not including) index 3.

# Modifying Lists

#     Changing Values: You can assign a new value to a specific index.

#         my_list[1] = "banana"

#     Adding Items:

#         append(x): Adds an item x to the end of the list.

#         insert(i, x): Inserts item x at a specific index i.

#         extend(iterable): Adds all items from another iterable (like another list) to the end.

#     Removing Items:

#         remove(x): Removes the first occurrence of item x.

#         pop(i): Removes and returns the item at index i (defaults to the last item if no index is specified).

#         clear(): Removes all items from the list.

#         del: Keyword used to delete an item by index or delete the entire list.

# Common List Methods & Functions

#     len(list): Returns the number of items in the list.

#     sort(): Sorts the list in ascending order (modifies the original list).

#     reverse(): Reverses the order of the list (modifies the original list).

#     index(x): Returns the index of the first item with the value x.

#     count(x): Returns the number of times x appears in the list.

#     copy(): Returns a shallow copy of the list.

# List Comprehension

#     A concise way to create lists based on existing lists.

#         Syntax: [expression for item in iterable if condition]

#         Example: [x**2 for x in range(5)] produces [0, 1, 4, 9, 16].

