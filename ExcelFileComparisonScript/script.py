import pandas as pd

def compare_excel_files(file1, file2, output_file):
    # Read the Excel files into pandas DataFrames
    df1 = pd.read_excel(file1)
    df2 = pd.read_excel(file2)

    # Find differences
    comparison_result = pd.concat([df1, df2]).drop_duplicates(keep=False)

    # Check if there are any differences
    if comparison_result.empty:
        print("The two Excel files are identical.")
    else:
        separator = "-----------------------------------------------------------------------------------------------------\n"
        with open(output_file, "w") as f:
            f.write(f"The differences between the two Excel files are:\n\n {separator}")
            # Write each row difference separated by the line
            for _, row in comparison_result.iterrows():
                f.write(row.to_string())
                f.write("\n" + separator)
    print(f"Differences saved to {output_file}")

if __name__ == "__main__":
    # Replace with your file paths
    file1 = r"Path to file 1"
    file2 = r"Path to file 2"
    output_file = r"differences_output.txt"  # Output file path
    
    compare_excel_files(file1, file2, output_file)
