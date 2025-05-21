func removeElement(nums []int, val int) int {
    c,i,j:=0,0,len(nums)-1
    for i<j{
        if nums[j]==val{
            c++
            j--
            continue
        }
        if nums[i]==val{
            nums[i]=nums[j]
            c++
            j--
        }
        i++
    }
    if i<len(nums) && nums[i]==val{
        c++
    }
    return len(nums)-c
}