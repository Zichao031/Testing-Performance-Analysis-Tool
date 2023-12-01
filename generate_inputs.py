import subprocess
import os

def run_command(command):
    """ Run a shell command and return its output """
    result = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    if result.returncode != 0:
        raise RuntimeError(f"Error running command '{command}': {result.stderr}")
    return result.stdout

def compile_to_bc(source_file, bc_file):
    """ Compile a C program to LLVM bitcode """
    run_command(f"clang -emit-llvm -c -g {source_file} -o {bc_file}")

def run_klee(bc_file):
    """ Run KLEE on a bitcode file """
    run_command(f"klee {bc_file}")

def parse_ktest_output(output):
    """ Parse the output of ktest-tool into a dictionary """
    lines = output.split('\n')
    data_dict = {}
    current_object = 0
    for line in lines:
        # num objects: 2
        if line.startswith('num objects:'):
            object_number = int(line.split(':')[1])

        if line.startswith(f'object {current_object}: int :'):
            parts = line.split('int :')
            key = parts[0].strip()
            value = parts[1].strip()
            data_dict[key] = value
            current_object += 1
    return data_dict

def generate_inputs(path):
    source_file = os.path.join(path, 'program.c')
    bc_file = os.path.join(path, 'program.bc')
    klee_last_dir = os.path.join(path, 'klee-last')

    # Compile the C program to bitcode
    compile_to_bc(source_file, bc_file)

    # Run KLEE on the bitcode
    run_klee(bc_file)

    # Ensure klee-last directory exists
    if not os.path.isdir(klee_last_dir):
        print("klee-last directory not found.")
        return

    # Process each ktest file
    all_data = {}
    for filename in os.listdir(klee_last_dir):
        if filename.endswith('.ktest'):
            ktest_file = os.path.join(klee_last_dir, filename)
            output = run_command(f"ktest-tool {ktest_file}")
            data_dict = parse_ktest_output(output)
            all_data[filename] = data_dict

    # Print all data
    print("\nSuccessfully generated inputs for each path! The inputs shows below: ")
    print(all_data)

    inputs = []
    for key in sorted(all_data.keys()):  # Sorting keys to maintain order
        values = list(all_data[key].values())
        inputs.append(values)

    print(inputs)
    return inputs
