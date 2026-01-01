#***************1. Lists (The Workhorse)*******************

# batch_scores = [85, 90, 78, 92, 88]

# print (batch_scores[0])
# print (batch_scores[-1])

# batch_scores.append(95)

# subaet = batch_scores[0:3]

# print (subaet)


# ------------------------------------------------------------------------------------------------------------------

#***************2. Tuples (The Safety Lock)*******************

# # Dimensions of an image (width, height)
# img_dims = (1920, 1080)

# # accessing is the same as lists
# print(img_dims[0]) # 1920

# # img_dims[0] = 720  <-- ERROR! TypeError: 'tuple' object does not support item assignment

# ------------------------------------------------------------------------------------------------------------------

#***************3. Sets (The De-Duplicator)*******************

# raw_tags = ["cat", "dog", "cat", "bird", "dog"]
# unique_tags = set(raw_tags)

# print(unique_tags) 
# # Output: {'bird', 'cat', 'dog'} (Order is not guaranteed!)

# # Checking existence (Very fast)

# if "cat" in unique_tags:
#     print("Tag 'cat' exists in the set.")

# ------------------------------------------------------------------------------------------------------------------

#***************4. Dictionaries (The Lookup Table)*******************

# model_config = {
#     "learning_rate": 0.001,
#     "batch_size": 32,
#     "num_epochs": 10
# }

# print(model_config["learning_rate"])

# model_config["dropout_rate"] = 0.5  # Adding a new key-value pair
# model_config["batch_size"] = 64    # Modifying an existing value

# *****************************************
# project1
# *****************************************

raw_ids = [101, 102, 101, 103, 104, 102, 105]

unique_ids = set(raw_ids)

uniqueList_ids = list(unique_ids)

sorted_unique_ids = sorted(uniqueList_ids)

summary = {
    "total_count": len(raw_ids),
    "uique_count": len(unique_ids),
    "cleaned_ids": sorted_unique_ids
}

cleaned_ids = tuple(sorted_unique_ids)

print("Summary:", summary)
print("Cleaned IDs (Tuple):", cleaned_ids)
