func majorityElement(nums []int) int {
    n:=len(nums)
    slices.Sort(nums)
    i,j:=0,n/2
    for j<n{
        if nums[i]==nums[j]{
            return nums[i]
        }
        i++
        j++
    }
    return nums[0]
}