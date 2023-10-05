# minimum ARPU value
min_arpu = data["ARPU"].min()

# maximum ARPU value
max_arpu = data["ARPU"].max()

# average ARPU value
average_arpu = data["ARPU"].mean()

print(f"Minimum ARPU: {min_arpu}")
print(f"Maximum ARPU: {max_arpu}")
print(f"Average ARPU: {average_arpu}")
