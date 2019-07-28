
#Name:Sanket Badjate
#Roll No:6
#Assignment No:10

import socket

print 'Welcome to DNS to IP Address'


URL=raw_input('Enter URL: ')

addr1 = socket.gethostbyname(URL)

print(addr1)
print 'WelCome IP address to DNS'
IP=raw_input('Enter IP Address: ')
addr6=socket.gethostbyaddr(IP)
print addr6


