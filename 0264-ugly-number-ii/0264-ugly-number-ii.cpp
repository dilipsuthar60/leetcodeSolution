class Solution {
public:
    int nthUglyNumber(int n) 
    {
      if(n==1)
        return 1;
      int p2,p3,p5;
      p2=p3=p5=0;
      int a[n];
      a[0]=1;
      for(int i=1;i<n;i++)
      {
        a[i]=min(a[p2]*2,min(a[p3]*3,a[p5]*5));
        if(a[i]==a[p2]*2)
          p2++;
        if(a[i]==a[p3]*3)
          p3++;
        if(a[i]==a[p5]*5)
          p5++;
      }
      return a[n-1];
    }
};