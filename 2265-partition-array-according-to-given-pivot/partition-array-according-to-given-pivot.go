func pivotArray(nums []int, pivot int) []int {
    var res []int
    var high []int
    var c int;
    for i:=0;i<len(nums);i++ {
        if nums[i]<pivot{ 
            res=append(res,nums[i])
        }
        if nums[i]==pivot { 
            c++
        }
        if nums[i]>pivot { 
            high=append(high,nums[i])
        }
    }
    for ;c>0;c-- {
        res=append(res,pivot)
    }
    res=append(res,high...)
    return res 
}