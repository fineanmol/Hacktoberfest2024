import tkinter as tk

class WeightConverterApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Weight Converter")

        self.create_widgets()

    def create_widgets(self):
        # Input Label and Entry
        self.input_label = tk.Label(self.root, text="Input the weight in KG")
        self.input_label.grid(row=0, column=0)

        self.e2_value = tk.StringVar()
        self.input_entry = tk.Entry(self.root, textvariable=self.e2_value)
        self.input_entry.grid(row=0, column=1)

        # Conversion Labels
        conversion_units = ["Gram", "Pound", "Ounce", "Stone", "US Ton"]
        for i, unit in enumerate(conversion_units):
            tk.Label(self.root, text=unit).grid(row=1, column=i)

        # Result Text Boxes
        self.result_texts = []
        for i in range(len(conversion_units)):
            t = tk.Text(self.root, height=5, width=30)
            t.grid(row=2, column=i)
            self.result_texts.append(t)

        # Convert Button
        self.convert_button = tk.Button(self.root, text="Convert", command=self.from_kg)
        self.convert_button.grid(row=0, column=2)

    def from_kg(self):
        kg_value = float(self.e2_value.get())
        conversions = [kg_value * factor for factor in [1000, 2.20462, 35.274, 0.157473, 0.00110231]]

        for i, t in enumerate(self.result_texts):
            t.delete("1.0", tk.END)
            t.insert(tk.END, conversions[i])

def main():
    root = tk.Tk()
    app = WeightConverterApp(root)
    root.mainloop()

if __name__ == "__main__":
    main()
