print('\n'.join
 ([''.join
   ([('Hacktober'[(x-y)%8 ]
     if((x*0.05)**2+(y*0.1)**2-1)
      **3-(x*0.05)**2*(y*0.1)
       **3<=0 else' ')
        for x in range(-30,30)])
         for y in range(15,-15,-1)]))
