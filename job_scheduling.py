job=[['A',2,100],['B',1,19],['C',2,27],['D',1,25],['E',3,15]]
t=int(input("deadline:"))
def job_sec(job,t):
    n=len(job)
    for i in range (n):
        for j in range (n-1-i):
            if job[j][2]<job[j+1][2]:
                job[j],job[j+1]=job[j+1],job[j]
    result=[False]*t
    sec_job=['-1']*t
    for i in range (len(job)):
        for j in range (min(t-1,job[i][1]-1),-1,-1):
            if result[j] == False:
                result[j]=True
                sec_job[j]=job[i][0]
                break
    print("job sc",sec_job)
job_sec(job,t)
