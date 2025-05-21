func merge(nums1 []int, m int, nums2 []int, n int)  {
    i,j:=0,0
    var tmp []int
    for i<m && j<n{
        if nums1[i]<nums2[j]{
            tmp=append(tmp,nums1[i])
            i++
        }else{
            tmp=append(tmp,nums2[j])
            j++
        }
    }
    if i<m {
        for ;i<m;i++{
            tmp=append(tmp,nums1[i])
        }
    }else{
        for ;j<n;j++{
            tmp=append(tmp,nums2[j])
        }
    }
    copy(nums1,tmp)
}