#!/usr/bin/env python3

import argparse
import queue
import threading
import requests

# ANSI escape codes for colors
YELLOW = "\033[38;2;255;241;0m"
GREEN = "\033[38;2;0;255;0m"
RESET = "\033[0m"

print(f"{YELLOW}   _____ ____   _____ _____  _               _                   ")
print(f"  / ____|  _ \ / ____|  __ \(_)             | |                  ")
print(f" | (___ | |_) | (___ | |  | |_ _ __ ___  ___| |_ ___  _ __ _   _ ")
print(f"  \___ \|  _ < \___ \| |  | | | '__/ _ \/ __| __/ _ \| '__| | | |")
print(f"  ____) | |_) |____) | |__| | | | |  __/ (__| || (_) | |  | |_| |")
print(f" |_____/|____/|_____/|_____/|_|_|  \___|\___|\__\___/|_|   \__, |")
print(f"                                                            __/ |")
print(f"                                                           |___/ ")
print("-By ShortBus Security")
print(RESET)

found_urls = set()


def get_arguments():
    parser = argparse.ArgumentParser(description="Simple directory bruteforcer")

    parser.add_argument("url", help="Target URL")
    parser.add_argument("-w", "--wordlist", dest="wordlist", metavar="", default="/usr/share/wordlists/dirb/common.txt",
                        help="Path to wordlist (default: %(default)s)")
    parser.add_argument("-x", "--extensions", dest="extensions", metavar="", default="",
                        help="Comma-separated list of file extensions to check (default: all)")
    parser.add_argument("-t", "--threads", dest="threads", metavar="", default=10, type=int,
                        help="Number of threads (default: %(default)s)")

    return parser.parse_args()


def worker(q):
    while True:
        try:
            directory = q.get()
            url = f"{args.url}/{directory}"
            if args.extensions:
                for ext in args.extensions.split(","):
                    url_with_ext = f"{url}.{ext}"
                    response = requests.get(url_with_ext, timeout=5)
                    if response.status_code != 404:
                        found_urls.add(url_with_ext)
                        print(f"{GREEN}[+] Found {url_with_ext}{RESET}")
                        break
            else:
                response = requests.get(url, timeout=5)
                if response.status_code != 404:
                    found_urls.add(url)
                    print(f"{GREEN}[+] Found {url}{RESET}")
        except requests.exceptions.RequestException:
            pass
        finally:
            q.task_done()


def main():
    q = queue.Queue()
    with open(args.wordlist, "r") as f:
        for directory in f.readlines():
            q.put(directory.strip())

    for i in range(args.threads):
        t = threading.Thread(target=worker, args=(q,))
        t.daemon = True
        t.start()

    q.join()

    #for url in found_urls:
        #print(f"Scan Complete")


if __name__ == "__main__":
    args = get_arguments()
    main()
    
print(f"{YELLOW}___________________")
print(f"|,-----.,-----.,---.\\")
print(f"||     ||     ||    \\")
print(f"|`-----'|-----||-----\`----.")
print(f"[       |    -||-   _|    (|")
print(f"[  ,--. |_____||___/.--.   |")
print(f"=-(( `))-----------(( `))-==")
print(f"   `--'             `--'")
print(f"{YELLOW}Your Bus Has Arrived! Beep Beep!{RESET}")
print(RESET)
