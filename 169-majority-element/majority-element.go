func majorityElement(nums []int) int {
    leader,count:=0,0
    for i:=range nums{
        if leader==nums[i]{
            count++
        }else{
            count--
        }
        if count<0 {
            leader=nums[i]
            count=1
        }
    }
    return leader
}