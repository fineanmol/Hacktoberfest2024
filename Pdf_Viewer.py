import tkinter as tk
from tkinter import filedialog
import fitz  # PyMuPDF

class PDFViewer(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("PDF Viewer")
        self.geometry("800x600")

        self.canvas = tk.Canvas(self, bg="white")
        self.canvas.pack(fill="both", expand=True)

        self.menu = tk.Menu(self)
        self.config(menu=self.menu)

        self.file_menu = tk.Menu(self.menu)
        self.menu.add_cascade(label="File", menu=self.file_menu)
        self.file_menu.add_command(label="Open", command=self.open_file)

    def open_file(self):
        file_path = filedialog.askopenfilename(defaultextension=".pdf", filetypes=[("PDF Files", "*.pdf")])
        if file_path:
            self.show_pdf(file_path)

    def show_pdf(self, file_path):
        self.canvas.delete("all")
        doc = fitz.open(file_path)
        page = doc.load_page(0)
        pix = page.get_pixmap()
        img_data = pix.tobytes("ppm")

        self.img = tk.PhotoImage(data=img_data)
        self.canvas.create_image(0, 0, anchor="nw", image=self.img)
        self.canvas.config(scrollregion=self.canvas.bbox(tk.ALL))

if __name__ == "__main__":
    app = PDFViewer()
    app.mainloop()
