https://leetcode.com/problems/two-sum/
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int ans[]= new int[2];
        int n=nums.length;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    ans[0]=i;ans[1]=j;
                }
            }
        }
        return ans;
    }
}


https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length ;
        for(int i=2 ; i<n ; i++){
            cost[i] = Math.min(cost[i-1] , cost[i-2]) + cost[i];
        }
        return Math.min(cost[n-1] , cost[n-2]);
    }
}

https://leetcode.com/problems/counting-bits/
class Solution {
    public int[] countBits(int n) {
        int count = 0;
        int[] arr = new int[n+1];

        for(int i=0; i<=n; i++){
            if(i == 0){
                arr[i] = 0;
            }
            count = 0;
            String str = Integer.toBinaryString(i);
            for(int j=0;j<str.length();j++){
                if(str.charAt(j) == '1'){
                    count++;
                }
            }
            arr[i]=count;
        }
        return arr;    
    }
}

leetcode.com/problems/invert-binary-tree/
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
   
    struct TreeNode* invert = root;
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    int top = -1;

    while (top >= 0 || root != NULL) {
        if (root != NULL) {
            stack[++top] = root;
            struct TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            root = root->left;
        } else {
            root = stack[top--];
            root = root->right;
        }
    }
   
    free(stack);
    return invert;
}

int height(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    } else {
        return false;
    }
}

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

class Solution {
    int value(char r)  
  {  
    if (r == 'I')  
      return 1;  
    if (r == 'V')  
      return 5;  
    if (r == 'X')  
      return 10;  
    if (r == 'L')  
      return 50;  
    if (r == 'C')  
      return 100;  
    if (r == 'D')  
      return 500;  
    if (r == 'M')  
      return 1000;  
    return -1;  
  }  
  public int romanToInt(String s) {  
  {  
    int total = 0;  
    for (int i=0; i<s.length(); i++)  
    {  
      int s1 = value(s.charAt(i));  
      if (i+1 <s.length())  
      {  
        int s2 = value(s.charAt(i+1));  
        if (s1 >= s2)  
        {  
          total = total + s1;  
        }  
        else  
        {    
          total = total - s1;  
        }  
      }  
      else  
      {  
        total = total + s1;  
      }  
    }  
    return total;  
  }  
    }
}
