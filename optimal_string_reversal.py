def revOptimal(inData):
	s = ""
  #if string length is even.
	for i in range((len(inData))//2):
    #if string length is odd.
		s = s[:len(s)//2] + inData[(len(inData)-1)-i] + inData[i] + s[len(s)//2:]
	if(len(inData) % 2) != 0:
    #if string length is even.
		s = s[:len(s)//2] + inData[len(inData)//2] + s[len(s)//2:]
	return s