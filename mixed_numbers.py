import random

# Generate random numbers
numbers = random.sample(range(-2147483646, 2147483646), 100)

# Shuffle the list
random.shuffle(numbers)

# Print the shuffled numbers
print(*numbers)

# -2147483646, 2147483646