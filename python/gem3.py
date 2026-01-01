def func_name(input_1, input_2):

    return input_1 + input_2
    
print("Function output:", func_name(5, 10))

def update_model(weights, learning_rate = 0.1):
    new_weights = weights - learning_rate

    return new_weights
print("Updated weights:", update_model(0.5))

w = update_model(10)
print("Weights after update:", w)   #use default argument

w = update_model(20, learning_rate = 0.5)  #override default argument
print("Weights after update with custom learning rate:", w)

def evaluate_model(scores, total):
    accuracy = (scores / total) * 100
    passed = accuracy >= 80

    return accuracy, passed   # reurn a tuple automatically

acc, is_passed = evaluate_model(70, 100)
print(acc, is_passed)


def claculate_area(length, width):
    area = length * width
    return area

print("Area:", claculate_area(5, 10))  # 


def normalize_data(raw_pixels):
    clean_pixels = []

    for pixel in raw_pixels:
        if pixel == None or pixel == 0:
            continue
        clean_pixels.append(pixel)

    max_value = max(clean_pixels)

    scaled_pixels = []

    for pixel in clean_pixels:
        scaled_pixels.append(pixel / max_value)

    return scaled_pixels


output = normalize_data([0, 128, None, 255, 64])

print("Normalized pixels:", output)
