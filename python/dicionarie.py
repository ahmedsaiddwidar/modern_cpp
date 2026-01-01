# Dictionaries in Python are very similar to real-world dictionaries. \
# These are mutable data structures that contain a collection of keys and, associated with them, values.

# Core Characteristics

#     Key-Value Pairs: Stores data as a map. Each item has a Key (the identifier) and a Value (the data).

#     Ordered: As of Python 3.7+, dictionaries preserve the order in which items were inserted.

#     Mutable: You can change values, add new pairs, or delete pairs after creation.

#     Unique Keys: Keys must be unique within a dictionary. Duplicate keys are not allowed (the last assignment wins).

#     Immutable Keys: Keys must be of an immutable type (strings, numbers, tuples). Values can be of any type.

# Creation and Syntax

#     Curly Braces: Uses curly braces {}, similar to sets, but with colons separating keys and values.

#         Example: my_dict = {"name": "Alice", "age": 25}

#     dict() Constructor: Creates a dictionary from a list of tuples or keyword arguments.

#         Example: dict(name="Alice", age=25)

# Accessing Data

#     By Key: Use square brackets [] with the key name.

#         my_dict["name"] returns "Alice".

#         Note: Raises a KeyError if the key doesn't exist.

#     .get() Method: Safer way to access values. Returns None (or a specified default) if the key is missing.

#         my_dict.get("height", 0) returns 0 if "height" is not found.

# Modifying Dictionaries

#     Adding/Updating: Assign a value to a key. If the key exists, it updates the value; if not, it adds the pair.

#         my_dict["email"] = "alice@example.com" (Add)

#         my_dict["age"] = 26 (Update)

#     update(): Merges another dictionary into the current one, overwriting existing keys.

#     Removing Items:

#         pop(key): Removes the key and returns its value.

#         del my_dict[key]: Deletes the key-value pair.

#         popitem(): Removes and returns the last inserted pair (LIFO).

#         clear(): Empties the dictionary.

# Key Methods & Iteration

#     .keys(): Returns a view object of all keys.

#     .values(): Returns a view object of all values.

#     .items(): Returns a view object of all (key, value) tuples.

# Looping Example:
# Python

# for key, value in my_dict.items():
#     print(f"{key}: {value}")

# Dictionary Comprehension

#     Similar to list comprehension but for creating dictionaries.

#         Syntax: {key_exp: val_exp for item in iterable}

#         Example: {x: x**2 for x in range(5)} creates {0: 0, 1: 1, 2: 4, ...}