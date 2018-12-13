class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		/**
		这是一个vector类型的方法，所以返回值也为vector类型，我们先初始化一个vector类型的变量，
		并且在初始化一个map类型来映射vector值以及索引，还是循环vector变量nums，并且求得目标值
		和vector元素之间的差值，在从map中找是否有这样的元素满足差值。map.find(diff) 返回的值一个
		迭代器，我们这里用auto关键值，自动适配类型，并且出了作用域就会被释放，如果迭代器不是指向
		map的尾部就说明找到了。则返回。否则返回空的res变量。
		*/
		std::vector<int> res;
		std::map<int,int> map;
		int diff = 0;
		for (int i = 0; i < nums.size(); i++) {
			diff = target - nums[i];
			auto found = map.find(diff);
			if (found != map.end()) {
				res = {found->second, i};
				return res;
			}
			else{
				map.insert(std::make_pair(nums[i], i))
			}
		}
		return res;
	}
}