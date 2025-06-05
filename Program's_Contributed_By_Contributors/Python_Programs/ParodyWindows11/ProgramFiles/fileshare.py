import socket
import tkinter
from tkinter import filedialog, messagebox
import os
from cryptography.fernet import Fernet

if os.access("theme_config.txt", os.F_OK):
    with open("theme_config.txt") as read_config:
        config = read_config.read().splitlines()
        THEME_WINDOW_BG, THEME_FOREGROUND = config
else:
    with open("theme_config.txt", "w") as FTR_write_config: #FirstTimeRun_Write_config, full form.
        THEME_WINDOW_BG = "Black"
        THEME_FOREGROUND = "White"
        FTR_write_config.write(f"{THEME_WINDOW_BG}\n{THEME_FOREGROUND}")


def _sendFiles(sender_ip, file_path, dest_port):
        """ send files over the same network
        thepythoncode.com's CODE"""
        #ALERT: thepythoncode.com's CODE! MAY CONTAIN FLAWS WITH THIS CODE
        #Comments from now on in this function is not mine, but from the outside sources. not mine.
        SEPARATOR = "<SEPARATOR>"
        BUFFER_SIZE = 4096
        host = sender_ip
        port = dest_port
        # the name of file we want to send, make sure it exists
        filename = file_path
        # get the file size
        filesize = os.path.getsize(filename)
        s = socket.socket()
        print(f"[+] Connecting to {host}:{port}")
        s.connect((host, port))
        print("[+] Connected.")
        s.send(f"{filename}{SEPARATOR}{filesize}".encode())
        with open(filename, "rb+") as f:
            while True:
                # read the bytes from the file
                bytes_read =  f.read(BUFFER_SIZE)
                if not bytes_read:
                    # file transmitting is done
                    break
                # we use sendall to assure transimission in busy networks
                file_to_send = encryption.encrypt(bytes_read)
                s.sendall(file_to_send)
        messagebox.showinfo("Success", f"Connected and sent to {sender_ip}")

        # close the socket
        s.close()

def _receiveFiles(key, receiver_ip, port=5001):
    """ receive files in the same network (thepythoncode.com's code)"""
    SERVER_HOST = receiver_ip
    SERVER_PORT = port
    # receive 4096 bytes each time
    BUFFER_SIZE = 4096
    SEPARATOR = "<SEPARATOR>"
    s = socket.socket()
    # bind the socket to our local address
    s.bind((SERVER_HOST, SERVER_PORT))
    s.listen(5)
    print(f"[*] Listening as {SERVER_HOST}:{SERVER_PORT}")
    client_socket, address = s.accept()
    # if below code is executed, that means the sender is connected
    print(f"[+] {address} is connected.")
    received = client_socket.recv(BUFFER_SIZE).decode()
    filename, filesize = received.split(SEPARATOR)
    # remove absolute path if there is
    filename = os.path.basename(filename)
    # convert to integer
    filesize = int(filesize)
    with open(filename, "wb+") as f:
        while True:
            # read 1024 bytes from the socket (receive)
            bytes_read = client_socket.recv(BUFFER_SIZE)
            if not bytes_read:
                # nothing is received
                # file transmitting is done
                break
            # write to the file the bytes we just received
            decryptor = Fernet(key=key)
            file_to_receive = decryptor.decrypt(bytes_read).decode(encoding='utf-8')
            f.write(file_to_receive)
    # close the client socket
    client_socket.close()
    # close the server socket
    s.close()

