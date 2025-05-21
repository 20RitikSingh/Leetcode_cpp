func reverse(nums []int ,l int,h int){
    for i:=0;i<(h-l)/2;i++{
        nums[i+l]+=nums[h-i-1]
        nums[h-i-1]=nums[i+l]-nums[h-i-1]
        nums[i+l]-=nums[h-i-1]
    }
}
func rotate(nums []int, k int)  {
    k%=len(nums)
    reverse(nums,0,len(nums)-k)
    reverse(nums,len(nums)-k,len(nums))
    reverse(nums,0,len(nums))
}