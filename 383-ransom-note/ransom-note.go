func canConstruct(ransomNote string, magazine string) bool {
    mp:=make(map[rune]int) 
    for _,ch:= range magazine{
        mp[ch]++
    }
    for _,ch:=range ransomNote{
        if mp[ch]<1{
            return false
        }
        mp[ch]--
    }
    return true
}