def send_file():

    """ send files GUI, if done neatly, will call the _sendFiles()
    method"""
    global encryption
    key = b'KEYKEYKEY123456123456'
    messagebox.showinfo("Key", f"Key is {key}")
    encryption = Fernet(key)
    def submit_form():
        """ submits the form to _sendFiles()"""
        _sendFiles(ip_address.get(), fileSelect, int(sendThruPort.get()))
    send_file_gui = tkinter.Tk()
    send_file_gui.configure(background=THEME_WINDOW_BG,)
    send_file_gui.title("File transfer form")
    a = tkinter.Label(send_file_gui,
                        text="Enter the IP address of the receiver:->",
                        background=THEME_WINDOW_BG,
                        foreground=THEME_FOREGROUND)
    a.grid(row=0, column=0)
    ip_address = tkinter.Entry(send_file_gui)
    ip_address.grid(row=0, column=1)
    b = tkinter.Label(send_file_gui, text="Enter the port to be sent through.",
                    background=THEME_WINDOW_BG,
                    foreground=THEME_FOREGROUND)
    b.grid(row=1, column=0)
    c = tkinter.Label(send_file_gui,
                        text="Enter the file needed to be sent:->",
                        background=THEME_WINDOW_BG,
                        foreground=THEME_FOREGROUND)
    c.grid(row=2, column=0)
    sendThruPort = tkinter.Entry(send_file_gui)
    sendThruPort.grid(row=1, column=1)

    def fileselector():
        """ file select"""
        global fileSelect
        fileSelect = filedialog.askopenfilename(title="Select files to "
                                                        "send over")
        return fileSelect

    select_files = tkinter.Button(send_file_gui,
                                    text="Select file",
                                    background=THEME_WINDOW_BG,
                                    foreground=THEME_FOREGROUND,
                                    command=fileselector)
    select_files.grid(row=2, column=1)
    submit = tkinter.Button(send_file_gui,
                            text="Submit the form",
                            background=THEME_WINDOW_BG,
                            foreground=THEME_FOREGROUND,
                            command=submit_form)
    submit.grid(row=3, column=0)
    send_file_gui.mainloop()


def recieveFiles():
    """ recieve files that had been sent (using thepythoncode.com's
    code)"""
    def submit_form():
        """ submits the form to _sendFiles()"""
        _receiveFiles(bytes(str(decryption_key), encoding='utf-8'), ip_address.get(), port=int(port.get()))
    recieve_files = tkinter.Tk()
    recieve_files.configure(background=THEME_WINDOW_BG,)
    recieve_files.title("File transfer form")
    a = tkinter.Label(recieve_files,
                        text="Enter the IP address of the receiver:->",
                        background=THEME_WINDOW_BG,
                        foreground=THEME_FOREGROUND)
    a.grid(row=0, column=0)
    ip_address = tkinter.Entry(recieve_files)
    ip_address.grid(row=0, column=1)
    b = tkinter.Label(recieve_files,
                        text="Enter the port:->",
                        background=THEME_WINDOW_BG,
                        foreground=THEME_FOREGROUND)
    b.grid(row=1, column=0)
    port = tkinter.Entry(recieve_files)
    port.grid(row=1, column=1)
    c = tkinter.Label(recieve_files, text="Decryption Key-> ",
    background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
    c.grid(row=2, column=0)
    decryption_key = tkinter.Entry(recieve_files)
    decryption_key.grid(row=2, column=1)
    submit = tkinter.Button(recieve_files,
                            text="Submit the form",
                            background=THEME_WINDOW_BG,
                            foreground=THEME_FOREGROUND,
                            command=submit_form)
    submit.grid(row=3, column=0)
    recieve_files.mainloop()
def main(*args):
    global control_window
    control_window = tkinter.Tk()
    control_window.configure(background=THEME_WINDOW_BG)
    a = tkinter.Label(master=control_window,
                        text="Transfer Files",
                        background=THEME_WINDOW_BG,
                        foreground=THEME_FOREGROUND)
    a.grid(row=0, column=0)
    send_files_btn = tkinter.Button(control_window,
                                text="Send files over local network",
                                background=THEME_WINDOW_BG,
                                foreground=THEME_FOREGROUND,
                                command=send_file)
    send_files_btn.grid(row=0, column=1)
    recieve_files_btn = tkinter.Button(control_window,
                                        text="Read the sent files in the "
                                            "network",
                                        background=THEME_WINDOW_BG,
                                        foreground=THEME_FOREGROUND,
                                        command=recieveFiles)
    recieve_files_btn.grid(row=0, column=2)
    control_window.mainloop()
def focusIn(): control_window.state(newstate='normal'); 
def focusOut(): control_window.state(newstate='iconic'); 