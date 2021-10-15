stats = {'a': 1000, 'b': 3000, 'c': 100}

print(max(stats, key=stats.get))  # Finds the highest value and returns its key
print(max(stats.values()))  # Returns the highest value
print(max(stats.keys()))  # Returns the highest key
print(max(stats.items()))  # Returns the highest key, along with its value (as a tuple)
print(max(stats))  # Returns the highest key
