class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        """
            c++中可以用map来映射vector中的值以及索引
            但是在python中，map只有循环赋值，这样的话，时间复杂度必定很高，
            因此python使用字典类型来替代map。这时候我们可能会考虑到dict类型
            的特性，键的唯一性，如果原列表中出现多次重复的元素怎么办，替代后是否
            会出现bug等，我们可以自己先找个例子验证一下会发现即使替代了，也不影响结果
            这里return 的值 i 在后，脑子里过一遍发现确实是这样。比如3，3 target 为 6
            这里的例子，第一次循环，dict为空，因此插入3:0 。第二次循环，diff为3
            i = 1， 因此diff in di 并且索引为0， 所以返回 0，1
        """
        # create a type of dict
        di = dict()
        # loop the list of nums to caculate the difference between target and element of nums
        for i in range(len(nums)):
            diff = target - nums[i]
            # if diff in the dict of di, we will get its index
            if diff in di:
                return [di[diff], i]
            else:
                di[nums[i]] = i
        # if not return 0
        return 0