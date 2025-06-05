# import EAN13 from barcode module
from barcode import EAN13
  
# Make sure to pass the number as string
number = '5901234123457'
  
# Now, let's create an object of EAN13
# class and pass the number
my_code = EAN13(number)
  
# Our barcode is ready. Let's save it.
my_code.save("new_code")
