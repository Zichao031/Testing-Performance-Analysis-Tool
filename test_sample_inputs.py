import subprocess
import os
import time
import matplotlib.pyplot as plt

# Compile the C program
subprocess.run(['gcc', '-o', 'track_time', 'track_time.c'], check=True)

# List of inputs to the C program
inputs = [
    ['1', '2'],
    ['12', '11'],
    ['123', '123'],
    ['1234', '100'],
]

execution_times = {}

# Run the compiled C program with each input and store the execution time
for input_args in inputs:
    start = time.time()
    proc = subprocess.run(['./track_time'] + input_args, capture_output=True, text=True)
    end = time.time()

    # Get the execution time from the output
    execution_time = float(proc.stdout.strip())
    execution_times[', '.join(input_args)] = execution_time

# Remove the C source and executable files
os.remove('track_time')

# Print the execution times
for args, time_taken in execution_times.items():
    print(f'Input: {args} - Execution Time: {time_taken} seconds')


# Extract the input arguments as labels and the execution times as values
input_labels = list(execution_times.keys())
execution_time_values = list(execution_times.values())

# Plot the execution times
plt.figure(figsize=(10, 6))
plt.bar(input_labels, execution_time_values, color='skyblue')

plt.title('Execution Time Distribution for Different Inputs')
plt.xlabel('Input')
plt.ylabel('Execution Time (seconds)')
plt.xticks(rotation=45)
plt.tight_layout()

# Display the plot
plt.show()




# # Normalize the histogram, so the sum of the bin heights is equal to 1 to represent probability
# plt.figure(figsize=(10, 6))
# n, bins, patches = plt.hist(execution_time_values, bins=10, color='skyblue', alpha=0.7, density=True)

# plt.title('Probability Distribution of Execution Times')
# plt.xlabel('Execution Time (seconds)')
# plt.ylabel('Probability')

# # Annotate the bin heights (probabilities) on the histogram
# for i in range(len(patches)):
#     plt.text(patches[i].xy[0], patches[i].get_height(), f'{patches[i].get_height():.2f}', ha='center', va='bottom')

# plt.tight_layout()  # Adjust layout to fit everything nicely
# plt.show()