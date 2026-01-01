score = 85
statue = "active"

if score >= 90:
    print("Grade: A")
elif score >= 80 and statue == "active":
    print("Grade: B")
else:
    print("Grade: C or below")

# Output: Grade: B

data = [10,20,30]

for i in data:
    print(i * 2)

for i in range(5):
    print(i)

loss = 1.5

while loss > 0.5:
    print(f"Current loss: {loss}")
    loss = loss - 0.5

banned_users = ["user1", "bot99", "admin"]
current_user = "bot99"# The Pythonic way
if current_user in banned_users:
    print("Access Denied")

queue = []
items = ["job1", "job2"]

# Checks if list is NOT empty
if items: 
    print("Processing items...") 

# Checks if list IS empty
if not queue:
    print("Queue is empty")

squares = []

for i in range(11):
    result = i * i
    squares.append(result)

print(squares)

sensor_data = [15, 22, None, 105, 34, None, 9, 110, 45]

#cleaned_data = [x for x in sensor_data if x is not None and 0 <= x <= 100]

cleaned_data = []

for reading in sensor_data:
    if reading is None:
        continue
    if reading > 100:
        continue
    cleaned_data.append(reading)

total_sum = sum(cleaned_data)


print("cleaned data = ",cleaned_data)
print("total sum = ", total_sum)