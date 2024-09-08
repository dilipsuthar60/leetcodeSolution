class Solution:
    def convertDateToBinary(self, date: str) -> str:
        nums=date.split('-')
        result=""
        for num in nums:
            result+=str(bin(int(num)))[2:]+'-'
        return result[:len(result)-1]
            
        