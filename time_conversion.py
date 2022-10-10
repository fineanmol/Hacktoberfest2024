def time_conversion(time: str)-> str:
  
  arr = int(time[:2]) + 12
  
    if time[8:] == 'PM':
      if time[:2] == '12':
        return '12' + time[2:8]
      
      else:
        return str(arr) + time[2:8]
      
    else:
      if time[:2] == '12':
        return '00' + time[2:8]
      
      return time[:8]
    
print(time_conversion("07:05:45PM"))
