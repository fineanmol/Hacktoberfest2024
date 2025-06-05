import tkinter as tk
from tkinter import ttk
import calendar
from tkinter import messagebox

class CalendarApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Calendar App")
        self.root.geometry("300x300")
        
        # Year label and entry
        self.year_label = ttk.Label(root, text="Enter Year:")
        self.year_label.pack(pady=10)
        
        self.year_entry = ttk.Entry(root)
        self.year_entry.pack(pady=10)
        
        # Month label and entry
        self.month_label = ttk.Label(root, text="Enter Month (1-12):")
        self.month_label.pack(pady=10)
        
        self.month_entry = ttk.Entry(root)
        self.month_entry.pack(pady=10)
        
        # Button to show calendar
        self.show_button = ttk.Button(root, text="Show Calendar", command=self.show_calendar)
        self.show_button.pack(pady=20)
        
        # Text widget to display the calendar
        self.calendar_display = tk.Text(root, width=25, height=8)
        self.calendar_display.pack(pady=10)
    
    def show_calendar(self):
        try:
            year = int(self.year_entry.get())
            month = int(self.month_entry.get())
            
            if month < 1 or month > 12:
                raise ValueError("Month must be between 1 and 12")
            
            cal = calendar.month(year, month)
            self.calendar_display.delete(1.0, tk.END)
            self.calendar_display.insert(tk.END, cal)
        except ValueError as e:
            messagebox.showerror("Error", f"Invalid input: {e}")

if __name__ == "__main__":
    root = tk.Tk()
    app = CalendarApp(root)
    root.mainloop()
