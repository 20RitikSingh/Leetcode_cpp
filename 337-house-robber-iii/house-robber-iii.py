class Solution:
    @cache
    def rob(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        x=root.val
        if root.left != None :
            x+=self.rob(root.left.left)+self.rob(root.left.right)
        if root.right != None :
            x+=self.rob(root.right.left)+self.rob(root.right.right)
        return max(x,self.rob(root.left)+self.rob(root.right))