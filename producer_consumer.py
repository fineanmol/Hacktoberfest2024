count=0
maxValue=5
mutex=1




def wait():
	global mutex
	if(mutex>=1):
		mutex-=1
		return
	else:
		wait()
	return
def signal():
	global mutex
	mutex+=1
	return
def produce():
	global maxValue,count
	if(count==maxValue):
		print("you cannot produce more....\n")
		return
	else:
		count+=1
	return
def consume():
	global maxValue,count
	if(count==0):
		print("you cannot consume....there is no product...\n")
		return
	else:
		count-=1
	return
def display():
	if(count==0):
		print("nothing is available to consume....no.of items produced => 0 \n")
	else:
		print("consumer can consume ",count," products more\n")
	return



while(1):
	print("1. produce\n2. consume\n3.display\n4. exit\nenter your choice:\n")
	proCons=int(input())
	if(proCons==1):
		wait()
		produce()
		signal()
	elif(proCons==2):
		wait()
		consume()
		signal()
	elif(proCons==3):
		display()
	elif(proCons==4):
		break
	else:
		print("invalid input:\n")
