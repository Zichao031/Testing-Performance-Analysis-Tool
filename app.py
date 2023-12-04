import subprocess
import os
import re
import time
import random
import matplotlib.pyplot as plt
from collections import defaultdict
from generate_inputs import generate_inputs
def get_usage_profile(inputs):
    """ Output the paths and assign random probability for them """
    inputs_size = len(inputs)
    probabilities = [random.random() for _ in range(inputs_size)]

    # Normalize probabilities to ensure they sum up to 1
    total = sum(probabilities)
    probabilities = [p / total for p in probabilities]
    return list(zip(inputs, probabilities))


def app(path):
    # Compile the C program
    subprocess.run(['gcc', os.path.join(path, 'track_time.c'), '-o', os.path.join(path, 'track_time')], check=True)

    # List of sample inputs to the C program
    all_inputs = []
    num_iterations = 2  # Set this to the number of times you want to run generate_inputs

    for _ in range(num_iterations):
        inputs = generate_inputs(path)
        all_inputs.append(inputs)
    print(f"\nGenerated inputs size: {len(all_inputs)}")
    """ Output the paths and assign random probability for them """

    inputs =  get_usage_profile(inputs)
    print("\nUsage Profile: ")
    print(inputs)
    execution_times = defaultdict(list)

    # Run the compiled C program with each input and store the execution time
    for inputs in all_inputs:
        for input_args in inputs:
            start = time.time()
            proc = subprocess.run([os.path.join(path, 'track_time')] + input_args, capture_output=True, text=True)
            end = time.time()

            # Get the execution time from the output
            output = proc.stdout.strip()
            match = re.search(r'Execution Time:\s*([\d.]+)', output)
            if match:
                # Extract the number and convert it to float
                execution_time = float(match.group(1))
                execution_times[', '.join(input_args)].append(execution_time)

    # Remove the C source and executable files
    os.remove(os.path.join(path, 'track_time'))

    # Print the execution times
    print('\nExexution time records: ')
    average_execution_times = {}
    for args, all_time_taken in execution_times.items():
        num_input = len(all_time_taken)
        total_time = 0
        for time_taken in all_time_taken:
            total_time += time_taken
            print(f'Input: {args} - Execution Time: {time_taken} seconds')
        average_time = total_time / num_input
        average_execution_times[args] = average_time
        print(f'Input: {args} - Average Execution Time: {average_time} seconds')

    # Extract the input arguments as labels and the execution times as values
    input_labels = list(average_execution_times.keys())
    execution_time_values = list(average_execution_times.values())

for root, dirs, files in os.walk('.'):  # Starts in the current directory
    for dir_name in dirs:
        if dir_name.startswith('p'):
            dir_path = os.path.join(root, dir_name)
            if 'program.c' in os.listdir(dir_path):
                app(dir_path)