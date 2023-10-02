from netaddr import *
import ipaddress
import pandas
from tabulate import tabulate
import re


print("Enter your IP-subnet address in CIDR format : ")
str = input()

ifc = ipaddress.IPv4Interface(str)
ip = ifc.ip
network = ifc.network
netmask = ifc.netmask


class MyIPv4(ipaddress.IPv4Address):

    @property
    def binary_repr(self, sep=".") -> str:
        """Represent IPv4 as 4 blocks of 8 bits."""

        return sep.join(f"{i:08b}" for i in self.packed)

    @classmethod
    def from_binary_repr(cls, binary_repr: str):
        """Construct IPv4 from binary representation."""

        # Remove anything that's not a 0 or 1

        i = int(re.sub(r"[^01]", "", binary_repr), 2)

        return cls(i)

def binary(num):
  '''returns the binary representation of an IP address'''
  return MyIPv4(num).binary_repr


def IP(ifc):
    '''returns the ip of the user'''
    ip = ifc.ip
    return ip


def CIDR(str):
    '''returns the number of number of subnet bits. e.g. 24 in 192.0.2.0/24'''
    cidr = str[-3:]
    return cidr


def subnet_mask(ifc):
    '''returns the subnet-mask of the user-input'''
    mask = ifc.netmask
    return mask


def broadcast(str):
    '''returns the broadcast address of the user-input'''
    ip = IPNetwork(str)
    bca = ip.broadcast
    return bca


def network(ifc):
    '''returns the broadcast address of the user-input'''
    nw = ifc.network
    return nw


def hosts(str):
    '''returns available user_count'''
    lis = list(ipaddress.ip_network(str).hosts())
    av_hosts = len(lis)
    total_hosts = av_hosts + 2
    return total_hosts, av_hosts, lis[0], lis[av_hosts-1]


def IPClass(str):
    '''returns the class of the IP'''
    dot_index = str.find('.')
    s = int(str[:dot_index])
    if s <= 127:
        return "A"
    if s >= 128 and s <= 191:
        return "B"
    if s >= 192 and s <= 223:
        return "C"
    if s >= 224 and s <= 239:
        return "D"
    if s >= 240:
        return "E"


def print_table(string, user_ip, mask, bin_mask, max_nets, net_id, broadcast_add, total_hosts, av_hosts, f_host, l_host, cidr, ip_class):
    '''prints the data in tabulated format'''

    data = {
        'Attribute': ['IP-subnet', 'IP-address', 'subnet-mask', 'Binary subnet mask', 'Maximum Subnets','Network', 'Broadcast', 'Total hosts', 'Available hosts', 'First host', 'Last host', 'CIDR Notation', 'IP Class'],
        'Value': [string, user_ip, mask, bin_mask, max_nets, net_id, broadcast_add, total_hosts, av_hosts, f_host, l_host, cidr, ip_class]
    }

    df = pandas.DataFrame(data)
    print(tabulate(df, headers='keys', tablefmt='fancy_grid'))
    

def max_subnets(x):
    '''returns the maximum number of subnets possible on the network'''
    x = int(x)
    count = 2**(x-8)
    return count
    

user_ip = IP(ifc)

mask = subnet_mask(ifc)

net_id = network(ifc)

broadcast_add = broadcast(str)

total_hosts, av_hosts, f_host, l_host = hosts(net_id)

cidr_notation = CIDR(str)

ip_class = IPClass(str)

bin_mask = binary(mask)

max_nets = max_subnets(cidr_notation[1:])


# print the table
print_table(str, user_ip, mask, bin_mask, max_nets, net_id, broadcast_add,
            total_hosts, av_hosts, f_host, l_host, cidr_notation, ip_class)
