import threading,socket,argparse
from sys import exit
from queue import Queue

lock = threading.Lock()
q = Queue()

parser=argparse.ArgumentParser()
group=parser.add_mutually_exclusive_group()

group.add_argument("-i", "--ip", help="Target's ip", action="store")
group.add_argument("-d", "--domain", help="Target's domain name", action="store")
parser.add_argument("-p", "--port", help="Target ports' number interval", action="store", nargs="*", type=int)
parser.add_argument("-t", "--thread", help="How many threads do you want to use?", action="store", default=4, type=int)
args = parser.parse_args()

# --------------------------------------

if args.ip:
    target = args.ip
if args.domain:
    target = socket.gethostbyname(args.domain)
if args.port:
    min_port = args.port[0]
    max_port = args.port[1]
if args.thread:
    number_of_threads = args.thread


def main():

    range_to_scan(min_port, max_port)
    create_thread(target,number_of_threads)
    q.join()


def scan(target,port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    con = s.connect_ex((target, port))
    try:
        if (con==0):
            with lock:
                print('[+] Port--> {}'.format(port))
            s.close()
    except:
        pass
def range_to_scan(min_port=1, max_port=1000):
    if (min_port <= 0):
        print("Minimum port number must be larger than 0")
        exit(1)
    for worker in range(min_port, max_port):
        q.put(worker)

def create_thread(target,number_of_threads=4):
    for x in range(number_of_threads):
        t = threading.Thread(target=threader,args=(target,),daemon=True)
        t.start()

def threader(target):
    while True:
        worker = q.get()
        scan(target,worker)
        q.task_done()


if __name__=="__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("Interrupted..")
        exit(1)
