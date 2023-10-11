import calendar


def print_calendar(year, month):
    """Prints a calendar for the given year and month."""

    print(calendar.month(year, month))

# Get the current year and month.
year = 2023
month = 10

# Print the calendar for the current year and month.
print_calendar(year, month)
