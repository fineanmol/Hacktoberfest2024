#URL SHORTENER COMMAND LINE TOOL
import pyshorteners
import argparse
import sys

shortener=pyshorteners.Shortener()
parser = argparse.ArgumentParser(description="Python Script that shortens a url",usage=f'%(prog)s --url')
parser.add_argument("--url",help="specify a url", metavar="url", dest="url")
parser.add_argument("-v",help="display version",action="version",version='%(prog)s 1.0')
args = parser.parse_args()
if len(sys.argv) == 1:
    parser.print_help(sys.stderr)
    sys.exit(1)
url=args.url
x = shortener.tinyurl.short(url)
print("Your Shortened url: ", x)


