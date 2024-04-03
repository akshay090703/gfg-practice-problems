#User function Template for python3

class Solution:
    #Function to return list containing first n fibonacci numbers.
    def printFibb(self,n):
        ans = []
        
        ans.append(1)
        if(n == 1):
            return ans
        
        ans.append(1)
        n -= 2
        while n > 0:
            ans.append(ans[-1] + ans[-2]);
            n -= 1
            
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__': 
    t=int(input())
    for tcs in range(t):
        
        n=int(input())
        res = Solution().printFibb(n)
        for i in range (len(res)):
            print (res[i], end = " ") 
        print()
# } Driver Code Ends