import subprocess
import os
import time


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
