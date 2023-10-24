#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> nums;
    nums.push_back(0);

    for(int i=1; i<=10; i++){
        nums.push_back(i);
    }

    // for(int n : nums){
    //     cout << n << endl;
    // }

    // for(auto it = nums.begin(); it != nums.end(); it++ ){
    //     cout << *it << endl;
    //     cout << &it << endl;
    //     cout << &(*it) << endl;
    // }

    auto it = nums.begin();
    cout << *(it + 5)<< endl;

    // for(auto it = nums.cbegin(); it!= nums.cend(); it++){     // cbegin and cend is used for read only 
    //     *it= 20;
    //     cout << *it << endl;
    // }
    cout << "Size:" <<  nums.size() <<  endl;
    cout << "Max Size:" <<  nums.max_size() <<  endl;
    cout << "Capacity:" <<  nums.capacity() <<  endl;
    nums.resize(5);
    cout << "Size:" <<  nums.size() <<  endl;
    if (nums.empty())
    {
        cout << "Vector is empty" << endl;
    }else{
        cout << "Vector is not empty" << endl;
    }
    cout << "Element [0]:" <<  nums[0] <<  endl;
    cout << "Element at(0) is:" <<  nums.at(0) <<  endl;
    cout << "Front:" <<  nums.front() <<  endl;
    cout << "Back:" <<  nums.back() <<  endl;
    //nums.clear();
    cout << "Size:" <<  nums.size() <<  endl;

    nums.insert(nums.begin()+2, 88);

    nums.erase(nums.begin()+2);
    nums.pop_back();

    for(auto i: nums){
        cout << i << endl;
    }

    

    cin.get();
}