public static void sieve(int n)
{
  boolean[] prime=new boolean[n+1];
  for(int i=0;i<=n;i++)
    prime[i]=true;
  
    for(int i=2;i*i<=n;i++)
    {
      if(prime[i]==true)
      {
        for(int j=i*i;j<=n;j+=i)
        {
          prime[j]=false;
        }
      }
    }
    for(int i=2;i<=n;i++)
    {
      if(prime[i]==true)
      {
        System.out.println(i);
      }
    }
}


   int res = 0;
    boolean[] isPrime = new boolean[n + 1];
    Arrays.fill(isPrime, true);
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            res++;
        }
    }
    return res;
