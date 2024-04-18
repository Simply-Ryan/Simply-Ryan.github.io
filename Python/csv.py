import csv

fileName = ""

# file = open(fileName, "r")
# Do something
# close(fileName)

with open(fileName, "r") as file:
    # Starts at value[0]
    reader = csv.reader(file)
    # reader = csv.DictReader(file) | Gives you dictionary not list

    # Next row to skip header (only necessary for regular reader)
    next(reader)

    # Loop through rows (row is a list/array)
    for row in reader:
        # print(row[x]) using REGULAR
        # print(row["X"]) using DICTIONARY
