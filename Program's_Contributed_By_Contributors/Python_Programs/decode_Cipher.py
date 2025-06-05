transcript_recieved="zm fmrwvmgrurvw lyqvxg rh hvvm mvzi lfi kozmvg.grv lyqvxg rh gibrmt gl ozmw.dszg gl wl? ovg gsv lyqvxg ozmw ru rg rh uzi uiln zmb rmhgzoozgrlm"
Decoded_message    ="an unidentified object is seen near our planet.the object is trying to land.what to do? let the object land if it is far from any installation"
# now decode this trasncripted message
message= "svool sld rh vevibgsrmt"
#make dictionary bi directional
def dictionary(transcripted_message,decoded_message):
    dict={}
    for i in range(len(transcripted_message)):
        dict[transcripted_message[i]]=decoded_message[i]
        #return dict in lower case
    return dict
d1=dictionary(transcript_recieved,Decoded_message)
d2=dictionary(Decoded_message,transcript_recieved)
d1.update(d2)
d1


#print values of key by using message
def print_message(message,d1):
    for i in message:
        print(d1[i],end="")
print_message(message,d1)