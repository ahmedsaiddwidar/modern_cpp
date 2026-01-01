import numpy as np  # Standard alias

# NumPy is the library that powers the entire AI industry. TensorFlow and PyTorch are basically "NumPy with a GPU." \
# If you know NumPy, you know the language of data.(the engine of ML)

# A. Why This Matters

#     Speed: Python lists are slow. NumPy arrays are 50x to 100x faster because they run in C.

#     Math: Python lists don't know math.

#         List: [1, 2] + [3, 4] = [1, 2, 3, 4] (It joins them).

#         NumPy: [1, 2] + [3, 4] = [4, 6] (It adds them).

#     Cleanliness: You can replace massive for loops with single lines of math.

data = [1,2,4,5,6,67,8,9] # Python list ->slow

data_npArr = np.array(data) # NumPy array ->fast

print("Original data:", data_npArr)
print(type(data_npArr))

scores = [10, 20, 30]

doubled_scores = []

scores_npArr = np.array(scores)

doubled_scores = scores_npArr * 2  # NumPy array math

print("Doubled scores:", doubled_scores)

# 3. Built-in Math NumPy has optimized versions of the functions we wrote manually.

#     np.mean(arr): Average

#     np.max(arr): Maximum

#     np.sum(arr): Sum

#     np.argmax(arr): Index of the max value (Crucial for classification models).

prices = [100, 200, 300, 400]

discounted_prices = np.array(prices)  * 0.9  # 10% discount

print("Discounted prices:", discounted_prices)

discounted_prices = discounted_prices + 5  # $5 off for a tax
print("Discounted prices after tax:", discounted_prices)

import numpy as np

raw_scores = [10, 25, 50, 5, 100]

# 1. Convert to Array
arr = np.array(raw_scores)

# 2. Find Max
# np.max() is highly optimized C code.
max_value = np.max(arr)

# 3. Normalize
# Element-wise division. One line replaces the whole loop + append logic.
normalized = arr / max_value

print("Normalized:", normalized)
