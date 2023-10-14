import tkinter
from socket import AF_INET, socket, SOCK_STREAM
from threading import Thread
from ProgramFiles.errorHandler import messagebox
import shelve
THEME_WINDOW_BG, THEME_FOREGROUND = open("theme_config.txt").read().split("\n")
def receive():
    """Handles receiving of messages."""
    while True:
        try:
            msg = client_socket.recv(BUFSIZ).decode("utf8")
            msg_list.insert(tkinter.END, msg)
        except OSError:  # Possibly client has left the chat.
            break


def send(event=None):  # event is passed by binders.
    """Handles sending of messages."""
    msg = my_msg.get() 
    client_socket.send(bytes(msg, "utf8"))
    my_msg.set("") # Clears input field.
    if msg == "{quit}":
        client_socket.close()
        top.destroy()


def on_closing(event=None):
    """This function is to be called when the window is closed."""
    try:
        my_msg.set("{quit}")
        send()
    except Exception as PROBLEM:
        messagebox.showerror("Program Can't Close!", f"<<DEBUG: {PROBLEM}>>\nThe chatter app cannot close the normal way (ie, saying 'leaving chat' automatically) due to error\nSo, program is force quitting... ")
        top.destroy()
def configureServer(event=None):
    def configureS(e=None):
        global HOST
        global PORT
        HOST = ipAddressEntry.get()
        PORT = int(portEntry.get())
        with shelve.open("ProgramFiles/IPChat/_serverConfig") as writeServerConfig:
            writeServerConfig['0'] = ipAddressEntry.get()
            writeServerConfig['1'] = int(portEntry.get())
        print("Getting there")
        with shelve.open("ProgramFiles/IPChat/serversList") as updateList:
            print("Came to the writing part")
            updateList[ipAddressEntry.get()] = int(portEntry.get())
            print(updateList[ipAddressEntry.get()])
            print("IT WORKS")
        try:
            global client_socket
            client_socket.close()
        except Exception: pass
        else:
            ADDR = (HOST, PORT)
            client_socket = socket(AF_INET, SOCK_STREAM)
            client_socket.connect(ADDR)

    serverConfWn = tkinter.Toplevel(background=THEME_WINDOW_BG)
    tkinter.Label(serverConfWn, text="Configure IP Address", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND).grid(row=0, column=0)
    ipAddressEntry = tkinter.Entry(serverConfWn, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
    ipAddressEntry.grid(row=0, column=1)
    ipAddressEntry.configure(insertbackground=THEME_FOREGROUND, selectbackground=THEME_FOREGROUND, selectforeground=THEME_WINDOW_BG)
    tkinter.Label(serverConfWn, text="Configure port", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND).grid(row=1, column=0)
    portEntry = tkinter.Entry(serverConfWn, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
    portEntry.grid(row=1, column=1)
    portEntry.configure(insertbackground=THEME_FOREGROUND, selectbackground=THEME_FOREGROUND, selectforeground=THEME_WINDOW_BG)
    submitButton = tkinter.Button(serverConfWn, text="Submit", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=configureS)
    submitButton.grid(row=2, column=1)
    serverConfWn.mainloop()
def getServerList(e=None):
    def connect(e=None):
        try:
            global client_socket
            client_socket.close()
        except Exception:
            messagebox.showerror("Can't connect", f"Cannot connect to {serverListLB.get(tkinter.ANCHOR)} at port {servers[serverListLB.get(tkinter.ANCHOR)]} due to error!")
        else:
            ADDR = (serverListLB.get(tkinter.ANCHOR), servers[serverListLB.get(tkinter.ANCHOR)])
            client_socket = socket(AF_INET, SOCK_STREAM)
            client_socket.connect(ADDR)
    serverListWn = tkinter.Toplevel(background=THEME_WINDOW_BG)
    serverListLB = tkinter.Listbox(serverListWn, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
    serverListLB.pack()
    with shelve.open("ProgramFiles/IPChat/serversList") as serversStored:
        global servers
        servers = serversStored
        print(serversStored)
        for server in serversStored.keys():
            print(server)
            serverListLB.insert(tkinter.END, server)
    serverListLB.bind("<<ListboxSelect>>", connect)
    serverListWn.mainloop()

def main(*args):
    global my_msg
    global msg_list
    global BUFSIZ
    global top
    top = tkinter.Toplevel(background=THEME_WINDOW_BG)
    top.title("Chatter")
    altMenu = tkinter.Menu(top, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
    top.configure(menu=altMenu)
    fileMenu = tkinter.Menu(altMenu, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
    fileMenu.add_command(label="Configure Server", command=configureServer)
    fileMenu.add_command(label="Previously connected servers", command=getServerList)
    altMenu.add_cascade(label="File", menu=fileMenu)
    messages_frame = tkinter.Frame(top, background=THEME_WINDOW_BG)
    my_msg = tkinter.StringVar()  # For the messages to be sent.
    my_msg.set("Type your messages here.")
    scrollbar = tkinter.Scrollbar(messages_frame)  # To navigate through past messages.
    # Following will contain the messages.
    msg_list = tkinter.Listbox(messages_frame, height=20, width=90, yscrollcommand=scrollbar.set, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
    scrollbar.pack(side=tkinter.RIGHT, fill=tkinter.Y)
    msg_list.pack(side=tkinter.LEFT, fill=tkinter.BOTH)
    msg_list.pack()
    messages_frame.pack()

    entry_field = tkinter.Entry(top, textvariable=my_msg, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, width=90)
    entry_field.configure(insertbackground=THEME_FOREGROUND, selectbackground=THEME_FOREGROUND, selectforeground=THEME_WINDOW_BG)
    entry_field.bind("<Return>", send)
    entry_field.pack()
    send_button = tkinter.Button(top, text="Send", command=send, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
    send_button.pack()

    top.protocol("WM_DELETE_WINDOW", on_closing)

    #----Now comes the sockets part----
    with shelve.open("ProgramFiles/IPChat/_serverConfig") as _serverConfig:
        HOST = _serverConfig['0']
        PORT = _serverConfig['1']

    BUFSIZ = 1024
    ADDR = (HOST, PORT)
    try:
        client_socket = socket(AF_INET, SOCK_STREAM)
        client_socket.connect(ADDR)
    except Exception as problem:
        messagebox.showerror("Error connecting to server", f"Error connecting to server '{HOST}' at port '{PORT}'\n"
        "This may be due to a configuration error, or the failure to add a server. Please reconfigure!")

    receive_thread = Thread(target=receive)
    receive_thread.start()
    top.mainloop()
def focusIn(): top.state(newstate='normal'); 
def focusOut(): top.state(newstate='iconic'); 