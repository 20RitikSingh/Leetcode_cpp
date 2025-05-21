func removeDuplicates(nums []int) int {
    j:=0
    count:=make([]int,201)
    for _,i:=range nums{
        count[100+i]++
    }
    for i:=range 201{
        if count[i]>0 {
            nums[j]=i-100
            j++
        }
    }
    return j
}